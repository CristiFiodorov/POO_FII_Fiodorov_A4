#pragma once


class Number
{
	char* m_number{};
	int m_base{};

public:
	Number(const char* value, int base); // where base is between 2 and 16
	Number(int n);
	~Number();

	Number(const Number& n);
	Number(Number&& n);

	Number& operator= (const Number& n);
	Number& operator= (Number&& n);
	Number& operator+= (const Number& n);

	Number& operator= (int n);
	Number& operator= (const char* n);

	char& operator[](int index);

	void operator--();
	void operator--(int);


	// add operators and copy/move constructor
	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base

	friend Number operator+(const Number& n1, const Number& n2);
	friend Number operator-(const Number& n1, const Number& n2);

	friend bool operator==(const Number& n1, const Number& n2);
	friend bool operator!=(const Number& n1, const Number& n2);
	friend bool operator<(const Number& n1, const Number& n2);
	friend bool operator>(const Number& n1, const Number& n2);
	friend bool operator<=(const Number& n1, const Number& n2);
	friend bool operator>=(const Number& n1, const Number& n2);
};