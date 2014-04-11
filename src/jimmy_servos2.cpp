#include "Plan.h"
#include "Logger.h"
#include "IK.h"
#include "ControlUtils.h"
#include "Utils.h"

#include <ros/ros.h>
#include <ros/package.h>
#include <boost/thread.hpp>
#include <jimmy/jimmy_servo.h>
#include <jimmy/jimmy_gesture.h>
//#include <jimmy/jimmy_setJoints.h>
#include <stdlib.h>
 
//#define SIMULATION

static const int8_t default_gain[TOTAL_JOINTS] = 
{
  32, 32, 60, 32, 60, 32,  
  32, 32, 60, 32, 60, 32,  
  32, 32, 32, 32,
  32, 32, 32, 32,
  32, 32, 32
};

static const int8_t walk_gain[TOTAL_JOINTS] = {
  40, 60, 120, 60, 60, 120,
  40, 60, 120, 60, 60, 120,
  32, 32, 32, 32,
  32, 32, 32, 32,
  32, 32, 32
};

///////////////////////////////////////////////////
// ros stuff
boost::mutex r_Lock;
static double r_vFwd = 0;
static double r_vLeft = 0;
static double r_dTheta = 0;
static int r_mode = 0;
static double r_neckEAd[3] = {0};

ros::Publisher pub_feedback;


Plan plan;
Logger logger;
IKcmd IK_d;
IKcon IK;
#ifndef SIMULATION
ControlUtils utils;
#endif

void cleanCommand()
{
  boost::mutex::scoped_lock lock(r_Lock);
  r_vFwd = 0;
  r_vLeft = 0;
  r_dTheta = 0;
  r_mode = 0;
  r_neckEAd[0] = 0; 
  r_neckEAd[1] = 0; 
  r_neckEAd[2] = 0; 
}

