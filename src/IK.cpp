//Code by Eric Whitman
//Based on code by Siyuan Feng
//Based on code by Eric Whitman
//Based on code by Ben Stephens


#include "IK.h"
#include "JimmyCommon.h"
#include "eigQuadProgTemplate.h"
#include "Utils.h"
#include "Eigen_utils.h"
#include "Logger.h"
#include "RobotState.h"

double IKcon::timeStep;

void IKcon::setPose(const double *theta, const double *thetad) {
	for(int i = 0;i < N_J; i++) {
		ikrs.joints[i] = theta[i];
		ikrs.jointsd[i] = thetad[i];
	}
	ikrs.computeSDFvars();
}

void IKcon::setRoot(const double *root, Eigen::Quaterniond rootQ, const double *rootd, const double *rootW) {
	for(int i = 0; i < 3; i++)	ikrs.root[i] = root[i];
	ikrs.rootQ = rootQ;
	if(rootd)		for(int i = 0; i < 3; i++)	ikrs.rootd[i] = rootd[i];
	if(rootW)		for(int i = 0; i < 3; i++)	ikrs.rootW[i] = rootW[i];
	ikrs.computeSDFvars();
}


/*
 * The basic idea is to solve for qd with a Quadratic Program. 
 * IK keeps its own internal state q. For each call to IK, it generates a new 
 * qd and with which integrates its q. 
 *
 * We want to track position x (e.g. foot, com, etc). We can compute a desired
 * velocity using feedback with
 * xd_d' = K*(x_d - x) + xd_d
 * where K is some gain, x_d, xd_d is the desired position and velocity, and x 
 * is IK's position. x_d and xd_d are specified in IKcmd. 
 * We then solve a QP with unknown qd that minimize 
 * |J * qd - xd_d'|^2,
 * where J is the Jacobian for point x. 
 *
 * To track multiple locations on the robot, we simply stack all the Jacobians 
 * and xd_d', and minimize the same cost function.  
 *
 * Joint limits are handled in the constraints part in QP.
 *
 * For more details, contact sfeng@cs.cmu.edu
 */
