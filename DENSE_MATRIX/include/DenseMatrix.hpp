#ifndef DENSE_MATRIX_HPP_
#define DENSE_MATRIX_HPP_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef REAL
#define REAL double
#endif

void randMatrix(REAL *A, int row, int col);

void randMatrix(REAL **A, int row, int col);

void displayMatrix(REAL **M, int row, int col);

void displayMatrix(REAL *M, int row, int col);

void dgemm( REAL **A, int rowA, int colA, REAL **B, int rowB, int colB, 
            REAL **C, REAL alpha=1.0, REAL beta=1.0, REAL gamma=1.0 );

void dgemm( REAL *A, int rowA, int colA, REAL *B, int rowB, int colB, 
            REAL *C, REAL alpha=1.0, REAL beta=1.0, REAL gamma=1.0 );
#endif
