#include "stdafx.h"
#include <iostream>
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
	vector<Sportsman> atlets = { { "ivanov", 190, 100 },{ "sidorov", 180, 95 },{ "petrov", 185, 95 } };
	Sportsman maxValue;
	FindMaxEx(atlets, maxValue, [](const Sportsman & firstMan, const Sportsman & secondMan) { return firstMan.weight < secondMan.weight; });
	cout << "Maximum weight: "<< maxValue.weight << endl;
	return 0;
}