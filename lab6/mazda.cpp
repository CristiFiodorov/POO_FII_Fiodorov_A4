#include "mazda.h"
#include "weather.h"

Mazda::Mazda()
{
	model = new char[] {"Mazda"};
	capacity_fuel_tank = 40;
	fuel_consumtion[Sunny] = 9;
	fuel_consumtion[Rainy] = 11;
	fuel_consumtion[Snowy] = 13;

	average_speed[Sunny] = 80;
	average_speed[Rainy] = 55;
	average_speed[Snowy] = 45;
}


int Mazda::get_capacity()
{
	return capacity_fuel_tank;
}

int Mazda::get_fuel_consumtion(Weather weather)
{
	return fuel_consumtion[weather];
}

int Mazda::get_average_speed(Weather weather)
{
	return average_speed[weather];
}

char* Mazda::get_model()
{
	return model;
}