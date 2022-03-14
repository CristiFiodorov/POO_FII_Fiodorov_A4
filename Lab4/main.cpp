#include <iostream>
#include "Sort.h"

int main()
{
	char str[] = "10,2,5,3,1,8,9,100";
	Sort s{str};
	s.QuickSort(true);

	s.Print();

	return 0;
}