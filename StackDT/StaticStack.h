#pragma once

#include <iostream>
template <typename T, size_t N>
class StaticStack 
{
private:

	T m_stack[N] = {};
	int m_items = 0;
public:
	T pop() 
	{
		if (m_items > 0) 
		{
			return m_stack[--m_items];
		}
		//TODO: Throw exception
		return m_stack[m_items];
	}
	T top()
	{
			return m_stack[m_items-1];
	}
	void push(T item) 
	{
		if (m_items < N) 
		{
			m_stack[m_items++] = item;
		}
		else 
		{
			// Silently fails on overflow
		}
	}
	
	void print() 
	{
		for (int i = m_items - 1; i >= 0; i--)
			std::cout << m_stack[i] << std::endl;
	}

	constexpr int getMaxSize()
	{
		return N;
	}
};
