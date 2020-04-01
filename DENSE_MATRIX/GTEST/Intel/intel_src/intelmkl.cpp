#include "intelmkl.hpp"

#if defined USE_MKL

#include <mkl.h>
#include <mkl_lapacke.h>

#else

#ifdef __APPLE__
#include <Accelerate/Accelerate.h>
#else
#include <cblas.h>
#endif

#endif

#include <iostream>
#include <cmath>

void using_MKL_dgemm( REAL *A, int rowA, int colA, REAL *B, int rowB, int colB, 
                      REAL *C, REAL alpha, REAL beta, REAL gamma)
{
  cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, rowA, colB, rowB,
  alpha, A, rowA, B, rowB, gamma, C, colB);
}
