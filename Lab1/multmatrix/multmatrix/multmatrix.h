#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

vector<vector<double>> GetFirstArrayFromFile(const string & inputFirstFile);
vector<vector<double>> GetSecondArrayFromFile(const string & inputSecondFile);
vector<vector<double>> MultiplicationOfMatrix(const string & inputFirstFile, const string & inputSecondFile);
void PrintMatrix(vector<vector<double>> & resultMatrix);