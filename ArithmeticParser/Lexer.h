#pragma once

#include <string>
#include <string_view>
#include <vector>

#include "NonDigitHandlerChain.h"
#include "Token.h"

class Lexer
{
public:
	Lexer(){}
	~Lexer(){}
	std::vector<Token> tokenize(const std::string& string);
private:
	NonDigitHandlerChain m_nonDigitHandlerChain;
	std::vector<Token> m_tokens;

	void addNumberToTokens(const std::string_view& string, size_t tokenStart, size_t nextTokenStart);
	bool isNotWhitespace(char c) const;
	std::string removeWhitespace(const std::string& string) const;
};