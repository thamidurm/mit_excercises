#pragma once
#include <cstdio>
class A
{
public:
	virtual void run() 
	{
		puts("A's run method!");
	}
private:
	int m_x;
};