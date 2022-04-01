#pragma once
#include "weather.h"

class Car
{
protected:
	char* model{};
	int capacity_fuel_tank{};
	int fuel_consumtion[3]{};
	int average_speed[3]{};

public:

	virtual int get_capacity() = 0;
	virtual int get_fuel_consumtion(Weather weather) = 0;
	virtual int get_average_speed(Weather weather) = 0;
	virtual char* get_model() = 0;

};