// gets called by ros, copies ros land commands to cache
void jimmyServoCallback(const jimmy::jimmy_servo &msg)
{
  std::vector<int> servo_ids;
  printf("In servo callback\n");

  assert(utils.getJoints());

//  boost::mutex::scoped_lock lock(r_Lock);

  if (msg.servo_numbers.empty()) {
    printf("Using servo names as IDs\n");
    for (int i = 0; i < msg.servo_names.size(); i++) {
      if (msg.servo_names[i] == jimmy::jimmy_servo::R_SHOULDER_PITCH) {
        servo_ids.push_back(jimmy::jimmy_servo::ID_R_SHOULDER_PITCH);
      }
      else if (msg.servo_names[i] == jimmy::jimmy_servo::L_SHOULDER_PITCH) {
        servo_ids.push_back(jimmy::jimmy_servo::ID_L_SHOULDER_PITCH);
      }
      else if (msg.servo_names[i] == jimmy::jimmy_servo::R_SHOULDER_ROLL) {
        servo_ids.push_back(jimmy::jimmy_servo::ID_R_SHOULDER_ROLL);
      }
      else if (msg.servo_names[i] == jimmy::jimmy_servo::L_SHOULDER_ROLL) {
        servo_ids.push_back(jimmy::jimmy_servo::ID_L_SHOULDER_ROLL);
      }
      else if (msg.servo_names[i] == jimmy::jimmy_servo::R_ELBOW) {
        servo_ids.push_back(jimmy::jimmy_servo::ID_R_ELBOW);
      }
      else if (msg.servo_names[i] == jimmy::jimmy_servo::L_ELBOW) {
        servo_ids.push_back(jimmy::jimmy_servo::ID_L_ELBOW);
      }
      else if (msg.servo_names[i] == jimmy::jimmy_servo::R_HIP_YAW) {
        servo_ids.push_back(jimmy::jimmy_servo::ID_R_HIP_YAW);
      }
      else if (msg.servo_names[i] == jimmy::jimmy_servo::L_HIP_YAW) {
        servo_ids.push_back(jimmy::jimmy_servo::ID_L_HIP_YAW);
      }
      else if (msg.servo_names[i] == jimmy::jimmy_servo::R_HIP_ROLL) {
        servo_ids.push_back(jimmy::jimmy_servo::ID_R_HIP_ROLL);
      }
      else if (msg.servo_names[i] == jimmy::jimmy_servo::L_HIP_ROLL) {
        servo_ids.push_back(jimmy::jimmy_servo::ID_L_HIP_ROLL);
      }
      else if (msg.servo_names[i] == jimmy::jimmy_servo::R_KNEE) {
        servo_ids.push_back(jimmy::jimmy_servo::ID_R_KNEE);
      }
      else if (msg.servo_names[i] == jimmy::jimmy_servo::L_KNEE) {
        servo_ids.push_back(jimmy::jimmy_servo::ID_L_KNEE);
      }
      else if (msg.servo_names[i] == jimmy::jimmy_servo::R_ANKLE_PITCH) {
        servo_ids.push_back(jimmy::jimmy_servo::ID_R_ANKLE_PITCH);
      }
      else if (msg.servo_names[i] == jimmy::jimmy_servo::L_ANKLE_PITCH) {
        servo_ids.push_back(jimmy::jimmy_servo::ID_L_ANKLE_PITCH);
      }
      else if (msg.servo_names[i] == jimmy::jimmy_servo::R_ANKLE_ROLL) {
        servo_ids.push_back(jimmy::jimmy_servo::ID_R_ANKLE_ROLL);
      }
      else if (msg.servo_names[i] == jimmy::jimmy_servo::L_ANKLE_ROLL) {
        servo_ids.push_back(jimmy::jimmy_servo::ID_L_ANKLE_ROLL);
      }
      else if (msg.servo_names[i] == jimmy::jimmy_servo::HEAD_PAN) {
        servo_ids.push_back(jimmy::jimmy_servo::ID_HEAD_PAN);
      }
      else if (msg.servo_names[i] == jimmy::jimmy_servo::HEAD_TILT) {
        servo_ids.push_back(jimmy::jimmy_servo::ID_HEAD_TILT);
      }
      else if (msg.servo_names[i] == jimmy::jimmy_servo::HEAD_TILT_2) {
        servo_ids.push_back(jimmy::jimmy_servo::ID_HEAD_TILT_2);
      }
      else {
        std::cerr << "Invalid servo name: " << msg.servo_names[i] << std::endl;
        return;
      }
      std::cout << "setting joint name  " << msg.servo_names[i] << "  at position  " << msg.positions[i] << "  in radians" << std::endl;
      std::cout << servo_ids[i] << std::endl;
    }
  }
    else if (msg.servo_names.empty()) {
      servo_ids = msg.servo_numbers;
      for (int i = 0; i < msg.positions.size(); i++) {
        std::cout << "setting joint id  " << msg.servo_numbers[i] << "  at position  " << msg.positions[i] << "  in radians" << std::endl;
      }
    }
    else {
        printf("no servo defined\n");
    } 
  
  std::cout << "servo ids set:  " << servo_ids.size() << "  servo positions set: " << msg.positions.size() << std::endl;
  utils.setJointSubset(servo_ids, msg.positions);
}

void jimmyGestureCallback(const jimmy::jimmy_gesture &msg)
{
  boost::mutex::scoped_lock lock(r_Lock);
  
  int newMode = msg.cmd;
  r_mode = newMode;
  std::cout << "Command received is  " << r_mode << std::endl;
  }
///////////////////////////////////////////////////
 


const int MAX_POSES = 100;
const int MAX_GESTURES = 100;
const int MAX_POSES_PER_GESTURE = 100;
const int N_VALS_PER_POSE = 17;

static int N_POSES;

static int prevStance = 2;
static bool prevLimp[2] = {false, false};

static double poses[MAX_POSES][N_VALS_PER_POSE];
static int gestureSeq[MAX_GESTURES][MAX_POSES_PER_GESTURE];
static double gestureTime[MAX_GESTURES][MAX_POSES_PER_GESTURE];
static int gestureNpose[MAX_GESTURES];

static double neckEAs[3];
static double neckAngs[3];
static double theta_d[N_J+3];

static double joints_actual[TOTAL_JOINTS];

const static double neckLims[2][3] = {
	{-1.4, -0.7, -0.7},
	{1.4, 0.7, 0.7}
};

