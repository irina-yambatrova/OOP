#pragma once

/*
Класс, моделирующий рациональное число
*/
class CRational final
{
public:
	CRational(int numerator = 0, int denominator = 1);

	// Возвращает числитель
	int GetNumerator() const;

	// Возвращает знаменатель
	int GetDenominator() const;

	// Возвращает отношение числителя и знаменателя в виде числа double
	double ToDouble() const;

	CRational const operator+() const;
	CRational const operator-() const;
	CRational & operator +=(CRational const& rational);
	CRational & operator -=(CRational const& rational);
	CRational & operator *=(CRational const& rational);
	CRational & operator /=(CRational const& rational);


private:
	int m_numerator;
	int m_denominator;

	// Нормализует рациональное число
	void Normalize();
};

// Вычисляет наибольший общий знаменатель чисел a и b
unsigned GCD(unsigned a, unsigned b);

CRational const operator +(CRational const& rational1, CRational const& rational2);
CRational const operator -(CRational const& rational1, CRational const& rational2);

CRational const operator *(CRational const& rational1, CRational const& rational2);
CRational const operator /(CRational const& rational1, CRational const& rational2);

bool const operator ==(CRational const& rational1, CRational const& rational2);
bool const operator !=(CRational const& rational1, CRational const& rational2);

bool const operator <(CRational const& rational1, CRational const& rational2);
bool const operator <=(CRational const& rational1, CRational const& rational2);
bool const operator >(CRational const& rational1, CRational const& rational2);
bool const operator >=(CRational const& rational1, CRational const& rational2);