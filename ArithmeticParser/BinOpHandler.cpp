#include "BinOpHandler.h"
#include "LexerException.h"

bool BinOpHandler::applicable(const std::string& string, size_t index) const
{
	char op = string[index];
	bool isBinOperator = op == '+' || op == '-' || op == '*' || op == '/';
	return isBinOperator && isOperandInLeft(string, index) && isOperandInRight(string, index);
}

Token BinOpHandler::getToken(char op) const
{
	switch (op)
	{
	case '+':
		return Token('+', Type::OP_BIN_ADD);
	case '-':
		return Token('-', Type::OP_BIN_SUB);
	case '*':
		return Token('*', Type::OP_BIN_MUL);
	case '/':
		return Token('/', Type::OP_BIN_DIV);
	}
	throw LexerException("Unexpected binary operator found");
}