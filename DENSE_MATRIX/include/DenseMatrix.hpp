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

/*!@brief Generate a random real scalar between the minimum and maximum value
 * @param[in] min The minimum value of the random number (default to 0.0)
 * @param[in] max The maximum value of the random number (default to 1.0)
 * @return A random number between the min and max value with decimal type */
template<typename T>
static T randReal(T min = 0.0, T max = 1.0){
  std::random_device seed;
  std::mt19937 engine( seed() );
  std::uniform_real_distribution<T> dist(min, max);
  return dist( engine );
}

/*!@brief Generate a random integer scalar between the minimum and maximum value
 * @param[in] min The minimum value of the random number (default to 0)
 * @param[in] max The maximum value of the random number (default to 100)
 * @return A random number between the min and max value with non-decimal type*/
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

/*!@brief Multiply two dense matrices in double floating point precision
 * @note  All matrices calculated are stored as a two-dimensional array
 * @param[in] A     Matrix A
 * @param[in] rowA  Row size of Matrix A
 * @param[in] colA  Column size of Matrix A
 * @param[in] B     Matrix B
 * @param[in] rowB  Row size of Matrix B
 * @param[in] colB  Column size of Matrix B
 * @param[out] C    Matrix C with a row size of Matrix A and a column size of 
 *                  Matrix B 
 * @param[in] alpha Scaling factor of matrix A (default to 1.0)
 * @param[in] beta  Scaling factor of matrix B (default to 1.0)
 * @param[in] gamma Scaling factor of matrix C (default to 1.0) */
void dgemm( double **A, int rowA, int colA, double **B, int rowB, int colB, 
            double **C, double alpha=1.0, double beta=1.0, double gamma=1.0 );

/* FIXME */
void dgemm_opt( double **A, int rowA, int colA, 
                double **B, int rowB, int colB, 
                double **C, 
                double alpha=1.0, double beta=1.0, double gamma=1.0 );

/*!@brief Multiply two dense matrices in double floating point precision
 * @note  All matrices calculated are stored as a one-dimensional array
 * @param[in] A     Matrix A
 * @param[in] rowA  Row size of Matrix A
 * @param[in] colA  Column size of Matrix A
 * @param[in] B     Matrix B
 * @param[in] rowB  Row size of Matrix B
 * @param[in] colB  Column size of Matrix B
 * @param[out] C    Matrix C with a row size of Matrix A and a column size of 
 *                  Matrix B 
 * @param[in] alpha Scaling factor of matrix A (default to 1.0)
 * @param[in] beta  Scaling factor of matrix B (default to 1.0)
 * @param[in] gamma Scaling factor of matrix C (default to 1.0) */
void dgemm( double *A, int rowA, int colA, double *B, int rowB, int colB, 
            double *C, double alpha=1.0, double beta=1.0, double gamma=1.0 );

/*!@brief Multiply two dense matrices in single floating point precision
 * @note  All matrices calculated are stored as a two-dimensional array
 * @param[in] A     Matrix A
 * @param[in] rowA  Row size of Matrix A
 * @param[in] colA  Column size of Matrix A
 * @param[in] B     Matrix B
 * @param[in] rowB  Row size of Matrix B
 * @param[in] colB  Column size of Matrix B
 * @param[out] C    Matrix C with a row size of Matrix A and a column size of 
 *                  Matrix B 
 * @param[in] alpha Scaling factor of matrix A (default to 1.0)
 * @param[in] beta  Scaling factor of matrix B (default to 1.0)
 * @param[in] gamma Scaling factor of matrix C (default to 1.0) */
void sgemm( float **A, int rowA, int colA, float **B, int rowB, int colB, 
            float **C, float alpha=1.0, float beta=1.0, float gamma=1.0 );

/*!@brief Multiply two dense matrices in single floating point precision
 * @note  All matrices calculated are stored as a one-dimensional array
 * @param[in] A     Matrix A
 * @param[in] rowA  Row size of Matrix A
 * @param[in] colA  Column size of Matrix A
 * @param[in] B     Matrix B
 * @param[in] rowB  Row size of Matrix B
 * @param[in] colB  Column size of Matrix B
 * @param[out] C    Matrix C with a row size of Matrix A and a column size of 
 *                  Matrix B 
 * @param[in] alpha Scaling factor of matrix A (default to 1.0)
 * @param[in] beta  Scaling factor of matrix B (default to 1.0)
 * @param[in] gamma Scaling factor of matrix C (default to 1.0) */
void sgemm( float *A, int rowA, int colA, float *B, int rowB, int colB, 
            float *C, float alpha=1.0, float beta=1.0, float gamma=1.0 );

