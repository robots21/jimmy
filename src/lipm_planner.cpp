#include "traj.h"

#include "lqr_controller.h"
#include "lipm_planner.h"
#include "JimmyCommon.h"

LipmConstHeightPlanner::LipmConstHeightPlanner(double z, double dt)
  : _height(z)
  , _dt(dt)
  , _lqr(LqrController<2,1>())
{
  _Q.setIdentity();
  _R.setIdentity();
  _Q *= 1e-6;

  _A(0,0) = 1;
  _A(0,1) = _dt;
  _A(1,0) = _dt*GRAVITY/_height;
  _A(1,1) = 1;

  _B(0,0) = 0;
  _B(1,0) = -_dt*GRAVITY/_height;

  _lqr.setQ(_Q);
  _lqr.setR(_R);
  _lqr.infTimeLQR(_A, _B);

  _K = _lqr.getK();
  _Quu_inv = (_B.transpose()*_lqr.getV()*_B + _R).inverse();
}

LipmConstHeightPlanner::~LipmConstHeightPlanner()
{
  _du.clear();
  _Vx.clear(); 
}

double LipmConstHeightPlanner::forwardPass(const double *x0, Traj<1,1> &com) const
{
  Eigen::Matrix<double,2,1> z;
  Eigen::Matrix<double,1,1> u;
  
  com = _zmp_d;

  com[0].x[0] = x0[0];
  com[0].x[1] = x0[1];

  for (size_t i=0; i<_zmp_d.size()-1; i++) {
    z(0) = com[i].x[0] - _zmp_d[i].x[0];
    z(1) = com[i].x[1];
    u = _K*z + _du[i];
    com[i].u[0] = u(0);

    z = _A*z + _B*u; 
    com[i+1].x[0] = z(0) + _zmp_d[i].x[0];
    com[i+1].x[1] = z(1);

    // save acc, and real cop
    com[i].u[0] += _zmp_d[i].x[0];
    com[i].x[2] = (com[i].x[0] - com[i].u[0]) * GRAVITY / _height;
  }

  int last = _zmp_d.size()-1;
  com[last].u[0] += _zmp_d[last].x[0];
  com[last].x[2] = (com[last].x[0] - com[last].u[0]) * GRAVITY / _height;
  
  return 0;
}

void LipmConstHeightPlanner::backwardPass(const Traj<1,1> &com)
{
  Eigen::Matrix<double,2,1> z;
  Eigen::Matrix<double,1,1> u;

  Eigen::Matrix<double,2,1> Lx;
  Eigen::Matrix<double,1,1> Lu;
  Eigen::Matrix<double,2,1> Qx;
  Eigen::Matrix<double,1,1> Qu;

  for (int i=(int)_zmp_d.size()-1; i>0; i--) {
    z(0) = com[i].x[0] - _zmp_d[i].x[0];
    z(1) = com[i].x[1];
    u(0) = com[i].u[0] - _zmp_d[i].x[0];

    Lx = _Q*z;
    Lu = _R*u;

    Qx = _A.transpose()*_Vx[i] + Lx;    
    Qu = _B.transpose()*_Vx[i] + Lu;

    _Vx[i-1] = _K.transpose()*Qu + Qx;
    _du[i] = -_Quu_inv.transpose()*Qu;
  }

#if 0
  std::fstream du("tmp/du", std::fstream::out);
  for (size_t i=0; i<_du.size(); i++) {
    du << _du[i](0) << std::endl;
  }
  du.close();
#endif
}

void LipmConstHeightPlanner::setZMPTraj(const Traj<1,1> &traj) 
{ 
  _zmp_d = traj; 

  _Vx.resize(traj.size(), Eigen::Matrix<double,2,1>::Zero());
  _du.resize(traj.size(), Eigen::Matrix<double,1,1>::Zero());
}

bool LipmConstHeightPlanner::getCOMTraj(const Traj<1,1> &zmpTraj, const double *x0, Traj<1,1> &traj)
{
  setZMPTraj(zmpTraj);

  forwardPass(x0, traj);
  backwardPass(traj);
  forwardPass(x0, traj);

  return true;
}

bool LipmConstHeightPlanner::getTrajs(const double *x0, int startIdx, const std::vector<double> &zmp_d, std::vector<double> &com_p, std::vector<double> &com_v)
{

	//prefer to do this inside the function for safety
	com_p.resize(zmp_d.size());
	com_v.resize(zmp_d.size());

  Traj<1,1> in, out;
  double p;
  for (size_t i = startIdx; i < zmp_d.size(); i++) {
    p = zmp_d[i];
    in.append(i*_dt, 0, &p, NULL, NULL, NULL);
  }

  bool res = getCOMTraj(in, x0, out);
  if (!res) 
    return false;

  //com_p.resize(out.size());
  //com_v.resize(out.size());

  for (size_t i = 0; i < out.size(); i++) {
    com_p[startIdx+i] = out[i].x[0];
    com_v[startIdx+i] = out[i].x[1];
  }

  return true;
} 

/*
bool LipmConstHeightPlanner::getTrajs(const double *x0, const std::vector<double> &zmp_d, std::vector<double> &com_p, std::vector<double> &com_v, std::vector<double> &com_a, std::vector<double> &cop)
{
  Traj<1,1> in, out;
  double p;
  for (size_t i = 0; i < zmp_d.size(); i++) {
    p = zmp_d[i];
    in.append(i*_dt, 0, &p, NULL, NULL, NULL);
  }
  
  bool res = getCOMTraj(in, x0, out);
  if (!res) 
    return false;
 
  com_p.resize(out.size());
  com_v.resize(out.size());
  com_a.resize(out.size());
  cop.resize(out.size());

  for (size_t i = 0; i < out.size(); i++) {
    //zmp = out[i].u[0] + _zmp_d[i].x[0];
    //acc = (out[i].x[0] - zmp) * GRAVITY / _height;

    com_p[i] = out[i].x[0];
    com_v[i] = out[i].x[1];
    com_a[i] = out[i].x[2];
    cop[i] = out[i].u[0];
  }

  return true;
}
*/
