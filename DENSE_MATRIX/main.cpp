#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define REAL double
#define SIZE 64

// TODO: Random Matrix Generator

void dgemm( REAL *A, int rowA, int colA, REAL *B, int rowB, int colB, 
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

void displayMatrix(REAL *M, int row, int col){
  for (int i=0; i<row; ++i){
    for (int j=0; j<col; ++j){
      int idx = i*col + j;
      printf("%.0f ", M[idx]);
    }
    printf("\n");
  }
}

int main(int argc, char *argv[]){
  REAL *A = (REAL*)calloc(SIZE, sizeof(REAL));
  REAL *B = (REAL*)calloc(SIZE, sizeof(REAL)); 
  REAL *C = (REAL*)calloc(SIZE, sizeof(REAL));

  for (int i=0; i<SIZE; ++i){
    A[i] = 1.0;
    B[i] = (REAL)i;
    C[i] = 0.0;
  }

  int side = sqrt(SIZE);
  displayMatrix(A, side, side);
  printf("\n");
  displayMatrix(B, side, side);
  
  dgemm(A, side, side, B, side, side, C);
  
  printf("\n");
  displayMatrix(C, side, side);
  
  free(A); free(B); free(C);
  return 0;
}
