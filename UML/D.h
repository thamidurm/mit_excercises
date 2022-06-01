#pragma once
#include "B.h"
#include "C.h"
class D : public B, public C 
{
public:
	void run() {
		B::run();
	}
};