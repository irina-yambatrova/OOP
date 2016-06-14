#include "stdafx.h"
#include "rational.h"
#include <utility>
#include <stdexcept>


CRational::CRational(int numerator, int denominator)
	: m_numerator(numerator)
	, m_denominator(denominator)
{
	if (denominator == 0)
	{
		throw std::invalid_argument("Denominator must not be equal to zero");
	}
	if (denominator < 0)
	{
		m_numerator = -m_numerator;
		m_denominator = -m_denominator;
	}
	Normalize();
}

int CRational::GetNumerator() const
{
	return m_numerator;
}

int CRational::GetDenominator() const
{
	return m_denominator;
}

void CRational::Normalize()
{
	const int gcd = GCD(abs(m_numerator), m_denominator);
	m_numerator /= gcd;
	m_denominator /= gcd;
}

unsigned GCD(unsigned a, unsigned b)
{
	while (b != 0)
	{
		std::swap(a, b);
		b = b % a;
	}
	return (a != 0) ? a : 1;
}

//////////////////////////////////////////////////////////////////////////
// TODO: 1. Реализовать метод ToDouble() согласно заданию
//////////////////////////////////////////////////////////////////////////
double CRational::ToDouble() const
{
	return double(m_numerator) / m_denominator;
}
//////////////////////////////////////////////////////////////////////////
// TODO: 2. Реализовать унарный + и унарный -
//////////////////////////////////////////////////////////////////////////
CRational const CRational::operator +()const
{
	return CRational(m_numerator, m_denominator);
}

CRational const CRational::operator -()const
{
	return CRational(-m_numerator, m_denominator);
}

//////////////////////////////////////////////////////////////////////////
// TODO: 3. Реализовать бинарный +
//////////////////////////////////////////////////////////////////////////
CRational const operator +(const CRational & rational1, const CRational & rational2)
{
	return CRational((rational1.GetNumerator() * rational2.GetDenominator()) + (rational2.GetNumerator() * rational1.GetDenominator()),
		rational1.GetDenominator() * rational2.GetDenominator());
}

//////////////////////////////////////////////////////////////////////////
// TODO: 4. Реализовать бинарный -
//////////////////////////////////////////////////////////////////////////
CRational const operator -(const CRational & rational1, const CRational & rational2)
{
	return rational1 + -rational2;
}

//////////////////////////////////////////////////////////////////////////
// TODO: 5. Реализовать оператор +=
//////////////////////////////////////////////////////////////////////////
CRational & CRational::operator +=(const CRational & rational)
{
	*this = *this + rational;
	return *this;
}

//////////////////////////////////////////////////////////////////////////
// TODO: 6. Реализовать оператор -=
//////////////////////////////////////////////////////////////////////////
CRational & CRational::operator -=(const CRational & rational)
{
	return *this += -rational;
}

//////////////////////////////////////////////////////////////////////////
// TODO: 7. Реализовать оператор *
//////////////////////////////////////////////////////////////////////////
CRational const operator *(const CRational & rational1, const CRational & rational2)
{
	return CRational(rational1.GetNumerator() * rational2.GetNumerator(), rational1.GetDenominator() * rational2.GetDenominator());
}

//////////////////////////////////////////////////////////////////////////
// TODO: 8. Реализовать оператор /
//////////////////////////////////////////////////////////////////////////

CRational const operator /(const CRational & rational1, const CRational & rational2)
{
	return rational1 * CRational(rational2.GetDenominator(), rational2.GetNumerator());
}

//////////////////////////////////////////////////////////////////////////
// TODO: 9. Реализовать оператор *=
//////////////////////////////////////////////////////////////////////////
CRational & CRational::operator *=(const CRational & rational)
{
	*this = *this * rational;
	return *this;
}

//////////////////////////////////////////////////////////////////////////
// TODO: 10. Реализовать оператор /=
//////////////////////////////////////////////////////////////////////////

CRational & CRational::operator /=(const CRational & rational)
{
	*this = *this / rational;
	return *this;
}

//////////////////////////////////////////////////////////////////////////
// TODO: 11. Реализовать операторы == и !=
//////////////////////////////////////////////////////////////////////////

bool const operator ==(const CRational & rational1, const CRational & rational2)
{
	return ((rational1.GetNumerator() == rational2.GetNumerator()) && (rational1.GetDenominator() == rational2.GetDenominator()));
}

bool const operator !=(const CRational & rational1, const CRational & rational2)
{
	return !(rational1 == rational2);
}

//////////////////////////////////////////////////////////////////////////
// TODO: 12. Реализовать операторы <, >, <=, >=
//////////////////////////////////////////////////////////////////////////
bool const operator <(const CRational & rational1, const CRational & rational2)
{
	return (rational1.GetNumerator() * rational2.GetDenominator() < rational2.GetNumerator() * rational1.GetDenominator());
}

bool const operator <=(const CRational & rational1, const CRational & rational2)
{
	return (rational1.GetNumerator() * rational2.GetDenominator() <= rational2.GetNumerator() * rational1.GetDenominator());
}

bool const operator >(const CRational & rational1, const CRational & rational2)
{
	return !(rational1 <= rational2);
}

bool const operator >=(const CRational & rational1, const CRational & rational2)
{
	return !(rational1 < rational2);
}