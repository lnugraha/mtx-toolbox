#include "DenseMatrix.hpp"

template<typename T>
static T randReal(T min = 0.0, T max = 1.0){
  std::random_device seed;
  std::mt19937 engine( seed() );
  std::uniform_real_distribution<T> dist(min, max);
  return dist( engine );
}

REAL* allocateOneDim(int size){
  REAL *A;
  if ( ( (REAL*)calloc(size, sizeof(REAL)) ) == NULL ){
    std::cerr << "ERROR: Insufficient memory allocation\n";
    exit(1);
  } 
  return A;
}

REAL** allocateTwoDim(int row, int col){
  REAL **A;

  return A;
}

void randMatrix(REAL *A, int row, int col){
  for (int i=0; i<row; ++i){
    for (int j=0; j<col; ++j){
      int idx = i*col + j;
      A[idx] = randReal<REAL>();
    }
  }
}

void randMatrix(REAL **A, int row, int col){
  for (int i=0; i<row; ++i)
  {
    for (int j=0; j<col; ++j) A[i][j] = randReal<REAL>();
  }
}

void randVector(REAL *A, int size){
  for (int i=0; i<size; ++i) A[i] = randReal<REAL>();
}

void dgemm( double **A, int rowA, int colA, 
            double **B, int rowB, int colB, 
            double **C, double alpha, double beta, double gamma)
{
  if (colA != rowB){
    printf("ERROR: Inconsistent number of rows and columns"); exit(1);
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

void dgemm( double *A, int rowA, int colA, 
            double *B, int rowB, int colB, 
            double *C, double alpha, double beta, double gamma)
{
  if (colA != rowB){
    printf("ERROR: Inconsistent number of rows and columns"); exit(1);
  }
  for (int i=0; i<rowA; ++i){
    for (int k=0; k<colB; ++k){
      double sum = 0.0;
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

// TODO optimized dgemm
// void dgemm_opt(){
// ijk-form
// for i = 1 to M{
//  for j = 1 to N{
//    c[i][j] = 0.0
//    for k = 1 to P{
//      c[i][j] += a[i][k]*b[k][j]
//    }
//  }
// }
//
// jki-form
// for j = 1 to N{
//  for i = 1 to M
//    c[i][j] = 0.0;
//  for k = 1 to P{
//    for i = 1 to M{
//      c[i][j] += a[i][k]*b[k][j]
//    }
//  }
// }

void dgemm_opt( double **A, int rowA, int colA, double **B, int rowB, int colB, 
                double **C, double alpha, double beta, double gamma )
{
  if (colA != rowB){
    printf("ERROR: Inconsistent number of rows and columns"); exit(1);
  }
  for (int j=0; j<colB; ++j){
    for (int i=0; i<rowA; ++i){ 
      C[i][j] = 0.0; 
    } // END-FOR i

    for (int k=0; k<rowB; ++k){
      for (int i=0; i<rowA; ++i){
        C[i][j] += (alpha*A[i][k]) * (beta*B[k][j]);
      } // END-FOR i
    } // END-FOR k
  } // END-FOR j
}

void sgemm( float **A, int rowA, int colA, float **B, int rowB, int colB, 
            float **C, float alpha, float beta, float gamma )
{
  if (colA != rowB){
    printf("ERROR: Inconsistent number of rows and columns"); exit(1);
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

void sgemm( float *A, int rowA, int colA, float *B, int rowB, int colB, 
            float *C, float alpha, float beta, float gamma )
{
  if (colA != rowB){
    printf("ERROR: Inconsistent number of rows and columns"); exit(1);
  }
  for (int i=0; i<rowA; ++i){
    for (int k=0; k<colB; ++k){
      float sum = 0.0;
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

// TODO: GTEST
void dgemv( double **matA, int rowA, int colA, double *vecB, int sizeB, 
            double *vecC )
{
  if (colA != sizeB){
    printf("ERROR: Inconsistent number of rows and columns"); exit(1);
  }
  for (int i=0; i<rowA; ++i){
    double sum = 0.0;
    for (int j=0; j<sizeB; ++j){
      sum += matA[i][j] * vecB[j];
    } // END-FOR j
    vecC[i] = sum;
  } // END-FOR i
}

// TODO: GTEST
void dgemv( double *matA, int rowA, int colA, double *vecB, int sizeB, 
            double *vecC )
{
  if (colA != sizeB){
    printf("ERROR: Inconsistent number of rows and columns"); exit(1);
  }
  for (int i=0; i<rowA; ++i){
    double sum = 0.0;
    for (int j=0; j<sizeB; ++j){
      int idx = i*colA + j;
      sum += matA[idx] * vecB[j];
    } // END-FOR j
    vecC[i] = sum;
  } // END-FOR i
}

// TODO: GTEST
void sgemv( float **matA, int rowA, int colA, float *vecB, int sizeB, 
            float *vecC )
{
  if (colA != sizeB){
    printf("ERROR: Inconsistent number of rows and columns"); exit(1);
  }
  for (int i=0; i<rowA; ++i){
    float sum = 0.0;
    for (int j=0; j<sizeB; ++j){
      sum += matA[i][j] * vecB[j];
    } // END-FOR j
    vecC[i] = sum;
  } // END-FOR i
}

// TODO: GTEST
void sgemv( float *matA, int rowA, int colA, float *vecB, int sizeB, 
            float *vecC )
{
  if (colA != sizeB){
    printf("ERROR: Inconsistent number of rows and columns"); exit(1);
  }
  for (int i=0; i<rowA; ++i){
    double sum = 0.0;
    for (int j=0; j<sizeB; ++j){
      int idx = i*colA + j;
      sum += matA[idx] * vecB[j];
    } // END-FOR j
    vecC[i] = sum;
  } // END-FOR i
}

// TODO: GTEST
double ddot( double *vecA, double *vecB, int size, double alpha, double beta )
{
  double product = 0.0;
  for (int i=0; i<size; ++i){
    product += (alpha*vecA[i]) * (beta*vecB[i]);
  }
  return product;
}

// TODO: GTEST
float sdot( float *vecA, float *vecB, int size, float alpha, float beta )
{
  float product = 0.0;
  for (int i=0; i<size; ++i){
    product += (alpha*vecA[i]) * (beta*vecB[i]);
  }
  return product;
}

// TODO: GTEST
void daxpy( double *x, double *y, int size, double alpha)
{ for (int i=0; i<size; ++i) y[i] += alpha*x[i]; }

// TODO: GTEST
void saxpy( float *x, float *y, int size, float alpha)
{ for (int i=0; i<size; ++i) y[i] += alpha*x[i]; }

