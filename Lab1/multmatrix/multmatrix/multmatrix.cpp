#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm> 
#include "multmatrix.h"
using namespace std;

int SIZE_ARRAY = 3;

vector<std::vector<double>> GetFirstArrayFromFile(const string & inputFile)
{
	ifstream inputFirstMatrix(inputFile);
	ifstream inputSecondMatrix(inputFile);
	vector<vector<double>> firstArray(SIZE_ARRAY);
	vector<vector<double>> secondArray(SIZE_ARRAY);
	for (size_t x = 0; x < SIZE_ARRAY; ++x)
	{
		firstArray[x].resize(SIZE_ARRAY);
		secondArray[x].resize(SIZE_ARRAY);
		for (size_t y = 0; y < SIZE_ARRAY; ++y)
		{
			double number = 0;
			inputFirstMatrix >> number;
			firstArray[x][y] = number;
			inputSecondMatrix >> number;
			secondArray[x][y] = number;
		}
	}
	return firstArray;
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
			for (size_t inner = 0; inner < SIZE_ARRAY; inner++)
			{
				resultMatrix[row][column] += firstMatrix[row][inner] * secondMatrix[inner][column];
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
