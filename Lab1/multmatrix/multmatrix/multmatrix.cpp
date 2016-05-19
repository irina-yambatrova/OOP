#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm> 
#include "multmatrix.h"
using namespace std;

size_t SIZE_ARRAY = 3;

vector<vector<double>> GetArrayFromFile(const string & nameOfFile)
{
	ifstream inputFile(nameOfFile);
	vector<vector<double>> array(SIZE_ARRAY);
	if (!inputFile.is_open())
	{
		cout << "File not found";
	}
	for (size_t x = 0; x < SIZE_ARRAY; ++x)
	{
		array[x].resize(SIZE_ARRAY);
		for (size_t y = 0; y < SIZE_ARRAY; ++y)
		{
			double number = 0.0;
			inputFile >> number;
			array[x][y] = number;
		}
	}
	return array;
}

vector<vector<double>> MultiplicationOfMatrix(const string & inputFirstFile, const string & inputSecondFile)
{
	vector<vector<double>> resultMatrix(3);
	for (auto & it : resultMatrix)
	{
		it.resize(SIZE_ARRAY);
	}
	vector<vector<double>> firstMatrix = GetArrayFromFile(inputFirstFile);
	vector<vector<double>> secondMatrix = GetArrayFromFile(inputSecondFile);
	for (size_t row = 0; row < SIZE_ARRAY; row++)
	{
		for (size_t column = 0; column < SIZE_ARRAY; column++)
		{
			for (size_t element = 0; element < SIZE_ARRAY; element++)
			{
				resultMatrix[row][column] += firstMatrix[row][element] * secondMatrix[element][column];
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
