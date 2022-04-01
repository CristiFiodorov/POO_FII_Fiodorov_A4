#pragma once
#include "weather.h"
#include "car.h"

class Circuit 
{
private:
	int circuit_length{};
	int number_of_cars{};
	Weather circuit_weather{};

	Car* cars[20]{};
	float finish_time[20]{};
	bool finish[20]{};
	double race_car(Car* car, Weather weather, int circuit_length) {};

public:

	Circuit();

	void SetLength(int length);
	void SetWeather(Weather weather );

	void AddCar(Car* car);

	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();

};