jimmy
=====

Base code for some of what we're working on.

Currently code is structured using ROS nodes. All servo actuation is done through the "jimmy_servos" script. We publish servo IDs and positions to this node, which will then write the position to the dynamixels. Servo IDs are defined in ControlUtils

All python scripts are located in the script folder, while C++ scripts are located in the src folder.

This is a work in progress, with a comphrehensive README coming soon.

For questions, contact sophia.li@students.olin.edu
