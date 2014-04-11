/*
 * Handles communication with the servos. 
 * Tick / radiant conversion is also handled here. 
 * Use sync write for multiple joints for faster speed.
 */

#include "ControlUtils.h"
#include "Utils.h"
#include <stdlib.h>
#include <math.h>
#include <iostream> 
#include <jimmy/jimmy_servo.h>

// servo pot ranges from 0 to 4096, -pi to pi
#define TICK_MIN          0
#define TICK_MAX          4096
#define TICK_ZEROS        2048

bool ControlUtils::setTorqueLimit(int16_t lim, int joint)
{
  dxl_write_word(_id[joint], ADDR_TRQ_LIM_L, lim);
  return (dxl_get_result() == COMM_RXSUCCESS);
}

bool ControlUtils::getLegJointsCircular(double a[TOTAL_JOINTS])
{
  int ctr = 0;
  while(ctr < 2)
  {
    ticks_from[_legIdx] = dxl_read_word(_id[_legIdx], ADDR_PRESENT_POSITION_L);
    int CommStatus = dxl_get_result();

    if(CommStatus == COMM_RXSUCCESS)
      a[_legIdx] = tick2rad(ticks_from[_legIdx], _legIdx);
    else
      return false;
    
    _legIdx++;
    if (_legIdx > R_AAA)
      _legIdx = L_HZ;
    ctr++;
  }
  return true;
}

bool ControlUtils::setAllBytes(const int8_t val[TOTAL_JOINTS], int8_t addr)
{
  std::vector<int> joints;
  std::vector<int8_t> vals;
  for (int i = 0; i < TOTAL_JOINTS; i++) {
    joints.push_back(i);
    vals.push_back(val[i]);
  }
  
  return syncWriteByte(addr, joints, vals); 
}

bool ControlUtils::getAllBytes(int8_t val[TOTAL_JOINTS], int8_t addr)
{
  for (int i = 0; i < TOTAL_JOINTS; i++) {
		if (!getByte(val+i, addr, i))
      return false;
    //usleep(5000);
  }
  return true;
}

/*
bool ControlUtils::getLoads(double *a) 
{
  for (int i = 0; i < TOTAL_JOINTS; i++) {
    // Read present position
    int16_t ret = dxl_read_word(_id[i], ADDR_PRESENT_LOAD_L);
    int CommStatus = dxl_get_result();
    int sign = 1;
    // It means currently applied load.
    // The range of the value is 0~2047, and the unit is about 0.1%.
    // If the value is 0~1023, it means the load works to the CCW direction.
    // If the value is 1024~2047, it means the load works to the CW direction.
    // That is, the 10th bit becomes the direction bit to control the direction, and 1024 is equal to 0.
    // For example, the value is 512, it means the load is detected in the direction of CCW about 50% of the maximum torque.
    if(CommStatus == COMM_RXSUCCESS) {
      if (ret >= 1024) {
        ret -= 1024;
        sign = -1;
      }
      else {
        sign = 1;
      }
      a[i] = ((double)ret / 1024.) * sign * tick_sign[i];
    }
    else
      return false;

    usleep(5000);
  }
}
*/

bool ControlUtils::getJoints(double *a)
{
  for (int i = 0; i < TOTAL_JOINTS; i++) {
    // Read present position
    ticks_from[i] = dxl_read_word(_id[i], ADDR_PRESENT_POSITION_L);
    int CommStatus = dxl_get_result();

    if(CommStatus == COMM_RXSUCCESS)
      a[i] = tick2rad(ticks_from[i], i);
    else
      return false;

    //usleep(5000);
  }

  return true;
}

