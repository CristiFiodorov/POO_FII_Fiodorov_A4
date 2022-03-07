#define _CRT_SECURE_NO_WARNINGS

#include "Math.h"
#include <iostream>

using namespace std;

int main()
{
    cout << Math::Add(1, 2, 3) << endl;
    cout << Math::Add(1, 2) << endl;
    cout << Math::Add(3.5, 2.0) << endl;
    cout << Math::Add(1.5, 3.0, 3.6) << endl;
    cout << Math::Mul(3, 3) << endl;
    cout << Math::Mul(3, 3, 3) << endl;
    cout << Math::Mul(3.5, 3.5) << endl;
    cout << Math::Mul(3.5, 3.5, 3.5) << endl;
    cout << Math::Add(5, 1, 2, 3, 4, 5) << endl;
    cout << Math::Add("Salut " , "Ce faci? ") << endl;
	
	return 0;
}