#pragma once

#include <string>

#include "OperatorHandler.h"
#include "Token.h"

class BinOpHandler : public OperatorHandler
{
public:

	BinOpHandler() {}
	~BinOpHandler() {}

	bool applicable(const std::string& string, size_t index) const;
	Token getToken(char op) const;
};