bool IKcon::IK(const IKcmd &cmd, double *theta_d, double *thetad_d) {
	Eigen::AngleAxisd rotVec;
	Eigen::Vector3d Rotvec;


	int rowIdx = 0;

	_A.setZero();
	_b.setZero();
	Eigen::Map<Eigen::MatrixXd> A(_A.data(),MAX_ROWS,N_U);
	Eigen::Map<Eigen::VectorXd> b(_b.data(),MAX_ROWS);


	//feet ***********************************************************************************
	//Jacobian in A
	for(int s = 0; s < 2; s++) {
		
		A.block<6,N_U>(rowIdx,0) = ikrs.J[s].transpose() * IK_FOOT_WEIGHT;

		//translation
		for (int i = 0; i < 3; i++)
			b(rowIdx+i) = cmd.footd[s][i] + IK_POS_RATE*(cmd.foot[s][i] - ikrs.foot[s][i]);

		//rotation
		Rotvec = quatMinus(ikrs.footQ[s], cmd.footQ[s]);
		for (int i = 0; i < 3; i++)
			b(rowIdx+i+3) = cmd.footW[s][i] - IK_POS_RATE*Rotvec[i];

		//weight
		b.segment<6>(rowIdx) *= IK_FOOT_WEIGHT;
		rowIdx += 6;	//indexing
		
	}


	//CoM (translation only) *****************************************************************************
	//Jacobian in A

	A.block<3,N_U>(rowIdx,0) = ikrs.Jc.transpose();
	for(int i = 0; i < 3; i++) {
		if(i == Z) {	//replace with a row of the identity matrix
			A.block<1, N_U>(rowIdx+i,0).setZero();
			A(rowIdx+i,i) = 1.0;
		}
	}

	//translation
	for (int i = 0; i < 3; i++) {
		if(i==Z)				b(rowIdx+i) = cmd.comd[i] + IK_POS_RATE*(cmd.com[i] - ikrs.root[i]);
		else					b(rowIdx+i) = cmd.comd[i] + IK_POS_RATE*(cmd.com[i]  - ikrs.com[i]);
	}

	//weight
	b.segment<3>(rowIdx);
	for(int i = 0; i < 3; i++) {
		b[rowIdx+i] *= IK_COMxyz_WEIGHT[i];
		A.block<1, N_U>(rowIdx+i,0) *= IK_COMxyz_WEIGHT[i];
	}

	rowIdx += 3;	//indexing



	//Torso (orientation only) **************************************************************************
	//Jacobian in A (2nd half only)

	A.block<3,N_U>(rowIdx,0) = ikrs.Jtorso.block<N_U,3>(0,3).transpose() * IK_TORSO_WEIGHT;

	//rotation
	Rotvec = quatMinus(ikrs.rootQ, cmd.rootQ);
	for (int i = 0; i < 3; i++)
		b(rowIdx+i) = cmd.rootW[i] - IK_POS_RATE*Rotvec[i];

	//weight
	b.segment<3>(rowIdx) *= IK_TORSO_WEIGHT;

	rowIdx += 3;	//indexing

	//Regularization **************************************************************************
	A.block<N_U,N_U>(rowIdx,0) = Eigen::Matrix<double,N_U,N_U>::Identity() * IK_REG_WEIGHT;
	b.segment<N_U>(rowIdx).setZero();
	rowIdx += N_U;


	//arm control
	for(int i = 0; i < 8; i++) {
		A(rowIdx+i, 6+i+12) = IK_ARM_WEIGHT;
		b[rowIdx+i] = (cmd.armJoints[i]-ikrs.joints[12+i])*IK_ARM_WEIGHT*IK_ARM_RATE;
	}
	rowIdx += 8;

	//knees
	for(int s = 0; s < 2; s++) {
		if(ikrs.joints[L_KFE+6*s] < 0.3) {
			double weight = 0.2*(0.3-ikrs.joints[L_KFE+6*s]);
			A(rowIdx, 6+L_KFE+6*s) = weight;
			b[rowIdx] = 0.5*weight;
			rowIdx++;
		}
	}


	/////////////////////////////////////////////////////////
	const int N_VARS = N_U;
	const int N_EQ_CON = 1;
	const int N_INEQ_CON = N_J*2;

	Eigen::Matrix<double,N_VARS,1> x;

	Eigen::Matrix<double,N_VARS,N_VARS> G =	A.topRows(rowIdx).transpose()*A.topRows(rowIdx);
	Eigen::Matrix<double,N_VARS,1> g0 =	-A.topRows(rowIdx).transpose()*b.topRows(rowIdx);

	Eigen::Matrix<double,N_EQ_CON, N_VARS> CE;
	Eigen::Matrix<double,N_EQ_CON,1> ce0;
	CE.setZero();
	ce0.setZero();

	Eigen::Matrix<double,N_INEQ_CON,N_VARS> CI;
	Eigen::Matrix<double,N_INEQ_CON,1> ci0;
	CI.setZero();
	ci0.setZero();

	//Begin Equality Constraints
	/******************************************************************************/

	int ceInd = 0;


	//Begin Inequality Constraints
	/*****************************************************************/


	int IEind = 0;
	// joint limit:
	for (int i = 0; i < N_J; i++) {
		//  qd*dt >= low - q
		CI(2*i, 6+i) = timeStep;
		ci0(2*i) = -RobotState::jointLimits[0][i] + ikrs.joints[i];

		// -qd*dt >= q - up
		CI(2*i+1, 6+i) = -timeStep;
		ci0(2*i+1) = RobotState::jointLimits[1][i] - ikrs.joints[i];
	}
	IEind += N_J*2;




	/*
  min 0.5 * x G x + g0 x
  s.t.
    CE^T x + ce0 = 0
    CI^T x + ci0 >= 0 
	 */



	QPval = Eigen::solve_quadprog<N_VARS,N_EQ_CON,N_INEQ_CON>(G, g0, CE.transpose(), ce0, CI.transpose(), ci0, x);
	if(QPval == std::numeric_limits<double>::infinity())	Logger::setErrEW(1);


	// integrate one step
	double qdot[N_Q] = {0};
	double q[N_Q] = {0};
	double sdfState[N_Q+N_U];
	dvec_copy(q, ikrs.getSDFstate(sdfState), N_Q);
	ikrs.model->sdu2qdot(x.data(), qdot);

	for (int i = 0; i < N_Q; i++)
		q[i] += timeStep * qdot[i];

	// update Robot State
	double filtA = 0.05;
	dvec_copy(ikrs.root, q, 3);
	for(int i = 0; i < 3; i++)	ikrs.rootd[i] = (1-filtA)*ikrs.rootd[i] + filtA*qdot[i];
	ikrs.rootQ = Eigen::Quaterniond(q[N_U], q[3], q[4], q[5]);
	ikrs.rootQ.normalize();
	for(int i = 0; i < 3; i++)	ikrs.rootW[i] = (1-filtA)*ikrs.rootW[i] + filtA*qdot[i+3];
	dvec_copy(ikrs.joints, q+6, N_J);

	for(int i = 0; i < N_J; i++)	ikrs.jointsd[i] = (1-filtA)*ikrs.jointsd[i] + filtA*qdot[i+6];
	ikrs.computeSDFvars();	//forward kinematics, Jacobians, etc.

	//output
	if(theta_d)		dvec_copy(theta_d, q+6, N_J);
	if(thetad_d)	dvec_copy(thetad_d, qdot+6, N_J);



	return true;
}



