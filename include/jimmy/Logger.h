#ifndef __LOGGER_H
#define __LOGGER_H

/*
 * Useful for logging data traces. The log is saved in mrdplot format. There is
 * a front end for data visulization in matlab. 
 */

#include <stdio.h>
#include <string.h>
#include <eigen3/Eigen/Geometry>

#define LOGGER_MAX_CHANNELS 1500 
#define LOGGER_MAX_CHARS 100   

typedef struct{
	char units[LOGGER_MAX_CHARS];
	char names[LOGGER_MAX_CHARS];
  char data_type;
	const void *ptr;
} DataPoint_t;

class Logger {
  public:
    bool _inited;

    int n_points;
    int n_channels;
    int myindex;
    float *data;
    float frequency;
    DataPoint_t datapoints[LOGGER_MAX_CHANNELS]; 
    void init(double timestep);
    static const int N_QUAT = 100;
    Eigen::Quaterniond *qPoint[N_QUAT];
    double EAbuff[3*N_QUAT];
    int nQuat;
    bool recorded;

    Logger();
    ~Logger();

    void saveData();
    void writeToMRDPLOT();  

    void add_datapoint(const char *names, const char *units, const double *ptr);
    void add_datapoint(const char *names, const char *units, const int *ptr);
    void add_datapoint(const char *names, const char *units, const bool *ptr);
    void add_quat(const char *names, Eigen::Quaterniond *q);

    
    ///////////////////////////////////////////
    // eric debugging tool
    static double tmpOut[20];
    static int errCode;
    static void setErrEW(int err);
    static void setTmpOut(int ind, double val);
    void addEWstatic();
    ///////////////////////////////////////////
    
};


#endif
