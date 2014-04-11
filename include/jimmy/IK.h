#ifndef __IK_CONTROLLER_H
#define __IK_CONTROLLER_H

/*
 * This is a full body IK controller, it considers all the joints + 6 DOF
 * floating base at the pelvis. 
 *
 * We solve velocity (qd) instead of going directly for positions (q). 
 * We start from some initial configuration. For each call of IK,
 * a qd is generated that best matches the input IKcmd, and we numerically 
 * integrate qd to get q, we then return q and qd to the caller.
 *
 * Since this is gradient based method, solutions are guaranteed to be smooth.
 * Constraints, mostly joint limits, are also handled correctly. So we can 
 * specify unrealistic IKcmd, and the controller will do its best to achieve 
 * it. This IK is formulated as a Quadratic Programming problem. 
 *
 * You can contact Siyuan at sfeng@cs.cmu.edu for more details.
 */

#include "RobotState.h"
#include "IKcmd.h"
#include <eigen3/Eigen/Core>
#include "Logger.h"

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm> 
#include "JimmyCommon.h"

class IKcon 
{
public:
	RobotState ikrs;

	static const int MAX_ROWS = 400;
	static const int MAX_VARS = N_U;
	Eigen::Matrix<double,MAX_ROWS,MAX_VARS> _A;
	Eigen::Matrix<double,MAX_ROWS,1> _b;

	static double timeStep;
	Eigen::Matrix<double,N_U,1> _qdOld;

	std::map <const std::string, double *> lookup;

	EIGEN_MAKE_ALIGNED_OPERATOR_NEW		// google this for more explanation

  // weights for different criteria in the cost function
	double IK_FOOT_WEIGHT;
	double IK_COMxyz_WEIGHT[3];
	double IK_TORSO_WEIGHT;
	double IK_REG_WEIGHT;
	double IK_DQDOT_WEIGHT;
	double IK_ARM_WEIGHT;

  // gains for computing desired xd_d: 
  // xd_d = K * (x_d - x), 
  // where xd_d is the input to the QP, K is the gain, x_d is the desired 
  // position, and x is the current position. 
	double IK_ARM_RATE;
	double IK_POS_RATE;

  // total cost
  double QPval;

	bool IK(const IKcmd &cmd, double *theta_d=NULL, double *thetad_d=NULL);
	void setPose(const double *theta, const double *thetad);
	void setRoot(const double *root, Eigen::Quaterniond rootQ, const double *rootd=NULL, const double *rootW=NULL);
	void getCommand(double *theta_d, double *thetad_d);
	void addToLog(Logger &logger);

	IKcon() : 
		IK_FOOT_WEIGHT(1.0),
		IK_TORSO_WEIGHT(1.0),
		IK_REG_WEIGHT(0.1),
		IK_DQDOT_WEIGHT(0),
		IK_ARM_WEIGHT(1.0),
		IK_ARM_RATE(10.0),
		IK_POS_RATE(2.0),
		QPval(0.0)
	{ 
		for(int i = 0; i < 3; i++)	IK_COMxyz_WEIGHT[i] = 1.0;

		lookup["IK_FOOT_WEIGHT"] = &IK_FOOT_WEIGHT;
		lookup["IK_COMX_WEIGHT"] = &(IK_COMxyz_WEIGHT[X]);
		lookup["IK_COMY_WEIGHT"] = &(IK_COMxyz_WEIGHT[Y]);
		lookup["IK_COMZ_WEIGHT"] = &(IK_COMxyz_WEIGHT[Z]);
		lookup["IK_TORSO_WEIGHT"] = &IK_TORSO_WEIGHT;
		lookup["IK_REG_WEIGHT"] = &IK_REG_WEIGHT;
		lookup["IK_ARM_WEIGHT"] = &IK_ARM_WEIGHT;
		lookup["IK_DQDOT_WEIGHT"] = &IK_DQDOT_WEIGHT;
		lookup["IK_POS_RATE"] = &IK_POS_RATE;
		lookup["IK_ARM_RATE"] = &IK_ARM_RATE;

		_qdOld.setZero();
	}

	bool readParams(const char *fileName)
	{
		std::ifstream in(fileName);
		
		if (!in.good())
			return false;

		bool ret = true;
		std::string name;
		std::map<const std::string, double *>::iterator res;
		double val;
		while (true)
		{
			in >> name;
			if (in.eof())
				break;

			res = lookup.find(name);
			// can't find item
			if (res == lookup.end()) {
				std::cerr << "cant find param: " << name << std::endl;
				ret = false;
				break;
			}

			in >> val; 
			*(res->second) = val;
			//std::cerr << "read " << name << " = " << val << std::endl;
		}

		printParams();

		return ret;
	}

	void printParams() 
	{
		std::cout << "===================================\n" << "ikCon params\n";
		for (std::map<const std::string, double *>::iterator it = lookup.begin(); it != lookup.end(); it++)
			std::cout << it->first << ": " << *(it->second) << std::endl;
		std::cout << "===================================\n"; 
	}
};







#endif
