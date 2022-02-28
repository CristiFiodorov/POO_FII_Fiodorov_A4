#include <iostream>
#include "Student.h"
#include "Globals.h"


int main()
{
	Student s1{};
	Student s2{};

	s1.set_name("Cristi");
	std::cout << s1.get_name() << '\n';

	s2.set_name("Marius");
	std::cout << s2.get_name() << '\n';

	s1.set_english_grade(9);
	s1.set_history_grade(8);
	s1.set_maths_grade(10);

	std::cout << s1.get_english_grade() << '\n';
	std::cout << s1.get_history_grade() << '\n';
	std::cout << s1.get_maths_grade() << '\n';
	std::cout << s1.get_average_grade() << '\n';

	s2.set_english_grade(10);
	s2.set_history_grade(8);
	s2.set_maths_grade(7);

	std::cout << compare_names(s1, s2) << '\n';
	std::cout << compare_english_grades(s1, s2) << '\n';
	std::cout << compare_history_grades(s1, s2) << '\n';
	std::cout << compare_maths_grades(s1, s2) << '\n';
	std::cout << compare_average_grades(s1, s2) << '\n';


	return 0;
}