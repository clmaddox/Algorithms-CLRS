#define BOOST_TEST_MODULE InsertionSortTest
#include <boost/test/unit_test.hpp>
#include <boost/timer/timer.hpp>
#include <insertionSort.hpp>
#include <iostream>

BOOST_AUTO_TEST_SUITE(insertionSortTests)

BOOST_AUTO_TEST_CASE(integer_test)
{
  boost::timer::auto_cpu_timer t("\nintegers:\n %ws wall, %us user + %ss system = %ts CPU (%p%)\n");
  const static vector<int> expected{0,1,2,3,4};
  vector<int> testObject{4,3,0,1,2};
  /* Debug Statement: leaving for future copy pasta
  for(auto num : insertion_sort(testObject)){
    cout << num << endl;
  } */
  BOOST_CHECK( insertion_sort(testObject) == expected );
}

BOOST_AUTO_TEST_CASE(integer_backwards_test)
{
  boost::timer::auto_cpu_timer t("\nintegers backwards:\n %ws wall, %us user + %ss system = %ts CPU (%p%)\n");
  const static vector<int> expected{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
  vector<int> testObject{20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};
  BOOST_CHECK( insertion_sort(testObject) == expected );
}

BOOST_AUTO_TEST_CASE(double_test)
{
  boost::timer::auto_cpu_timer t("\ndoubles:\n %ws wall, %us user + %ss system = %ts CPU (%p%)\n");
  const static vector<double> expected{0.5, 1.2, 1.4, 3.14, 4.6};
  vector<double> testObject{1.4, 3.14, 0.5, 1.2, 4.6};
  BOOST_CHECK( insertion_sort(testObject) == expected );
}

BOOST_AUTO_TEST_CASE(letters_test)
{
  boost::timer::auto_cpu_timer t("\nletters\n %ws wall, %us user + %ss system = %ts CPU (%p%)\n");
  const static vector<char> expected{'a','b','c','d','e'};
  vector<char> testObject{'d','c','a','e','b'};
  BOOST_CHECK( insertion_sort(testObject) == expected );
}

BOOST_AUTO_TEST_SUITE_END( )
