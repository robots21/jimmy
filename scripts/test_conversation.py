#!/usr/bin/env python
import rospy
from std_msgs.msg import String

def talker():
    pub = rospy.Publisher("conversation", String)
    rospy.init_node('talker', anonymous=True)
    r = rospy.Rate(10) # 10hz
    print "Hello! My name is Jimmy. How are you?"
    while not rospy.is_shutdown():
        sentance = str(raw_input("What would you like to say?    "))
        pub.publish(sentance)
        r.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException: pass