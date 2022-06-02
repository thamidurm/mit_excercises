#include "ParenthesisHandler.h"

bool ParenthesisHandler::applicable(const std::string& string, size_t index) const
{
	char op = string[index];
	return op == '(' || op == ')';
}

Token ParenthesisHandler::getToken(char parenthesis) const
{
	if (parenthesis == '(')
	{
		return Token('(', Type::OPEN_BRACKET);
	}
	else
	{
		return Token(')', Type::CLOSE_BRACKET);
	}
}
