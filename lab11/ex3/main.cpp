#include <iostream>
#include "MyVector.h"

using namespace std;


int main()
{
	MyVector v{};

	v.Add(10);
	v.Add(-254);
	v.Add(20);
	v.Add(50);
	v.Add(9);
	v.Add(99);
	//v.Add(34234);

	v.Delete(1);

	for (auto e : v)
		cout << e << " ";


	auto f = [](int a) {
		return a + 1;
	};


	v.Iterate(f);


	cout << endl;
	for (auto e : v)
		cout << e << " ";

	v.Filter([](int a) {return a % 2 == 0; });

	cout << endl;
	for (auto e : v)
		cout << e << " ";

	return 0;
}