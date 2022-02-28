#include <cstring>
#include "Student.h"
#include "Globals.h"

int compare_names(const Student& s1, const Student& s2)
{
	return strcmp(s1.get_name(), s2.get_name());
}

int compare_maths_grades(const Student& s1, const Student& s2)
{
	return (s1.get_maths_grade() > s2.get_maths_grade()) ?
		1 : s1.get_maths_grade() < s2.get_maths_grade() ?
		-1 : 0;
}

int compare_english_grades(const Student& s1, const Student& s2)
{
	return (s1.get_english_grade() > s2.get_english_grade()) ?
		1 : s1.get_english_grade() < s2.get_english_grade() ?
		-1 : 0;
}

int compare_history_grades(const Student& s1, const Student& s2)
{
	return (s1.get_history_grade() > s2.get_history_grade()) ?
		1 : s1.get_history_grade() < s2.get_history_grade() ?
		-1 : 0;
}

int compare_average_grades(const Student& s1, const Student& s2)
{
	return (s1.get_average_grade() > s2.get_average_grade()) ?
		1 : s1.get_average_grade() < s2.get_average_grade() ?
		-1 : 0;
}