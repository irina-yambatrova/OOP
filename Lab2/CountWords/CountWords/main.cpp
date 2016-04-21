#include "stdafx.h"
#include <Windows.h>
#include <string>
#include <iostream>
#include "CountWords.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	string inputString = ReadInputData();
	PrintNumberOfWords(CountOccurrenceOfWords(inputString));
	return 0;
}