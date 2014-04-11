#include "Plan.h"	
#include "JimmyCommon.h"
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include "IK.h"
#include "TrajEW.h"

static const double armsDown[8] = {-0.33, -1.14, 1.03, -1.42, -0.33, 1.14, 1.03, 1.42};
static const double armsOut[8] = {-0.33, -0.2, 1.03, 0, -0.33, 0.2, 1.03, 0};

static const double neckLean[2][3] = {
	{0, 0.5, 0.5},
	{0, -0.5, -0.5}
};

void Plan::clearForRecord() {
	for(int i = 0; i < 3; i++) {
		nomPlanForRecord[i] = 0.0;
	}
	for(int i = 0; i < 5; i++) {
		nomNowForRecord[i] = 0.0;
	}

}


void Plan::addToLog(Logger &logger) {
	logger.add_datapoint("PN.nomPln[X]","m",&(nomPlanForRecord[0]));
	logger.add_datapoint("PN.nomPln[Y]","m",&(nomPlanForRecord[1]));
	logger.add_datapoint("PN.nomPln[YAW]","r",&(nomPlanForRecord[2]));

	logger.add_datapoint("PN.nom[X]","m",&(nomNowForRecord[0]));
	logger.add_datapoint("PN.nom[Y]","m",&(nomNowForRecord[1]));
	logger.add_datapoint("PN.nom[YAW]","r",&(nomNowForRecord[2]));
	logger.add_datapoint("PN.z_d[X]","m",&(nomNowForRecord[3]));
	logger.add_datapoint("PN.z_d[Y]","m",&(nomNowForRecord[4]));
}


void Plan::init() {
	MAX_SPEED = 0.02;
	MAX_ACCEL = 0.01;
	SS_TIME = 3.0;
	DS_TIME = 2.0;
	DS0_TIME = DS_TIME+SS_TIME/2.0;
	LO_TIME = 0.8;
	TD_TIME = LO_TIME;
	SWING_HEIGHT = 0.05;
	TIME_STEP = 0.01;
	STANCE_WIDTH = 0.2;
	PRE_PLAN_TIME = 5.0;
	ROLL_AMPLITUDE = 0.3;
	endTime = std::numeric_limits<double>::infinity();
	startDDPind = 0;
	isStopped = false;
}

Plan::Plan() {
	init();
}

Plan::Plan(const char *config) {
	init();

	static std::map <const std::string, double *> planLookup;

	planLookup["MAX_SPEED"] = &(MAX_SPEED);
	planLookup["MAX_ACCEL"] = &(MAX_ACCEL);
	planLookup["SS_TIME"] = &(SS_TIME);
	planLookup["DS_TIME"] = &(DS_TIME);
	planLookup["DS0_TIME"] = &(DS0_TIME);
	planLookup["LO_TIME"] = &(LO_TIME);
	planLookup["TD_TIME"] = &(TD_TIME);
	planLookup["SWING_HEIGHT"] = &(SWING_HEIGHT);
	planLookup["TIME_STEP"] = &(TIME_STEP);
	planLookup["STANCE_WIDTH"] = &(STANCE_WIDTH);
	planLookup["PRE_PLAN_TIME"] = &(PRE_PLAN_TIME);
	planLookup["ROLL_AMPLITUDE"] = &(ROLL_AMPLITUDE);
	
	std::ifstream in(config);

	if (in.good()) {

		std::string name;
		std::map<const std::string, double *>::iterator res;
		double val;
		while (true) {
			in >> name;
			if (in.eof())		break;

			res = planLookup.find(name);
			// can't find item
			if (res == planLookup.end()) {
				std::cerr << "unknown param: " << name << " aborting." << std::endl;
				break;
			}

			in >> val;
			*(res->second) = val;
			std::cerr << "read " << name << " = " << val << std::endl;
		}
	}
	else {
		printf("couldn't open config file\n");
	}
	in.close();

	IKcon::timeStep = TIME_STEP;
}

