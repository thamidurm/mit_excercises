#include "UnaryOpHandler.h"

bool UnaryOpHandler::applicable(const std::string& string, size_t index) const
{
	char op = string[index];
	bool isUnOperator = op == '+' || op == '-';
	return isUnOperator && isOperandInRight(string, index) && !isOperandInLeft(string, index);
}

Token UnaryOpHandler::getToken(char op) const
{
	if (op == '+')
	{
		return Token('+', Type::OP_UN_PLUS);
	}
	else
	{
		return Token('-', Type::OP_UN_MINUS);
	}
}
