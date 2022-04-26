#include <iostream>
#include "vector.h"


int main()
{
	Vector<int> vector_int;

	vector_int.push(1);
	vector_int.push(1);
	vector_int.push(1);
	vector_int.push(1);
	vector_int.push(1);
	vector_int.push(12);
	vector_int.push(13);
	vector_int.push(1);
	vector_int.push(1);
	vector_int.push(1);
	vector_int.push(1);
	vector_int.push(1);
	vector_int.push(1);

	
	vector_int.remove(5);
	vector_int.insert(6, 99);

	std::cout << vector_int.first_index_of(13, nullptr) << '\n';

	vector_int.sort(nullptr);

	for (int j{ 0 }; j < vector_int.count(); ++j)
		std::cout << vector_int.get(j) << " ";

	return 0;
}