void Plan::driveFutureRobot(double vForward, double vLeft, double dTheta) {
	if(isStopped) return;
	if(nomYaw.size() < (DS0_TIME-DS_TIME)/TIME_STEP) {
		vForward = vLeft = dTheta = 0.0;
	}
	//drive virtual point
	double oldYaw = nomYaw.back();
	double newYaw = oldYaw+dTheta*TIME_STEP;
	nomYaw.push_back(newYaw);
	double newX = nomP[X].back() + (vForward*cos(oldYaw) - vLeft*sin(oldYaw))*TIME_STEP;
	nomP[X].push_back(newX);
	double newY = nomP[Y].back() + (vForward*sin(oldYaw) + vLeft*cos(oldYaw))*TIME_STEP;
	nomP[Y].push_back(newY);

	nomPlanForRecord[0] = newX;
	nomPlanForRecord[1] = newY;
	nomPlanForRecord[2] = newYaw;


	int nextTDind = prevTDind + (DS_TIME+SS_TIME)/TIME_STEP;
	if(allSteps.size() == 2)		nextTDind = prevTDind + (DS0_TIME+SS_TIME)/TIME_STEP;		//long first DS

	int curInd = nomYaw.size();

	//printf("drive %d %d, %g %g %g\n", curInd, nextTDind, vForward, vLeft, dTheta);
	double time = curInd*TIME_STEP;
	if(curInd >= nextTDind) {	//time for a new step
		printf("New step %d %d %d\n", curInd, prevTDind, nextTDind);
		steps[nextTD].back()->lo = time-SS_TIME;	//beginning of swing
		Step *s;
		//offset step to left or right of nominal trajectory by half a stance width
		if(nextTD == LEFT) {
			s = new Step(newX - sin(newYaw)*STANCE_WIDTH/2.0, newY + cos(newYaw)*STANCE_WIDTH/2.0, newYaw, time, nextTD);
		}
		else {	//nextTD == RIGHT
			s = new Step(newX + sin(newYaw)*STANCE_WIDTH/2.0, newY - cos(newYaw)*STANCE_WIDTH/2.0, newYaw, time, nextTD);				
		}
		addStep(s);
		prevTDind = curInd;	//keep track of when to add the next step
		nextTD = 1-nextTD;	//keep track of which foot is next
	}
}



