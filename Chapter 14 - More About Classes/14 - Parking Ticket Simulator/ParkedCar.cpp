#include "ParkedCar.h"
#include <iostream>

using std::cout;
using std::cin;

ParkedCar::ParkedCar() {

	make = "";
	model = "";
	colour = "";
	license_number = "";
	minutes_parked = 0;

}

ParkedCar::ParkedCar(const string MA, const string MO, const string C, const string L) {

	make = MA;
	model = MO;
	colour = C;
	license_number = L;
	minutes_parked = 0;

}

ParkedCar::ParkedCar(const ParkedCar& right) {

	make = right.getMake();
	model = right.getModel();
	colour = right.getColour();
	license_number = right.getLicenseNumber();
	minutes_parked = right.getMinutesParked();

}

 const ParkedCar ParkedCar::operator = (const ParkedCar& PC) {

	make = PC.getMake();
	model = PC.getModel();
	colour = PC.getColour();
	license_number = PC.getLicenseNumber();
	minutes_parked = PC.getMinutesParked();

	return *this;

}

 void ParkedCar::increaseMinutesParked() {

	 minutes_parked++;

 }
