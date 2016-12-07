#pragma once
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>

template < typename T, typename Less>
bool FindMaxEx(std::vector<T> const & arr, T & maxValue, Less const & less)
{
	if (arr.empty())
	{
		return false;
	}
	T maxValueInArr = arr[0];
	for (int i = 1; i < arr.size(); i++)
	{
		if (less(maxValueInArr, arr[i]))
		{
			maxValueInArr = arr[i];
		}
	}
	maxValue = maxValueInArr;
	return true;
}


template < typename T >
bool FindMax(std::vector<T> const & arr, T & maxValue)
{
	if (arr.empty())
	{
		return false;
	}
	maxValue = *(std::max_element(arr.begin(), arr.end()));
	return true;
}
