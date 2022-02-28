#include <iostream>
#include "NumberList.h"


int main()
{
	NumberList list;

	list.Init();

	list.Add(2);
	list.Print();
	list.Add(1);
	list.Print();
	list.Sort();
	list.Print();

	return 0;
}