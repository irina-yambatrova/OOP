#include "stdafx.h"

#include <boost/test/test_case_template.hpp>
#include <boost/mpl/list.hpp>
#include "../FindMaxEx/FindMaxEx.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(Tests)

struct Sportsman
{
	std::string FIO;
	int	growth;
	int	weight;
};

BOOST_AUTO_TEST_CASE(check_int)
{
	int maxValue;
	std::vector<int> intArr = { -9, -1, 0, 1, 2, 3, 5, 6, 7, 8, 9 };
	BOOST_CHECK(FindMax(intArr, maxValue));
	BOOST_CHECK_EQUAL(maxValue, 9);
}

BOOST_AUTO_TEST_CASE(check_string)
{
	std::string maxValueString;
	std::vector<std::string> arr = { "one", "two", "three" };
	BOOST_CHECK(FindMax(arr, maxValueString));
	BOOST_CHECK_EQUAL(maxValueString, "three");
}

BOOST_AUTO_TEST_CASE(Check_max_growth)
{
	std::vector<Sportsman> atlets = { { "ivanov", 190, 100 },{ "sidorov", 180, 95 },{ "petrov", 185, 95 } };
	Sportsman maxValue;
	FindMaxEx(atlets, maxValue, [](const Sportsman & firstMan, const Sportsman & secondMan) { return firstMan.growth < secondMan.growth; });
	BOOST_CHECK_EQUAL(maxValue.growth, 190);
}

BOOST_AUTO_TEST_CASE(Check_max_weight)
{
	
	std::vector<Sportsman> atlets = { { "ivanov", 190, 100 },{ "sidorov", 180, 95 },{ "petrov", 185, 95 } };
	Sportsman maxValue;
	FindMaxEx(atlets, maxValue, [](const Sportsman & firstMan, const Sportsman & secondMan) { return firstMan.weight < secondMan.weight; });
	BOOST_CHECK_EQUAL(maxValue.weight, 100);
}

BOOST_AUTO_TEST_SUITE_END()