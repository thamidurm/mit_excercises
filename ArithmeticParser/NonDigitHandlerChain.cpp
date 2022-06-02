#include "NonDigitHandlerChain.h"

Token NonDigitHandlerChain::getToken(const std::string& string, size_t index) const
{
	for (auto& handler : m_handlers)
	{
		if (handler->applicable(string, index))
		{
			return handler->getToken(string[index]);
		}
	}
	throw LexerException("Unexpected character encountered");
}
