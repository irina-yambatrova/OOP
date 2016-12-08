#include "stdafx.h"
#define BOOST_TEST_MODULE Tests
#include <boost/test/unit_test.hpp>
#include <boost/test/test_case_template.hpp>
#include <boost/mpl/list.hpp>
#include "../FindMaxEx/FindMaxEx.h"

using namespace std;

struct Sportsman
{
	std::string FIO;
	int	growth;
	int	weight;
};

bool LessByInt(int const& leftArg, int const& rightArg)
{
	return leftArg < rightArg;
}

bool LessByString(std::string const& firstArg, std::string const& secondArg)
{
	return firstArg.length() < secondArg.length();
}


BOOST_AUTO_TEST_SUITE(Tests)
	

	BOOST_AUTO_TEST_CASE(guarantees_strong_exception_safety)
	{
		size_t callCount = 0;
		auto func = [&](auto const& num1, auto const& num2)
		{
			if (callCount == 2)
			{
				throw std::runtime_error("Error!");
			}
			callCount++;
			return num1 < num2;
		};

		int max = 0;
		try
		{
			FindMaxEx({ 1, 2, 3, 4, 5 }, max, func);
		}
		catch (...) {};
		BOOST_CHECK(max != 3);
		BOOST_CHECK(max == 0);

	}
	BOOST_AUTO_TEST_CASE(check_empty_vector)
	{
		int maxValue;
		vector<int> arr;
		BOOST_CHECK(!FindMaxEx(arr, maxValue, LessByInt));
	}

	BOOST_AUTO_TEST_CASE(check_one_element_int)
	{
		int maxValue;
		vector<int> arr = { 3 };
		BOOST_CHECK(FindMaxEx(arr, maxValue, LessByInt));
		BOOST_CHECK_EQUAL(maxValue, 3);
	}

	BOOST_AUTO_TEST_CASE(check_int)
	{
		int maxValue;
		std::vector<int> intArr = { -1, 0, 1, 2, 3, 5, 6, 7, 8, 9 };
		BOOST_REQUIRE_NO_THROW(FindMaxEx(intArr, maxValue, LessByInt));
		BOOST_CHECK(FindMaxEx(intArr, maxValue, LessByInt));
		BOOST_CHECK_EQUAL(maxValue, 9);
	}

	BOOST_AUTO_TEST_CASE(check_one_element_string)
	{
		std::string maxValueString;
		std::vector<std::string> stringArr = { "one" };
		BOOST_CHECK(FindMaxEx(stringArr, maxValueString, LessByString));
		BOOST_CHECK_EQUAL(maxValueString, "one");
	}

	BOOST_AUTO_TEST_CASE(check_string)
	{
		std::string maxValueString;
		std::vector<std::string> stringArr = { "one", "two", "three" };
		BOOST_CHECK(FindMaxEx(stringArr, maxValueString, LessByString));
		BOOST_CHECK_EQUAL(maxValueString, "three");
	}

	BOOST_AUTO_TEST_CASE(Check_max_weight)
	{
	
		std::vector<Sportsman> atlets = { { "ivanov", 190, 100 },{ "sidorov", 180, 95 },{ "petrov", 185, 95 } };
		Sportsman maxValue;
		FindMaxEx(atlets, maxValue, [](const Sportsman & firstMan, const Sportsman & secondMan) { return firstMan.weight < secondMan.weight; });
		BOOST_CHECK_EQUAL(maxValue.weight, 100);
	}

	BOOST_AUTO_TEST_CASE(Check_max_growth)
	{
		std::vector<Sportsman> atlets = { { "ivanov", 190, 100 },{ "sidorov", 180, 95 },{ "petrov", 185, 95 } };
		Sportsman maxValue;
		FindMaxEx(atlets, maxValue, [](const Sportsman & firstMan, const Sportsman & secondMan) { return firstMan.growth < secondMan.growth; });
		BOOST_CHECK_EQUAL(maxValue.growth, 190);
	}

	
BOOST_AUTO_TEST_SUITE_END()