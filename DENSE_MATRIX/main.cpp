#include <cstdio>
#include "matrix.hpp"

const unsigned long int size = 5;
const unsigned long int N = size*size;

int main(int argc, char *argv[]){

	HomogeneousMat Single;

	REAL *A, *B, *C; 
	A = (REAL*)malloc(N*sizeof(REAL));
	B = (REAL*)malloc(N*sizeof(REAL));
	C = (REAL*)malloc(N*sizeof(REAL));

	Single.generateMat(A,size);
	Single.printMat(A,size);
	printf("\n");

	Single.generateMat(B,size);
	Single.printMat(B,size);
	printf("\n");

	Single.mulMat(A,B,C,size);
	Single.printMat(C,size);

	free(A); free(B); free(C);
	return 0;
}
