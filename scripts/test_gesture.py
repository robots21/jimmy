#!/usr/bin/env python
from math import *
import roslib; roslib.load_manifest('jimmy')
import rospy
from std_msgs.msg import String
#from jimmy.msg import *


"""
s = shoulder
e = elbow
h = hip
k = knee
a = ankle
"""

def setup():
    rsPitch = 16
    lsPitch = 12
    rsRoll = 17
    lsRoll = 13 
    reExt = 19
    leExt = 15
    rhTwist = 6
    lhTwist = 0
    rhTilt = 8
    lhTilt = 2
    rhSwing = 7
    lhSwing = 1
    rkExt = 9
    lkExt = 3
    raExt = 10
    laExt = 4
    raTilt = 11
    laTilt = 5
    neck1 = 21
    neck2 = 22
    reRoll = 18
    leRoll = 14
    neckRot = 20

    
    return (rsPitch, lsPitch, rsRoll, lsRoll, reExt, leExt, rhTwist, lhTwist, rhTilt, lhTilt, rhSwing, lhSwing, rkExt, lkExt, raExt, laExt, raTilt, laTilt, neck1, neck2, reRoll, leRoll, neckRot)

def get_servos():
    rsPitch, lsPitch, rsRoll, lsRoll, reExt, leExt, rhTwist, lhTwist, rhTilt, lhTilt, rhSwing, lhSwing, rkExt, lkExt, raExt, laExt, raTilt, laTilt, neck1, neck2, reRoll, leRoll, neckRot = setup()
    motors = [rsPitch, lsPitch, rsRoll, lsRoll, reExt, leExt, rhTwist, lhTwist, rhTilt, lhTilt, rhSwing, lhSwing, rkExt, lkExt, raExt, laExt, raTilt, laTilt, neck1, neck2, reRoll, leRoll, neckRot]
    legmotors = [rhTwist, lhTwist, rhTilt, lhTilt, rhSwing, lhSwing, rkExt, lkExt, raExt, laExt, raTilt, laTilt]
    torsomotors = [rsPitch, lsPitch, rsRoll, lsRoll, reExt, leExt, neck1, neck2, reRoll, leRoll, neckRot]
    legposition = [1,1,1,1,1,1,1,1,1,1,1,1]
    torsoposition = [1,1,1,1,1,1,1,1,1,1,1]
    maxSpeed = radians(100)
    command = raw_input('Next Command? ')
    while command != 'end':
        if command == 'stand':
            target = [0,0,0,0,0,0,0,0,0,0,0,0]
            servos_set = setMotors(legmotors, target)
            return servos_set
            
        elif command == 'crouch':
            target = [0,0,0,0,radians(20),radians(-20),radians(-40),radians(-40),radians(-20),radians(-20),0,0]
            servos = setMotors(legmotors,target)
            return servos

        elif command == 'balance':
            #Stand Up
            target = [0,0,0,0,0,0,0,0,0,0,0,0]
            servos = setMotors(legmotors,target)
            #Shift Arms and Head
            command = raw_input('step (hit enter to proceed)')
            target = [radians(39.8), radians(1.6), radians(13.98), radians(35.87), radians(-70.2), radians(-6.8), radians(-5.3), radians(17.7), radians(156.3), radians(-83.9), radians(6.3)]
            servos = setMotors(legmotors,target)
            #Shift onto Left Foot
            command = raw_input('step (hit enter to proceed)')
            target = [0,0,radians(13),radians(5),0,0,0,0,0,0,radians(-13),radians(-20)]
            servos = setMotors(legmotors,target)
            #Lift Right Leg
            command = raw_input('step (hit enter to proceed)')
            target = [0,0,radians(13),radians(5),radians(20),0,radians(-40),0,radians(-20),0,radians(-13),radians(-20)]
            servos = setMotors(legmotors,target)
        
        elif command == 'limparm':
            for motor in torsomotors:
                motor.disable_torque()
            command = raw_input('Ready to read angles? ')
            if command == 'yes':
                angles = []
                for i in range(len(torsomotors)):
                    angles.append(degrees(torsomotors[i].read_angle()))
                print angles            

        elif command == 'shuffle':
            while True:
                target = [0,0,radians(13),radians(13),0,0,0,0,0,0,radians(-13),radians(-13)]
                legposition = move_legs(legmotors, target, legposition, maxSpeed/3) #Shift Left
                command = raw_input('step (hit enter to proceed)')
                if command != '':
                    break
                target = [0,0,radians(13),radians(13),radians(20),0,radians(-40),0,radians(-20),0,radians(-13),radians(-13)]
                legposition = move_legs(legmotors, target, legposition, maxSpeed) #Lift Right Leg
                command = raw_input('step (hit enter to proceed)')
                if command != '':
                    break
                target = [0,0,radians(13),radians(13),0,0,0,0,0,0,radians(-13),radians(-13)]
                legposition = move_legs(legmotors, target, legposition, maxSpeed) #lower Right Leg
                command = raw_input('step (hit enter to proceed)')
                if command != '':
                    break

                target = [0,0,radians(-13),radians(-13),0,0,0,0,0,0,radians(13),radians(13)]
                legposition = move_legs(legmotors, target, legposition, maxSpeed/3) #Shift Right
                command = raw_input('step (hit enter to proceed)')
                if command != '':
                    break
                target = [0,0,radians(-13),radians(-13),0,radians(-20),0,radians(-40),0,radians(-20),radians(13),radians(13)]
                legposition = move_legs(legmotors, target, legposition, maxSpeed) #Lift Left Leg
                command = raw_input('step (hit enter to proceed)')
                if command != '':
                    break
                target = [0,0,radians(-13),radians(-13),0,0,0,0,0,0,radians(13),radians(13)]
                legposition = move_legs(legmotors, target, legposition, maxSpeed) #Lower Left Leg
                command = raw_input('step (hit enter to proceed)')
                if command != '':
                    break

        elif command == 'makesetpoint':
            for motor in motors:
                motor.disable_torque()
            command = raw_input('Ready to read angles? ')
            if command == 'yes':
                angles = []
                for i in range(len(motors)):
                    angles.append(degrees(motors[i].read_angle()))
                print angles

        elif command == 'readpos':
            angles = []
            for i in range(len(motors)):
                angles.append(degrees(motors[i].read_angle()))
            print angles


        else:
            print 'Invalid Command'   
        command = raw_input('Next Command? ')     
        
def setMotors(motors, target):
    servo_move = []
    i = 0
    while i < len(motors):
        servo_move.append(str(motors[i]))
        servo_move.append(str(target[i]))
        i += 1
    string = ' '.join(servo_move)
    return string
    
    
def send_ros():
    pub = rospy.Publisher('jimmy_move_gesture', String)
    rospy.init_node('test_send_gesture_cmd_py')
    r = rospy.Rate(10) # 10hz
    while not rospy.is_shutdown():
        servos_set = get_servos()
        pub.publish(servos_set)
        r.sleep()
        

if __name__ == '__main__':
    try:
        send_ros()
        torsoposition = [39.8, 1.6, 13.98, 35.87, -70.2, -6.8, -5.3, 17.7, 156.3, -83.9, 6.3]
        [39.8, 1.6, 13.98, 35.87, -70.2, -6.8, 3.3, 8.5, -10.3, -17.4, -1.9, -0.4, 4.7, -0.7, 3.8, 0.1, 4.7, 11.3, -5.3, 17.7, 156.3, -83.9, 6.3]
    except rospy.ROSInterruptException: pass

