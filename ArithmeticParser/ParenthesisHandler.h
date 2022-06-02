#pragma once

#include <string>

#include "NonDigitHandler.h"
#include "Token.h"

class ParenthesisHandler : public NonDigitHandler
{
public:

	ParenthesisHandler() {}
	~ParenthesisHandler() {}

	bool applicable(const std::string& string, size_t index) const;

	Token getToken(char parenthesis) const;
};
