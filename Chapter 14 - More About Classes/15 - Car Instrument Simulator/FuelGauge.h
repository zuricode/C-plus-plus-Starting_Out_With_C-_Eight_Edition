#ifndef FUELGAUGE_H
#define FUELGAUGE_H

#include <iostream>

using std::ostream;
using std::istream;

const double	MAX_FUEL = 15;

class FuelGauge {

private:
	double fuel_gallons;

public:
	FuelGauge() { fuel_gallons = 0; }				// Default constructor with arguments

	bool checkFuel(const double);

	void addFuel(const double);		// Set fuel in gallons, argument
	void addFuel();					// Set fuel in gallons, data entry
	void useFuel(const double);		// Use fuel in gallons, argument

	double getFuel() const;			// Get fuel in gallons, argument

	void operator ++(int);				// Add 1 gallon of fuel in the tank
	void operator --(int);				// Use 1 gallon of fuel in the tank

	friend ostream& operator << (ostream&, const FuelGauge&);
	friend istream& operator >> (istream&, FuelGauge&);

};

#endif