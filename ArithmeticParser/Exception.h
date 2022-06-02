#pragma once

#pragma once

#include <exception>
#include <string>

class Exception : public std::exception
{

public:
	std::string getMessage() const;

	Exception(std::string message) : m_message(message) {}

	Exception() {}
	~Exception() {}

private:
	std::string m_message;
};