bool ControlUtils::setStanceGain(int side)
{
  // ankle pitch p gain
  std::vector<int> joints;
  std::vector<int8_t> vals;
  // set left gain
  if (side == 0) {
    joints.push_back(L_AFE);
    joints.push_back(R_AFE);
    vals.push_back(100);
    vals.push_back(60);
    printf("set SSL gains\n");
  }
  else if (side == 1) {
    joints.push_back(R_AFE);
    joints.push_back(L_AFE);
    vals.push_back(100);
    vals.push_back(60);
    printf("set SSR gains\n");
  }
  else {
    joints.push_back(L_AFE);
    joints.push_back(R_AFE);
    vals.push_back(100);
    vals.push_back(100); 
    printf("set DS gains\n");
  }
  
  bool ret = syncWriteByte(ADDR_P_GAIN, joints, vals); 
  
  /*
  // hip roll i gain
  // ankle pitch i gain
  joints.clear();
  vals.clear();
  if (side == 0) {
    joints.push_back(L_HAA);
    joints.push_back(L_AFE);
    joints.push_back(R_HAA);
    joints.push_back(R_AFE);
    vals.push_back(5);
    vals.push_back(5);
    vals.push_back(0);
    vals.push_back(0);
  }
  else if (side == 1) {
    joints.push_back(R_HAA);
    joints.push_back(R_AFE);
    joints.push_back(L_HAA);
    joints.push_back(L_AFE);
    vals.push_back(5);
    vals.push_back(5);
    vals.push_back(0);
    vals.push_back(0);
  }
  else {
    joints.push_back(R_HAA);
    joints.push_back(R_AFE);
    joints.push_back(L_HAA);
    joints.push_back(L_AFE);
    vals.push_back(5);
    vals.push_back(5);
    vals.push_back(5);
    vals.push_back(5);
  }
  
  ret &= syncWriteByte(ADDR_I_GAIN, joints, vals); 
  */

  return ret;
}

bool ControlUtils::syncWriteByte(int8_t addr, const std::vector<int> &joints, const std::vector<int8_t> &val)
{
  if (joints.size() != val.size())
    return false;

  if (joints.empty())
    return true;

  // Make syncwrite packet
  dxl_set_txpacket_id(BROADCAST_ID);
  dxl_set_txpacket_instruction(INST_SYNC_WRITE);
  dxl_set_txpacket_parameter(0, addr);
  dxl_set_txpacket_parameter(1, 1);
  for (size_t i = 0; i < joints.size(); i++) {
    dxl_set_txpacket_parameter(2+2*i, _id[joints[i]]);
    
    dxl_set_txpacket_parameter(2+2*i+1, val[i]);
  }
  dxl_set_txpacket_length((1+1)*joints.size()+4);

  dxl_txrx_packet();
  if(dxl_get_result() == COMM_RXSUCCESS)
    return true;
  else
    return false;
}

bool ControlUtils::syncWriteWord(int8_t addr, const std::vector<int> &joints, const std::vector<int16_t> &val)
{
  if (joints.size() != val.size())
    return false;
  
  if (joints.empty())
    return true;

  // Make syncwrite packet
  dxl_set_txpacket_id(BROADCAST_ID);
  dxl_set_txpacket_instruction(INST_SYNC_WRITE);
  dxl_set_txpacket_parameter(0, addr);
  dxl_set_txpacket_parameter(1, 2);
  for (size_t i = 0; i < joints.size(); i++) {
    dxl_set_txpacket_parameter(2+3*i, _id[joints[i]]);
    
    dxl_set_txpacket_parameter(2+3*i+1, dxl_get_lowbyte(val[i]));
    dxl_set_txpacket_parameter(2+3*i+2, dxl_get_highbyte(val[i]));
  }
  dxl_set_txpacket_length((2+1)*joints.size()+4);

  dxl_txrx_packet();
  if(dxl_get_result() == COMM_RXSUCCESS)
    return true;
  else
    return false; 
}

bool ControlUtils::setByte(int8_t val, int8_t addr, int joint)
{  
  dxl_write_byte(_id[joint], addr, val);
  if (dxl_get_result() == COMM_RXSUCCESS) {
    return true;  
  }
  else {
    printf("faled to write byte to %d at %d\n", addr, joint);
    return false;
  }
}

bool ControlUtils::getByte(int8_t *val, int8_t addr, int joint)
{
  int8_t tmp = dxl_read_byte(_id[joint], addr); 
  if(dxl_get_result() == COMM_RXSUCCESS) {
    *val = tmp;
    return true;
  }
  else {
    printf("faled to get byte from %d at %d\n", addr, joint);
    return false;
  } 
}

bool ControlUtils::setJointSubset(const std::vector<int>& joints, const std::vector<double>& positions)
{
  int16_t tmp_tick[positions.size()];
  std::vector<int16_t> positions_to_send;
  std::vector<int> joints_to_send;

  for (int i = 0; i < positions.size(); i++) {
    tmp_tick[i] = rad2tick(positions[i], i);
    if (tmp_tick[i]!= ticks_to[i]) {
      joints_to_send.push_back(joints[i]);
      positions_to_send.push_back(tmp_tick[i]);
      ticks_to[i] = tmp_tick[i];
  }
  }
  return syncWriteWord(ADDR_GOAL_POSITION_L, joints_to_send, positions_to_send);
}



