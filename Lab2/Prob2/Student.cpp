#define _CRT_SECURE_NO_WARNINGS

#include "Student.h"
#include <cstring>

bool Student::set_name(const char name[])
{
	if (strlen(name) < 50)
	{
		strcpy(m_name, name);
		return true;
	}
	return false;
}
const char* Student::get_name() const 
{
	return m_name;
}

bool Student::set_maths_grade(float grade)
{
	if (grade >= 0 && grade <= 10)
	{
		m_grade_maths = grade;
		return true;
	}

	return false;
}
float Student::get_maths_grade() const
{
	return m_grade_maths;
}

bool Student::set_english_grade(float grade)
{
	if (grade >= 0 && grade <= 10)
	{
		m_grade_english = grade;
		return true;
	}

	return false;
}
float Student::get_english_grade() const
{
	return m_grade_english;
}

bool Student::set_history_grade(float grade)
{
	if (grade >= 0 && grade <= 10)
	{
		m_grade_history = grade;
		return true;
	}

	return false;
}
float Student::get_history_grade() const
{
	return m_grade_history;
}

float Student::get_average_grade() const
{
	return (m_grade_english + m_grade_history + m_grade_maths) / 3;
}
