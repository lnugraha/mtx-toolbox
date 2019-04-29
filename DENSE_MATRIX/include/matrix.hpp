#ifndef MATRIX_HPP_
#define MATRIX_HPP_


#include <iostream>
#include <cmath>
#include <ctime>
#define REAL double

class SquareDenseMat{
  private:

  public:
	virtual void generateMat(REAL* MTX, unsigned long int size, REAL alpha=1.) = 0;
	void printMat(REAL* MTX, unsigned long int size);
	void mulMat(REAL *A, REAL *B, REAL *C, unsigned long int size);
	void addMat(REAL *A, REAL *B, REAL *C, unsigned long int size);
};

class DiagonalMat: public SquareDenseMat{
  private:

  public:
	void generateMat(REAL* MTX, unsigned long int size, REAL alpha=1.);
};

class HomogeneousMat: public SquareDenseMat{
  private:

  public:
	virtual void generateMat(REAL* MTX, unsigned long int size, REAL alpha=1.);
};

class RandomMat: public SquareDenseMat{
  private:

  public:
	virtual void generateMat(REAL* MTX, unsigned long int size, REAL alpha=1.);
};
#endif
