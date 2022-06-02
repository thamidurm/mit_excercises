#pragma once

#include <stack>
#include <vector>

#include "Lexer.h"
#include "Token.h"
#include "Type.h"

class Parser
{
public:

	Parser(){}
	~Parser(){}

	int applyBinOp(int operand2, int operand1);
	int applyUnOp(int operand);
	int apply();
	int parse(const std::vector<Token>& tokens);
	int popOperand();
	Type popOperator();

private:
	std::stack<int> m_operandStack;
	std::stack<Type> m_operatorStack;
};