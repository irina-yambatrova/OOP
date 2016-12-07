#include "stdafx.h"
#include <string>
#include "FindMaxEx.h"

int main()
{
	int maxValue;
	std::string maxValueString;
	std::vector<int> intArr = { -9, -1, 0, 1, 2, 3, 5, 6, 7, 8, 9 };
	std::vector<std::string> arr = { "one", "two", "three"};
	
	FindMax(arr, maxValueString);
	FindMax(intArr, maxValue);
	std::cout << maxValueString << " "<< maxValue << std::endl;
	return 0;
}