#ifndef DENSE_MATRIX_HPP_
#define DENSE_MATRIX_HPP_

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cassert>

#include <iostream>
#include <future>
#include <random>
#include <numeric>
#include <chrono>

#ifndef REAL
#define REAL double
#endif

template<typename T>
static T randReal(T min = 0.0, T max = 1.0){
  std::random_device seed;
  std::mt19937 engine( seed() );
  std::uniform_real_distribution<T> dist(min, max);
  return dist( engine );
}


template<typename T>
static T randInt(T min = 0, T max = 100){
  std::random_device seed;
  std::mt19937 engine( seed() );
  std::uniform_int_distribution<T> dist(min, max);
  return dist( engine );
}

/*!@brief Random matrix generator with elements ranging from 0.0 to 1.0
 * @notes This version uses one dimensional array to represent a matrix
 * @param[in] A A dynamically allocated matrix with a size of (row * col)
 * @param[in] row the number of rows in matrix A
 * @param[in] col the number of columns in matrix A  
 * @return    Matrix A */
void randMatrix(REAL *A, int row, int col);

/*!@brief Random matrix generator with elements ranging from 0.0 to 1.0
 * @notes This version uses two dimensional array to represent a matrix
 * @param[in] A A dynamically allocated matrix with a size of (row * col)
 * @param[in] row the number of rows in matrix A
 * @param[in] col the number of columns in matrix A  
 * @return    Matrix A */
void randMatrix(REAL **A, int row, int col);

/*!@brief Random vector generator with elements ranging from 0.0 to 1.0
 * @param[in] A A dynamically allocated vector with a discrete length
 * @param[in] size the length of vector A
 * @return    Vector A */
void randVector(REAL *A, int size);

void dgemm( double **A, int rowA, int colA, double **B, int rowB, int colB, 
            double **C, double alpha=1.0, double beta=1.0, double gamma=1.0 );

/* FIXME */
void dgemm_opt( double **A, int rowA, int colA, 
                double **B, int rowB, int colB, 
                double **C, 
                double alpha=1.0, double beta=1.0, double gamma=1.0 );

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

double ddot_async( double *vecA, double *vecB, int size, 
                   double alpha=1.0, double beta=1.0 );

float sdot( float *vecA, float *vecB, int size,
            float alpha=1.0, float beta=1.0 );

float sdot_async( float *vecA, float *vecB, int size, 
                  float alpha=1.0, float beta=1.0 );

void daxpy( double *x, double *y, int size, double alpha=1.0 );

void daxpy_async( double *x, double *y, int size, double alpha=1.0 );

void saxpy( float *x, float *y, int size, float alpha=1.0 );

void saxpy_async( float *x, float *y, int size, float alpha=1.0 );

#endif
