#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>


std::vector<std::vector<double>> GetArrayFromFile(const std::string & nameOfFile);
std::vector<std::vector<double>> MultiplicationOfMatrix(const std::string & inputFirstFile, const std::string & inputSecondFile);
void PrintMatrix(const std::vector<std::vector<double>> & resultMatrix);
