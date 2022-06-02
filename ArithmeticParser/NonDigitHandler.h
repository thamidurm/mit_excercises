#pragma once

#include <string>

#include "LexerException.h"
#include "Token.h"

class NonDigitHandler
{
public:
	virtual Token getToken(char nonDigit) const = 0;
	virtual bool applicable(const std::string& string, size_t index) const = 0;
};