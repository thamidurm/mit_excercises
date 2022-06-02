#pragma once

#include <exception>
constexpr int StartPointerCount = 1;
constexpr int StartStackSize = 10;
template <typename T>

class DynamicStack
{
public:

	T pop()
	{
		T value = m_listPtrs[m_curListIndex][m_topIndex];

		if (m_topIndex > 0)
		{
			--m_topIndex;
			--m_totalSize;
		}
		else
		{
			if (m_curListIndex > 0)
			{
				m_topIndex = m_listCapacities[m_curListIndex] - 1;
				--m_curListIndex;
				--m_totalSize;
			}
			else {
				//Attempt to pop from empty stack
				throw std::exception();
			}
		}
		return value;
	}

	void push(T item) {
		if (m_topIndex == m_listCapacities[m_curListIndex] - 1)
		{
			if (m_listPtrCount == m_listPtrCapacity) {
				auto tempListPtrs = new T * [m_listPtrCapacity * 2];
				auto tempCapacities = new int[m_listPtrCapacity * 2];
				for (int i = 0; i < m_listPtrCapacity; ++i)
				{
					tempListPtrs[i] = m_listPtrs[i];
					tempCapacities[i] = m_listCapacities[i];
				}
				
				delete[] m_listPtrs;
				delete[] m_listCapacities;

				m_listPtrs = tempListPtrs;
				m_listCapacities = tempCapacities;
				m_listPtrCapacity = m_listPtrCapacity * 2;
			}
			int lastCapacity = m_listCapacities[m_curListIndex];
			m_listPtrs[m_curListIndex + 1] = new T[lastCapacity * 2];
			m_listCapacities[m_curListIndex + 1] = lastCapacity * 2;
			++m_listPtrCount;
			m_topIndex = -1;//
			++m_curListIndex;
		}
		++m_topIndex;
		++m_totalSize;
		m_listPtrs[m_curListIndex][m_topIndex] = item;
	}
	int getSize() {
		return m_totalSize;
	}

	DynamicStack()
	{
		m_listPtrs = new T * [StartPointerCount];
		m_listCapacities = new int[StartPointerCount];
		m_listPtrCapacity = StartPointerCount;

		m_listCapacities[m_curListIndex] = StartStackSize;
		m_listPtrs[m_curListIndex] = new T[StartStackSize];
		m_listPtrCount = 1;
	}

	~DynamicStack()
	{
		_delete();
	}

	void _delete()
	{
		for (int i = 0; i < m_listPtrCount; ++i)
			delete[] m_listPtrs[i];
		delete[] m_listPtrs;
		delete[] m_listCapacities;
	}
	void copy(const DynamicStack& stack)
	{
		m_listPtrCapacity = stack.m_listPtrCapacity;
		m_listPtrCount = stack.m_listPtrCount;
		m_curListIndex = stack.m_curListIndex;
		m_topIndex = stack.m_topIndex;
		m_totalSize = stack.m_totalSize;


		m_listPtrs = new T * [m_listPtrCapacity];
		m_listCapacities = new int[m_listPtrCount];

		for (int i = 0; i < m_listPtrCount; ++i)
		{
			m_listCapacities[i] = stack.m_listCapacities[i];
			m_listPtrs[i] = new T[m_listCapacities[i]];
		}

		for (int i = 0; i < m_listPtrCount; ++i)
		{
			int length = (i == m_curListIndex) ? m_topIndex + 1 : m_listCapacities[i];
			for (int j = 0; j < length; ++j)
				m_listPtrs[i][j] = stack.m_listPtrs[i][j];
		}
	}

	DynamicStack(const DynamicStack& stack)
	{
		copy(stack);
	}

	DynamicStack operator=(const DynamicStack& stack)
	{
		_delete();
		copy(stack);
	}

	T top()
	{
		return m_listPtrs[m_curListIndex][m_topIndex];
	}

	void print() {
		for (int i = m_curListIndex; i >= 0; --i)
		{
			int j = (i == m_curListIndex) ? m_topIndex : m_listCapacities[i] - 1;
			for (; j >= 0; --j)
			{
				std::cout << m_listPtrs[i][j] << std::endl;
			}
		}
	}

private:
	T** m_listPtrs;
	int* m_listCapacities;
	int m_listPtrCount = 0;
	int m_listPtrCapacity = 0;
	int m_curListIndex = 0;
	int m_topIndex = -1; //
	int m_totalSize = 0;
};