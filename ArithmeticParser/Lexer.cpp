#include "Lexer.h"

std::vector<Token> Lexer::tokenize(const std::string& rawString)
{
	auto string = removeWhitespace(rawString);
	int tokenStart = 0;
	bool scanningNum = false;
	for (size_t i = 0; i < string.size(); ++i)
	{
		if (!std::isdigit(string[i]))
		{
			if (scanningNum)
			{
				addNumberToTokens(string, tokenStart, i);
				scanningNum = false;
			}
			auto token = m_nonDigitHandlerChain.getToken(string, i);
			m_tokens.push_back(token);
		}
		else
		{
			if (!scanningNum) {
				scanningNum = true;
				tokenStart = i;
			}
		}
	}
	if (scanningNum)
	{
		addNumberToTokens(string, tokenStart, string.length());
	}
	return m_tokens;
}

std::string Lexer::removeWhitespace(const std::string& string) const
{
	std::string newStr;
	for (auto& c : string)
	{
		if (isNotWhitespace(c))
		{
			newStr += c;
		}
	}
	return newStr;
}

bool Lexer::isNotWhitespace(char c) const
{
	return c != ' ' && c != '\t' && c != '\n' && c != '\r';
}

void Lexer::addNumberToTokens(const std::string_view& string, size_t tokenStart, size_t nextTokenStart)
{
	auto substr = string.substr(tokenStart, nextTokenStart - tokenStart);
	std::string number;
	for (auto s : substr)
	{
		if (isdigit(s))
			number += s;
	}
	m_tokens.push_back(Token(std::stoi(number)));
}
