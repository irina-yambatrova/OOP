#include "stdafx.h"
#include <Windows.h>
#include <string>
#include <iostream>
#include "HtmlDecode.h"
#include <algorithm>


using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	string inputText = ReadInputData();
	while (inputText != "end")
	{
		PrintOuputText(HtmlDecode(inputText));
		inputText = ReadInputData();
	}
	
	return 0;
}