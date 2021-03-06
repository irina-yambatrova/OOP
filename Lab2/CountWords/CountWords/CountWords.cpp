﻿#include "stdafx.h"
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <iomanip>
#include <Windows.h>
#include <set>
#include <boost/algorithm/string.hpp>
#include <boost/range/algorithm/transform.hpp>

using namespace std;

std::string ReadInputData()
{
	string inputText ;
	cout << "Введите строку, по окончании введите end  " << endl;
	getline(cin, inputText);
	return inputText;
}

void RemoveDividers(string &inputText)
{
	set<char> delimiter{'.',':',',',';','(',')','-','?','!'};
	for (auto &ch : inputText)
	{
		if (delimiter.count(ch) != 0)
		{
			ch = ' ';
		}
	}
}

std::map<std::string, size_t> CountOccurrenceOfWords(const string &words)
{
	string wordsCopy = words;
	boost::transform(wordsCopy, wordsCopy.begin(), tolower);
	RemoveDividers(wordsCopy);
	std::map <std::string, size_t> frequencyOfOccurrence; 
	stringstream inputString(wordsCopy);
	string word;
	while (inputString >> word)
	{
		frequencyOfOccurrence[word]++;
	}
	return frequencyOfOccurrence;
}

void PrintNumberOfWords(const map<std::string, size_t> &frequencyOfOccurrence)
{
	cout << "вхождение каждого слова: " << endl;
	for (auto iter : frequencyOfOccurrence)
	{
		cout << iter.first << " -> " << (iter.second) << endl;
	}
}



