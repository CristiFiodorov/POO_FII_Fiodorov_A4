#pragma once

#include "car.h"

class Mazda : public Car
{
public:
	Mazda();

	int get_capacity() override;
	int get_fuel_consumtion(Weather weather) override;
	int get_average_speed(Weather weather) override;
	char* get_model() override;
};