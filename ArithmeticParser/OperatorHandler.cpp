#include "OperatorHandler.h"

bool OperatorHandler::isOperandInLeft(const std::string& string, size_t index) const
{
	if (index > 0)
	{
		char prev = string[index - 1];
		if (std::isdigit(prev) || prev == ')')
			return true;
	}
	return false;
}

bool OperatorHandler::isOperandInRight(const std::string& string, size_t index) const
{
	if (index < string.length() - 1)
	{
		char next = string[index + 1];
		if (std::isdigit(next) || next == '(')
			return true;
	}
	return false;
}