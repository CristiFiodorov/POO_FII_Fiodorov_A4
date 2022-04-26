#include <iostream>
#include <vector>

double operator"" _Kelvin(unsigned long long g)
{
    return g - 273.15;
}

double operator"" _Fahrenheit(unsigned long long g)
{
    return (g - 32) / 1.8;
}

int main() {

    float a = 300_Kelvin;

    float b = 120_Fahrenheit;


    std::cout << a << " " << b;

    return 0;

}

