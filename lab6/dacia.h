#pragma once
#include "car.h"

class Dacia : public Car
{
public:
	Dacia();

	int get_capacity() override;
	int get_fuel_consumtion(Weather weather) override;
	int get_average_speed(Weather weather) override;
	char* get_model() override;
};