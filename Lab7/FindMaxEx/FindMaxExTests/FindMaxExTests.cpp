#include "stdafx.h"
#define BOOST_TEST_MODULE Tests
#include <boost/test/unit_test.hpp>
#include "../FindMaxEx/FindMaxEx.h"

struct Sportsman
{
	std::string FIO;
	int	growth;
	int	weight;
};

struct MockThrowsWhenCopy
{
	MockThrowsWhenCopy()
	{}

	~MockThrowsWhenCopy()
	{}

	MockThrowsWhenCopy(MockThrowsWhenCopy const& val)
	{
		if (!copied)
		{
			copied = true;
			return;
		}
		throw std::exception("cannot copy this object");
	}

	MockThrowsWhenCopy(MockThrowsWhenCopy && val)
	{	
		
		throw std::exception("cannot move this object");
	}

	MockThrowsWhenCopy operator=(MockThrowsWhenCopy const& val)
	{
		throw std::exception("cannot assign this object");
	}
	
	bool operator<(MockThrowsWhenCopy const& val)const
	{
		throw std::exception("cannot compare this object");
	}

private:
	bool copied = false;
};

bool LessByInt(int const& leftArg, int const& rightArg)
{
	return leftArg < rightArg;
}

bool Less(MockThrowsWhenCopy const& leftArg, MockThrowsWhenCopy const& rightArg)
{
	return leftArg < rightArg;
}

bool LessByString(std::string const& leftArg, std::string const& rightArg)
{
	return leftArg.length() < rightArg.length();
}


BOOST_AUTO_TEST_SUITE(Tests)
	
	BOOST_AUTO_TEST_CASE(guarantees_strong_exception_safety_first)
	{
		std::vector<MockThrowsWhenCopy> data = { MockThrowsWhenCopy{}, MockThrowsWhenCopy{} };
		MockThrowsWhenCopy maxValue;
		BOOST_REQUIRE_THROW(FindMaxEx(data, maxValue, Less), std::exception);
	}

	BOOST_AUTO_TEST_CASE(guarantees_strong_exception_safety_second)
	{
		std::vector<MockThrowsWhenCopy> data = { MockThrowsWhenCopy{}, MockThrowsWhenCopy{} };
		MockThrowsWhenCopy maxValue;
		auto oldAddr = std::addressof(maxValue);

		BOOST_REQUIRE_THROW(FindMaxEx(data, maxValue, Less), std::exception);

		auto currentAddr = std::addressof(maxValue);

		BOOST_REQUIRE(oldAddr == currentAddr);
	}

	BOOST_AUTO_TEST_CASE(check_empty_vector)
	{
		int maxValue;
		std::vector<int> arr;
		BOOST_CHECK(!FindMaxEx(arr, maxValue, LessByInt));
	}

	BOOST_AUTO_TEST_CASE(check_one_element_int)
	{
		int maxValue;
		std::vector<int> arr = { 3 };
		BOOST_CHECK(FindMaxEx(arr, maxValue, LessByInt));
		BOOST_CHECK_EQUAL(maxValue, 3);
	}

	BOOST_AUTO_TEST_CASE(check_max_int)
	{
		int maxValue;
		std::vector<int> intArr = { -1, 0, 1, 2, 3, 5, 6, 7, 8, 9 };
		BOOST_REQUIRE_NO_THROW(FindMaxEx(intArr, maxValue, LessByInt));
		BOOST_CHECK(FindMaxEx(intArr, maxValue, LessByInt));
		BOOST_CHECK_EQUAL(maxValue, 9);
	}

	BOOST_AUTO_TEST_CASE(check_one_element_of_type_string)
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