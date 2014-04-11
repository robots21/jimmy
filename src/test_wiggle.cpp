#include "ControlUtils.h"
#include "Utils.h"
#include <math.h>
#include <fstream>
#include <ros/ros.h>
#include <ros/package.h>
 

/*
 * loads joint angles from home_of_jimmy/conf/wiggle
 * and play it on the robot. 
 * Each joint is controlled by linearly interpolating from the start joint poition
 * to the desired. 
 *
 * Press Enter to execute the next pose.
 */

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
    printf("read %d, %g\n", i, joints1[i]);
  }
  return true;
}

int main()
{
  ControlUtils utils;
  double t0, t1;
  
	std::string name = ros::package::getPath("jimmy") + "/conf/wiggle";
  std::ifstream in(name.c_str());

  utils.requestJoints();
  for (int i = 0; i < TOTAL_JOINTS; i++) {
    printf("%g %d\n", utils.joints[i], utils.ticks_from[i]);  
  }

  getchar();

  printf("stand preping.\n");
  for (int i = 0; i < TOTAL_JOINTS; i++)
    joints0[i] = standPrepPose[i];
  utils.sendStandPrep(joints0);
  utils.waitForReady();
  
  for (int i = 0; i < TOTAL_JOINTS; i++) {
    printf("%g %d\n", utils.joints[i], utils.ticks_from[i]);  
  } 

  double duration = 5;  
  while(true) {
    printf("press enter to continue.\n");
    getchar();

    if (!load_pose(in)) {
      printf("out of poses\n");
      break;
    }

    t0 = get_time();
    printf("pose start at %g\n", t0);
    do {
      t1 = get_time();
      for (int i = 0; i < TOTAL_JOINTS; i++)
        joints[i] = joints0[i] + (t1-t0)/duration * (joints1[i]-joints0[i]);
      utils.sendJoints_d(joints);
      usleep(1e4);
    } while (t1 - t0 < duration);
      
    for (int i = 0; i < TOTAL_JOINTS; i++)
      joints0[i] = joints1[i];
    
    printf("pose end at %g\n", t1);
  
    utils.requestJoints();
    for (int i = 0; i < TOTAL_JOINTS; i++) {
      printf("%g %d\n", utils.joints[i], utils.ticks_from[i]);  
    } 

  }

  return 0;
}