/*!@brief Multiply a matrix and a vector in double floating point precision
 * @param[in] matA  Matrix A which is represented as a two-dimensional array
 * @param[in] rowA  Row size of Matrix A
 * @param[in] colA  Column size of Matrix A
 * @param[in] vecB  Vector B
 * @param[in] sizeB The length of Vector B, which must be identical with colA
 * @param[out] vecC Vector result from multiplication between Matrix A and 
 *                  Vector B with a length equals to rowA */
void dgemv( double **matA, int rowA, int colA, double *vecB, int sizeB, 
            double *vecC );

/*!@brief Multiply a matrix and a vector in double floating point precision
 * @param[in] matA  Matrix A which is represented as a one-dimensional array
 * @param[in] rowA  Row size of Matrix A
 * @param[in] colA  Column size of Matrix A
 * @param[in] vecB  Vector B
 * @param[in] sizeB The length of Vector B, which must be identical with colA
 * @param[out] vecC Vector result from multiplication between Matrix A and 
 *                  Vector B with a length equals to rowA */
void dgemv( double *matA, int rowA, int colA, double *vecB, int sizeB, 
            double *vecC );

/*!@brief Multiply a matrix and a vector in single floating point precision
 * @param[in] matA  Matrix A which is represented as a two-dimensional array
 * @param[in] rowA  Row size of Matrix A
 * @param[in] colA  Column size of Matrix A
 * @param[in] vecB  Vector B
 * @param[in] sizeB The length of Vector B, which must be identical with colA
 * @param[out] vecC Vector result from multiplication between Matrix A and 
 *                  Vector B with a length equals to rowA */
void sgemv( float **matA, int rowA, int colA, float *vecB, int sizeB, 
            float *vecC );

/*!@brief Multiply a matrix and a vector in single floating point precision
 * @param[in] matA  Matrix A which is represented as a one-dimensional array
 * @param[in] rowA  Row size of Matrix A
 * @param[in] colA  Column size of Matrix A
 * @param[in] vecB  Vector B
 * @param[in] sizeB The length of Vector B, which must be identical with colA
 * @param[out] vecC Vector result from multiplication between Matrix A and 
 *                  Vector B with a length equals to rowA */
void sgemv( float *matA, int rowA, int colA, float *vecB, int sizeB, 
            float *vecC );

/*!@brief Calculate the dot product between two vectors of the same length using 
 *        double floating point precision  
 * @param[in] vecA  Vector A
 * @param[in] vecB  Vector B
 * @param[in] size  Length of the vector
 * @param[in] alpha Scaling factor of Vector A (default to 1.0)
 * @param[in] beta  Scaling factor of Vector B (default to 1.0)
 * @return Scalar number from multiplication between two vectors */
double ddot( double *vecA, double *vecB, int size, 
             double alpha=1.0, double beta=1.0 );

// TODO: Coming soon
double ddot_async( double *vecA, double *vecB, int size, 
                   double alpha=1.0, double beta=1.0 );

/*!@brief Calculate the dot product between two vectors of the same length using 
 *        single floating point precision  
 * @param[in] vecA  Vector A
 * @param[in] vecB  Vector B
 * @param[in] size  Length of the vector
 * @param[in] alpha Scaling factor of Vector A (default to 1.0)
 * @param[in] beta  Scaling factor of Vector B (default to 1.0)
 * @return Scalar number from multiplication between two vectors */
float sdot( float *vecA, float *vecB, int size,
            float alpha=1.0, float beta=1.0 );

// TODO: Coming soon
float sdot_async( float *vecA, float *vecB, int size, 
                  float alpha=1.0, float beta=1.0 );

/*!@brief Perform y = ax + y operation in double floating point precision
 * @param[in] x     The first vector 
 * @param[in] y     The second vector which also doubles as the return value
 * @param[in] size  Length of the vector
 * @param[in] alpha Scaling factor of the first vector (default to 1.0) */
void daxpy( double *x, double *y, int size, double alpha=1.0 );

// TODO: Coming soon
void daxpy_async( double *x, double *y, int size, double alpha=1.0 );

/*!@brief Perform y = ax + y operation in single floating point precision
 * @param[in] x     The first vector 
 * @param[in] y     The second vector which also doubles as the return value
 * @param[in] size  Length of the vector
 * @param[in] alpha Scaling factor of the first vector (default to 1.0) */
void saxpy( float *x, float *y, int size, float alpha=1.0 );

// TODO: Coming soon
void saxpy_async( float *x, float *y, int size, float alpha=1.0 );

#endif
