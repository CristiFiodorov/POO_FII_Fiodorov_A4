#include <iostream>
#include "circuit.h"
#include "car.h"
#include "weather.h"

double Circuit::race_car(Car* car, Weather w, int length)
{
	double drive_hours = car->get_capacity() / car->get_fuel_consumtion(w);
	double distance_done = drive_hours * car->get_average_speed(w);

	if (distance_done < length)
		return -1;
	return (drive_hours * length / distance_done);
}

void Circuit::car_sort()
{
	for (int i{ 0 }; i < number_of_cars; i++)
		for (int j{ 0 }; j < number_of_cars - i - 1; j++)
			if (finish_time[j] > finish_time[j + 1])
			{
				double time = finish_time[j];
				finish_time[j] = finish_time[j + 1];
				finish_time[j + 1] = time;

				Car* car = cars[j];
				cars[j] = cars[j + 1];
				cars[j + 1] = car;
			}
}

Circuit::Circuit() : circuit_length{ 100 }, number_of_cars{ 0 }, circuit_weather{Sunny}
{
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
	for (int i{ 0 }; i < number_of_cars; ++i)
	{
		finish_time[i] = race_car(cars[i], circuit_weather, circuit_length);
	}
}

void Circuit::ShowFinalRanks()
{
	car_sort();
	int place{ 0 };

	for (int i{ 0 }; i < number_of_cars; ++i)
	{
		if (finish_time[i] != -1)
		{
			++place;
			std::cout << place << ". " << cars[i]->get_model() << " -- Time: " << finish_time[i] << std::endl;
		}
	}
}

void Circuit::ShowWhoDidNotFinish()
{
	for (int i{ 0 }; i < number_of_cars; ++i)
	{
		if (finish_time[i] == -1)
		{
			std::cout << cars[i]->get_model() << " has not finished the race! " << std::endl;
		}
	}
}
