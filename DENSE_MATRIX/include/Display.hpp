#ifndef DISPLAY_HPP_
#define DISPLAY_HPP_

#include <iostream>

/*!@brief Print to check whether the matrix is according to expectation
 * @param[in] M   Matrix M that is stored as a two-dimensional array
 * @param[in] row Row size of the matrix
 * @param[in] col Column size of the matrix */
void displayMatrix(double **M, int row, int col);

/*!@brief Print to check whether the matrix is according to expectation
 * @param[in] M   Matrix M that is stored as a one-dimensional array
 * @param[in] row Row size of the matrix
 * @param[in] col Column size of the matrix */
void displayMatrix(double *M, int row, int col);

/*!@brief Print to check whether the vector is according to expectation
 * @param[in] A     Vector A that is stored as a one-dimensional array
 * @param[in] size  Length of the vector */
void displayVector(double *A, int size);

#endif
