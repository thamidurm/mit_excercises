#pragma once

template <typename T>
class StackItem
{
public:
	StackItem<T>* getPrev()
	{
		return m_prev;
	}

	T getValue()
	{
		return m_value;
	}

	StackItem(T value, StackItem<T>* prev) : m_value(value), m_prev(prev) {};

private:
	T m_value;
	StackItem<T>* m_prev = nullptr;
};

template <typename T>
class DynamicStackLL
{
private:
	StackItem<T>* m_stackPtr;

	int m_items = 0;
public:

	~DynamicStackLL()
	{
		while (m_stackPtr) {
			auto tempCur = m_stackPtr->getPrev();
			delete m_stackPtr;
			m_stackPtr = tempCur;
		}
	}

	T pop()
	{
		if(m_stackPtr != nullptr)
		{ 
			T value = m_stackPtr->getValue();
			auto tempPtr = m_stackPtr;
			m_stackPtr = m_stackPtr->getPrev();
			delete tempPtr;
			--m_items;
			return value;
		}
		//TODO: Throw exception
	}
	T top()
	{
		return  m_stackPtr->getValue();
	}
	void push(T item)
	{
		m_stackPtr = new StackItem<T>(item, m_stackPtr);
		++m_items;
	}

	void print()
	{
		auto cur = m_stackPtr;
		while (cur != nullptr) {
			std::cout << cur->getValue() << '\n';
			cur = cur->getPrev();
		}
	}

	int getSize()
	{
		return m_items;
	}


};
