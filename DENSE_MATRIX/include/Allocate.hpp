#ifndef ALLOCATE_HPP_ 
#define ALLOCATE_HPP_

#include <cstdio>
#include <cstdlib>
#include <iostream>

#ifndef REAL 
#define REAL double
#endif

/*!@brief Allocate an array of numbers using one-dimensional (vector) format
 * @note Do not forget to deallocate this array to prevent memory leak
 * @param[in] The number of the allocated data
 * @return The allocated array stored in REAL data type */
REAL* allocateOneDim(int size);

/*!@brief Allocate an array of numbers using two-dimensional (matrix) format
 * @note Do not forget to deallocate this array to prevent memory leak
 * @param[in] row The number of rows of the allocated data
 * @param[in] col The number of columns of the allocated data
 * @return The allocated array stored in REAL data type */
REAL** allocateTwoDim(int row, int col);

#endif
