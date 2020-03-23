#include "DenseMatrix.hpp"
#include <math.h>

#define REAL double
#define SIZE 64

int main(int argc, char *argv[]){
  int side = sqrt(SIZE);
  REAL *A = (REAL*)calloc(SIZE, sizeof(REAL));
  REAL *B = (REAL*)calloc(SIZE, sizeof(REAL)); 
  REAL *C = (REAL*)calloc(SIZE, sizeof(REAL));

  REAL **X = (REAL **)calloc(side, sizeof(REAL *)); // row then column
  for (int i=0; i<side; ++i) X[i] = (REAL *)calloc(side, sizeof(REAL));
  REAL **Y = (REAL **)calloc(side, sizeof(REAL *)); // row then column
  for (int i=0; i<side; ++i) Y[i] = (REAL *)calloc(side, sizeof(REAL));
  REAL **Z = (REAL **)calloc(side, sizeof(REAL *)); // row then column
  for (int i=0; i<side; ++i) Z[i] = (REAL *)calloc(side, sizeof(REAL));

  for (int i=0; i<SIZE; ++i) C[i] = 0.0;

  randMatrix(A, side, side);
  randMatrix(B, side, side);

  dgemm(A, side, side, B, side, side, C);
  printf("\nDisplaying Matrix Multiplication Result:\n");
  displayMatrix(C, side, side);
  
#if 0
  for (int i=0; i<side; ++i){
    for (int j=0; j<side; ++j){
      Z[i][j] = 0.0;
    }
  }  
  randMatrix(X, side, side);
  randMatrix(Y, side, side);
  dgemm(X, side, side, Y, side, side, Z);
  displayMatrix(Z, side, side);
#endif
  free(A); free(B); free(C);
  for (int i=0; i<side; ++i){
    free(X[i]); free(Y[i]); free(Z[i]);
  }
  free(X); free(Y); free(Z);
  return 0;
}
