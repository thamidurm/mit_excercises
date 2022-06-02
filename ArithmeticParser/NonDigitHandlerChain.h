#pragma once

#include <array>
#include <memory>
#include <string>

#include "BinOpHandler.h"
#include "NonDigitHandler.h"
#include "ParenthesisHandler.h"
#include "Token.h"
#include "UnaryOpHandler.h"

class NonDigitHandlerChain
{
public:
	Token getToken(const std::string& string, size_t index) const;
	NonDigitHandlerChain(){}
	~NonDigitHandlerChain(){}
private:
	std::array<std::unique_ptr<NonDigitHandler>, 3> m_handlers = {
		std::make_unique<BinOpHandler>(),
		std::make_unique<UnaryOpHandler>(),
		std::make_unique<ParenthesisHandler>(),
	};
};