const static double neckEAlims[2][3] = {
	{-1.4, -0.6, -0.6},
	{1.4, 0.6, 0.6}
};

const static double poseBodyLims[2][6] = {
	{-0.1, -0.1, 0.35, -0.3, -0.3, -0.3},
	{0.1, 0.1, 0.45, 0.3, 0.3, 0.3}
};

enum ConMode {
	IDLE=0,
	PRE_WALK,	//wait until we have enough steps queued up
	WALK,
	GESTURE,
	STAND_PREP
};

static double wallClockStart, wallClockLast, wallClockDT, wallClockT;

static bool isIdle;
static ConMode mode;

static double curTime;		//time since start of controller
static double modeTime;	//time since start of current mode
static double modeT0;		//time this mode started;
static double modeDur;		//intended duration of current mode

static double vForward, vLeft, dTheta;

int getCommand() {
  /*
	if(curTime > 10)	return -1;
	if(curTime > 7.0 && curTime < 120)		return 1;
	if(curTime > 7 && curTime < 7.1)		return 2;
  */

  boost::mutex::scoped_lock lock(r_Lock);
  return r_mode;
}

void getDriveCommand(double *vFwd, double *vLef, double *dYaw) {
  /*
	*vFwd = 0.005;
	*vLef = 0.00;
	*dYaw = 0.0;
  */
 
  boost::mutex::scoped_lock lock(r_Lock);
  *vFwd = r_vFwd;
  *vLef = r_vLeft;
  *dYaw = r_dTheta;
}

void constrainDriveCommand(double *vForward, double *vLeft, double *dTheta) {
	//TODO: limit acceleration
	//TODO: limit velocities (including in combination)
}

void getNeckCommand(double *EAs) {
  /*
	double EAsd[3] = {0,0,0};		//desired velocities
	for(int i = 0; i < 3; i++)	EAs[i] += EAsd[i]*plan.TIME_STEP;	//integrate
	for(int i = 0; i < 3; i++) {						//limit
		if(EAs[N_J+i] < neckEAlims[0][i])	EAs[N_J+i] = neckEAlims[0][i];
		if(EAs[N_J+i] > neckEAlims[1][i])	EAs[N_J+i] = neckEAlims[1][i];
	}
  */

  boost::mutex::scoped_lock lock(r_Lock);
  for(int i = 0; i < 3; i++)	
    EAs[i] += r_neckEAd[i]*plan.TIME_STEP;	//integrate
	for(int i = 0; i < 3; i++) {						//limit
		if(EAs[N_J+i] < neckEAlims[0][i])	EAs[N_J+i] = neckEAlims[0][i];
		if(EAs[N_J+i] > neckEAlims[1][i])	EAs[N_J+i] = neckEAlims[1][i];
	}
}

TrajEW spJoints[23];

void initStandPrep() {
#ifndef SIMULATION
	utils.getJoints(joints_actual);
#endif
	for(int i = 0; i < 23; i++)		
    spJoints[i].freshMove(joints_actual[i], standPrepPose[i], 5.0);
	modeDur = 5.0;
}

TrajEW gestureArms[8];
TrajEW gestureNeck[3];
TrajEW gestureCoM[3];
TrajEW gestureRootEA[3];

