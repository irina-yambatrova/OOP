#pragma once
#include <iostream>
#include <vector>

#include <algorithm>
#include <string>


template < typename T, typename Less>
bool FindMaxEx(const std::vector<T>  & arr, T & maxValue, Less const & less)
{
	if (arr.empty())
	{
		return false;
	}

	auto maxValueInArr = arr.begin();
	for (auto i = arr.begin(); i != arr.end(); ++i)
	{
		if (less(*maxValueInArr, *i))
		{
			maxValueInArr = i;
		}
	}
	maxValue = *maxValueInArr;

	return true;
}
