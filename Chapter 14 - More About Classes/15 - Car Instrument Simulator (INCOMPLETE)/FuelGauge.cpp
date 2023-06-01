#include "FuelGauge.h"
#include <iostream>

using std::cin;
using std::cout;

bool FuelGauge::checkFuel(const double FUEL) {

	if (fuel_gallons + FUEL <= MAX_FUEL) {
		return true;
	}
	else {
		return false;
	}

}

void FuelGauge::addFuel(const double FUEL) {

	if (checkFuel(FUEL)) {
		fuel_gallons += FUEL;
		cout << FUEL << " gallons of fuel was added to the tank.\n";
	}
	else {
		cout << "NOTE: The fuel tank already contains " << fuel_gallons << ".\n";
		cout << "Adding " << FUEL << " gallon(s) would exceed the tank limit of " << MAX_FUEL << ".\n";
		cout << "Fuel tank still contains " << fuel_gallons << " gallons.\n";
	}

	cout << "\n";

}

void FuelGauge::addFuel() {

	double num;

	cout << "Enter the amount of fuel you would like to add to your tank (gallons): ";

	while (!(cin >> num) || num <= 0) {
		cout << "ERROR: Fuel must be a value greater than 0.\n";
		cout << "\n";
		cout << "Fuel: ";
	}

	addFuel(num);

}

void FuelGauge::useFuel(const double FUEL) {

	if (fuel_gallons - FUEL >= 0) {
		fuel_gallons -= FUEL;
	}
	else {
		cout << "NOTE: The fuel tank already contains " << fuel_gallons << ".\n";
		cout << "There is not " << FUEL << " gallon(s) of fuel to burn in the tank.\n";
		cout << "Fuel tank still contains " << fuel_gallons << " gallons.\n";
		cout << "\n";
	}

}

double FuelGauge::getFuel() const {

	return fuel_gallons;

}

void FuelGauge::operator ++(int) {

	addFuel(1);

}

void FuelGauge::operator --(int) {

	useFuel(1);

}

ostream& operator << (ostream& strm, const FuelGauge& f) {

	strm << "Fuel: " << f.getFuel() << " gallons\n";
	
	return strm;

}

istream& operator >> (istream& strm, FuelGauge& f) {

	f.addFuel();

	strm >> f.fuel_gallons;

	return strm;

}