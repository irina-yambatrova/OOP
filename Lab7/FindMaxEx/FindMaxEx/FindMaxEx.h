#pragma once
#include <vector>
#include <string>


template < typename T, typename Less>
bool FindMaxEx(std::vector<T> const & arr, T & maxValue, Less const & less)
{
	if (arr.empty())
	{
		return false;
	}
	T maxValueInArr = arr[0];
	for (size_t i = 1; i < arr.size(); i++)
	{
		if (less(maxValueInArr, arr[i]))
		{
			maxValueInArr = arr[i];
		}
	}
	maxValue = maxValueInArr;
	return true;
}

