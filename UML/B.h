#pragma once
#include "A.h"

class B : public A 
{
public:
	virtual void run()
	{
		puts("B's run method!");
	}
private:
	int m_y;
};