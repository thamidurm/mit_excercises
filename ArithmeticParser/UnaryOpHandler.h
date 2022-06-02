#pragma once

#include <string>

#include "OperatorHandler.h"
#include "Token.h"

class UnaryOpHandler : public OperatorHandler
{
public:

	UnaryOpHandler() {}
	~UnaryOpHandler() {}

	bool applicable(const std::string& string, size_t index) const;
	Token getToken(char op) const;
};