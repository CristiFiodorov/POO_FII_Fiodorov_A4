#pragma once
#include "Student.h"

class Catalog
{
private:
	Student* m_students[100];
	int m_count{0};

public:

	Catalog();

	Catalog& operator +=(const Student s);

	Student& operator[](const char* name);
	Student& operator[](int index);

	int GetCount();
};