#include "lipm_planner.h"
#include <fstream>
#include <iostream>

int main()
{
  double dt = 0.01;
  double z = 0.6;
  double com0[2] = {0};

  LipmConstHeightPlanner lipm(z, dt);

  std::vector<double> zmp_d; 
  std::vector<double> com_p; 
  std::vector<double> com_v; 
  std::vector<double> com_a; 
  std::vector<double> cop; 

  for (int i = 0; i < 400; i++) {
    if (i < 100)
      zmp_d.push_back(0);
    else if (i < 200)
      zmp_d.push_back(0.2);
    else if (i < 300)
      zmp_d.push_back(-0.2);
    else
      zmp_d.push_back(0.);
  }

  lipm.getTrajs(com0, 0, zmp_d, com_p, com_v);
  std::fstream p_d("tmp/pd", std::fstream::out);
  std::fstream p_a("tmp/pa", std::fstream::out);
  std::fstream com_out("tmp/com", std::fstream::out);
  for (size_t i = 0; i < zmp_d.size(); i++) {
    p_d << zmp_d[i] << std::endl;
    com_out << com_p[i] << "," << com_v[i] << std::endl;
  }  
  p_d.close();
  p_a.close();
  com_out.close();
  
  return 1;
}
