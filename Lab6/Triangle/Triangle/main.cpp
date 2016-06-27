#include "stdafx.h"
#include <vector>
#include <iterator>
#include <istream>
#include <iostream>
#include "Triangle.h"

using namespace std;
int main()
{
	cout << "enter 3 side of triangle at the end type , " << endl;
	std::vector<double> side(istream_iterator<double>(cin), (istream_iterator<double>()));
	CTriangle Triangle1(side[0], side[1], side[2]);
	ShowInfo(Triangle1);
	return 0;
}