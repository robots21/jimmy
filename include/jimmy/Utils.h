#ifndef __UTILS_HPP
#define __UTILS_HPP

#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <algorithm>
 
template <class T> void clamp (T &in, const T &l, const T &h)
{
  in = std::min(in, h);
  in = std::max(in, l);
}

template <class T> void vec_set (T *dest, T num, size_t n)
{
  for (size_t i = 0; i < n; i++)
    dest[i] = num;
}

template <class T> void vec_copy (T *dest, const T *src, size_t n)
{
  memcpy(dest, src, sizeof(T)*n);  
}

inline void dvec_set(double *dest, double num, size_t n)
{
  for (size_t i = 0; i < n; i++)  
    dest[i] = num;
}

inline void fvec_set(float *dest, float num, size_t n)
{
  for (size_t i = 0; i < n; i++)  
    dest[i] = num;
}

inline void dvec_copy(double *dest, const double *src, size_t n)
{ 
  memcpy(dest, src, sizeof(double)*n);
}

inline void fvec_copy(float *dest, const float *src, size_t n)
{ 
  memcpy(dest, src, sizeof(float)*n);
}

inline bool write_n_bin_double(const double *data, int len, std::ofstream &out)
{
  out.write((const char *)data, len*sizeof(double));
  return out.good();  
}

inline bool read_n_bin_double(double *data, int len, std::ifstream &in)
{
  in.read((char *)data, len*sizeof(double));
  return in.good();
}

inline double get_rand(double mag) { 
  return (((double)rand() / (double)RAND_MAX) - 0.5) * mag; 
}

inline void get_rand_vec(double *v, int len, double mag) {
  for (int i = 0; i < len; i++)  
    v[i] = get_rand(mag);
}

inline double get_time() {
  struct timespec the_tp;
  clock_gettime( CLOCK_MONOTONIC, &the_tp );
  return ((double) (the_tp.tv_sec)) + 1.0e-9*the_tp.tv_nsec;  
}

#endif
