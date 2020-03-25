#include "DenseMatrix.hpp"
#include "Timer.hpp"
#include <math.h>
#include <gsl/gsl_matrix_double.h>
#include <gsl/gsl_blas.h>

#define REAL double

int main(int argc, char *argv[]){
  const int SIZE = 1000000;
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

  randMatrix(A, side, side); randMatrix(B, side, side);

  { 
  Timer time_00;
  dgemm(A, side, side, B, side, side, C);
  }
  // printf("\nDisplaying Matrix Multiplication Result:\n");
  // displayMatrix(C, side, side);

  REAL *C_ans = (REAL*)calloc(SIZE, sizeof(REAL));
  gsl_matrix_view A_gsl = gsl_matrix_view_array(A, side, side);
  gsl_matrix_view B_gsl = gsl_matrix_view_array(B, side, side);
  gsl_matrix_view C_gsl = gsl_matrix_view_array(C_ans, side, side);

  {
  Timer time_01;
  gsl_blas_dgemm(CblasNoTrans, CblasNoTrans, 1.0, &A_gsl.matrix, &B_gsl.matrix, 
  0.0, &C_gsl.matrix);
  }
  /*
  printf("\nDisplaying Matrix Multiplication Result:\n");
  for (int i=0; i<side; ++i){
	for (int j=0; j<side; ++j){
	  int idx = i*side + j;
	  printf("%.2f ", C_ans[idx]);
	}
	printf("\n");
  }
  */

#if 0
// Matrix matrix multiplication using 2D array scenario
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
