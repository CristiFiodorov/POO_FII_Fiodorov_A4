#include "toyota.h"
#include "weather.h"

Toyota::Toyota()
{
	model = new char[] {"Toyota"};
	capacity_fuel_tank = 70;
	fuel_consumtion[Sunny] = 17;
	fuel_consumtion[Rainy] = 19;
	fuel_consumtion[Snowy] = 21;

	average_speed[Sunny] = 80;
	average_speed[Rainy] = 60;
	average_speed[Snowy] = 45;
}

int Toyota::get_capacity()
{
	return capacity_fuel_tank;
}

int Toyota::get_fuel_consumtion(Weather weather)
{
	return fuel_consumtion[weather];
}

int Toyota::get_average_speed(Weather weather)
{
	return average_speed[weather];
}

char* Toyota::get_model()
{
	return model;
}