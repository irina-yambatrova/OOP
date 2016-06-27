#include "stdafx.h"
#include "Triangle.h"
#include <stdexcept>
#include <string>
#include <sstream>
#include <iostream>
#include <boost/format.hpp>
#include <math.h>

using namespace std;

namespace
{
	const double & AssureNotNegative(const double & value, const string & argName = string())
	{
		if (value >= 0)
		{
			return value;
		}
		throw invalid_argument(argName.empty() ? "Argument" : argName + " can not be negative.");
	}
}


CTriangle::CTriangle(double side1, double side2, double side3)
	: m_side1(AssureNotNegative(side1, "Side 1"))
	, m_side2(AssureNotNegative(side2, "Side 2"))
	, m_side3(AssureNotNegative(side3, "Side 3"))
{
	if (side1 > side2 + side3)
	{
		throw domain_error("Side 1 can not be greater than sum of side 2 and side 3");
	}

	if (side2 > side1 + side3)
	{
		throw domain_error("Side 2 can not be greater than sum of side 1 and side 3");
	}

	if (side3 > side1 + side2)
	{
		throw domain_error("Side 3 can not be greater than sum of side 1 and side 2");
	}
}

double CTriangle::GetSide1()const
{
	return m_side1;
}

double CTriangle::GetSide2()const
{
	return m_side2;
}

double CTriangle::GetSide3()const
{
	return m_side3;
}

double CTriangle::GetPerimeter()const
{
	return m_side1 + m_side2 + m_side3;
}

double CTriangle::GetArea()const
{
	double p = GetPerimeter() / 2;
	return sqrt(p * (p - m_side1) * (p - m_side2) * (p - m_side3));
}

void ShowInfo(CTriangle const& triangle)
{
	cout << "area of triangle " << triangle.GetArea() << " , " << "perimeter of triangle "<< triangle.GetPerimeter()<< endl;
}

