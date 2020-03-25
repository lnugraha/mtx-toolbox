#ifndef DENSE_MATRIX_HPP_
#define DENSE_MATRIX_HPP_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef REAL
#define REAL double
#endif

void randMatrix(double *A, int row, int col);

void randMatrix(double **A, int row, int col);

void displayMatrix(REAL **M, int row, int col);

void displayMatrix(REAL *M, int row, int col);

void dgemm( double **A, int rowA, int colA, double **B, int rowB, int colB, 
            double **C, double alpha=1.0, double beta=1.0, double gamma=1.0 );

void dgemm( double *A, int rowA, int colA, double *B, int rowB, int colB, 
            double *C, double alpha=1.0, double beta=1.0, double gamma=1.0 );

void sgemm( float **A, int rowA, int colA, float **B, int rowB, int colB, 
            float **C, float alpha=1.0, float beta=1.0, float gamma=1.0 );

void sgemm( float *A, int rowA, int colA, float *B, int rowB, int colB, 
            float *C, float alpha=1.0, float beta=1.0, float gamma=1.0 );

void dgemv( double **matA, int rowA, int colA, double *vecB, int sizeB, 
            double *vecC );

void dgemv( double *matA, int rowA, int colA, double *vecB, int sizeB, 
            double *vecC );

void sgemv( float **matA, int rowA, int colA, float *vecB, int sizeB, 
            float *vecC );

void sgemv( float *matA, int rowA, int colA, float *vecB, int sizeB, 
            float *vecC );

double ddot( double *vecA, double *vecB, int size, 
             double alpha=1.0, double beta=1.0 );

float sdot( float *vecA, float *vecB, int size,
            float alpha=1.0, float beta=1.0 );

void daxpy( double *x, double *y, int size, double alpha=1.0 );

void saxpy( float *x, float *y, int size, float alpha=1.0 );

#endif