void initGesture(int gesture) {
	gesture-=2;
	printf("Starting gesture %d\n", gesture);
	//initialize with current state
	for(int i = 0; i < 8; i++) {
		gestureArms[i].clear();
		gestureArms[i].addKnot(0, IK_d.armJoints[i], 0, 0);
	}
	for(int i = 0; i < 3; i++) {
		gestureNeck[i].clear();
		gestureNeck[i].addKnot(0, neckEAs[i], 0, 0);
	}
	for(int i = 0; i < 3; i++) {
		gestureCoM[i].clear();
		gestureCoM[i].addKnot(0, IK_d.com[i]-(IK_d.foot[LEFT][i]+IK_d.foot[RIGHT][i])/2.0, 0, 0);
	}
	double rootEA[3];
	quat2EA(IK_d.rootQ, rootEA);
	for(int i = 0; i < 3; i++) {
		gestureRootEA[i].clear();
		gestureRootEA[i].addKnot(0, rootEA[i], 0, 0);
	}

	Eigen::Quaterniond avgFootQ = mySlerp(IK_d.footQ[LEFT], IK_d.footQ[RIGHT], 0.5);
	double footYaw = getYaw(avgFootQ);
	if(footYaw - rootEA[2] > M_PI)		footYaw -= M_PI*2.0;
	if(footYaw - rootEA[2] < -M_PI)		footYaw += M_PI*2.0;

	double totTime = 0;
	//add the poses to the trajectories
	for(int p = 0; p < gestureNpose[gesture]; p++) {
		totTime += gestureTime[gesture][p];
		int pose = gestureSeq[gesture][p];
		for(int i = 0; i < 8; i++) 	gestureArms[i].addKnot(totTime, poses[pose][i], 0, 0);
		for(int i = 0; i < 3; i++)	gestureNeck[i].addKnot(totTime, poses[pose][i+8], 0, 0);
		for(int i = 0; i < 3; i++)	gestureCoM[i].addKnot(totTime, poses[pose][i+11], 0, 0);
		for(int i = 0; i < 2; i++)	gestureRootEA[i].addKnot(totTime, poses[pose][i+14], 0, 0);
						gestureRootEA[2].addKnot(totTime, footYaw+poses[pose][16], 0, 0);
	}
	//when the gesture ends and returns to IDLE
	modeDur = totTime;
}

static const double armsOut[8] = {-0.33, -0.2, 1.03, 0, -0.33, 0.2, 1.03, 0};
//static const double armsOut[8] = {0,0,0,0,0,0,0,0};

void initWalk() {
	plan.initFeet(IK.ikrs.foot[LEFT][X], IK.ikrs.foot[LEFT][Y], getYaw(IK.ikrs.footQ[LEFT]), IK.ikrs.foot[RIGHT][X], IK.ikrs.foot[RIGHT][Y], getYaw(IK.ikrs.footQ[RIGHT]));
	for(int i = 0; i < 2; i++) {
		plan.com[i].push_back(IK.ikrs.com[i]);
		plan.comd[i].push_back(IK.ikrs.comd[i]);
	}
	double startEA[3];
	quat2EA(IK_d.rootQ, startEA);
	plan.bodyRoll.addKnot(0, startEA[0], 0);
	plan.bodyPitch.addKnot(0, startEA[1], 0);
	for(int s = 0; s < 2; s++)	plan.footPitch[s].addKnot(0, 0, 0);
	for(int i = 0; i < 23; i++)	plan.jointOffset[i].addKnot(0, 0, 0);
	for(int i = 0; i < 8; i++)	plan.armTraj[i].addKnot(0, IK_d.armJoints[i], 0);
	for(int i = 0; i < 8; i++)	plan.armTraj[i].addKnot(plan.DS_TIME/2.0, armsOut[i], 0);	//get clear
	for(int i = 0; i < 3; i++)	plan.neckTraj[i].addKnot(0, theta_d[i+20], 0);
	for(int i = 0; i < 3; i++)	plan.neckTraj[i].addKnot(plan.DS_TIME/2.0, 0.0, 0);		//center
}

void loadPoses() {
	std::string name = ros::package::getPath("jimmy") + "/conf/poses.cf";
	std::ifstream in(name.c_str());

	int pose = 0;
	int i = 0;
	while (true) {
		in >> poses[pose][i];
		std::cout << i << " " << poses[pose][i] << std::endl;
		i++;
		if(i >= N_VALS_PER_POSE) {
			i = 0;
			pose++;
		}


		if (in.eof()) {
			if(i != 0) {
				printf("Ran out of data mid pose, in pose %d\n", pose);
				exit(-1);
			}	
			printf("Loaded %d poses\n",pose);
			break;
		}
	}
	N_POSES = pose;

	//assemble pose limits from other limits
	double poseLimits[2][N_VALS_PER_POSE];
	for(int m = 0; m < 2; m++) {
		for(int i = 0; i < 8; i++)	poseLimits[m][i] = RobotState::jointLimits[m][i+12];
		for(int i = 0; i < 3; i++)	poseLimits[m][i+8] = neckEAlims[m][i];
		for(int i = 0; i < 6; i++)	poseLimits[m][i+11] = poseBodyLims[m][i];
	}

	for(int p = 0; p < pose; p++) {
		for(int i = 0; i < N_VALS_PER_POSE; i++) {
			if(poses[p][i] < poseLimits[0][i]) {
				printf("Limiting pose %d value %d from %g to %g\n", p, i, poses[p][i], poseLimits[0][i]);
				poses[p][i] = poseLimits[0][i];

			}
			if(poses[p][i] > poseLimits[1][i]) {
				printf("Limiting pose %d value %d from %g to %g\n", p, i, poses[p][i], poseLimits[1][i]);
				poses[p][i] = poseLimits[1][i];
			}
		}
	}
}

