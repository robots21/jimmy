#!/usr/bin/env python

from pattern.en import *    
import pygame
import rospy
from std_msgs.msg import String
import os
#from espeak import espeak


def load(something):
    path = os.path.join(os.path.expanduser('~'), 'catkin_ws', 'src', 'jimmy', 'scripts','media')
    return os.path.join(path, something)    

def callback(data):
    sentance = str(data)
    if positive(sentance, threshold = 0):
        print ("That's nice!")
        pygame.mixer.music.load(load('laughing.wav'))
        pygame.mixer.music.play()
        while pygame.mixer.music.get_busy(): 
            pygame.time.Clock().tick(1)
    else:
        print ("That's sad.")
        pygame.mixer.music.load(load('sad.wav'))
        pygame.mixer.music.play()
        while pygame.mixer.music.get_busy(): 
            pygame.time.Clock().tick(1)

    
def listener():
    rospy.init_node('listener', anonymous=True)
    rospy.Subscriber("conversation", String, callback)
    rospy.spin()
        
if __name__ == '__main__':
    try:
        pygame.init()
        pygame.mixer.init()
#        espeak.set_parameter(espeak.Parameter.Rate,150)
#        espeak.set_parameter(espeak.Parameter.Pitch,99)
        listener()
    except rospy.ROSInterruptException: pass
