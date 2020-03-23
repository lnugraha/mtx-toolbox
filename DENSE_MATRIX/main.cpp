#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define REAL double
#define SIZE 64

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

void dgemm( REAL **A, int rowA, int colA, 
            REAL **B, int rowB, int colB, 
            REAL **C, REAL alpha=1.0, REAL beta=1.0, REAL gamma=1.0 )
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
            REAL *C, REAL alpha=1.0, REAL beta=1.0, REAL gamma=1.0 )
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
  
  for (int i=0; i<side; ++i){
    for (int j=0; j<side; ++j){
      X[i][j] = 1.0;
      Y[i][j] = i*side + j;
      Z[i][j] = 0.0;
    }
  }  
  
  // dgemm(X, side, side, Y, side, side, Z);
  // displayMatrix(Z, side, side);

  free(A); free(B); free(C);
  for (int i=0; i<side; ++i){
    free(X[i]); free(Y[i]); free(Z[i]);
  }
  free(X); free(Y); free(Z);
  return 0;
}
