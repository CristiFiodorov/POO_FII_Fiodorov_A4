#pragma once

class Student
{
private:
	char m_name[50]{};
	float m_grade_maths{};
	float m_grade_english{};
	float m_grade_history{};

public:

	Student() = default;

	bool set_name(const char name[]);
	const char* get_name() const;

	bool set_maths_grade(float grade);
	float get_maths_grade() const;

	bool set_english_grade(float grade);
	float get_english_grade() const;

	bool set_history_grade(float grade);
	float get_history_grade() const;

	float get_average_grade() const;
};