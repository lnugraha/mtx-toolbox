#include <cmath>
#include <iostream>
#include <gtest/gtest.h>
#include "DenseMatrix.hpp"

#include <mkl.h>
#include <mkl_cblas.h>

#define REAL double
#define SIZE 10000
#define TOL 10E-06

/* WARNING: Always source .sh script from Intel MKL to activate MKL
 * since neither macOS Catalina nor zsh enables automated source during 
 * terminal login */

TEST(CASE_00, TESTING){
  int side = sqrt(SIZE);

  REAL *A = (REAL*)calloc(SIZE, sizeof(REAL));
  REAL *B = (REAL*)calloc(SIZE, sizeof(REAL)); 
  REAL *C = (REAL*)calloc(SIZE, sizeof(REAL));
  REAL *C_ans = (REAL*)calloc(SIZE, sizeof(REAL));

  for (int i=0; i<SIZE; ++i){ C[i] = 0.0; C_ans[i] = 0.0; }
  randMatrix(A, side, side); 
  randMatrix(B, side, side);
  // Manual Version
  dgemm(A, side, side, B, side, side, C);
  cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, side, side, side, 1.0, A, side, B, side, 1.0, C_ans, side);
  
  // mkl_dgemm(A, side, side, B, side, side, C_ans);
  for (int i=0; i<side; ++i){
	  for (int j=0; j<side; ++j){
	    int idx = i*side + j;
	    EXPECT_NEAR(C_ans[idx], C[idx], TOL);
  	}
  }
  free(A); free(B); free(C); free(C_ans);
}

int main(int argc, char *argv[]){
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}
