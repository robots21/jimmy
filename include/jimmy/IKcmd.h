#ifndef IKCMD_INCLUDED
#define IKCMD_INCLUDED

/*
 * Input to IK. User specifies desired, and IK will try to track these subject
 * to kinematic constraints (joint angle limits, etc). 
 */

#include <eigen3/Eigen/Geometry>
#include "Logger.h"
#include "RobotState.h"
#include "Eigen_utils.h"
#include "JimmyCommon.h"

class IKcmd {
public:
  // center of mass position and velocity
	double com[3], comd[3];

  // pelvis orientation and angular velocity
	Eigen::Quaterniond rootQ;
	double rootW[3];

  // foot position and orientation
	double foot[2][3];
	Eigen::Quaterniond footQ[2];
  // foot linear and angular velocity
	double footd[2][3];
	double footW[2][3];

  // arm angles 
	double armJoints[8];


public:
	IKcmd() {

	}

  // set IKcmd to match the given RobotState
	void setToRS(const RobotState &rs) {
		for(int i = 0; i < 3; i++) {
			com[i] = rs.com[i];
			comd[i] = rs.comd[i];
			rootW[i] = rs.rootW[i];
		}
		com[Z] = rs.root[Z];
		comd[Z] = rs.rootd[Z];

		rootQ = rs.rootQ;

		for(int i = 0; i < 2; i++) {
			footQ[i] = rs.footQ[i];
			for(int j = 0; j < 3; j++) {
				foot[i][j] = rs.foot[i][j];
				footd[i][j] = rs.footd[i][j];
				footW[i][j] = rs.footW[i][j];
			}
		}

		for(int i = 0; i < 8; i++)		armJoints[i] = rs.joints[i+12];
	}

	void setVel0() {
		for(int i = 0; i < 3; i++) {
			comd[i] = 0.0;
			rootW[i] = 0.0;
		}
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 2; j++) {
				footd[j][i] = 0.0;
				footW[j][i] = 0.0;
			}
		}
	}

  // add data traces to the logger
	void addToLog(Logger &logger) {
		logger.add_datapoint("IK_d.com[X]","m",&(com[X]));
		logger.add_datapoint("IK_d.com[Y]","m",&(com[Y]));
		logger.add_datapoint("IK_d.com[Z]","m",&(com[Z]));
		logger.add_datapoint("IK_d.comd[X]","v",&(comd[X]));
		logger.add_datapoint("IK_d.comd[Y]","v",&(comd[Y]));
		logger.add_datapoint("IK_d.comd[Z]","v",&(comd[Z]));

		logger.add_quat("IK_d.rootQ",&(rootQ));

		logger.add_datapoint("IK_d.rootW[X]","-",&(rootW[X]));
		logger.add_datapoint("IK_d.rootW[Y]","-",&(rootW[Y]));
		logger.add_datapoint("IK_d.rootW[Z]","-",&(rootW[Z]));

		logger.add_datapoint("IK_d.foot[L][X]","m",&(foot[LEFT][X]));
		logger.add_datapoint("IK_d.foot[L][Y]","m",&(foot[LEFT][Y]));
		logger.add_datapoint("IK_d.foot[L][Z]","m",&(foot[LEFT][Z]));

		logger.add_datapoint("IK_d.foot[R][X]","m",&(foot[RIGHT][X]));
		logger.add_datapoint("IK_d.foot[R][Y]","m",&(foot[RIGHT][Y]));
		logger.add_datapoint("IK_d.foot[R][Z]","m",&(foot[RIGHT][Z]));

		logger.add_datapoint("IK_d.footd[L][X]","v",&(footd[LEFT][X]));
		logger.add_datapoint("IK_d.footd[L][Y]","v",&(footd[LEFT][Y]));
		logger.add_datapoint("IK_d.footd[L][Z]","v",&(footd[LEFT][Z]));

		logger.add_datapoint("IK_d.footd[R][X]","v",&(footd[RIGHT][X]));
		logger.add_datapoint("IK_d.footd[R][Y]","v",&(footd[RIGHT][Y]));
		logger.add_datapoint("IK_d.footd[R][Z]","v",&(footd[RIGHT][Z]));

		logger.add_quat("IK_d.footQ[L]",&(footQ[LEFT]));
		logger.add_quat("IK_d.footQ[R]",&(footQ[RIGHT]));

		logger.add_datapoint("IK_d.footw[L][X]","v",&(footW[LEFT][X]));
		logger.add_datapoint("IK_d.footw[L][Y]","v",&(footW[LEFT][Y]));
		logger.add_datapoint("IK_d.footw[L][Z]","v",&(footW[LEFT][Z]));

		logger.add_datapoint("IK_d.footw[R][X]","v",&(footW[RIGHT][X]));
		logger.add_datapoint("IK_d.footw[R][Y]","v",&(footW[RIGHT][Y]));
		logger.add_datapoint("IK_d.footw[R][Z]","v",&(footW[RIGHT][Z]));

		logger.add_datapoint("IK_d.L_SFE","r",&(armJoints[0]));
		logger.add_datapoint("IK_d.L_SAA","r",&(armJoints[1]));
		logger.add_datapoint("IK_d.L_SR","r",&(armJoints[2]));
		logger.add_datapoint("IK_d.L_ELB","r",&(armJoints[3]));
		logger.add_datapoint("IK_d.R_SFE","r",&(armJoints[4]));
		logger.add_datapoint("IK_d.R_SAA","r",&(armJoints[5]));
		logger.add_datapoint("IK_d.R_SR","r",&(armJoints[6]));
		logger.add_datapoint("IK_d.R_ELB","r",&(armJoints[7]));
	}

};

#endif