void loadGestures() {
	std::string name = ros::package::getPath("jimmy") + "/conf/gestures.cf";
	std::ifstream in(name.c_str());

	int gesture = 0;
	while (true) {
		in >> gestureNpose[gesture];
		if (in.eof()) 	break;
		for(int i = 0; i < gestureNpose[gesture]; i++) {
			in >> gestureSeq[gesture][i];
			if(gestureSeq[gesture][i] < 0) {
				printf("We only use positive pose ID's: %d\n",gestureSeq[gesture][i]);
				exit(-1);
			}
			if(gestureSeq[gesture][i] >= N_POSES) {
				printf("We only have %d poses stored: %d\n",N_POSES, gestureSeq[gesture][i]);
				exit(-1);
			}
			in >> gestureTime[gesture][i];
			if(gestureTime[gesture][i] <= 0) {
				printf("Require a positive time in gesture %d, pose %d: %g\n", gesture, i, gestureTime[gesture][i]);
				exit(-1);
			}
		}
		if (in.eof()) {
			printf("Ran out of data mid gesture, in gesture: %d \n", gesture);
			exit(-1);
		}
		gesture++;
	}
	printf("Loaded %d gestures\n",gesture);
}

void init() {
	printf("Start init\n");
	loadPoses();
	loadGestures();
	isIdle = false;
	curTime = 0.0;
	modeTime = 0.0;
	modeT0 = 0.0;
	modeDur = 0.0;
	for(int i = 0; i < 3; i++)		neckEAs[i] = 0.0;

  int8_t thermal_max[TOTAL_JOINTS] = {0};
  for (int i = 0; i < TOTAL_JOINTS; i++)
    thermal_max[i] = 60;
#ifndef SIMULATION
  assert(utils.setThermalMax(thermal_max));
  //assert(utils.getThermalMax(thermal_max));
#endif
  for (int i = 0; i < TOTAL_JOINTS; i++)
    printf("max thermal %10s %d\n", RobotState::jointNames[i].c_str(), thermal_max[i]);
  
#ifndef SIMULATION
  assert(utils.setPGains(default_gain));
#endif

	std::string name = ros::package::getPath("jimmy") + "/conf/plan.cf";
	plan = Plan(name.c_str());
	name = ros::package::getPath("jimmy") + "/conf/IK.cf";
	IK.readParams(name.c_str());
	logger.init(plan.TIME_STEP);

  char buf[100];
  for (int i = 0; i < TOTAL_JOINTS; i++) {
    sprintf(buf, "RS.joint[%s]", RobotState::jointNames[i].c_str());
    logger.add_datapoint(buf,"rad",joints_actual+i); 
  }
  
  logger.add_datapoint("realT","s",&wallClockT);
	logger.add_datapoint("realDT","s",&wallClockDT);
	logger.add_datapoint("curTime","s",&curTime);
	logger.add_datapoint("modeTime","s",&modeTime);
	logger.add_datapoint("mode","-",(int*)(&mode));
	logger.add_datapoint("CMD.vForward","m/s",&vForward);
	logger.add_datapoint("CMD.vLeft","m/s",&vLeft);
	logger.add_datapoint("CMD.dTheta","m/s",&dTheta);
	logger.add_datapoint("stance","-",&prevStance);
	logger.add_datapoint("limpA[L]","-",&(prevLimp[LEFT]));
	logger.add_datapoint("limpA[R]","-",&(prevLimp[RIGHT]));
	IK_d.addToLog(logger);
	IK.addToLog(logger);
	plan.addToLog(logger);

  for (int i = 0; i < TOTAL_JOINTS; i++) {
    sprintf(buf, "CMD.%s", RobotState::jointNames[i].c_str());
    logger.add_datapoint(buf,"rad",theta_d+i); 
  }
	IK_d.setToRS(IK.ikrs);
	IK_d.setVel0();
	mode = STAND_PREP;
	initStandPrep();
}



