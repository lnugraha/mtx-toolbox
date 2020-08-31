#include <iostream>

#include <boost/test/unit_test.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/operation.hpp>

#include "DenseMatrix.hpp"

#define BOOST_TEST_MODULE custom_main
#define BOOST_TEST_NO_MAIN
#define BOOST_TEST_ALTERNATIVE_API

#ifndef REAL
#define REAL double
#endif

#define TOL 1.0e-06
const int SIZE = 100;
const int size = 10;

int add(int x, int y);

template<class T>
static T multiply(T x, T y);

// BOOST_AUTO_TEST_SUITE( boost_test_suite )

BOOST_AUTO_TEST_CASE( test_case_00 )
{
  // Seven ways to check and report errors
  // BOOST_CHECK( add(2,3) == 5 );
  // BOOST_REQUIRE( add(2,3) == 5 );
  // if ( add(2,3) != 5 ) BOOST_ERROR("Incorrect answer");
  // if ( add(2,3) != 5 ) BOOST_FAIL("Incorrect answer");
  // if ( add(2,3) != 5 ) throw "Incorrect answer";
  // BOOST_CHECK_MESSAGE( add(2,3) == 5, "add(...) result: " << add(2,3) );
  // BOOST_CHECK_EQUAL( add(2,3), 5);

  REAL *A = (REAL*) calloc (SIZE, sizeof(REAL));
  REAL *B = (REAL*) calloc (SIZE, sizeof(REAL));
  REAL *C = (REAL*) calloc (SIZE, sizeof(REAL));

  boost::numeric::ublas::matrix<double> A_bst(size, size), B_bst(size, size), 
    C_bst(size, size);

  randMatrix(A, size, size); 
  randMatrix(B, size, size);
  for (int i=0; i<SIZE; ++i) C[i] = 0.0;

  // Assign all element values to Boost matrices
  for (int i=0; i<size; ++i){
    for (int j=0; j<size; ++j){
      int idx = i*size + j;
      A_bst(i, j) = A[idx];
      B_bst(i, j) = B[idx];
    }
  }
  
  // Manual Version
  dgemm(A, size, size, B, size, size, C);
  // Boost Version
  boost::numeric::ublas::axpy_prod(A_bst, B_bst, C_bst, true);

  for (int i=0; i<size; ++i){
    for (int j=0; j<size; ++j){
      int idx = i*size + j;
      BOOST_CHECK_CLOSE(C_bst(i,j), C[idx], TOL);
    }
  }

}

BOOST_AUTO_TEST_CASE( test_case_01 )
{
  int x = 5; int y = 7; int z = add(x, y);
  BOOST_CHECK_EQUAL( z, 12 );
}

BOOST_AUTO_TEST_CASE( test_case_02 )
{
  long int x = 50; long int y = 30; 
  long int z = multiply<long int> (x, y);
  BOOST_CHECK_EQUAL(z, 1500);
}


// BOOST_AUTO_TEST_SUITE_END()

bool init_unit_test(){ return true; }
int main(int argc, char **argv){ 
  return boost::unit_test::unit_test_main( &init_unit_test, argc, argv ); 
} 

int add(int x, int y) { return (x + y); }

template<class T>
static T multiply(T x, T y)
{ return (x*y); }
