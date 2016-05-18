#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm> 
#include "multmatrix.h"
using namespace std;

int SIZE_ARRAY = 3;

vector<std::vector<double>> GetFirstArrayFromFile(const string & inputFirstFile)
{
	ifstream inputFirstMatrix(inputFirstFile);
	vector<vector<double>> firstArray(SIZE_ARRAY);
	for (size_t x = 0; x < SIZE_ARRAY; ++x)
	{
		firstArray[x].resize(SIZE_ARRAY);
		for (size_t y = 0; y < SIZE_ARRAY; ++y)
		{
			double number = 0;
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
	for (size_t x = 0; x < SIZE_ARRAY; ++x)
	{
		secondArray[x].resize(SIZE_ARRAY);
		for (size_t y = 0; y < SIZE_ARRAY; ++y)
		{
			double number = 0;
			inputSecondMatrix >> number;
			secondArray[x][y] = number;
		}
	}
	return secondArray;
}

vector<vector<double>> MultiplicationOfMatrix(const string & inputFirstFile, const string & inputSecondFile)
{
	vector<vector<double>> resultMatrix = { { 0,0,0 }, { 0,0,0 }, { 0,0,0 } };
	vector<vector<double>> firstMatrix = GetFirstArrayFromFile(inputFirstFile);
	vector<vector<double>> secondMatrix = GetSecondArrayFromFile(inputSecondFile);

	for (int row = 0; row < SIZE_ARRAY; row++)
	{
		for (int column = 0; column < SIZE_ARRAY; column++)
		{
			for (int inner = 0; inner < SIZE_ARRAY; inner++)
			{
				resultMatrix[row][column] += firstMatrix[row][inner] * secondMatrix[inner][column];
			}
		}
	}
	return resultMatrix;
}

void PrintMatrix(vector<vector<double>> & resultMatrix)
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