void stateMachine() {
	int command;
	switch(mode) {
	case IDLE:
		command = getCommand();
		modeT0 = curTime;
		//don't want to make this unreadable with a switch inside a switch
		if(command == 1) {
			modeT0 = curTime;
			mode = PRE_WALK;
			initWalk();
			printf("IDLE to INIT_WALK\n");
		}
		else if(command > 1) {	//each number corresponds to a gesture
			modeT0 = curTime;
			mode = GESTURE;
			initGesture(command);
      		cleanCommand();
			printf("IDLE to GESTURE\n");
		}

		break;


	case PRE_WALK:
		if(modeTime > plan.PRE_PLAN_TIME) {
			modeT0 = curTime;
			mode = WALK;
			printf("PRE_WALK to WALK\n");
#ifndef SIMULATION
      assert(utils.setPGains(walk_gain));
      assert(utils.setStanceGain(2));
      printf("setting walking gain\n");
#endif
		}
		break;
	case WALK:
		if(getCommand() == 0) {
			plan.stopHere();
		}
		if(plan.isDone(modeTime) || modeTime > 36) {
			modeT0 = curTime;
			mode = IDLE;
			printf("WALK to IDLE\n");
      assert(utils.setPGains(default_gain));
      printf("setting default gain\n");
      cleanCommand();
		}
		break;
	case GESTURE:
		if(modeTime > modeDur) {
			modeT0 = curTime;
			mode = IDLE;
			printf("GESTURE to IDLE\n");
		}
		break;
	case STAND_PREP:
		if(modeTime > modeDur) {
			modeT0 = curTime;
			mode = IDLE;
			printf("STAND_PREP to IDLE\n");
		}
		break;
	default:
		printf("Bad mode in stateMachine\n");
		exit(-1);
		break;
	}
}

double nomPose[3] = {0.0, 0.0, 0.42};

//integrate towards normal body pose
void idleCon() {
	//CoM pos
	for(int i = 0; i <3; i++) {
		IK_d.com[i] += 0.004*(nomPose[i]-(IK_d.com[i]-(IK_d.foot[LEFT][i]+IK_d.foot[RIGHT][i])/2.0));
	}

	//foot orientation
	for(int s = 0; s < 2; s++) {
		Eigen::Quaterniond desQ = IK_d.footQ[s];
		flattenQuat(desQ);
		IK_d.footQ[s] = mySlerp(IK_d.footQ[s], desQ, 0.004);
	}

	//torso orientation
	Eigen::Quaterniond desBodyQ = mySlerp(IK_d.footQ[LEFT], IK_d.footQ[RIGHT], 0.5);
	IK_d.rootQ = mySlerp(IK_d.rootQ, desBodyQ, 0.004);
}

void walkCon() {
	for(int i = 0; i < 3; i++)	neckEAs[i] *= 0.995;
	plan.fillIK_d(IK_d, modeTime);
}

void gestureCon() {
	for(int i = 0; i < 8; i++) 	IK_d.armJoints[i] = gestureArms[i].readPos(modeTime);
	for(int i = 0; i < 3; i++)	neckAngs[i] = gestureNeck[i].readPos(modeTime);
	for(int i = 0; i < 3; i++) {
		gestureCoM[i].read(modeTime, &(IK_d.com[i]), &(IK_d.comd[i]), NULL);
		IK_d.com[i] += (IK_d.foot[LEFT][i] + IK_d.foot[RIGHT][i])/2.0;
	}
	double rootEA[3];
	for(int i = 0; i < 3; i++)	rootEA[i] = gestureRootEA[i].readPos(modeTime);
	IK_d.rootQ = EA2quat(rootEA);
}

