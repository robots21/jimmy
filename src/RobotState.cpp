#include "RobotState.h"
#include "Jimmy.h"
#include "SDModel_common.h"
#include "sdlib.h"
 
const std::string RobotState::jointNames[TOTAL_JOINTS] = {
	"L_HZ",
	"L_HFE",
	"L_HAA",
	"L_KFE",
	"L_AFE",
	"L_AAA",
	"R_HZ",
	"R_HFE",
	"R_HAA",
	"R_KFE",
	"R_AFE",
	"R_AAA",
	"L_SFE",
	"L_SAA",
	"L_SR",
	"L_ELB",
	"R_SFE",
	"R_SAA",
	"R_SR",
	"R_ELB",
	"N_YAW",
	"N_TL1",
	"N_TL2"
};

const double RobotState::jointLimits[2][N_JOINTS] = 
{
	{
		-0.43,-0.7,-0.38,0,-0.78,-0.78,
		-0.43,-0.7,-0.27,0,-0.78,-0.78,
		-1.04,-1.12,-2.8,-1.9,
		-1.04,0.09,-2.8,0
	},
	{
		0.43,0.7,0.27,1.12,0.61,0.78,
		0.43,0.7,0.38,1.12,0.61,0.78,
		1.04,-0.09,1.3,0,
		1.04,1.12,1.3,1.9
	}
};

void RobotState::fillZeros() {
	for(int i = 0; i < 3; i++) {
		com[i] = 0.0;
		comd[i] = 0.0;
		root[i] = 0.0;
		rootd[i] = 0.0;
		rootW[i] = 0.0;
		for(int s = 0; s < 2; s++) {
			foot[s][i] = 0.0;
			footd[s][i] = 0.0;
			footW[s][i] = 0.0;
		}
	}

	rootQ = Eigen::Quaterniond::Identity();
	for(int s = 0; s < 2; s++)		footQ[s] = Eigen::Quaterniond::Identity();

	for(int i = 0; i < N_JOINTS; i++) {
		joints[i] = 0.0;
		jointsd[i] = 0.0;
	}

	m = 0.0;

	for(int s = 0; s < 2; s++)		J[s].setZero();
	Jc.setZero();
	Jtorso.setZero();
}

RobotState::RobotState() {
	model = new Jimmy();
	model->sdinit();
	fillZeros();
	for(int i = 0; i < 20; i++)	joints[i] = standPrepPose[i];
	computeSDFvars();
	root[Z] = -(foot[LEFT][Z]+foot[RIGHT][Z])/2.0;
	computeSDFvars();
}

// generate a sdfast state with 
//  root position, orientation, 
//  linear and angular velocity,
//  and all joint position and velocity
double *RobotState::getSDFstate(double *sdState) {
	// copy joint pos and vel
	memcpy(sdState+6, joints, sizeof(double)*N_JOINTS);
	memcpy(sdState+N_Q+6, jointsd, sizeof(double)*N_JOINTS);

	// get position and vel
	memcpy(sdState, root, sizeof(double)*XYZ);
	sdState[3] = rootQ.x();
	sdState[4] = rootQ.y();
	sdState[5] = rootQ.z();
	sdState[26] = rootQ.w();

	memcpy(sdState+N_Q, rootd, sizeof(double)*XYZ);
	memcpy(sdState+N_Q+3, rootW, sizeof(double)*XYZ);

	return sdState;
}

// computes forward kinematics and Jacobian for vairous body parts
void RobotState::computeSDFvars() {
	double sdfast_state[N_U+N_Q];

	// copy joint pos and vel
	memcpy(sdfast_state+6, joints, sizeof(double)*N_JOINTS);
	memcpy(sdfast_state+N_Q+6, jointsd, sizeof(double)*N_JOINTS);

	// get position and vel
	memcpy(sdfast_state, root, sizeof(double)*XYZ);
	sdfast_state[3] = rootQ.x();
	sdfast_state[4] = rootQ.y();
	sdfast_state[5] = rootQ.z();
	sdfast_state[26] = rootQ.w();

	memcpy(sdfast_state+N_Q, rootd, sizeof(double)*XYZ);
	memcpy(sdfast_state+N_Q+3, rootW, sizeof(double)*XYZ);

	set_state(model, sdfast_state);


	const int footBody[2] = {6, 12};
	double ankle2foot[2][3] = {{0.012, -0.0, -0.094}, {0.012, 0.0, -0.094}};



	double dircos[3][3];
	double qq[4];
	double com_to_ankle[3];

	double temp[6];
	for (int side = 0; side < 2; side++) {
		model->sdgetbtj(footBody[side], com_to_ankle);

		//foot positions and jacobians
		sdvadd(com_to_ankle, &(ankle2foot[side][0]), temp);
		body_position(model, NULL, footBody[side], temp, &(foot[side][0]), J[side].data());
		model->sdvel(footBody[side], temp, &(footd[side][0]));

		//foot quaternion
		model->sdorient(footBody[side], dircos);
		sddc2quat(dircos, qq, qq+1, qq+2, qq+3);
		footQ[side] = Eigen::Quaterniond(qq[3], qq[0], qq[1], qq[2]).normalized();

		//foot angular velocities
		model->sdangvel(footBody[side], footW[side]);
	}


	double mom[3], angMom[3], KE;
	model->sdmom(mom, angMom, &KE);
	double Itmp[3][3];
	//mass, com position, and total moment of inertia
	model->sdsys(&m, com, Itmp);

	//comd from momentum
	for(int i = 0; i < 3; i++)
		comd[i] = mom[i]/m;		//compute comd from momentum

	// utorso orientation
	double zeros[3] = {0,0,0};
	body_position(model, NULL, 0, zeros, temp, Jtorso.data());

	//com jacobian
	com_jacobian(model, Jc.data());
}

void RobotState::addToLog(Logger &logger) {

}
