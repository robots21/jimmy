#include "ControlUtils.h"
#include "Utils.h"
#include <math.h>
#include <fstream>
#include <ros/ros.h>
#include <ros/package.h>
#include "RobotState.h"

/*
 * Stiffen the legs, but leave arm and neck joints loose. You can also make 
 * all joints loose by commenting out a section. 
 * When Enter is pressed, the program grabs the current joint position and 
 * appends them to the end of home_of_jimmy/conf/puppet
 */
int main()
{
 	ControlUtils utils;
    
  std::string name = ros::package::getPath("jimmy") + "/conf/puppet";
  std::ofstream out;
  out.open(name.c_str(), std::ofstream::out | std::ofstream::app);

  ///////////////////////////////////////////////////////////
  // set leg joints to stance, leave arms limp
  double j0[TOTAL_JOINTS];
  assert(utils.getJoints(j0));
  double t0 = get_time();
  
  while(true) {
    double t = get_time() - t0;

    std::vector<int> joints; 
    std::vector<int16_t> ticks;
    for (int i = L_HZ; i <= R_AAA; i++) {
      joints.push_back(i);
      ticks.push_back(utils.rad2tick(j0[i] + t * (standPrepPose[i] - j0[i]), i));
    }
    assert(utils.syncWriteWord(ADDR_GOAL_POSITION_L, joints, ticks));    
    std::cout << "Finished standing" << std::endl;
    if (t > 1)
      break;
    usleep(1e4);
  }
  ///////////////////////////////////////////////////////////

  while(true) {
    getchar();
    
    assert(utils.getJoints());
    for (int i = 0; i < TOTAL_JOINTS; i++) {
      printf("%10s %g %d\n", RobotState::jointNames[i].c_str(), utils.joints[i], utils.ticks_from[i]);  
    }
    
    int ctr;
    for (ctr = 0; ctr < 6; ctr++)
      out << utils.joints[ctr] << " ";
    out << std::endl;
    for (; ctr < 12; ctr++)
      out << utils.joints[ctr] << " ";
    out << std::endl;
    for (; ctr < 16; ctr++)
      out << utils.joints[ctr] << " ";
    out << std::endl;
    for (; ctr < 20; ctr++)
      out << utils.joints[ctr] << " ";
    out << std::endl;
    for (; ctr < 23; ctr++)
      out << utils.joints[ctr] << " ";
    out << std::endl;
    out << std::endl;

    out.flush();
  }

}
