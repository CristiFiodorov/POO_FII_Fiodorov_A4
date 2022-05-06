#pragma once


class Phrase
{
public:
	char* m_words[100];
	int m_count;

public:

	Phrase(const char* sursa);

	operator int();

	const char* operator[] (int index);

	int CountLetter(int index, char ch);
	int CountLetter(char ch);

	const char* GetLongestWord();
	int CountVowels();

};

