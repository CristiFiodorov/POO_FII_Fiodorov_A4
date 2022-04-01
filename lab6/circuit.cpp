#include "circuit.h"
#include "car.h"
#include "weather.h"

double Circuit::race_car(Car* car, Weather weather, int circuit_length)
{
	double drive_hours = car->get_capacity() / car->get_fuel_consumtion(weather);
	double distance_done = drive_hours * car->get_average_speed(weather);

	if (distance_done > circuit_length)
		return -1;
	return (drive_hours * circuit_length / distance_done);
}

Circuit::Circuit() : circuit_length{ 100 }, number_of_cars{ 0 }, circuit_weather{Sunny}
{
	for (int i{0}; i < car)
}

void Circuit::SetLength(int length)
{
	circuit_length = length;
}

void Circuit::SetWeather(Weather weather)
{
	circuit_weather = weather;
}

void Circuit::AddCar(Car* car)
{
	if(number_of_cars < 20)
		cars[number_of_cars++] = car;
}

void Circuit::Race()
{

}

void Circuit::ShowFinalRanks()
{
}

void Circuit::ShowWhoDidNotFinish()
{
}
