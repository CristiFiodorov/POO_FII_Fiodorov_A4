#include <iostream>
#include "weather.h"
#include "dacia.h"
#include "toyota.h"
#include "mercedes.h"
#include "ford.h"
#include "mazda.h"
#include "circuit.h"

int main()
{
	Circuit c;
	c.SetLength(150);
	c.SetWeather(Weather::Rainy);
	c.AddCar(new Dacia());
	c.AddCar(new Toyota());
	c.AddCar(new Mercedes());
	c.AddCar(new Ford());
	c.AddCar(new Mazda());
	c.Race();
	c.ShowFinalRanks(); // it will print the time each car needed to finish the circuit sorted from the fastest car to the   slowest.
	c.ShowWhoDidNotFinish(); // it is possible that some cars don't have enough fuel to finish the circuit
	return 0;
}