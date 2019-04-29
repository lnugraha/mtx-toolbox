#include "parallel.hpp"

void parallelMulMat::withOpenMP(REAL *A, REAL *B, REAL *C, unsigned long int size, int nthread)
{
	unsigned long int i, j, k;
	REAL sum, a, b;
	#pragma omp parallel default(none) num_threads(nthread) shared(A,B,C,size) private(i,j,k,sum,a,b)
	{
	#pragma omp for schedule(static) nowait
	for (i=0; i<size; ++i) {
		for (j=0; j<size; ++j) {
			sum = 0.0;
			for (k=0; k<size; ++k) {
				a = A[i*size+k]; 
				b = B[k*size+j];
				sum += a*b;
			}
		C[i*size+j] = sum;	
		}
	}
	}
};

void parallelMulMat::withThread(REAL *A, REAL *B, REAL *C, unsigned long int size, int nthread)
{




};

void parallelMulMat::withBoost(REAL *A, REAL *B, REAL *C, unsigned long int size, int nthread)
{




};