void standPrepCon() {
	for(int i = 0; i < 23; i++)		theta_d[i] = spJoints[i].readPos(modeTime);
#ifndef SIMULATION
 	

	utils.setJoints(theta_d);
	#endif
}


void controlLoop() {

	//handle mode switching
	stateMachine();

	modeTime = curTime-modeT0;

	//whipe out record values
	vForward = vLeft = dTheta = 0.0;
	plan.clearForRecord();
	
#ifndef SIMULATION
  utils.getLegJointsCircular(joints_actual);
#endif

  //do actual control
	switch(mode) {
	case IDLE:
		getNeckCommand(neckEAs);
		idleCon();
		break;
	case PRE_WALK:
		idleCon();
		getDriveCommand(&vForward, &vLeft, &dTheta);
		constrainDriveCommand(&vForward, &vLeft, &dTheta);
		plan.driveFutureRobot(vForward, vLeft, dTheta);
		break;
	case WALK:
		getDriveCommand(&vForward, &vLeft, &dTheta);
		constrainDriveCommand(&vForward, &vLeft, &dTheta);
		plan.driveFutureRobot(vForward, vLeft, dTheta);
		walkCon();
		break;
	case GESTURE:
		gestureCon();
		break;
	case STAND_PREP:
		standPrepCon();
		break;
	default:
		printf("Bad mode in controlLoop\n");
		exit(-1);
		break;
	}


	if(mode != STAND_PREP) {
		double thetad_d[N_J+3];
		IK.IK(IK_d, theta_d, thetad_d);

		if(mode == WALK)	for(int i = 0; i < 23; i++)	theta_d[i]+=plan.jointOffset[i].readPos(modeTime);		

		double stance = 2;
		if(IK_d.foot[LEFT][Z] - IK_d.foot[RIGHT][Z] > 0.01)	stance = RIGHT;
		if(IK_d.foot[RIGHT][Z] - IK_d.foot[LEFT][Z] > 0.01)	stance = LEFT;

#ifndef SIMULATION
		if(stance != prevStance)	assert(utils.setStanceGain(stance));
#endif
		prevStance = stance;

		//limp ankles
		for(int s = 0; s < 2; s++) {
			bool limp = false;
			if(IK_d.footd[s][Z] < 0)	limp = true;
			if(limp != prevLimp[s]) {
				//if(limp)	utils.setTorqueLimit(0, 5+6*s); //utils.setPGain(0, 5+6*s);
				//else		utils.setTorqueLimit(1023, 5+6*s); //utils.setPGain(120, 5+6*s);
			}
			prevLimp[s] = limp;
		}
		if(mode == WALK) {
			for(int i = 0; i < 3; i++)	theta_d[20+i] = plan.neckTraj[i].readPos(modeTime);
			neckEAs[0] = (-neckAngs[2] - neckAngs[1])/2.0;
			neckEAs[1] = ( neckAngs[2] - neckAngs[1])/2.0;
			neckEAs[2] = neckAngs[0];
		}
		else if(mode == GESTURE) {
			for(int i = 0; i < 3; i++)	theta_d[N_J+i] = neckAngs[i];
			neckEAs[0] = (-neckAngs[2] - neckAngs[1])/2.0;
			neckEAs[1] = ( neckAngs[2] - neckAngs[1])/2.0;
			neckEAs[2] = neckAngs[0];
		}
		else {
			//conversion from RPY to angles
			theta_d[N_J] = neckEAs[2];
			theta_d[N_J+1] = -neckEAs[1]-neckEAs[0];
			theta_d[N_J+2] = neckEAs[1]-neckEAs[0];
		}

		//limit angles
		for(int i = 0; i < 3; i++) {
			thetad_d[N_J+i] = 0.0;
			if(theta_d[N_J+i] < neckLims[0][i])	theta_d[N_J+i] = neckLims[0][i];
			if(theta_d[N_J+i] > neckLims[1][i])	theta_d[N_J+i] = neckLims[1][i];
		}
/*#ifndef SIMULATION

		//std::cout << "joint number 1 set at  " << theta_d[1] << std::endl;
		//float setjoints.positions;
		for(int i = 0; i < 23; i++){
			setjoints.positions.push_back(theta_d[i]);
		}
		pub.publish(setjoints);
		ros.spinOnce();

		//utils.setJoints(theta_d);
#endif*/
		/*for(int i = 0; i < 23; i++){
		std::cout << "Theta change  " << theta_d[i] << std::endl;
		}*/
		utils.setJoints(theta_d);
	}
}

