#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	vector<string> v{ "bb", "aa", "aaa" };

	sort(v.begin(), v.end(), 
		[](string a, string b) 
		{
			if (a.length() < b.length())
				return true;
			else if (a.length() > b.length())
				return false;

			if (a < b)
				return true;

			return false;
		});

	for (auto str : v)
		cout << str << " ";

	cout << endl;


	vector inturi{ 1, 2, 4, 100, -1, -82, 3 };

	auto biggest_number_function = [](vector<int> v)
	{
		int biggest = v[0];
		for (auto e : v)
			if (e > biggest)
				biggest = e;

		return biggest;
	};

	cout << biggest_number_function(inturi) << endl;

	return 0;
}