void Plan::addStep(Step *step, double extraTraj) {
	printf("Add step: %d, %g, %g, %g, %g\n",step->side, step->x, step->y, step->yaw, step->td);

	int s = step->side;
	if(steps[s].size() > 0) {	//if not initializing
		Step *prev = allSteps.back();
		double prevInside[2] = {-sin(prev->yaw), cos(prev->yaw)};
		double prevForward[2] = {cos(prev->yaw), sin(prev->yaw)};
		if(prev->side == LEFT) {
			prevInside[0] = -prevInside[0];
			prevInside[1] = -prevInside[1];
		}


		step->adjustClearOf(allSteps.back());
		steps[s].back()->lo = step->td-SS_TIME;		//previous step now ends
		foot[s][X].addMove(steps[s].back()->lo, step->td, step->x);
		foot[s][Y].addMove(steps[s].back()->lo, step->td, step->y);
		foot[s][Z].addMove(steps[s].back()->lo-DS_TIME/4.0, steps[s].back()->lo, 0.025, Linear);		//lift foot up a bit
		foot[s][Z].addKnot(steps[s].back()->lo+LO_TIME, SWING_HEIGHT, 0.0);				//remainder of liftoff
		foot[s][Z].addMove(step->td-TD_TIME, step->td, 0.04, Linear);						//put foot down (mostly)
		foot[s][Z].addKnot(step->td+DS_TIME/2.0, 0.0);								//finish putting it down
		footPitch[s].addMove(steps[s].back()->lo+LO_TIME/2.0, steps[s].back()->lo+LO_TIME, -0.1, Linear);
		if (s == LEFT)
      footPitch[s].addMove(step->td, step->td+DS_TIME/2., 0.0, Linear);
    else
  		footPitch[s].addMove(step->td-TD_TIME, step->td, 0.0, Linear);
		footYaw[s].addMove(steps[s].back()->lo, step->td, step->yaw);
		//pause a bit
		zmp_d[X].addKnot(step->td-SS_TIME-DS_TIME/4.0, allSteps.back()->x+prevInside[X]*0.01);
		zmp_d[Y].addKnot(step->td-SS_TIME-DS_TIME/4.0, allSteps.back()->y+prevInside[Y]*0.01);
		//beginning of SS
		zmp_d[X].addKnot(step->td-SS_TIME, allSteps.back()->x+prevInside[X]*0.01);
		zmp_d[Y].addKnot(step->td-SS_TIME, allSteps.back()->y+prevInside[Y]*0.01);

		//halfway through LO
		zmp_d[X].addKnot(step->td-SS_TIME+LO_TIME/2.0, allSteps.back()->x+prevInside[X]*0.01);
		zmp_d[Y].addKnot(step->td-SS_TIME+LO_TIME/2.0, allSteps.back()->y+prevInside[Y]*0.01);

		//shift out a bit
		zmp_d[X].addKnot(step->td-SS_TIME+LO_TIME, allSteps.back()->x-prevInside[X]*0.01-prevForward[X]*0.0);
		zmp_d[Y].addKnot(step->td-SS_TIME+LO_TIME, allSteps.back()->y-prevInside[Y]*0.01-prevForward[X]*0.0);
		//end of SS
		zmp_d[X].addKnot(step->td, allSteps.back()->x-prevInside[X]*0.01-prevForward[X]*0.0);
		zmp_d[Y].addKnot(step->td, allSteps.back()->y-prevInside[Y]*0.01-prevForward[X]*0.0);

		for(int i = 0; i < 4; i++) {
			armTraj[i+4*s].addKnot(step->td-SS_TIME, armsDown[i+4*s], 0.0);
			armTraj[i+4*s].addKnot(step->td, armsDown[i+4*s], 0.0);
			armTraj[i+4-4*s].addKnot(step->td-SS_TIME, armsOut[i+4-4*s], 0.0);
			armTraj[i+4-4*s].addKnot(step->td, armsOut[i+4-4*s], 0.0);
		}

		for(int i = 0; i < 3; i++) {
			neckTraj[i].addKnot(step->td-SS_TIME, neckLean[1-s][i], 0.0);
			neckTraj[i].addKnot(step->td, neckLean[1-s][i], 0.0);
		}


		//absurd hack: hip roll offset
		double hrOffset = 0.045;
		double hrwOffset = -0.12;
		if(s == RIGHT) {
			hrOffset = -0.045;
			hrwOffset = -hrwOffset;
		}
		//stance
		jointOffset[8-s*6].addMove(steps[s].back()->lo, steps[s].back()->lo+LO_TIME/2.0, -hrOffset, Linear);
		jointOffset[8-s*6].addMove(step->td-TD_TIME/2.0, step->td, 0, Linear);
		//swing
		jointOffset[2+s*6].addMove(steps[s].back()->lo+LO_TIME/2., steps[s].back()->lo+LO_TIME, -hrwOffset, Linear);
		jointOffset[2+s*6].addMove(step->td, step->td+DS_TIME/3.0, 0, Linear);

		//absurd asymmetric hack: right hip and knee offset
		if(s == LEFT) {
      jointOffset[R_HFE].addMove(steps[s].back()->lo, steps[s].back()->lo+LO_TIME/2.0, 0.12, Linear);
		  jointOffset[R_HFE].addMove(step->td-TD_TIME/2.0, step->td, 0, Linear);
		  //jointOffset[R_AFE].addMove(steps[s].back()->lo, steps[s].back()->lo+LO_TIME/2.0, -0.02, Linear);
		  //jointOffset[R_AFE].addMove(step->td-TD_TIME/2.0, step->td, 0, Linear); 
			
      jointOffset[R_KFE].addMove(steps[s].back()->lo, steps[s].back()->lo+LO_TIME/4.0, -0.0, Linear);
			jointOffset[R_KFE].addMove(step->td-TD_TIME/2.0, step->td, 0, Linear);
		}
    
    //absurd asymmetric hack: right hip and knee offset
		if(s == RIGHT) {
			jointOffset[L_KFE].addMove(steps[s].back()->lo, steps[s].back()->lo+LO_TIME/4.0, -0.0, Linear);
			jointOffset[L_KFE].addMove(step->td-TD_TIME/2.0, step->td, 0, Linear);
			jointOffset[L_AFE].addMove(steps[s].back()->lo, steps[s].back()->lo+LO_TIME/2.0, 0.03, Linear);
			jointOffset[L_AFE].addMove(step->td-TD_TIME/2.0, step->td, 0, Linear);
		}
		
    double bRoll = ROLL_AMPLITUDE;
		if(step->side == RIGHT)		bRoll = -bRoll;
		bodyRoll.addKnot(step->td-SS_TIME, bRoll, 0);
		bodyRoll.addKnot(step->td, bRoll, 0);

		//fill in zmpVec
		int startInd = zmpVec[X].size();
		for(int i = startInd; i < (extraTraj + step->td)/TIME_STEP; i++) {
			for(int j = 0; j < 2; j++) {
				zmpVec[j].push_back(zmp_d[j].readPos(i*TIME_STEP));
			}
		}

		if(com[X].size() < startDDPind) {
			startDDPind = com[X].size()-1;
			printf("running extra trajectory\n");
		}

		printf("Planning from %d to %d\n", startDDPind, zmpVec[X].size());
		//run DDP in both x and y
		for(int i = 0; i < 2; i++) {
			double x0[2] = {(com[i])[startDDPind], (comd[i])[startDDPind]};
			LipmConstHeightPlanner ddp(0.45, TIME_STEP);			
			ddp.getTrajs(x0, startDDPind, zmpVec[i], com[i], comd[i]);
		}

		if(com[X].size() != zmpVec[X].size()) {
			printf("Size mismatch after ddp plan %d %d\n", com[X].size(), zmpVec[X].size());
			exit(-1);
		}
	}
	else {	//if initializing
		foot[s][X].addKnot(0.0, step->x, 0, 0);
		foot[s][Y].addKnot(0.0, step->y, 0, 0);
		foot[s][Z].addKnot(0.0, 0.0, 0, 0);
		footYaw[s].addKnot(0.0, step->yaw, 0, 0);
	}
	steps[s].push_back(step);
	allSteps.push_back(step);
}


