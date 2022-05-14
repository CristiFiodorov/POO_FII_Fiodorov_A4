#include <iostream>
#include "Array.h"
#include "Compare.h"
#include "MyException.h"

using namespace std;

int comp(const int& a, const int& b)
{
	if (a == b)
		return 0;
	if (a < b)
		return 1;
	return -1;
}

int main()
{

	Array<int> inturi{ 100 };

	cout << inturi.GetCapacity() << " " << inturi.GetSize() << endl;

	inturi += 10;
	inturi += 11;
	inturi += 2;
	inturi += 99;
	inturi += 65;
	inturi += 10;

	cout << inturi.GetCapacity() << " " << inturi.GetSize() << endl;

	inturi.Delete(2);

	cout << inturi.GetCapacity() << " " << inturi.GetSize() << endl;

	for (auto el : inturi)
		cout << *el << " ";
	cout << endl;

	Array<int> inturi2{ 100 };
	inturi2 += 7;
	inturi2 += 0;
	inturi2 += 32;
	inturi2 += 1023123;

	inturi.Insert(5, 99);
	inturi.Insert(5, 76);
	inturi.Insert(5, inturi2);

	for (auto el : inturi)
		cout << *el << " ";
	cout << endl;

	inturi2 = inturi;

	cout << "Sortat: \n";
	inturi.Sort(comp);
	for (auto el : inturi)
		cout << *el << " ";
	cout << endl;


	for (auto el : inturi2)
		cout << *el << " ";
	cout << endl;


	cout << inturi2.Find(10, comp) << endl;

	cout << inturi2.BinarySearch(7, comp) << endl;

	cout << inturi2[inturi2.BinarySearch(7, comp)] << endl;
	for (auto el : inturi2)
		cout << *el << " ";
	cout << endl;


	try
	{
		cout << inturi2[1000] << endl;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}

	try
	{
		Array<int> inturi{ -9 };
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}

	try
	{
		Array<int> inturi{ 3 };
		inturi += 10;
		inturi += 3;
		inturi += 9;
		inturi += 6;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}

	return 0;
}