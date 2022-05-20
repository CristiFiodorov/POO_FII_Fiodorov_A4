#pragma once

class MyVector
{
private:
	int* m_vector;
	int m_count;
	int m_allocated_space;

public:
	MyVector();
	~MyVector();

	bool Add(int); // return true if the value was added. As a result, the size of the vector increases with one.
	bool Delete(int index); // returns true if the value from the index was removed. As a result, the size of the vector decreases with one.

	void Iterate(int (*function)(int));
	void Filter(bool (*function)(int));

	int* begin();
	int* end();
};

