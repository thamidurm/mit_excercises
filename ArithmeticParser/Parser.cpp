#include "Parser.h"
#include "ParserException.h"

int Parser::applyBinOp(int operand2, int operand1)
{
	Type op = popOperator();

	switch (op)
	{
	case Type::OP_BIN_ADD:
		return operand1 + operand2;
	case Type::OP_BIN_SUB:
		return operand1 - operand2;
	case Type::OP_BIN_DIV:
		return operand1 / operand2;
	case Type::OP_BIN_MUL:
		return operand1 * operand2;
	}
}

int Parser::applyUnOp(int operand)
{
	Type op = popOperator();
	if (op == Type::OP_UN_MINUS)
	{
		return -operand;
	}
	return operand;
}

int Parser::apply()
{
	auto& op = m_operatorStack.top();

	if (op == Type::OP_UN_MINUS || op == Type::OP_UN_PLUS)
	{
		int operand = popOperand();
		applyUnOp(operand);
	}
	else
	{
		int operand1 = popOperand();
		int operand2 = popOperand();
		return applyBinOp(operand1, operand2);
	}
}


int Parser::parse(const std::vector<Token>&  tokens)
{
	for (auto& token : tokens)
	{
		if (token.getType() == Type::INTEGER)
		{
			m_operandStack.push(std::get<int>(token.getValue()));
		}
		else if (token.getType() == Type::CLOSE_BRACKET)
		{
			while (m_operatorStack.top() != Type::OPEN_BRACKET)
			{
				int result = apply();
				m_operandStack.push(result);
			}
			popOperator();
		}
		else {
			Type type = token.getType();
			if (m_operatorStack.empty()
				|| m_operatorStack.top() <= type
				|| type == Type::OPEN_BRACKET)
			{
				m_operatorStack.push(type);
			}
			else {

				int result = apply();
				m_operandStack.push(result);
				m_operatorStack.push(type);
			}
		}
	}
	while (!m_operatorStack.empty())
	{
		int result = apply();
		m_operandStack.push(result);
	}

	if (m_operandStack.empty())
		throw ParserException("Parser reached an invalid state");
	return m_operandStack.top();
}

int Parser::popOperand()
{
	if (m_operandStack.empty())
		throw ParserException("Expected an operand but it was not found");
	int popped = m_operandStack.top();
	m_operandStack.pop();
	return popped;
}

Type Parser::popOperator()
{
	if (m_operatorStack.empty())
		throw ParserException("Expected an operator but it was not found");
	Type popped = m_operatorStack.top();
	m_operatorStack.pop();
	return popped;
}