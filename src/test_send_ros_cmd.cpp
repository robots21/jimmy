#include <jimmy/jimmy_command.h>
#include <ros/ros.h>

int main(int argc, char **argv)
{
  if (argc < 2) {
    printf("argc > 2\n");
    exit(-1);
  }

  ////////////////////////////////////////////////////
  // ros stuff
  ros::init(argc, argv, "test_ros", ros::init_options::NoSigintHandler);
  ros::NodeHandle rosnode = ros::NodeHandle();

  ros::Time last_ros_time_;
  bool wait = true;
  while (wait) {
    last_ros_time_ = ros::Time::now();
    if (last_ros_time_.toSec() > 0) {
      wait = false;
    }
  }

  ros::Publisher pub = rosnode.advertise<jimmy::jimmy_command>("Jimmy_cmd", 10);
  jimmy::jimmy_command cmd;

  int type = atoi(argv[1]);
  if (type == jimmy::jimmy_command::CMD_WALK) 
  {
    if (argc != 5) {
      printf("wrong # walk params %d\n", argc); 
    }
    cmd.cmd = jimmy::jimmy_command::CMD_WALK;
    cmd.param.resize(3,0);
    cmd.param[0] = atof(argv[2]);
    cmd.param[1] = atof(argv[3]);
    cmd.param[2] = atof(argv[4]);
  
    printf("press enter to send walk %g %g %g\n", cmd.param[0], cmd.param[1], cmd.param[2]);
  }
  else if (type == jimmy::jimmy_command::CMD_NECK) {
    if (argc != 5) {
      printf("wrong # neck params %d\n", argc); 
    }
    cmd.cmd = jimmy::jimmy_command::CMD_NECK;
    cmd.param.resize(3,0);
    cmd.param[0] = atof(argv[2]);
    cmd.param[1] = atof(argv[3]);
    cmd.param[2] = atof(argv[4]);
    
    printf("press enter to send neck %g %g %g\n", cmd.param[0], cmd.param[1], cmd.param[2]);
  }
  else if (type == jimmy::jimmy_command::CMD_SAVE_AND_QUIT) {
    cmd.cmd = jimmy::jimmy_command::CMD_SAVE_AND_QUIT;
    printf("press enter to send quit\n");
  }
  else if (type == jimmy::jimmy_command::CMD_IDLE) {
    cmd.cmd = jimmy::jimmy_command::CMD_IDLE;
    printf("press enter to send idle\n");
  }
  else if (type >= jimmy::jimmy_command::CMD_GESTURE_START) {
    cmd.cmd = type;
    printf("press enter to send gesture %d\n", type);
  }
  else {
    printf("bad cmd: %d", type);  
    exit(-1);
  }

  getchar();
  pub.publish(cmd);

  for (int i = 0; i < 10000; i++)
    ros::spinOnce();
}