void Plan::initFeet(double lx, double ly, double lYaw, double rx, double ry, double rYaw) {
	printf("Init feet\n");
	isStopped = false;
	clearVectors();
	Step *il = new Step(lx, ly, lYaw, -std::numeric_limits<double>::infinity(), LEFT);
	addStep(il);
	Step *ir = new Step(rx, ry, rYaw, -std::numeric_limits<double>::infinity(), RIGHT);
	addStep(ir);
	nomP[X].push_back((lx+rx)/2.0);
	nomP[Y].push_back((ly+ry)/2.0);
	nomYaw.push_back((lYaw+rYaw)/2.0);
	zmp_d[X].addKnot(0,(lx+rx)/2.0);
	zmp_d[Y].addKnot(0,(ly+ry)/2.0);
	prevTDind = 0;
	nextTD = LEFT;
	endTime = std::numeric_limits<double>::infinity();
	bodyPitch.addKnot(1.5, 0.15, 0);
	zmp_d[X].overRideType = Cubic;
	zmp_d[Y].overRideType = Cubic;
	foot[LEFT][Z].overRideType = Cubic;
	foot[RIGHT][Z].overRideType = Cubic;
}




void Plan::clearVectors() {
	nomP[X].clear();
	nomP[Y].clear();
	nomYaw.clear();

	steps[LEFT].clear();
	steps[RIGHT].clear();
	allSteps.clear();

	zmp_d[X].clear();
	zmp_d[Y].clear();
	for(int s = 0; s < 2; s++)	for(int i = 0; i < 3; i++)	foot[s][i].clear();
	for(int i = 0; i < 2; i++) {
		zmpVec[i].clear();
		com[i].clear();
		comd[i].clear();
		footYaw[i].clear();
		footPitch[i].clear();
	}
	bodyRoll.clear();
	bodyPitch.clear();

	for(int i = 0; i < 23; i++)	jointOffset[i].clear();
	for(int i = 0; i < 8; i++)	armTraj[i].clear();
	for(int i = 0; i < 3; i++)	neckTraj[i].clear();
}

void Plan::printSteps(char *fileName) {
	std::ofstream f(fileName);
	for(int i = 0; i < allSteps.size(); i++) {
		Step *s = allSteps[i];
		f << s->x << " " << s->y << " " << s->yaw << " " << s->td << " " << s->lo << " " << s->side << std::endl;
	}


	f.close();
}