void IKcon::getCommand(double *theta_d, double *thetad_d) {
	if(theta_d)		dvec_copy(theta_d, ikrs.joints, N_J);
	if(thetad_d)	dvec_copy(thetad_d, ikrs.jointsd, N_J);
}



void IKcon::addToLog(Logger &logger) {
	logger.add_datapoint("IK.QPval","-",&QPval);
	logger.add_datapoint("IK.com[X]","m",&(ikrs.com[X]));
	logger.add_datapoint("IK.com[Y]","m",&(ikrs.com[Y]));
	logger.add_datapoint("IK.com[Z]","m",&(ikrs.com[Z]));

	logger.add_datapoint("IK.comd[X]","v",&(ikrs.comd[X]));
	logger.add_datapoint("IK.comd[Y]","v",&(ikrs.comd[Y]));
	logger.add_datapoint("IK.comd[Z]","v",&(ikrs.comd[Z]));

	logger.add_quat("IK.rootQ",&(ikrs.rootQ));

	logger.add_datapoint("IK.foot[L][X]","m",&(ikrs.foot[LEFT][X]));
	logger.add_datapoint("IK.foot[L][Y]","m",&(ikrs.foot[LEFT][Y]));
	logger.add_datapoint("IK.foot[L][Z]","m",&(ikrs.foot[LEFT][Z]));
	logger.add_datapoint("IK.foot[R][X]","m",&(ikrs.foot[RIGHT][X]));
	logger.add_datapoint("IK.foot[R][Y]","m",&(ikrs.foot[RIGHT][Y]));
	logger.add_datapoint("IK.foot[R][Z]","m",&(ikrs.foot[RIGHT][Z]));

	logger.add_quat("IK.footQ[L]",&(ikrs.footQ[LEFT]));
	logger.add_quat("IK.footQ[R]",&(ikrs.footQ[RIGHT]));


	logger.add_datapoint("IK.rootW[X]","r/s",&(ikrs.rootW[X]));
	logger.add_datapoint("IK.rootW[Y]","r/s",&(ikrs.rootW[Y]));
	logger.add_datapoint("IK.rootW[Z]","r/s",&(ikrs.rootW[Z]));

	logger.add_datapoint("IK.root[X]","m",&(ikrs.root[X]));
	logger.add_datapoint("IK.root[Y]","m",&(ikrs.root[Y]));
	logger.add_datapoint("IK.root[Z]","m",&(ikrs.root[Z]));
	logger.add_datapoint("IK.rootd[X]","v",&(ikrs.rootd[X]));
	logger.add_datapoint("IK.rootd[Y]","v",&(ikrs.rootd[Y]));
	logger.add_datapoint("IK.rootd[Z]","v",&(ikrs.rootd[Z]));

	logger.add_datapoint("IK.jt[L_HZ]","-",&(ikrs.joints[0]));
	logger.add_datapoint("IK.jt[L_HFE]","-",&(ikrs.joints[1]));
	logger.add_datapoint("IK.jt[L_HAA]","-",&(ikrs.joints[2]));
	logger.add_datapoint("IK.jt[L_KFE]","-",&(ikrs.joints[3]));
	logger.add_datapoint("IK.jt[L_AFE]","-",&(ikrs.joints[4]));
	logger.add_datapoint("IK.jt[L_AAA]","-",&(ikrs.joints[5]));
	logger.add_datapoint("IK.jt[R_HZ]","-",&(ikrs.joints[6]));
	logger.add_datapoint("IK.jt[R_HFE]","-",&(ikrs.joints[7]));
	logger.add_datapoint("IK.jt[R_HAA]","-",&(ikrs.joints[8]));
	logger.add_datapoint("IK.jt[R_KFE]","-",&(ikrs.joints[9]));
	logger.add_datapoint("IK.jt[R_AFE]","-",&(ikrs.joints[10]));
	logger.add_datapoint("IK.jt[R_AAA]","-",&(ikrs.joints[11]));
	logger.add_datapoint("IK.jt[L_SFE]","-",&(ikrs.joints[12]));
	logger.add_datapoint("IK.jt[L_SAA]","-",&(ikrs.joints[13]));
	logger.add_datapoint("IK.jt[L_SR]","-",&(ikrs.joints[14]));
	logger.add_datapoint("IK.jt[L_ELB]","-",&(ikrs.joints[15]));
	logger.add_datapoint("IK.jt[R_SFE]","-",&(ikrs.joints[16]));
	logger.add_datapoint("IK.jt[R_SAA]","-",&(ikrs.joints[17]));
	logger.add_datapoint("IK.jt[R_SR]","-",&(ikrs.joints[18]));
	logger.add_datapoint("IK.jt[R_ELB]","-",&(ikrs.joints[19]));

	logger.add_datapoint("IK.jtd[L_HZ]","-",&(ikrs.jointsd[0]));
	logger.add_datapoint("IK.jtd[L_HFE]","-",&(ikrs.jointsd[1]));
	logger.add_datapoint("IK.jtd[L_HAA]","-",&(ikrs.jointsd[2]));
	logger.add_datapoint("IK.jtd[L_KFE]","-",&(ikrs.jointsd[3]));
	logger.add_datapoint("IK.jtd[L_AFE]","-",&(ikrs.jointsd[4]));
	logger.add_datapoint("IK.jtd[L_AAA]","-",&(ikrs.jointsd[5]));
	logger.add_datapoint("IK.jtd[R_HZ]","-",&(ikrs.jointsd[6]));
	logger.add_datapoint("IK.jtd[R_HFE]","-",&(ikrs.jointsd[7]));
	logger.add_datapoint("IK.jtd[R_HAA]","-",&(ikrs.jointsd[8]));
	logger.add_datapoint("IK.jtd[R_KFE]","-",&(ikrs.jointsd[9]));
	logger.add_datapoint("IK.jtd[R_AFE]","-",&(ikrs.jointsd[10]));
	logger.add_datapoint("IK.jtd[R_AAA]","-",&(ikrs.jointsd[11]));
	logger.add_datapoint("IK.jtd[L_SFE]","-",&(ikrs.jointsd[12]));
	logger.add_datapoint("IK.jtd[L_SAA]","-",&(ikrs.jointsd[13]));
	logger.add_datapoint("IK.jtd[L_SR]","-",&(ikrs.jointsd[14]));
	logger.add_datapoint("IK.jtd[L_ELB]","-",&(ikrs.jointsd[15]));
	logger.add_datapoint("IK.jtd[R_SFE]","-",&(ikrs.jointsd[16]));
	logger.add_datapoint("IK.jtd[R_SAA]","-",&(ikrs.jointsd[17]));
	logger.add_datapoint("IK.jtd[R_SR]","-",&(ikrs.jointsd[18]));
	logger.add_datapoint("IK.jtd[R_ELB]","-",&(ikrs.jointsd[19]));

}


   
