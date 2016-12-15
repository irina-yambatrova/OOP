#include "stdafx.h"
#include <iostream>
#include <string>
#include "FindMaxEx.h"

using namespace std;

struct Sportsman
{
	std::string FIO;
	int	growth;
	int	weight;

};

int main()
{
	//int maxValue;
	//std::vector<int> intArr = { -1, 0, 1, 2, 3, 5, 6, 7, 8, 9 };
	//FindMaxEx(intArr, maxValue, [](const int & first, const int & second) { return first < second; });

	std::vector<Sportsman> atlets = { { "ivanov", 190, 100 },{ "sidorov", 180, 95 },{ "petrov", 185, 95 } };
	Sportsman maxValue;
	FindMaxEx(atlets, maxValue, [](const Sportsman & firstMan, const Sportsman & secondMan) { return firstMan.weight < secondMan.weight; });
	std::cout << "Maximum weight: "<< maxValue.weight << std::endl;
	return 0;
}