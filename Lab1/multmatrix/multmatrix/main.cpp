#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "multmatrix.h"
using namespace std;

int main(int argc, char * argv[])
{
	if (argc == 3)
	{
		PrintMatrix(MultiplicationOfMatrix(argv[1], argv[2]));
		return 0;
	}
	cout << "Error input data! You should enter 2 arguments !\n multmatrix.exe <first file name> <second file name>\n";
	return 1;
}
