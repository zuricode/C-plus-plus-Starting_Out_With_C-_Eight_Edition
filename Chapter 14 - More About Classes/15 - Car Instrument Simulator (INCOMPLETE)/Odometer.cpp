#include "Odometer.h"
#include <iostream>

using std::cin;
using std::cout;

bool Odometer::checkMileage(const double MILES) {

	if (mileage + MILES <= MAX_MILEAGE) {
		return true;
	}
	else {
		return false;
	}

}

void Odometer::addMileage(const double MILES, FuelGauge& f) {



	if(checkMileage(MILES)) {
		mileage += MILES;
	}
	else {
		cout << "The current mileage reading is " << mileage << ".\n";
		cout << MILES << " extra miles will surpass the gauge limit of " << MAX_MILEAGE << ", reset to 0 and resume as normal.\n";
		mileage += MILES;
		mileage = (mileage - MAX_MILEAGE) - 1;		
		cout << "The new mileage gauge shows " << mileage << " miles.\n";
		cout << "\n";
	}

	updateFuelGauge(MILES, f);

}

void Odometer::addMileage(FuelGauge& f) {

	double num;

	cout << "Enter a distance you would like to drive (miles): ";

	while (!(cin >> num) || num <= 0) {
		cout << "ERROR: Mileage value must be a positive value.\n";
		cout << "\n";
		cout << "Miles to drive: ";
	}

	cout << "\n";

	if (checkFuelForMileage(num, f)) {
		addMileage(num, f);
	}

}

bool Odometer::checkFuelForMileage(const double MILES, FuelGauge& f) {

	if (MILES / MILES_PER_GALLON <= f.getFuel()) {
		cout << "There is enough fuel in the tank for " << MILES << " miles of travel.\n";
		cout << "Completing the drive...\n";
		cout << "You have just driven " << MILES << " miles.\n";
		cout << "\n";
		return true;
	}
	else {
		cout << "You cannot travel " << MILES << " miles.\n";
		cout << "You have " << f.getFuel() << " gallons of fuel in the tank.\n";
		cout << f.getFuel() << " gallons of fuel can only offer " << f.getFuel() * MILES_PER_GALLON << " miles of travel.\n";
		cout << "Please enter a shorter distance to travel or enter more fuel in the tank.\n";
		cout << "\n";
		return false;
	}

}

void Odometer::operator ++(int) {

	if (checkMileage(1)) {
		mileage++;
	}
	else {
		cout << "The current mileage reading is " << mileage << ".\n";
		cout << "1 extra mile will surpass the gauge limit of " << MAX_MILEAGE << ", reset to 0 and resume as normal.\n";
		mileage++;
		mileage = (mileage - MAX_MILEAGE) - 1;
		cout << "The new mileage gauge shows " << mileage << " miles.\n";
		cout << "\n";
	}

}

void Odometer::updateFuelGauge(const double MILES, FuelGauge& f) {

	double miles = MILES;
	double fuel_burnt_gallons;

	if (miles > MILES_PER_GALLON) {
		f--;
		miles -= MILES_PER_GALLON;
	}

	fuel_burnt_gallons = miles / MILES_PER_GALLON;

	f.useFuel(fuel_burnt_gallons);

}

ostream& operator << (ostream& strm, const Odometer& o) {

	strm << "Mileage: " << o.getMileage() << " miles\n";

	return strm;

}

