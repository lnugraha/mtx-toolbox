#ifndef PARALLEL_HPP_
#define PARALLEL_HPP_

#define REAL double

#include <cmath>
#include <thread>
#include <omp.h>

class parallelMulMat{
  private:

  public:
	void withBoost (REAL *A, REAL *B, REAL *C, unsigned long int size, int nthread);
	void withOpenMP(REAL *A, REAL *B, REAL *C, unsigned long int size, int nthread);
	void withThread(REAL *A, REAL *B, REAL *C, unsigned long int size, int nthread);
};

#endif
