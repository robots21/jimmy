#include "ControlUtils.h"
#include "Utils.h"
#include <math.h>
#include <fstream>
#include <ros/ros.h>
#include <ros/package.h>
#include "RobotState.h"

static double joints0[TOTAL_JOINTS] = {0};
static double joints1[TOTAL_JOINTS] = {0};
static double joints[TOTAL_JOINTS] = {0};

bool load_pose(std::ifstream &in)
{
	if (!in.good())  
		return false;

	for (int i = 0; i < 23; i++) {
		in >> joints1[i];
		if (in.eof())
			return false;
		printf("read %10s, %g\n", RobotState::jointNames[i].c_str(), joints1[i]);
	}
	return true;
}

int main()
{
	ControlUtils utils;
	double t0, t1;

	assert(utils.getJoints());
	for (int i = 0; i < TOTAL_JOINTS; i++) {
		printf("%10s %g %d\n", RobotState::jointNames[i].c_str(), utils.joints[i], utils.ticks_from[i]);  
	}

	for (int i = 0; i < TOTAL_JOINTS; i++)
		joints0[i] = utils.joints[i];

  // setting gains on robot
  int8_t p_gains[TOTAL_JOINTS] = {
    40, 60, 120, 60, 60, 120,
    40, 60, 120, 60, 60, 120,
    60, 60, 60, 60, 
    60, 60, 60, 60, 
    60, 60, 60
  };
  assert(utils.setPGains(p_gains));
  assert(utils.getPGains(p_gains));
  for (int i = 0; i < TOTAL_JOINTS; i++)
    printf("gains %10s %d\n", RobotState::jointNames[i].c_str(),  p_gains[i]);

	double duration = 2;  
	while(true) {
		printf("press enter to continue.\n");
		getchar();

    std::string name = ros::package::getPath("jimmy") + "/conf/wiggle";
    std::ifstream in(name.c_str());

		if (!load_pose(in)) {
			printf("out of poses\n");
			break;
		}
    in.close();

		t0 = get_time();
		printf("pose start at %g\n", t0);
		do {
			t1 = get_time();
			for (int i = 0; i < TOTAL_JOINTS; i++)
				joints[i] = joints0[i] + (t1-t0)/duration * (joints1[i]-joints0[i]);

			utils.setJoints(joints);
			usleep(1e4);
		} while (t1 - t0 < duration);

		for (int i = 0; i < TOTAL_JOINTS; i++)
			joints0[i] = joints1[i];

		printf("pose end at %g\n", t1);

		utils.getJoints();
		for (int i = 0; i < TOTAL_JOINTS; i++) {
			printf("%10s %g %d\n", RobotState::jointNames[i].c_str(), utils.joints[i], utils.ticks_from[i]);  
		} 
	}

	return 0;
} 
