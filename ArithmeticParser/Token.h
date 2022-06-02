#pragma once

#include "Type.h"

#include <variant>

class Token
{
public:
	Type getType() const;
	std::variant<int, char> getValue() const;

	Token(int integer) : m_type(Type::INTEGER), m_value(integer) {}
	Token(char nonInteger, Type type) : m_value(nonInteger), m_type(type) {}
	~Token() {}
private:
	Type m_type;
	std::variant<int, char> m_value;
};