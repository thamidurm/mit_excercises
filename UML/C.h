#pragma once

#include "A.h"
class C : public A
{
public:
	virtual void run()
	{
		puts("C's run method!");
	}
private:
	int m_z;
};