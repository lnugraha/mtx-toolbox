#include "DenseMatrix.hpp"
#include <math.h>
#include <gsl/gsl_blas.h>
#include <gtest/gtest.h>

#define REAL double
#define TOL 1.0E-06

const int SIZE = 100;

TEST(CASE_01, one_dimension_configuration){
  int side = sqrt(SIZE);
  REAL *A = (REAL*)calloc(SIZE, sizeof(REAL));
  REAL *B = (REAL*)calloc(SIZE, sizeof(REAL)); 
  REAL *C = (REAL*)calloc(SIZE, sizeof(REAL));
  REAL *C_ans = (REAL*)calloc(SIZE, sizeof(REAL));

  for (int i=0; i<SIZE; ++i){ C[i] = 0.0; C_ans[i] = 0.0; }
  
  randMatrix(A, side, side); randMatrix(B, side, side);
  
  // Manual Version
  dgemm(A, side, side, B, side, side, C);

  gsl_matrix_view A_gsl = gsl_matrix_view_array(A, side, side);
  gsl_matrix_view B_gsl = gsl_matrix_view_array(B, side, side);
  gsl_matrix_view C_gsl = gsl_matrix_view_array(C_ans, side, side);

  // GSL Version
  gsl_blas_dgemm(CblasNoTrans, CblasNoTrans, 1.0, &A_gsl.matrix, &B_gsl.matrix, 
  0.0, &C_gsl.matrix);

  for (int i=0; i<side; ++i){
	  for (int j=0; j<side; ++j){
	    int idx = i*side + j;
	    EXPECT_NEAR(C_ans[idx], C[idx], TOL);
  	} // END-FOR j
  } // END-FOR i
  free(A); free(B); free(C); free(C_ans);
}

TEST(CASE_02, two_dimension_configuration){
  int side = sqrt(SIZE);
  REAL **X = (REAL **)calloc(side, sizeof(REAL *)); // row then column
  for (int i=0; i<side; ++i) X[i] = (REAL *)calloc(side, sizeof(REAL));
  REAL **Y = (REAL **)calloc(side, sizeof(REAL *)); // row then column
  for (int i=0; i<side; ++i) Y[i] = (REAL *)calloc(side, sizeof(REAL));
  REAL **Z = (REAL **)calloc(side, sizeof(REAL *)); // row then column
  for (int i=0; i<side; ++i) Z[i] = (REAL *)calloc(side, sizeof(REAL));

  randMatrix(X, side, side); randMatrix(Y, side, side);
  dgemm(X, side, side, Y, side, side, Z);

  for (int i=0; i<side; ++i){
    free(X[i]); free(Y[i]); free(Z[i]);
  }
  free(X); free(Y); free(Z);
}

TEST(CASE_03, matrix_vector_multiplication){
  int side = sqrt(SIZE);
  REAL *A = (REAL*)calloc(SIZE, sizeof(REAL)); // matrix
  REAL *B = (REAL*)calloc(side, sizeof(REAL)); // vector 
  REAL *C = (REAL*)calloc(side, sizeof(REAL)); // vector [result]
  REAL *C_ans = (REAL*)calloc(side, sizeof(REAL)); // vector [result]

  for (int i=0; i<side; ++i){ C[i] = 0.0; C_ans[i] = 0.0; }
  
  randMatrix(A, side, side); randVector(B, side);
  // Manual Version
  dgemv(A, side, side, B, side, C);

  gsl_matrix_view A_gsl = gsl_matrix_view_array(A, side, side);
  gsl_vector_view B_gsl = gsl_vector_view_array(B, side);
  gsl_vector_view C_gsl = gsl_vector_view_array(C_ans, side);
  // GSL Version
  // for (int i=0; i<side; ++i) EXPECT_NEAR(C_ans[i], C[i], TOL);
  free(A); free(B); free(C); free(C_ans);
}

TEST(CASE_04, dot_product){


}

TEST(CASE_05, vector_scaling){


}

int main(int argc, char *argv[]){
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}
