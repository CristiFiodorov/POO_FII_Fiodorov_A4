#pragma warning(disable:4996)
#pragma once
#include <string.h>
#include <exception>

class MyException : public std::exception
{
private:
	char m_error[100];

public:

	MyException(const char* error)
	{
		strcpy(m_error, error);
	}

	const char* what() const noexcept override
	{
		return m_error;
	}
};

