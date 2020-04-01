#include <iostream>
#include <cstdlib>
#include <cmath>

#ifndef REAL
#define REAL double
#endif

void using_MKL_dgemm( REAL *A, int rowA, int colA, REAL *B, int rowB, int colB, 
                      REAL *C, REAL alpha=1.0, REAL beta=1.0, REAL gamma=1.0);
