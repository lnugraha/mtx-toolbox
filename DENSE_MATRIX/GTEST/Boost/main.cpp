#include "DenseMatrix.hpp"
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/operation.hpp>
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

  boost::numeric::ublas::matrix<double> A_bst(side, side), B_bst(side, side), 
    C_bst(side, side);

  randMatrix(A, side, side); randMatrix(B, side, side);
  for (int i=0; i<SIZE; ++i) C[i] = 0.0;
  
  for (int i=0; i<side; ++i){
    for (int j=0; j<side; ++j){
      int idx = i*side + j;
      A_bst(i,j) = A[idx];
      B_bst(i,j) = B[idx];
    }
  }
  // Manual Version
  dgemm(A, side, side, B, side, side, C);
  // Boost Version
  boost::numeric::ublas::axpy_prod(A_bst, B_bst, C_bst, true);

  for (int i=0; i<side; ++i){
	  for (int j=0; j<side; ++j){
	    int idx = i*side + j;
	    EXPECT_NEAR(C_bst(i,j), C[idx], TOL);
  	}
  }
  free(A); free(B); free(C);
}

int main(int argc, char *argv[]){
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}
