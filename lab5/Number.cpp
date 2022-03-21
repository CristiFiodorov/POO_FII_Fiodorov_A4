#define _CRT_SECURE_NO_WARNINGS
#include "Number.h"
#include <cstring>
#include <iostream>
#include <stdio.h>

int letter_to_figure(char c)
{
	if (c >= '0' && c <= '9')
		return (int)c - '0';
	else
		return (int)c - 'A' + 10;
}

char figure_to_letter(int n)
{
	if (n >= 10)
		return char(n + 55);
	else
		return char(n + 48);
}

char* invert_char(char* a)
{
	int len = strlen(a);
	char* b{ new char[len+1] };
	for (int i{ 0 }; i < len; ++i)
		b[i] = a[len - i - 1];
	b[len] = '\0';
	return b;
}

char* ConvertFromDec(int number, int base)
{
	char* num{ new char[50] };
	int i{ 0 };

	while (number > 0)
	{
		int rest = number % base;
		char cif = figure_to_letter(rest);
		num[i] = cif;
		number = number / base;

		++i;
	}

	num[i] = '\0';
	return invert_char(num);
}

int ConvertToDec(char* number, int base)
{
	int len = strlen(number);
	int power{ 1 };
	int num { 0 };

	for (int i{ len - 1 }; i >= 0; --i)
	{
		if (letter_to_figure(number[i]) >= base)
		{
			printf("Invalid Number");
			return -1;
		}

		num += letter_to_figure(number[i]) * power;
		power = power * base;
	}

	return num;
}


//=========================================================================

Number::Number(const char* value, int base = 10)
{
	if (base >= 2 && base <= 16)
	{
		m_base = base;

		int size = strlen(value);
		
		m_number = new char[size + 1];
		strcpy(m_number, value);
	}
}

Number::Number(int n) : m_base{ 10 }, m_number{ ConvertFromDec(n, 10) }
{
}

Number::~Number()
{
	delete[] m_number;
}

Number::Number(const Number& n)
{
	strcpy(m_number, n.m_number);
	m_base = n.m_base;
}

Number::Number(Number&& n)
{
	m_base = n.m_base;
	m_number = n.m_number;
	n.m_number = nullptr;
}

Number& Number::operator=(const Number& n)
{
	delete[] m_number;
	m_number = new char[strlen(n.m_number) + 1];
	strcpy(m_number, n.m_number);
	m_base = n.m_base;
	return *this;
}

Number& Number::operator=(Number&& n)
{ 
	if (this != &n)
	{
		delete[] m_number;
		m_number = n.m_number;
		n.m_number = nullptr;
		m_base = n.m_base;
	}
	return *this;
}

Number& Number::operator+=(const Number& n)
{
	int suma{ ConvertToDec(m_number, m_base) + ConvertToDec(n.m_number, n.m_base) };

	delete[] m_number;
	char* str{ ConvertFromDec(suma, m_base) };
	m_number = new char[strlen(str) + 1];
	strcpy(m_number, str);
	return *this;
}

Number& Number::operator=(int n)
{
	delete[] m_number;
	char* str = ConvertFromDec(n, 10);
	m_number = new char[strlen(str) + 1];
	strcpy(m_number, str);
	m_base = 10;
	return *this;
}

Number& Number::operator=(const char* str)
{
	delete[] m_number;
	m_number = new char[strlen(str) + 1];
	strcpy(m_number, str);
	m_base = 10;
	return *this;
}

char& Number::operator[](int index)
{
	if (index >= 0 && index < strlen(m_number))
	{
		return m_number[index];
	}
}

void Number::operator--()
{
	strcpy(m_number, m_number + 1);
}

void Number::operator--(int)
{
	m_number[strlen(m_number) - 1] = '\0';
}

void Number::SwitchBase(int newBase)
{
	int number = ConvertToDec(m_number, m_base);
	delete[] m_number;
	m_number = ConvertFromDec(number, newBase);
	m_base = newBase;
}

void Number::Print()
{
	std::cout << m_number << '\n';
}

int Number::GetDigitsCount()
{
	return strlen(m_number);
}

int Number::GetBase()
{
	return m_base;
}

Number operator+(const Number& n1, const Number& n2)
{
	int suma{ConvertToDec(n1.m_number, n1.m_base) + ConvertToDec(n2.m_number, n2.m_base)};
	int base = (n1.m_base > n2.m_base ? n1.m_base : n2.m_base);

	return Number{ ConvertFromDec(suma, base), base };
}

Number operator-(const Number& n1, const Number& n2)
{
	int dif{ ConvertToDec(n1.m_number, n1.m_base) - ConvertToDec(n2.m_number, n2.m_base) };
	int base = (n1.m_base > n2.m_base ? n1.m_base : n2.m_base);

	return Number{ ConvertFromDec(dif, base), base };
}

bool operator==(const Number& n1, const Number& n2)
{
	return ConvertToDec(n1.m_number, n1.m_base) == ConvertToDec(n2.m_number, n2.m_base);
}

bool operator!=(const Number& n1, const Number& n2)
{
	return !(n1 == n2);
}

bool operator<(const Number& n1, const Number& n2)
{
	return ConvertToDec(n1.m_number, n1.m_base) < ConvertToDec(n2.m_number, n2.m_base);
}

bool operator>(const Number& n1, const Number& n2)
{
	return n2 < n1;
}

bool operator<=(const Number& n1, const Number& n2)
{
	return !(n1 > n2);
}

bool operator>=(const Number& n1, const Number& n2)
{
	return !(n1 < n2);
}