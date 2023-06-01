#ifndef CAR_H
#define CAR_H

#include "FuelGauge.h"
#include "Odometer.h"

class Car {

private:
	FuelGauge tank;
	Odometer odometer;

public:
	Car() {}

	void addToTank();
	void drive();

	void showDetails();

};

#endif