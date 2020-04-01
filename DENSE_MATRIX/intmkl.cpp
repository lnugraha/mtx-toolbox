#include "DenseMatrix.hpp"
#include "Timer.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include <mkl.h>
#include <mkl_cblas.h>

int main(int argc, char *argv[]){
/* void cblas_dgemm (const CBLAS_LAYOUT Layout, 
 * const CBLAS_TRANSPOSE transa, const CBLAS_TRANSPOSE transb, 
 * const MKL_INT m, const MKL_INT n, const MKL_INT k, 
 * const double alpha, const double *a, const MKL_INT lda, 
 * const double *b, const MKL_INT ldb, const double beta, 
 * double *c, const MKL_INT ldc); */

  const int SIZE = 100000000;
  int side = sqrt(SIZE);
  REAL *A = (REAL*)calloc(SIZE, sizeof(REAL));
  REAL *B = (REAL*)calloc(SIZE, sizeof(REAL));
  REAL *C = (REAL*)calloc(SIZE, sizeof(REAL));
  REAL *C_mkl = (REAL*)calloc(SIZE, sizeof(REAL));
  randMatrix(A, side, side); randMatrix(B, side, side);

  {
  Timer intel;
  cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 
  side, side, side, 1.0, A, side, B, side, 1.0, C_mkl, side);
  }
  // displayMatrix(C_mkl, side, side);
/*
  {
  Timer original;
  dgemm(A, side, side, B, side, side, C, 1.0, 1.0, 1.0);
  }
  // displayMatrix(C, side, side);
*/
  free(A); free(B); free(C); free(C_mkl);
  return 0;
}
