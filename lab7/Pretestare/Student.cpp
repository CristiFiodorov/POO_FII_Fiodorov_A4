#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"
#include <iostream>

Student::Student(const char* nume) 
	: m_nota_mate{ 0 },
	m_nota_romana{0},
	m_nota_franceza{0},
	m_nota_sport{0}
{
	m_nume = new char[strlen(nume+1)];
	strcpy(m_nume, nume);
}

char* Student::GetName()
{
	return m_nume;
}

void Student::PrintNote()
{
	if(m_nota_mate != 0)
		std::cout << "Matematica: " << m_nota_mate << std::endl;
	if (m_nota_romana != 0)
		std::cout << "Romana: " << m_nota_romana << std::endl;
	if (m_nota_franceza != 0)
		std::cout << "Franceza: " << m_nota_franceza << std::endl;
	if (m_nota_sport != 0)
		std::cout << "Sport: " << m_nota_sport << std::endl;
}

Student::operator float() const
{
	float medie{ 0 };
	int materii{ 0 };

	if (m_nota_mate != 0)
	{
		medie += m_nota_mate;
		++materii;
	}
	if (m_nota_romana != 0)
	{
		medie += m_nota_romana;
		++materii;
	}
	if (m_nota_franceza != 0)
	{
		medie += m_nota_franceza;
		++materii;
	}
	if (m_nota_sport != 0)
	{
		medie += m_nota_sport;
		++materii;
	}

	return medie / materii;
}

int& Student::operator[](const char* materie)
{
	if (strcmp(materie, "matematica") == 0)
		return m_nota_mate;
	if (strcmp(materie, "romana") == 0)
		return m_nota_romana;
	if (strcmp(materie, "franceza") == 0)
		return m_nota_franceza;
	if (strcmp(materie, "sport") == 0)
		return m_nota_sport;

}
