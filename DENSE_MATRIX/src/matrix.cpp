#include "matrix.hpp"

/*!
 *@brief  One print function for all types of matrix
 *@return Print the square matrix
 */
void SquareDenseMat::printMat(REAL* MTX, unsigned long int size){
for (unsigned long int i=0; i<size; ++i) {
	for (unsigned long int j=0; j<size; ++j) {
		std::cout << MTX[i*size+j] << "   ";
	} // END-FOR j
	std::cout << std::endl;
} // END-FOR i
};

void SquareDenseMat::addMat(REAL *A, REAL *B, REAL *C, unsigned long int size)
{
for (unsigned long int i=0; i<size; ++i){
	for (unsigned long int j=0; j<size; ++j){
		C[i*size+j]= A[i*size+j]+B[i*size+j];
	} // END-FOR j
} // END-FOR i
};

void SquareDenseMat::mulMat(REAL *A, REAL *B, REAL *C, unsigned long int size)
{
for (unsigned long int i=0; i<size; ++i){
	for (unsigned long int j=0; j<size; ++j){
		REAL sum = 0.;
		for (unsigned long int k=0; k<size; ++k){
			sum += A[i*size+k]*B[k*size+j];
		} // END-FOR k
		C[i*size+j] = sum;
	} // END-FOR j
} // END-FOR i
};

void DiagonalMat::generateMat(REAL* MTX, unsigned long int size, REAL alpha){
for (unsigned long int i=0; i<size; ++i) {
	for (unsigned long int j=0; j<size; ++j) {
		unsigned long int idx = i*size + j;
		if (i==j) { 
		  MTX[idx] = alpha*1.0;
		} else {
		  MTX[idx] = 0.0;
		}
	} // END-FOR j
} // END-FOR i
};

void HomogeneousMat::generateMat(REAL* MTX, unsigned long int size, REAL alpha){
for (unsigned long int i=0; i<size; ++i){
	for (unsigned long int j=0; j<size; ++j){
		unsigned long int idx = i*size + j;
		MTX[idx] = alpha*1.0;
	} // END-FOR j
} // END-FOR i
};

void RandomMat::generateMat(REAL* MTX, unsigned long int size, REAL alpha){
for (unsigned long int i=0; i<size; ++i){
	for (unsigned long int j=0; j<size; ++j){
		unsigned long int idx = i*size + j;

		REAL random = (REAL)rand()/RAND_MAX;
		MTX[idx] = alpha*random;
	} // END-FOR j
} // END-FOR i
};

