#pragma once

#include "car.h"

class Mazda : public Car
{
public:
	Mazda();


	double race_car(Weather weather, int circuit_length) override;
	char* get_model() override;
};