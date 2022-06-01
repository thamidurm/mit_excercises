#pragma once


template <typename T>
class DynamicStack 
{
private:
	T* m_stackPtr;
	int m_capacity = 10;
	int m_items = 0;
public:

	DynamicStack()
	{
		m_stackPtr = new T[m_capacity];
	}

	~DynamicStack()
	{
		delete[] m_stackPtr;
	}

	void reallocate()
	{
		auto tempPtr = new T[m_capacity + m_capacity / 2];
		for (int i = 0; i < m_capacity; ++i) 
		{
			tempPtr[i] = m_stackPtr[i]; 
		}
		delete[] m_stackPtr;
		m_stackPtr = tempPtr;
		m_capacity = m_capacity + m_capacity / 2;
	}

	T pop() 
	{
		if (m_items > 0) 
		{
			return m_stackPtr[--m_items];
		}
		//TODO: Throw exception
		return m_stackPtr[m_items];
	}
	T top() 
	{
		return m_stackPtr[m_items - 1];
	}
	void push(T item)
	{
		if (m_items >= m_capacity) 
		{
			reallocate();
		}
		m_stackPtr[m_items++] = item;
	}

	void print() 
	{
		for (int i = m_items - 1; i >= 0; i--)
			std::cout << m_stackPtr[i] << std::endl;
	}

	int getSize()
	{
		return m_items;
	}

	int getCapacity()
	{
		return m_capacity;
	}
};