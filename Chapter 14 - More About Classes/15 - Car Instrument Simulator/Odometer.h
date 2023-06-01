#ifndef ODOMETER_H
#define ODOMETER_H

#include "FuelGauge.h"
#include <iostream>

using std::ostream;
using std::istream;

class Odometer {

	const double MAX_MILEAGE = 999999;
	const double MILES_PER_GALLON = 24;

private:
	double mileage;

public:
	Odometer() { mileage = 0;  }							// Default constructor

	bool checkMileage(const double);

	double getMileage() const { return mileage; }			// Get the current mileage reading on the gauge

	void addMileage(const double, FuelGauge&);				// Add miles to the mileage gauge (driving), arguments
	void addMileage(FuelGauge&);							// Add miles to the mileage guage (driving), data entry
	
	bool checkFuelForMileage(const double, FuelGauge&);

	void updateFuelGauge(const double, FuelGauge&);			// Decrease the fule gauge accordingly in relation to the mileage travelled

	void operator ++();										// Increment the mileage by 1 mile

	friend ostream& operator << (ostream&, const Odometer&);

};

#endif