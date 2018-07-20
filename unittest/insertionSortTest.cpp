#define BOOST_TEST_MODULE InsertionSortTest
#include <boost/test/unit_test.hpp>
#include <boost/timer/timer.hpp>
#include <insertionSort.hpp>
#include <iostream>

BOOST_AUTO_TEST_SUITE(insertionSortTests)

BOOST_AUTO_TEST_CASE(vector_int_test)
{
  boost::timer::auto_cpu_timer t("\nvector integers:\n %ws wall, %us user + %ss system = %ts CPU (%p%)\n");
  const static vector<int> expected{0,1,2,3,4};
  vector<int> testObject{4,3,0,1,2};
  insertion_sort(testObject.begin(), testObject.end());
  //Debug Statement: leaving for future copy pasta
  // for(auto num : testObject){
  //   cout << num << " ";
  // }
  BOOST_CHECK( testObject == expected );
}

BOOST_AUTO_TEST_CASE(vector_int_backwards_test)
{
  boost::timer::auto_cpu_timer t("\nvector integers backwards:\n %ws wall, %us user + %ss system = %ts CPU (%p%)\n");
  const static vector<int> expected{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
  vector<int> testObject{20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};
  insertion_sort(testObject.begin(), testObject.end());
  BOOST_CHECK( testObject == expected );
}

BOOST_AUTO_TEST_CASE(vector_double_test)
{
  boost::timer::auto_cpu_timer t("\nvector doubles:\n %ws wall, %us user + %ss system = %ts CPU (%p%)\n");
  const static vector<double> expected{0.5, 1.2, 1.4, 3.14, 4.6};
  vector<double> testObject{1.4, 3.14, 0.5, 1.2, 4.6};
  insertion_sort(testObject.begin(), testObject.end());
  BOOST_CHECK( testObject == expected );
}

BOOST_AUTO_TEST_CASE(vector_letter_test)
{
  boost::timer::auto_cpu_timer t("\nvector letters\n %ws wall, %us user + %ss system = %ts CPU (%p%)\n");
  const static vector<char> expected{'a','b','c','d','e'};
  vector<char> testObject{'d','c','a','e','b'};
  insertion_sort(testObject.begin(), testObject.end());
  BOOST_CHECK( testObject == expected );
}

BOOST_AUTO_TEST_CASE(string_test)
{
  boost::timer::auto_cpu_timer t("\nstring\n %ws wall, %us user + %ss system = %ts CPU (%p%)\n");
  const static string expected("affjjkoopsww");
  string testObject("askjfoowpwjf");
  insertion_sort(testObject.begin(), testObject.end());
  // cout << testObject << endl;
  // cout << expected << endl;
  BOOST_CHECK( testObject.compare(expected) == 0 );
}

BOOST_AUTO_TEST_CASE(array_int_test)
{
  boost::timer::auto_cpu_timer t("\narray integers:\n %ws wall, %us user + %ss system = %ts CPU (%p%)\n");
  const static int expected[] = {0,1,2,3,4};
  int testObject[] = {4,3,0,1,2};
  int sizeTestObj = sizeof(testObject)/sizeof(*testObject);
  insertion_sort(testObject, testObject+sizeTestObj);
  // Debug Statement: leaving for future copy pasta
  for(int i = 0; i < sizeTestObj; ++i){
    // cout << testObject[i] << " ";
    BOOST_CHECK( testObject[i] == expected[i] );
  }
}

BOOST_AUTO_TEST_SUITE_END( )
