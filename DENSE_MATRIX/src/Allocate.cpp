#include "Allocate.hpp"

REAL* allocateOneDim(int size){
  REAL *A;
  if ( ( A=(REAL*)calloc(size, sizeof(REAL)) ) == NULL ){
    std::cerr << "ERROR: Insufficient memory allocation\n";
    exit(1);
  } 
  return A;
}

REAL** allocateTwoDim(int row, int col){
  REAL **A;
  if ( (A=(REAL**)calloc( row, sizeof(REAL) ) )==NULL ){
    std::cerr << "ERROR: Insufficient memory allocation\n";
    exit(1);
  }

  if ( (A[0]=(REAL*)calloc( (row*col),sizeof(REAL) ) )==NULL ){
    std::cerr << "ERROR: Insufficient memory allocation\n";
    exit(1);
  }
  return A;
}
