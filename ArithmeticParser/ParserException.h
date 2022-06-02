#pragma once
#pragma once

#include "Exception.h"

class ParserException : public Exception
{

public:
	ParserException(const std::string& msg) : Exception(msg) {}
	~ParserException() {}
};