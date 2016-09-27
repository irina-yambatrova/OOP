#include "stdafx.h"
#include "Point.h"


CPoint::CPoint(int x, int y, std::string const& borderColor)
	: m_x(x)
	, m_y(y)
	, m_borderColor(borderColor)
{
};

int CPoint::GetX() const
{
	return m_x;
}

int CPoint::GetY() const
{
	return m_y;
}

double CPoint::GetArea() const
{
	return 0;
}

double CPoint::GetPerimeter() const
{
	return 0;
}

std::string CPoint::ToString() const
{
	std::stringstream stream;
	stream << "Point <" << m_x << "," << m_y << ">";
	stream << ", Perimeter=" << GetPerimeter() << ", Area=" << GetArea();
	return stream.str();
}


std::string CPoint::GetBorderColor() const
{
	return m_borderColor;
}