#pragma once
#include "stdafx.h"
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <iomanip>
#include <Windows.h>
#include <set>

std::string ReadInputData();
void RemoveDividers(std::string &inputString);
std::map<std::string, size_t> CountOccurrenceOfWords(std::string &words);
void PrintNumberOfWords(std::map<std::string, size_t> &frequencyOfOccurrence);
