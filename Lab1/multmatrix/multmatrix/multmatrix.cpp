#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm> 
#include "multmatrix.h"
using namespace std;

size_t SIZE_ARRAY = 3;

vector<vector<double>> GetFirstArrayFromFile(const string & inputFirstFile)
{
	ifstream inputFirstMatrix(inputFirstFile);
	vector<vector<double>> firstArray(SIZE_ARRAY);
	if (!inputFirstMatrix.is_open())
	{
		cout << "File not found";
	}
	for (size_t x = 0; x < SIZE_ARRAY; ++x)
	{
		firstArray[x].resize(SIZE_ARRAY);
		for (size_t y = 0; y < SIZE_ARRAY; ++y)
		{
			double number = 0.0;
			inputFirstMatrix >> number;
			firstArray[x][y] = number;
		}
	}
	return firstArray;
}
vector<vector<double>> GetSecondArrayFromFile(const string & inputSecondFile)
{
	ifstream inputSecondMatrix(inputSecondFile);
	vector<vector<double>> secondArray(SIZE_ARRAY);
	if (!inputSecondMatrix.is_open())
	{
		cout<<"File nod found";
	}
	for (size_t x = 0; x < SIZE_ARRAY; ++x)
	{
		secondArray[x].resize(SIZE_ARRAY);
		for (size_t y = 0; y < SIZE_ARRAY; ++y)
		{
			double number = 0.0;
			inputSecondMatrix >> number;
			secondArray[x][y] = number;
		}
	}
	return secondArray;
}

vector<vector<double>> MultiplicationOfMatrix(const string & inputFirstFile, const string & inputSecondFile)
{
	vector<vector<double>> resultMatrix(3);
	for (auto & it : resultMatrix)
	{
		it.resize(3);
	}
	vector<vector<double>> firstMatrix = GetFirstArrayFromFile(inputFirstFile);
	vector<vector<double>> secondMatrix = GetFirstArrayFromFile(inputSecondFile);

	for (size_t row = 0; row < SIZE_ARRAY; row++)
	{
		for (size_t column = 0; column < SIZE_ARRAY; column++)
		{
			for (size_t number = 0; number < SIZE_ARRAY; number++)
			{
				resultMatrix[row][column] += firstMatrix[row][number] * secondMatrix[number][column];
			}
		}
	}
	return resultMatrix;
}

void PrintMatrix(const vector<vector<double>> & resultMatrix)
{
	for (auto it1 : resultMatrix)
	{
		for (auto it2 : it1)
		{
			cout << fixed << setprecision(3) << it2 << " ";
		}
		cout << endl;
	}
}
