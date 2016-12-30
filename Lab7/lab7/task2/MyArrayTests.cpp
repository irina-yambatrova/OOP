#include "stdafx.h"
#include "MyArray.h"
#include <stdexcept>
#include <iostream>
using namespace std;


struct MyStruct
{
	CMyArray<int> arr;
};

BOOST_FIXTURE_TEST_SUITE(Array_tests, MyStruct)
	BOOST_AUTO_TEST_CASE(get_size_tests)
	{
		BOOST_CHECK_EQUAL(arr.GetSize(), 0u);
		arr.Append(0);
		BOOST_CHECK_EQUAL(arr.GetSize(), 1u);
		arr.Append(0);
		BOOST_CHECK_EQUAL(arr.GetSize(), 2u);
		arr.Append(0);
		BOOST_CHECK_EQUAL(arr.GetSize(), 3u);
	}
	
BOOST_AUTO_TEST_SUITE(after_copy_construction)
	BOOST_AUTO_TEST_CASE(has_size_capacity_equal_to_size_of_original_array)
	{
		for (auto i = 0; i < 6; ++i)
		{
			arr.Append(i);
		}
		BOOST_CHECK_NE(arr.GetSize(), arr.GetCapacity());

		auto copy(arr);
		BOOST_CHECK_EQUAL(copy.GetSize(), arr.GetSize());
		BOOST_CHECK_EQUAL(copy.GetCapacity(), arr.GetSize());
		BOOST_CHECK_EQUAL(arr.GetSize(), 6u);
		BOOST_CHECK_EQUAL(arr[2], 2);
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_CASE(assigment_cmyarray)
{
	for (auto i = 0; i < 6; ++i)
	{
		arr.Append(i);
	}
	BOOST_CHECK_EQUAL(arr.GetSize(), 6u);
	BOOST_CHECK_EQUAL(arr[1], 1);
}

BOOST_AUTO_TEST_CASE(resize_array)
{
	for (auto i = 0; i < 9; ++i)
	{
		arr.Append(i);
	}
	BOOST_CHECK_EQUAL(arr.GetSize(), 9u);
	BOOST_CHECK_EQUAL(arr.GetCapacity(), 16u);
	arr.Resize(4);
	BOOST_CHECK_EQUAL(arr.GetSize(), 4u);
	BOOST_CHECK_EQUAL(arr.GetCapacity(), 16u);
	arr.Resize(7);
	BOOST_CHECK_EQUAL(arr.GetSize(), 7u);
	BOOST_CHECK_EQUAL(arr.GetCapacity(), 16u);
	arr.Resize(12);
	BOOST_CHECK_EQUAL(arr.GetSize(), 12u);
	BOOST_CHECK_EQUAL(arr.GetCapacity(), 16u);
	arr.Resize(18);
	BOOST_CHECK_EQUAL(arr.GetSize(), 18u);
	BOOST_CHECK_EQUAL(arr.GetCapacity(), 18u);
}

BOOST_AUTO_TEST_CASE(clear_array)
{
	for (auto i = 0; i < 6; ++i)
	{
		arr.Append(i);
	}
	arr.Clear();
	BOOST_CHECK_EQUAL(arr.GetSize(), 0u);
	BOOST_CHECK_THROW(arr[2], std::out_of_range);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_CASE(assignment_operator)
{
	bool result = true;
	CMyArray<int> arr;
	CMyArray<int> arr1;
	for (auto i = 0; i < 6; ++i)
	{
		arr.Append(i);
	}
	arr1 = arr;
	for (auto i = 0; i < 6; i++)
	{
		if (arr[i] != arr1[i])
		{
			result = false;
		}
	}
	BOOST_CHECK_EQUAL(result, true);
}


BOOST_AUTO_TEST_CASE(operator_not_equal)
{
	CMyArray<int> arr5;
	bool result1 = true;
	for (auto i = 0; i < 6; ++i)
	{
		arr5.Append(i);
	}
	CMyIterator<int, false> it2 = arr5.begin();
	if (it2[1u] != it2[2u])
	{
		result1 = true;
	}
	BOOST_CHECK(result1);
}

BOOST_AUTO_TEST_CASE(operator_less)
{
	CMyArray<int> arr6;
	bool result2 = true;
	for (auto i = 0; i < 6; ++i)
	{
		arr6.Append(i);
	}
	CMyIterator<int, false> it1 = arr6.begin();
	if (it1[1u] < it1[2u])
	{
		result2 = true;
	}
	BOOST_CHECK(result2);
}

BOOST_AUTO_TEST_CASE(operator_more)
{
	CMyArray<int> arr6;
	bool result3 = true;
	for (auto i = 0; i < 6; ++i)
	{
		arr6.Append(i);
	}
	CMyIterator<int, true> it1 = arr6.rbegin();
	if (it1[1u] > it1[2u])
	{
		result3 = true;
	}
	BOOST_CHECK(result3);
}

BOOST_AUTO_TEST_CASE(minus_plus)
{
	CMyArray<int> arr;
	arr.Append(1);
	arr.Append(2);
	arr.Append(3);

	auto ptr = arr.begin();
	ptr += 1;
	BOOST_CHECK_EQUAL(*ptr, 2);
	ptr += 1;
	BOOST_CHECK_EQUAL(*ptr, 3);
	ptr -= 1;
	BOOST_CHECK_EQUAL(*ptr, 2);
}