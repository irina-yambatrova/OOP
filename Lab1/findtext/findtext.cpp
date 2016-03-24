#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void PrintLineNumbersWithFoundText( ifstream &file, const string &searchText)
{
	std: string str;
	int counter = 1;
	while (getline(file, str))
	{
		if (str.find(searchText) != -1)
		{
			cout << "line number: " << searchText << counter << endl;
		}
		counter++;
	}
};

int main(int argc, char * argv[])
{
	if (argc == 3)
	{
		ifstream file(argv[1]);
		std::string searchText = argv[2];
		if (!file.is_open())
		{
			cout << "File not found\n";
			return 1;
		}
		else 
		{		
			PrintLineNumbersWithFoundText(file, searchText);
		}
	}
	else
	{ 
		cout << "Error input data! You should enter 3 arguments !\nfindtext.exe <file name> <text to search>\nexample: findtext.exe input.txt Fox  ";
		return 1;
	}
	return 0;
}

