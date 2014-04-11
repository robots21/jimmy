#include <ros/ros.h>
#include <ros/package.h>
#include <time.h>
#include <jimmy/jimmy_servo.h>
#include <jimmy/jimmy_command.h>
#include <jimmy/jimmy_gesture.h>

void Callback(){
  sleep(5);
}


int main( int argc, char **argv ) 
{
  ////////////////////////////////////////////////////
  // ros stuff
  ros::init(argc, argv, "jimmy_idle", ros::init_options::NoSigintHandler);
  ros::NodeHandle rosnode = ros::NodeHandle();
  printf("Ready to listen for commands!\n");

  //Subscribes to jimmy_move_servo, which tells us which servos to move
  ros::Subscriber subcommand = rosnode.subscribe("jimmy_move_servo", 10, Callback);
  ros::Subscriber sub = rosnode.subscribe("jimmy_move_gesture", 10, Callback);


  ros::Publisher pub = rosnode.advertise<jimmy::jimmy_gesture>("jimmy_send_gesture", 10);
  jimmy::jimmy_gesture gestures;

  int type;
  srand (time(NULL));
  type = rand() % 6 + 1;
  
  gestures.cmd = type;

  pub.publish(gestures);

  printf("Gesture sent!\n");

  for (int i = 0; i < 10000; i++){
    ros::spinOnce();
    sleep(0.0001);
  }

    return 0;
}