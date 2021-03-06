#include "stdafx.h"
#include "VectorProcessor.h"
#include <iostream>
#include <iterator>
#include <algorithm> 
#include <boost/range/algorithm/transform.hpp>
#include <boost/range/algorithm/copy.hpp>

vector<double> ReadInputDataInVector()
{
	return{ istream_iterator<double>(cin), (istream_iterator<double>()) };
}

void DivideNumberByHalfMaxVector(vector<double> & numbers)
{
	if (!numbers.empty())
	{
		double max = *std::max_element(begin(numbers), end(numbers));
		double halfOfMax = max / 2;
		boost::transform(numbers, numbers.begin(), [halfOfMax](double number)
		{
			return number / halfOfMax;
		});
	}
}

void SortVector(vector<double> & numbers)
{
	std::sort(numbers.begin(),  numbers.end());
}

void PrintVector(vector<double> const& numbers)
{
	boost::copy(numbers, ostream_iterator<double>(cout, " "));
}
