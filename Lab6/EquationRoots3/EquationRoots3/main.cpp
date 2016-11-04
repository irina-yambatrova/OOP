#include "stdafx.h"
#include "EquationRoots3.h"
#include <stdexcept>
#include <iostream>
#include <iterator>
#include <vector>
#include <boost/math/constants/constants.hpp>

using boost::math::double_constants::pi;
using namespace std;



void ShowRoots(EquationRoots3 const & roots)
{
	for (size_t i = 0; i < roots.numRoots; i++)
	{
		cout << roots.roots[i] << " ";
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Input coefficient a b c d: ";
	vector<double> number(istream_iterator<double>(cin), (istream_iterator<double>()));
	ShowRoots(Solve3(number[0], number[1], number[2], number[3]));
	return 0;
}