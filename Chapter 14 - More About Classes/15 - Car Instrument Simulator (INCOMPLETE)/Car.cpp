#include "Car.h"

#include<iostream>

using std::cout;

void Car::addToTank() {

	tank.addFuel();

}

void Car::drive() {

	odometer.addMileage(tank);

}

void Car::showDetails() {

	cout << "Car Information: \n";
	cout << "-----------------\n";

	cout << tank;
	cout << odometer;
	cout << "\n";

}