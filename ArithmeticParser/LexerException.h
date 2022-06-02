#pragma once

#include "Exception.h"

class LexerException : public Exception
{

public:
	LexerException(const std::string& msg) : Exception(msg){}
	~LexerException() {}
};