int sleep_t = 1e4;
double t_pre_sleep = 0;
double t_aft_sleep = 0;
double t_real_sleep = 0;


void spin_wait(double dt)
{
  double t0 = get_time();
  int spin = 1;
  int ctr = 0;
  while(spin) {
    if (get_time() - t0 < dt) {
      ctr++;
    }
    else
      spin = 0;
  }
  return;
}

int main( int argc, char **argv ) 
{
  ////////////////////////////////////////////////////
  // ros stuff
  ros::init(argc, argv, "jimmy_servos", ros::init_options::NoSigintHandler);
  ros::NodeHandle rosnode = ros::NodeHandle();

  ros::Time last_ros_time_;
  bool wait = true;
  while (wait) {
    last_ros_time_ = ros::Time::now();
    if (last_ros_time_.toSec() > 0) {
      wait = false;
    }
  }


  printf("Ready to listen for commands!\n");

  //Subscribes to jimmy_move_servo, which tells us which servos to move
  ros::Subscriber subcommand = rosnode.subscribe("jimmy_send_gesture", 10, jimmyGestureCallback);
  ros::Subscriber sub = rosnode.subscribe("jimmy_move_servo", 10, jimmyServoCallback);
  ros::Subscriber sub_idle = rosnode.subscribe("jimmy_idle", 2, jimmyGestureCallback);
  //ros::Subscriber subcommand = rosnode.subscribe("jimmy_move_gesture", 10, jimmyGestureCallback);
	

  //   ros::Publisher pub = rosnode.advertise<jimmy::jimmy_setJoints>("jimmy_move_gesture", 10);
//   jimmy::jimmy_setJoints setjoints;
//   //////////////////////////////////////////////////// 

// for(int i = 0; i < 23; i++){
// 	setjoints.positions.push_back(theta_d[i]);
// }
// 	pub.publish(setjoints);
// 	//	ros.spinOnce();

// ////

	wallClockStart = get_time();
	init();

  printf("Starting\n");
  double timeQuota = plan.TIME_STEP;

  wallClockLast = get_time();
	logger.add_datapoint("sleep_time", "us", &sleep_t);
	logger.add_datapoint("sleep_time_real", "s", &t_real_sleep);


  while(true) {
		double wallNow = get_time();
		wallClockT = wallNow-wallClockStart;
		wallClockDT = wallNow-wallClockLast;
		wallClockLast = wallNow;
		curTime += plan.TIME_STEP;		//maybe do this off a real clock if we're not getting true real time accurately

		controlLoop();

		logger.saveData();

		if(getCommand() == -1) {
#ifndef SIMULATION
      int8_t temperature[TOTAL_JOINTS];
      utils.getCurTemperature(temperature);
      for (int i = 0; i < TOTAL_JOINTS; i++)
        printf("%10s temp %d\n", RobotState::jointNames[i].c_str(), temperature[i]);
#endif

			logger.writeToMRDPLOT();
			exit(-1);
		}

    ///////////////////////////////////////////////
    // proc ros msg
    ros::spinOnce();

    ///////////////////////////////////////////////
    // wait
    double wall1 = get_time();
    double dt = wall1 - wallNow;
    // step up quota for the next time step
    if (dt > timeQuota) {
      timeQuota -= (dt - plan.TIME_STEP);
      printf("takes too long %g\n", dt);
    }
    else {
      timeQuota = plan.TIME_STEP;
      sleep_t = (int)((plan.TIME_STEP - dt)*1e6);
#ifndef SIMULATION      
      //t_pre_sleep = get_time();
      //usleep(sleep_t);
      //t_real_sleep = get_time() - t_pre_sleep;
      spin_wait(sleep_t / 1e6);
#endif
    }
    ///////////////////////////////////////////////
	}

	return 0;
}