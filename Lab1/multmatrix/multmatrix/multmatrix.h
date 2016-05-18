#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

vector<std::vector<double>> GetFirstArrayFromFile(const string & inputFile);
vector<vector<double>> MultiplicationOfMatrix(const string & inputFirstFile, const string & inputSecondFile);
void PrintMatrix(const vector<vector<double>> & resultMatrix);