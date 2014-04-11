#!/usr/bin/env python
import roslib; roslib.load_manifest('jimmy')
import rospy
from std_msgs.msg import String
from jimmy.msg import *

def send_servo(data):
    pub = rospy.Publisher('jimmy_move_servo', jimmy_servo)
    r = rospy.Rate(10) # 10hz
    while not rospy.is_shutdown():
        input_command = str(data).split()
        print input_command
        if input_command[0] == "end":
            break
        i = 1
        msg = jimmy_servo()
        while i < len(input_command):
            msg.positions.append(float(input_command[i+1]))
            if input_command[i].isalpha():
                print "adding this to servo names"
                msg.servo_names.append(input_command[i])
            elif input_command[i].isdigit():
                print "adding this to servo numbers"
                msg.servo_numbers.append(int(input_command[i]))
            i += 2 
        rospy.loginfo(msg)
        pub.publish(msg)
        print "message published!"
        r.sleep()
        
def main():
    rospy.init_node('test_send_servo_cmd_py')
    rospy.Subscriber("jimmy_move_gesture", String, send_servo)
    print "Waiting for commands!"

    rospy.spin()
        
        
if __name__ == '__main__':
    try:
        main()
    except rospy.ROSInterruptException: pass
