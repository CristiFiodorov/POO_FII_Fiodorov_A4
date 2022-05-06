#include "Phrase.h"
#include "string.h"
#include <iostream>

Phrase::Phrase(const char* sursa) : m_count{ 0 }, m_words{ nullptr }
{
	const char* inceput = sursa;
	const char* sfarsit = sursa;

	int i{ 0 };

	while (true)
	{
		if ( (*sfarsit == ' ' && sfarsit - inceput > 0) || (*sfarsit == '\0' && sfarsit - inceput > 1))
		{
			m_words[i] = new char[sfarsit - inceput + 1];

			memcpy(m_words[i], inceput, sfarsit - inceput);

			m_words[i][sfarsit - inceput] = '\0';

			++m_count;
			inceput = sfarsit;
			++i;
			if (*sfarsit == '\0')
				break;
		}
		if (*sfarsit == '\0')
			break;
		if(*sfarsit == ' ')
			++inceput;
		++sfarsit;
	}
}

Phrase::operator int()
{
	return m_count;
}

const char* Phrase::operator[](int index)
{
	if(index >= m_count)
		return nullptr;

	return m_words[index];
}

int Phrase::CountLetter(int index, char ch)
{
	if(index >= m_count)
		return 0;

	char* word = m_words[index];
	int count = 0;

	while (*word != '\0')
	{
		if (*word == ch)
			++count;
		++word;
	}

	return count;
}

int Phrase::CountLetter(char ch)
{
	int count = 0;

	for (int i{ 0 }; i < m_count; ++i)
	{
		count += CountLetter(i, ch);
	}

	return count;
}

const char* Phrase::GetLongestWord()
{
	if(m_count < 0)
		return nullptr;

	int longest = 0;
	char* long_word = nullptr;

	for (int i{ 0 }; i < m_count; ++i)
	{
		char* word_i = m_words[i];
		char* word = m_words[i];
		int len = 0;
		while (*word_i != '\0')
		{
			++len;
			++word_i;
		}

		if (len > longest)
		{
			longest = len;
			long_word = word;
		}
	}

	return long_word;
}

int Phrase::CountVowels()
{
	if (m_count < 0)
		return 0;

	int count = 0;

	for (int i{ 0 }; i < m_count; ++i)
	{
		char* word = m_words[i];

		while (*word != '\0')
		{
			if (*word == 'a' || *word == 'e' || *word == 'i' || *word == 'o' || *word == 'u' ||
				*word == 'A' || *word == 'E' || *word == 'I' || *word == 'O' || *word == 'U')
				++count;
			++word;
		}
	}

	return count;
}
