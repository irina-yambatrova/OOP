// vectorTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../vector/VectorProcessor.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(ProcessVector_function)

BOOST_AUTO_TEST_CASE(return_vector_with_empty_vector) 
{
	vector<double> inputVector;
	DivideNumberByHalfMaxVector(inputVector);
	BOOST_CHECK(!inputVector.size());
}; 

BOOST_AUTO_TEST_CASE(return_vector_with_different_numbers) 
{
	vector<double> inputVector = { 2, 1, 4};
	vector<double> expectedVector = { 1, 0.5, 2};
	DivideNumberByHalfMaxVector(inputVector);
	BOOST_CHECK(inputVector == expectedVector);
}; 

BOOST_AUTO_TEST_CASE(return_vector_with_identical_numbers) 
{
	vector<double> inputVector = { 4, 4, 4};
	vector<double> expectedVector = { 2, 2, 2};
	DivideNumberByHalfMaxVector(inputVector);
	BOOST_CHECK(inputVector == expectedVector);
};

BOOST_AUTO_TEST_CASE(return_vector_with_negative_numbers) 
{
	vector<double> inputVector = { -2, -2, -2 };
	vector<double> expectedVector = { 2, 2, 2 };
	DivideNumberByHalfMaxVector(inputVector);
	BOOST_CHECK(inputVector == expectedVector);
};

BOOST_AUTO_TEST_SUITE_END()



