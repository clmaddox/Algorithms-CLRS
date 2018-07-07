#define BOOST_TEST_MODULE InsertionSortTest
#include <boost/test/unit_test.hpp>
#include <insertionSort.hpp>
#include <iostream>

BOOST_AUTO_TEST_SUITE(insertionSortTests)

BOOST_AUTO_TEST_CASE(nominal_test)
{
  const static vector<int> expected{0,1,2,3,4};
  vector<int> testObject{4,3,0,1,2};
  BOOST_CHECK( insertion_sort(testObject) == expected );
}

BOOST_AUTO_TEST_CASE(backwards_test)
{
  const static vector<int> expected{0,1,2,3,4};
  vector<int> testObject{4,3,2,1,0};
  BOOST_CHECK( insertion_sort(testObject) == expected );
}
BOOST_AUTO_TEST_SUITE_END( )
