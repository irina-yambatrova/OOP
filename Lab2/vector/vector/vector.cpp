﻿#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm> 
#include <Windows.h>
#include "VectorProcessor.h"
#include "VectorProcessor.h"

int _tmain()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	vector<double> numbers;
	std::cout << "Введите числа через пробел, по окончании нажмите , + enter  " << endl;
	numbers = ReadInputDataInVector();
	DivideNumberByHalfMaxVector(numbers);
	std::sort(numbers.begin(), numbers.end());
	PrintVector(numbers);
	return 0;
}
