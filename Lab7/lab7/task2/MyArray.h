﻿#pragma once
#include "stdafx.h"
#include "MyIterator.h"
#include <new>
#include <algorithm>

template <typename T>
class CMyArray
{
public:
	CMyArray() = default;

	CMyArray(const CMyArray& arr)
	{
		const auto size = arr.GetSize();
		if (size != 0)
		{
			m_begin = RawAlloc(size);
			try
			{
				CopyItems(arr.m_begin, arr.m_end, m_begin, m_end);
				m_endOfCapacity = m_end;
			}
			catch (...)
			{
				DeleteItems(m_begin, m_end);
				throw;
			}
		}
	}

	CMyArray(CMyArray&& arr)
		:m_begin(std::move(arr.m_begin))
		, m_end(std::move(arr.m_end))
		, m_endOfCapacity(std::move(arr.m_endOfCapacity))
	{
		/*arr.m_begin = nullptr;
		arr.m_end = nullptr;
		arr.m_endOfCapacity = nullptr;*/
	}


	CMyArray<T> & operator=(const CMyArray<T> & arr)
	{
		if (&arr != this)
		{
			T*temp_begin = nullptr;
			T*temp_end = nullptr;
			T*temp_endOfCapacity = nullptr;
			const auto size = arr.GetSize();
			if (size != 0)
			{
				temp_begin = RawAlloc(size);
				temp_end = temp_begin + size;
				try
				{
					CopyItems(arr.m_begin, arr.m_end, temp_begin, temp_end);
					temp_endOfCapacity = temp_begin + size;
				}
				catch (...)
				{
					DeleteItems(temp_begin, temp_end);
					temp_endOfCapacity = nullptr;
					throw;
				}
				DeleteItems(m_begin, m_end);
				m_begin = temp_begin;
				m_end = temp_end;
				m_endOfCapacity = temp_endOfCapacity;
			}
		}
		return *this;
	}

	T & operator[](size_t index)
	{
		if (index >= GetSize())
		{
			throw std::out_of_range("index out of range");
		}
		return *(m_begin + index);
	}

	const T & operator[](size_t index)const
	{
		if (index >= GetSize())
		{
			throw std::out_of_range("index out of range");
		}
		return *(m_begin + index);
	}

	void Clear()
	{
		DestroyItems(m_begin, m_end);
		m_end = m_begin;
	}

	void Resize(size_t newSize)
	{
		if (newSize <= GetSize())
		{
			DestroyItems(m_begin + newSize, m_end);
			m_end -= (GetSize() - newSize);
		}
		else if ((newSize > GetSize()) && (newSize <= GetCapacity()))
		{
			size_t oldSize = GetSize();
			try
			{
				auto end = m_end;
				m_end = m_begin + newSize;
				for (; end != m_end; end++)
				{
					new (end)T();
				}
			}
			catch (...)
			{
				DestroyItems(m_begin + oldSize, m_end);
				m_end = m_begin + oldSize;
				throw;
			}

		}
		else if (newSize > GetSize() && newSize > GetCapacity())
		{
			auto newBegin = RawAlloc(newSize);
			T *newEnd = newBegin;
			try
			{
				for (size_t i = 0; i < newSize - GetSize(); i++)
				{
					new (newEnd)T();
					++newEnd;
				}
				CopyItems(m_begin, m_begin + newSize, newBegin, newEnd);
			}
			catch (...)
			{
				DeleteItems(newBegin, newEnd);
				throw;
			}
			DeleteItems(m_begin, m_end);

			m_begin = newBegin;
			m_end = newEnd;
			m_endOfCapacity = m_begin + newSize;
		}
	}

	void Append(const T & value)
	{
		if (m_end == m_endOfCapacity) // no free space
		{
			size_t newCapacity = std::max(1u, GetCapacity() * 2);

			auto newBegin = RawAlloc(newCapacity);
			T *newEnd = newBegin;
			try
			{
				CopyItems(m_begin, m_end, newBegin, newEnd);
				// Конструируем копию value по адресу newItemLocation
				new (newEnd)T(value);
				++newEnd;
			}
			catch (...)
			{
				DeleteItems(newBegin, newEnd);
				throw;
			}
			DeleteItems(m_begin, m_end);

			// Переключаемся на использование нового хранилища элементов
			m_begin = newBegin;
			m_end = newEnd;
			m_endOfCapacity = m_begin + newCapacity;
		}
		else // has free space
		{
			new (m_end) T(value);
			++m_end;
		}
	}

	typedef CMyIterator<T, false> iterator;
	typedef CMyIterator<T, true> reverse_iterator;
	typedef CMyIterator<const T, false> const_iterator;
	typedef CMyIterator<const T, true> const_reverse_iterator;

	iterator begin()
	{
		return iterator(m_begin);
	}

	iterator end() {
		return iterator(m_end);
	}

	const_iterator begin() const
	{
		return const_iterator(m_begin);
	}

	const_iterator end() const
	{
		return const_iterator(m_end);
	}

	reverse_iterator rbegin()
	{
		return reverse_iterator(m_end - 1);
	}

	reverse_iterator rend()
	{
		return reverse_iterator(m_begin - 1);
	}

	const_reverse_iterator rbegin() const
	{
		return const_reverse_iterator(m_end - 1);
	}

	const_reverse_iterator rend() const
	{
		return const_reverse_iterator(m_begin - 1);
	}

	T & GetBack()
	{
		assert(GetSize() != 0u);
		return m_end[-1];
	}

	const T & GetBack()const
	{
		assert(GetSize() != 0u);
		return m_end[-1];
	}

	size_t GetSize()const
	{
		return m_end - m_begin;
	}
	size_t GetCapacity()const
	{
		return m_endOfCapacity - m_begin;
	}

	~CMyArray()
	{
		try
		{
			DeleteItems(m_begin, m_end);
		}
		catch (...)
		{
			// do nothing
		}
	}
private:
	static void DeleteItems(T *begin, T *end)
	{
		// Разрушаем старые элементы
		DestroyItems(begin, end);
		// Освобождаем область памяти для их хранения
		RawDealloc(begin);
	}

	// Копирует элементы из текущего вектора в to, возвращает newEnd
	static void CopyItems(const T *srcBegin, T *srcEnd, T * const dstBegin, T * & dstEnd)
	{
		for (dstEnd = dstBegin; srcBegin != srcEnd; ++srcBegin, ++dstEnd)
		{
			// Construct "T" at "dstEnd" as a copy of "*begin"
			new (dstEnd)T(*srcBegin);
		}
	}

	static void DestroyItems(T *from, T *to)
	{
		// dst - адрес объект, при конструирование которого было выброшено исключение
		// to - первый скорнструированный объект
		while (to != from)
		{
			--to;
			// явно вызываем деструктор для шаблонного типа T
			to->~T();
		}
	}

	static T *RawAlloc(size_t n)
	{
		size_t memSize = n * sizeof(T);
		T *p = static_cast<T*>(malloc(memSize));
		if (!p)
		{
			throw std::bad_alloc();
		}
		return p;
	}

	static void RawDealloc(T *p)
	{
		free(p);
	}

private:
	T *m_begin = nullptr;
	T *m_end = nullptr;
	T *m_endOfCapacity = nullptr;
};