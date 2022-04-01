#include "mercedes.h"
#include "weather.h"

Mercedes::Mercedes()
{
	model = new char[] {"Mercedes"};
	capacity_fuel_tank = 80;
	fuel_consumtion[Sunny] = 20;
	fuel_consumtion[Rainy] = 23;
	fuel_consumtion[Snowy] = 25;

	average_speed[Sunny] = 90;
	average_speed[Rainy] = 70;
	average_speed[Snowy] = 55;
}

int Mercedes::get_capacity()
{
	return capacity_fuel_tank;
}

int Mercedes::get_fuel_consumtion(Weather weather)
{
	return fuel_consumtion[weather];
}

int Mercedes::get_average_speed(Weather weather)
{
	return average_speed[weather];
}

char* Mercedes::get_model()
{
	return model;
}