bool ControlUtils::setJoints(const double a[TOTAL_JOINTS])
{
  int16_t tmp_tick[TOTAL_JOINTS];
  std::vector<int16_t> vals;
  std::vector<int> joints;
  for (int i = 0; i < TOTAL_JOINTS; i++) {
    tmp_tick[i] = rad2tick(a[i], i);
    if (tmp_tick[i] != ticks_to[i]) {
    //printf("changing tick!\n");
    //std::cout << tmp_tick[i] << std::endl;
      vals.push_back(tmp_tick[i]);
      joints.push_back(i);
      //printf("joint being moved\n");
      //std::cout << i << std::endl;
      ticks_to[i] = tmp_tick[i];
    }
  }
                                                               
  return syncWriteWord(ADDR_GOAL_POSITION_L, joints, vals);
}


ControlUtils::ControlUtils()
{
  vec_set(joints, 0., TOTAL_JOINTS);
  vec_set(jointsd, 0., TOTAL_JOINTS);
  vec_set(joints_d, 0., TOTAL_JOINTS);
  
  if( dxl_initialize(0, 1) == 0 )
	{
		printf( "Failed to open USB2Dynamixel!\n" );
		printf( "Press Enter key to terminate...\n" );
		getchar();
	  exit(-1);
  }
	else
		printf( "Succeed to open USB2Dynamixel!\n" ); 

  _legIdx = 0;
}

ControlUtils::~ControlUtils()
{
	dxl_terminate();
}

int16_t ControlUtils::rad2tick(double r, int j)
{
  int16_t tmp = (int16_t)(r*ticks_per_rad)*tick_sign[j];
  return tmp+tick_zeros[j];
}

double ControlUtils::tick2rad(int16_t t, int j)
{
  int16_t tmp = (t-tick_zeros[j])*tick_sign[j];
  return (double)tmp/ticks_per_rad;
}


const double ControlUtils::ticks_per_rad = (TICK_MAX-TICK_MIN) / (2*M_PI);

#define ID_R_SHOULDER_PITCH      1
#define ID_L_SHOULDER_PITCH      2
#define ID_R_SHOULDER_ROLL       3
#define ID_L_SHOULDER_ROLL       4
#define ID_R_ELBOW               5
#define ID_L_ELBOW               6
#define ID_R_HIP_YAW             7
#define ID_L_HIP_YAW             8
#define ID_R_HIP_ROLL            9
#define ID_L_HIP_ROLL            10
#define ID_R_HIP_PITCH           11
#define ID_L_HIP_PITCH           12
#define ID_R_KNEE                13
#define ID_L_KNEE                14
#define ID_R_ANKLE_PITCH         15
#define ID_L_ANKLE_PITCH         16
#define ID_R_ANKLE_ROLL          17
#define ID_L_ANKLE_ROLL          18
#define ID_HEAD_PAN              19
#define ID_HEAD_TILT             20
#define ID_R_ELBOW_YAW           21
#define ID_L_ELBOW_YAW           22
#define ID_R_WRIST_YAW           23
#define ID_L_WRIST_YAW           24
#define ID_R_GRIPPER             25
#define ID_L_GRIPPER             26
#define ID_HEAD_TILT_2           27

// servo ids
const int ControlUtils::_id[TOTAL_JOINTS] = {
  ID_L_HIP_YAW, ID_L_HIP_PITCH, ID_L_HIP_ROLL, ID_L_KNEE, ID_L_ANKLE_PITCH, ID_L_ANKLE_ROLL,
  ID_R_HIP_YAW, ID_R_HIP_PITCH, ID_R_HIP_ROLL, ID_R_KNEE, ID_R_ANKLE_PITCH, ID_R_ANKLE_ROLL,
  ID_L_SHOULDER_PITCH, ID_L_SHOULDER_ROLL, ID_L_ELBOW_YAW, ID_L_ELBOW, 
  ID_R_SHOULDER_PITCH, ID_R_SHOULDER_ROLL, ID_R_ELBOW_YAW, ID_R_ELBOW, 
  ID_HEAD_PAN, ID_HEAD_TILT, ID_HEAD_TILT_2
};


const int16_t ControlUtils::tick_zeros[TOTAL_JOINTS] = {
	2048, 2048, 2048, 2048, 2048, 2048,
	2048, 2048, 2048, 2048, 2048, 2048,
	2048, 2560, 1024, 1707,
	2048, 1536, 3072, 2389,
  2048, 2048, 2048
};

const int16_t ControlUtils::tick_sign[TOTAL_JOINTS] = {
	-1,  1, -1, -1,  1, -1,
	-1, -1, -1, -1,  1, -1,
	 1,  1, -1, -1,
	-1,  1,  1, -1,
   1,  1,  1
};
 
