#include "MyVector.h"
#include <string.h>
MyVector::MyVector() : m_count{ 0 }, m_allocated_space{8}
{
	m_vector = new int[m_allocated_space];
}

MyVector::~MyVector()
{
	delete[] m_vector;
}

bool MyVector::Add(int value)
{
	if (m_count + 1 > m_allocated_space)
	{
		m_allocated_space *= 2;
		int* tmp = new int[m_allocated_space];
		memcpy(tmp, m_vector, m_count * sizeof(m_vector[0]));
		delete[] m_vector;
		m_vector = tmp;
		tmp = nullptr;
	}

	m_vector[m_count++] = value;
	return true;
}

bool MyVector::Delete(int index)
{
	if(index > m_count)
		return false;

	int* ptr{ m_vector };
	ptr += index;
	memmove(ptr, ptr+1, (m_count - index -1)*sizeof(int));

	--m_count;

	return true;
}

void MyVector::Iterate(int(*function)(int))
{
	for (int i{ 0 }; i < m_count; ++i)
	{
		m_vector[i] = function(m_vector[i]);
	}
}

void MyVector::Filter(bool(*function)(int))
{
	for (int i{ 0 }; i < m_count; ++i)
	{
		if (function(m_vector[i]))
		{
			Delete(i);
			--i;
		}
	}
}

int* MyVector::begin()
{
	return &(m_vector[0]);
}

int* MyVector::end()
{
	return &(m_vector[m_count]);
}
