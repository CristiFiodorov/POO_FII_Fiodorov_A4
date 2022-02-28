#include "NumberList.h"

#include <iostream>

/*
* ===Constructor===
* 
* NumberList() : m_count{0}
* {
* }
*/

void NumberList::Init()
{
	m_count = 0;
}


bool NumberList::Add(int x)      // adds X to the numbers list and increase the data member count.
{                                // if count is bigger or equal to 10, the function will return false
	if (m_count < 10)
	{
		m_numbers[m_count++] = x;
		return true;
	}

	return false;
}

void NumberList::Sort()
{
	int swap_v{};

	for (int i{ 0 }; i < m_count - 1; i++)
		for (int j{ 0 }; j < m_count - i - 1; j++)
			if (m_numbers[j] > m_numbers[j + 1])
			{
				swap_v = m_numbers[j];
				m_numbers[j] = m_numbers[j + 1];
				m_numbers[j + 1] = swap_v;
			}
}


void NumberList::Print()
{
	std::cout << m_numbers[m_count - 1];
}