
#include "stdafx.h"
#include  "../multmatrix/multmatrix.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(multmatrix_function)

BOOST_AUTO_TEST_CASE(check_result_of_multiplication_on_zero_matrix)
{
	vector<vector<double>> expectedMatrix = { {0, 0, 0}, {0, 0, 0},{0, 0, 0} };
	
	BOOST_CHECK(MultiplicationOfMatrix("FirstFileForFirstCheck.txt", "SecondFileForFirstCheck.txt") == expectedMatrix);
};

BOOST_AUTO_TEST_CASE(check_result_of_multiplication_two_matrix)
{
	vector<vector<double>> expectedMatrix ={ {22, 28, 21 },{30, 40, 33 },{43, 58, 49 } };

	BOOST_CHECK(MultiplicationOfMatrix("FirstFileForSecondCheck.txt", "SecondFileForSecondCheck.txt") == expectedMatrix);
};

BOOST_AUTO_TEST_CASE(check_result_of_multiplication_matrix_from_empty_file)
{
	vector<vector<double>> expectedMatrix = { { 0, 0, 0 },{ 0, 0, 0 },{ 0, 0, 0 } };
	BOOST_CHECK(MultiplicationOfMatrix("FirstFileForThirdCheck.txt", "SecondFileForThirdCheck.txt") == expectedMatrix);
};
BOOST_AUTO_TEST_SUITE_END()


