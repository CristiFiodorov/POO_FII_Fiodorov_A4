#include "dacia.h"
#include "weather.h"

Dacia::Dacia()
{
	model = new char[] {"Dacia"};
	capacity_fuel_tank = 50;
	fuel_consumtion[Sunny] = 10;
	fuel_consumtion[Rainy] = 14;
	fuel_consumtion[Snowy] = 17;

	average_speed[Sunny] = 70;
	average_speed[Rainy] = 50;
	average_speed[Snowy] = 35;
}

int Dacia::get_capacity()
{
	return capacity_fuel_tank;
}

int Dacia::get_fuel_consumtion(Weather weather)
{
	return fuel_consumtion[weather];
}

int Dacia::get_average_speed(Weather weather)
{
	return average_speed[weather];
}


char* Dacia::get_model()
{
	return model;
}
