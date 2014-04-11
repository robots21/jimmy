#ifndef PLAN_DEFINED
#define PLAN_DEFINED

/*
 * Simple planner for walking.
 * It does the following things, 
 *   1. Plans the next couple steps based on the given linear and angular 
 *    velocity
 *   2. Uses the foots to generate center of mass trajectory with lipm_planner
 *   3. Generates swing foot trajectory with 5th spline. 
 */

#include <vector>
#include "Step.h"
#include "JimmyCommon.h"
#include "TrajEW.h"
#include "lipm_planner.h"
#include "IKcmd.h"

class Plan {
public:
	double MAX_SPEED;
	double MAX_ACCEL;
	double SS_TIME;
	double DS_TIME;
	double DS0_TIME;
	double LO_TIME;
	double TD_TIME;
	double SWING_HEIGHT;
	double TIME_STEP;
	double STANCE_WIDTH;
	double PRE_PLAN_TIME;
	double ROLL_AMPLITUDE;

	Plan();
	Plan(const char *config);

	void clearForRecord();
	void addToLog(Logger &logger);

	void initFeet(double lx, double ly, double lYaw, double rx, double ry, double rYaw);
	void driveFutureRobot(double vForward, double vLeft, double dTheta);
	void fillIK_d(IKcmd &IK_d, double t);
	
	void printSteps(char *fileName);
	void printNom(char *fileName);

	void stopHere();
	bool isDone(double walkTime);

	void init();

//private:

	std::vector<double> nomP[2];
	std::vector<double> nomYaw;

	std::vector<Step *> steps[2];
	std::vector<Step *> allSteps;

	TrajEW foot[2][3];
	TrajEW footYaw[2];
	TrajEW footPitch[2];
	TrajEW bodyRoll;
	TrajEW bodyPitch;

	TrajEW zmp_d[2];

	TrajEW jointOffset[23];

	TrajEW armTraj[8];
	TrajEW neckTraj[3];

	std::vector<double> zmpVec[2];
	std::vector<double> com[2];
	std::vector<double> comd[2];
	int startDDPind;

	double endTime;		//time at which the walking trajectory is done
	int prevTDind;		//index of the previous touch down in the nominal trajectory
	int nextTD;			//which foot will touch down next (LEFT or RIGHT)

	void addStep(Step *step, double extraTraj=0);
	void clearVectors();

private:
	double nomPlanForRecord[3];
	double nomNowForRecord[5];
	bool isStopped;
};

#endif
