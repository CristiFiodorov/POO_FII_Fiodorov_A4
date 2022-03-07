#define _CRT_SECURE_NO_WARNINGS
#include "Math.h";
#include <cstdarg>
#include <string.h>


int Math::Add(int a, int b)
{
	return a + b;
}

int Math::Add(int a, int b, int c)
{
	return a + b + c;
}

int Math::Add(double a, double b)
{
	return a + b;
}

int Math::Add(double a, double b, double c)
{
	return a + b + c;
}

int Math::Mul(int a, int b)
{
	return a * b;
}

int Math::Mul(int a, int b, int c)
{
	return a * b * c;
}

int Math::Mul(double a, double b)
{
	return a * b;
}
int Math::Mul(double a, double b, double c)
{
	return a * b * c;
}
int Math::Add(int count, ...)
{
	int suma{ 0 };
	
	va_list v;
	va_start(v, count);

	for (int i = 0; i < count; i++) {
		suma += va_arg(v, int);
	}

	return suma;
}

char* Math::Add(const char* a, const char* b)
{
	if (a == nullptr || b == nullptr)
		return nullptr;

	int size_a{ 0 };
	int size_b{ 0 };

	int i{ 0 };

	while (a[i] != '\0' || b[i] != '\0')
	{
		if (a[i] != '\0')
		{
			++size_a;
		}
		if (b[i] != '\0')
		{
			++size_a;
		}
		++i;
	}

	char* str{ new char[size_a + size_b + 1] };

	strcpy(str, a);
	strcat(str, b);

	return str;
}