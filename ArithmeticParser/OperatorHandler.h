#pragma once

#include <string>

#include "NonDigitHandler.h"

class OperatorHandler : public NonDigitHandler
{
public:
	OperatorHandler(){}
	~OperatorHandler(){}
protected:
	bool isOperandInLeft(const std::string& string, size_t index) const;
	bool isOperandInRight(const std::string& string, size_t index) const;
};