void Plan::printNom(char *fileName) {
	if(nomP[X].size() != nomP[Y].size()) {
		printf("size mismatch x = %d; y = %d\n", nomP[X].size(), nomP[Y].size());
		return;
	}
	if(nomP[X].size() != nomYaw.size()) {
		printf("size mismatch x = %d; yaw = %d\n", nomP[X].size(), nomYaw.size());
		return;
	}
	
	std::ofstream f(fileName);
	for(int i = 0; i < nomP[X].size(); i++) {
		f << TIME_STEP*i << " " << nomP[X][i] << " " << nomP[Y][i] << " " << nomYaw[i] << std::endl;
	}


	f.close();
}

void Plan::stopHere() {
	if(isStopped)	return;
	isStopped = true;
	Step *prev = allSteps.back();
	double yaw = prev->yaw;
	Step *s;
	if(prev->side == LEFT) {
		s = new Step(prev->x+sin(yaw)*STANCE_WIDTH, prev->y-cos(yaw)*STANCE_WIDTH, yaw, prev->td+DS_TIME+SS_TIME, RIGHT);
	}
	else {
		s = new Step(prev->x-sin(yaw)*STANCE_WIDTH, prev->y+cos(yaw)*STANCE_WIDTH, yaw, prev->td+DS_TIME+SS_TIME, LEFT);
	}
	double forwardVec[2] = {cos(s->yaw), sin(s->yaw)};

	zmp_d[X].addKnot(s->td+DS0_TIME, (s->x+prev->x)/2.0+forwardVec[X]*0.0);
	zmp_d[Y].addKnot(s->td+DS0_TIME, (s->y+prev->y)/2.0+forwardVec[Y]*0.0);
	bodyRoll.addKnot(s->td+DS0_TIME, 0.0);
	bodyPitch.addMove(s->td+DS0_TIME-1.5, s->td+DS0_TIME, 0.0, Cubic);

	for(int i = 0; i < 3; i++)	neckTraj[i].addKnot(s->td+DS0_TIME, 0.0, 0.0);
	for(int i = 0; i < 8; i++)	armTraj[i].addKnot(s->td+DS0_TIME, armsOut[i], 0.0);

	addStep(s, DS0_TIME+0.1);	//0.1 for buffer; DS0_TIME is time to return to symmetric DS

	printf("Stopping at {%g, %g}\n", (s->x+prev->x)/2.0,(s->y+prev->y)/2.0);
	endTime = s->td+DS0_TIME;
}

bool Plan::isDone(double walkTime) {
	return walkTime > endTime;
}

void Plan::fillIK_d(IKcmd &IK_d, double t) {
	int nowInd = (int)floor(t/TIME_STEP);
	nomNowForRecord[0] = (nomP[X])[nowInd];
	nomNowForRecord[1] = (nomP[Y])[nowInd];
	nomNowForRecord[2] = (nomYaw)[nowInd];
	nomNowForRecord[3] = (zmpVec[X])[nowInd];
	nomNowForRecord[4] = (zmpVec[Y])[nowInd];
	startDDPind = (t+0.1)/TIME_STEP;

	IK_d.com[X] = (com[X])[nowInd];
	IK_d.com[Y] = (com[Y])[nowInd];
	IK_d.com[Z] = 0.4;

	IK_d.comd[X] = (comd[X])[nowInd];
	IK_d.comd[Y] = (comd[Y])[nowInd];
	IK_d.comd[Z] = 0.0;

	double torsoYaw;
	if(nowInd >= nomYaw.size()) 	torsoYaw = nomYaw.back();
	else				torsoYaw = nomYaw[nowInd];

	double rootEA[3] = {bodyRoll.readPos(t), bodyPitch.readPos(t), torsoYaw};
	IK_d.rootQ = EA2quat(rootEA);

	for(int i = 0; i < 3; i++) {
		IK_d.rootW[i] = 0.0;
		for(int s = 0; s < 2; s++) IK_d.footW[s][i] = 0.0;
	}

	for(int s = 0; s < 2; s++) {
		for(int i = 0; i < 3; i++) {
			foot[s][i].read(t, &(IK_d.foot[s][i]), &(IK_d.footd[s][i]), NULL);
		}
	}

	for(int s = 0; s < 2; s++) {
		double footEA[3] = {0.0, footPitch[s].readPos(t), footYaw[s].readPos(t)};
		IK_d.footQ[s] = EA2quat(footEA);
	}

	for(int i = 0; i < 8; i++)	IK_d.armJoints[i] = armTraj[i].readPos(t);
}

