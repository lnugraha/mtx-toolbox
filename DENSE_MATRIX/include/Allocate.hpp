#ifndef ALLOCATE_HPP_ 
#define ALLOCATE_HPP_

#include <cstdio>
#include <cstdlib>
#include <iostream>

#ifndef REAL 
#define REAL double
#endif

REAL* allocateOneDim(int size);

REAL** allocateTwoDim(int row, int col);

#endif
