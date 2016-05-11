#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm> 
#include <Windows.h>
#include "VectorProcessor.h"
#include "VectorProcessor.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	vector<double> numbers;
	std::cout << "Введите числа через пробел. по окончании введите , и Enter  " << endl;
	numbers = ReadInputDataInVector();
	ProcessVector(numbers);
	SortVector(numbers);
	PrintVector(numbers);
	return 0;
}

