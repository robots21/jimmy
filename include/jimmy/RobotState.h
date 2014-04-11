#ifndef __ROBOT_STATE_DEFINED
#define __ROBOT_STATE_DEFINED

/*
 * Generates and stores usful info about the robot.
 * 
 * q = root position, orientation + all joint position
 * qd = root linear and angular velocity + all joint velocity
 * Takes q and qd, generates position and velocity for COM, torso and foot 
 * using sdfast model's forward kinematics. Can generalize to any arbitrary
 * body part on the robot.
 */

#include "SDModel.h"
#include "JimmyCommon.h"

#include "Logger.h"
#include <eigen3/Eigen/Geometry>

class RobotState {
  public:

    static const double jointLimits[2][N_JOINTS];
    static const std::string jointNames[TOTAL_JOINTS];

    Eigen::Quaterniond rootQ;           // pelvis orientation
    double rootW[3];                    // pelvis angular vel
    double root[3];                     // pelvis position  
    double rootd[3];                    // pelvis velocity
    double joints[N_JOINTS];            // joint position
    double jointsd[N_JOINTS];           // joint velocity


    double com[3];                      // com position
    double comd[3];                     // com velocity
    double foot[LR][3];                 // foot position
    double footd[LR][3];                // foot linear velocity
    double footW[LR][3];                // foot angular velocity
    Eigen::Quaterniond footQ[LR];       // foot orientation

    SDModel *model;                     // sdfast model ptr

    double m;

    // EIGEN uses col major by default, need to explicitly say rowmajor!!!
    Eigen::Matrix<double,N_U,6,Eigen::RowMajor> J[LR];    // foot J transpose
    Eigen::Matrix<double,N_U,3,Eigen::RowMajor> Jc;       // com J transpose, position only
    Eigen::Matrix<double,N_U,6,Eigen::RowMajor> Jtorso;   // torso J transpose

    RobotState();
    void fillZeros();
    void computeSDFvars();
    double *getSDFstate(double *sdState);
    void addToLog(Logger &logger);
};




#endif
