#include "Catalog.h"
#include "string.h"

Catalog::Catalog() : m_count{0}
{
}

Catalog& Catalog::operator+=(const Student s)
{
	m_students[m_count] = new Student{ s };
	++m_count;

	return *this;
}

Student& Catalog::operator[](const char* name)
{
	for (int i{ 0 }; i < m_count; ++i)
	{
		if (strcmp(name, m_students[i]->GetName()) == 0)
			return *m_students[i];
	}
}

Student& Catalog::operator[](int index)
{
	return *m_students[index];
}

int Catalog::GetCount()
{
	return m_count;
}
