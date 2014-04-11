#ifndef LIPM_PLANNER_H
#define LIPM_PLANNER_H

/*
 * Plans a center of mass (com) trajectory given a sequence of foot steps and
 * the current com position and velocity. 
 *
 * For more info, http://www.cs.cmu.edu/~sfeng/sf_humanoids13.pdf
 */

#include <vector>

#include <eigen3/Eigen/Core>

#include "traj.h"
#include "lqr_controller.h"

class LipmConstHeightPlanner {
  private:
    double _height;
    double _dt;

    Eigen::Matrix<double,2,2> _A;
    Eigen::Matrix<double,2,1> _B;
    Eigen::Matrix<double,1,2> _K;

    Eigen::Matrix<double,2,2> _Q;
    Eigen::Matrix<double,1,1> _R;
    Eigen::Matrix<double,1,1> _Quu_inv;
    
    std::vector< Eigen::Matrix<double,1,1> > _du;
    std::vector< Eigen::Matrix<double,2,1> > _Vx;

    LqrController<2,1> _lqr;
    
    Traj<1,1> _zmp_d;    

    void setZMPTraj(const Traj<1,1> &traj);
    double forwardPass(const double *x0, Traj<1,1> &com) const;
    void backwardPass(const Traj<1,1> &com);
  
  public:
    LipmConstHeightPlanner(double z, double dt);
    ~LipmConstHeightPlanner();
    
    bool getCOMTraj(const Traj<1,1> &zmp, const double *state, Traj<1,1> &com);
    bool getTrajs(const double *x0, int startIdx, const std::vector<double> &zmp_d, std::vector<double> &com_p, std::vector<double> &com_v);
    //bool getTrajs(const double *x0, const std::vector<double> &zmp_d, std::vector<double> &com_p, std::vector<double> &com_v, std::vector<double> &com_a, std::vector<double> &cop);
}; 

#endif
