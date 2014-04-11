/*Basically only listens to input from the ROS servo node
and writes to servos. */

#include "ControlUtils.h"
#include "Utils.h"

#include <ros/ros.h>
#include <ros/package.h>
#include <boost/thread.hpp>
#include <jimmy/jimmy_servo.h>
#include <jimmy/jimmy_command.h>
#include <jimmy/jimmy_setJoints.h>
 
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
#ifndef SIMULATION
ControlUtils utils;  // talks to all the servos
#endif
///////////////////////////////////////////////////
// ros stuff
boost::mutex r_Lock;
static double r_vFwd = 0;
static double r_vLeft = 0;
static double r_dTheta = 0;
static int r_mode = 0;
static double r_neckEAd[3] = {0};


ros::Publisher pub_feedback;

// wipes all stored commands
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
///////////////////////////////////////////////////

/*void jimmyGestureCallback(jimmy::jimmy_setJoints &msg){
  std::vector<float> servo_positions;
  assert(utils.getJoints());

  for(int i = 0; i < msg.positions.size(); i+){
    servo_positions.push_back(msg.positions[i]);
  }
  utils.setJoints(servo_positions);

}*/

int main( int argc, char **argv ) 
{
  ////////////////////////////////////////////////////
  // ros stuff
  ros::init(argc, argv, "jimmy_servos", ros::init_options::NoSigintHandler);
  ros::NodeHandle rosnode = ros::NodeHandle();
  printf("Ready to listen for commands!\n");

  //Subscribes to jimmy_move_servo, which tells us which servos to move
  ros::Subscriber subcommand = rosnode.subscribe("jimmy_move_servo", 10, jimmyServoCallback);
  //ros::Subscriber subcommand = rosnode.subscribe("jimmy_move_gesture", 10, jimmyGestureCallback);
	

    ///////////////////////////////////////////////
    // proc ros msg
   for (;;) {
     //printf("Spinning!\n");
     ros::spinOnce();
     sleep(0.0001);
   }
	return 0;
}



