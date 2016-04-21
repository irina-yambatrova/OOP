#include "stdafx.h"
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <iomanip>
#include <Windows.h>
#include <set>
using namespace std;

std::string ReadInputData()
{
	string inputString;
	cout << "Введите строку  " << endl;
	getline(cin, inputString);
	return inputString;
}

void RemoveDividers(string &inputString)
{
	set<char> delimiter{'.',':',',',';','(',')','-','?','!'};
	for (auto &ch : inputString)
	{
		if (delimiter.count(ch) != 0)
		{
			ch = ' ';
		}
	}
}

std::map<std::string, size_t> CountOccurrenceOfWords(string &words)
{
	RemoveDividers(words);
	std::map <std::string, size_t> frequencyOfOccurrence; 
	stringstream inputString(words);
	while (inputString >> words)
	{
		frequencyOfOccurrence[words]++;
	}
	return frequencyOfOccurrence;
}

void PrintNumberOfWords(map<std::string, size_t> &frequencyOfOccurrence)
{
	cout << "вхождение каждого слова: " << endl;
	for (auto iter : frequencyOfOccurrence)
	{
		cout << iter.first << " -> " << (iter.second) << endl;
	}
}



