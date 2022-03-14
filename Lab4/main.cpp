#include <iostream>
#include "Sort.h"

int main()
{
	char str[] = "1,2,5,3,8,9,100";
	Sort s{};
	s.BubbleSort(false);

	s.Print();

	return 0;
}