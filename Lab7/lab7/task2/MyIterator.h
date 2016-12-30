#pragma once
#include "stdafx.h"

template <typename T, bool isReversed>
class CMyIterator
{
public:
	CMyIterator(T * current)
		:m_current(current)
	{
	}

	T operator*() const
	{
		return *m_current;
	}

	CMyIterator & operator ++()
	{
		isReverse ? --m_current : ++m_current;
		return *this;
	}

	CMyIterator & operator --()
	{
		isReverse ? ++m_current : --m_current;
		return *this;
	}

	CMyIterator & operator += (const ptrdiff_t numb)
	{
		if (m_isReverse)
		{
			m_current += numb * (-1);
		}
		else
		{
			m_current += numb;
		}
		return *this;
	}

	CMyIterator & operator -= (const ptrdiff_t numb)
	{
		if (m_isReverse)
		{
			m_current -= numb * (-1);
		}
		else
		{
			m_current -= numb;
		}
		return *this;
	}

	CMyIterator operator + (ptrdiff_t numb) const
	{
		return (m_isReverse ? m_current + numb : m_current - numb);
	}

	CMyIterator operator - (ptrdiff_t numb) const
	{
		return (m_isReverse ? m_current - numb : m_current + numb);
	}

	bool operator ==(CMyIterator const& other)
	{
		return (*m_current == *other);
	}

	bool operator !=(CMyIterator const& other)
	{
		return (*m_current != *other);
	}

	bool operator < (CMyIterator const& other) const
	{
		return (*this) < other;
	}

	bool operator > (CMyIterator const& other) const
	{
		return (*this) > other;
	}

	bool operator <= (CMyIterator const& other) const
	{
		return (*this) <= other;
	}

	bool operator >= (CMyIterator const& other) const
	{
		return (*this) >= other;
	}

	T & operator[](size_t index)
	{
		return m_current[index];
	}

	const T & operator[](const size_t index)const
	{
		return m_current[index];
	}

private:
	T * m_current;
	bool m_isReverse;
};
