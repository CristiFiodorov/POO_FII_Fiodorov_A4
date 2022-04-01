#include "ford.h"
#include "weather.h"

Ford::Ford()
{
	model = new char[] {"Ford"};
	capacity_fuel_tank = 60;
	fuel_consumtion[Sunny] = 13;
	fuel_consumtion[Rainy] = 16;
	fuel_consumtion[Snowy] = 18;

	average_speed[Sunny] = 75;
	average_speed[Rainy] = 60;
	average_speed[Snowy] = 35;
}

int Ford::get_capacity()
{
	return capacity_fuel_tank;
}

int Ford::get_fuel_consumtion(Weather weather)
{
	return fuel_consumtion[weather];
}

int Ford::get_average_speed(Weather weather)
{
	return average_speed[weather];
}

char* Ford::get_model()
{
	return model;
}