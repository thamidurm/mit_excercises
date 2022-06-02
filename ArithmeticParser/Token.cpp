#include "Token.h"

Type Token::getType() const
{
	return m_type;
}

std::variant<int, char> Token::getValue() const
{
	return m_value;
}
