#include "DenseMatrix.hpp"

void randMatrix(REAL *A, int row, int col){
  srand((long)time(NULL));
  for (int i=0; i<row; ++i){
    for (int j=0; j<col; ++j){
      REAL random = rand()/(REAL)RAND_MAX;
      int idx = i*col + j;
      A[idx] = random;
    }
  }
}

void randMatrix(REAL **A, int row, int col){
  srand((long)time(NULL));
  for (int i=0; i<row; ++i){
    for (int j=0; j<col; ++j){
      REAL random = rand()/(REAL)RAND_MAX;
      A[i][j] = random;
    }
  }
}

void displayMatrix(REAL **M, int row, int col){
  for (int i=0; i<row; ++i){
    for (int j=0; j<col; ++j) printf("%.2f ", M[i][j]);
    printf("\n");
  }
}

void displayMatrix(REAL *M, int row, int col){
  for (int i=0; i<row; ++i){
    for (int j=0; j<col; ++j){
      int idx = i*col + j;
      printf("%.2f ", M[idx]);
    }
    printf("\n");
  }
}

void dgemm( REAL **A, int rowA, int colA, 
            REAL **B, int rowB, int colB, 
            REAL **C, REAL alpha, REAL beta, REAL gamma)
{
  if (colA != rowB){
    printf("ERROR: Inconsistent number of rows and columns");
    exit(1);
  }
  for (int i=0; i<rowA; ++i){
    for (int k=0; k<colB; ++k){
      REAL sum = 0.0;
      for (int j=0; j<colA; ++j){
        sum += (alpha*A[i][j]) * (beta*B[j][k]);
      } // END-FOR j

    C[i][k] = gamma*sum;
    } // END-FOR k
  } // END-FOR i
}

void dgemm( REAL *A, int rowA, int colA, 
            REAL *B, int rowB, int colB, 
            REAL *C, REAL alpha, REAL beta, REAL gamma)
{
  if (colA != rowB){
    printf("ERROR: Inconsistent number of rows and columns");
    exit(1);
  }
  for (int i=0; i<rowA; ++i){
    for (int k=0; k<colB; ++k){
      REAL sum = 0.0;
      for (int j=0; j<colA; ++j){
        int idxA = i*colA + j;
        int idxB = j*rowB + k;
        sum += (alpha*A[idxA]) * (beta*B[idxB]);
      } // END-FOR j

    int idxC = i*colA + k;
    C[idxC] = gamma*sum;
    } // END-FOR k
  } // END-FOR i
}
