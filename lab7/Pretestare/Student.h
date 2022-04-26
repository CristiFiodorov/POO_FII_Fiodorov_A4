#pragma once

class Student
{
private:

	char* m_nume;
	int m_nota_mate;
	int m_nota_romana;
	int m_nota_franceza;
	int m_nota_sport;

public:

	Student(const char*);

	char* GetName();
	void PrintNote();

	operator float() const;

	int& operator[] (const char* materie);
};