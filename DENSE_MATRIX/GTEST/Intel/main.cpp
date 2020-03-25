#include "DenseMatrix.hpp"
#include <gtest/gtest.h>
#include <math.h>

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
  randMatrix(A, side, side); 
  randMatrix(B, side, side);
  // Manual Version
  dgemm(A, side, side, B, side, side, C);
  #if 0
  for (int i=0; i<side; ++i){
	  for (int j=0; j<side; ++j){
	    int idx = i*side + j;
	    EXPECT_NEAR(C_ans[idx], C[idx], TOL);
  	}
  }
  #endif
  free(A); free(B); free(C); free(C_ans);
}

int main(int argc, char *argv[]){
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}
