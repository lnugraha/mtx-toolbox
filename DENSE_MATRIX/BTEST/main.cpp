#include <iostream>
#include <boost/test/unit_test.hpp>

#define BOOST_TEST_MODULE custom_main
#define BOOST_TEST_NO_MAIN
#define BOOST_TEST_ALTERNATIVE_API

int add(int x, int y);

BOOST_AUTO_TEST_SUITE( boost_test_suite )

BOOST_AUTO_TEST_CASE( test_case_00 )
{
  BOOST_CHECK_EQUAL(2, 2);
  
  // Seven ways to check and report errors
  BOOST_CHECK( add(2,3) == 5 );
  BOOST_REQUIRE( add(2,3) == 5 );

  // if ( add(2,3) != 5 ) BOOST_ERROR("Incorrect answer");
  // if ( add(2,3) != 5 ) BOOST_FAIL("Incorrect answer");
  // if ( add(2,3) != 5 ) throw "Incorrect answer";
  
  BOOST_CHECK_MESSAGE( add(2,3) == 5, "add(...) result: " << add(2,3) );
  BOOST_CHECK_EQUAL( add(2,3), 5);

}

BOOST_AUTO_TEST_SUITE_END()

bool init_unit_test(){ return true; }

int main(int argc, char **argv){ 
  return boost::unit_test::unit_test_main( &init_unit_test, argc, argv ); 
} 

int add(int x, int y) { return (x + y); }
