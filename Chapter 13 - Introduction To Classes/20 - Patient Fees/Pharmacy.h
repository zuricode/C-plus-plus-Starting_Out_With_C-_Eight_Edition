#ifndef PHARMACY_H
#define PHARMACY_H

#include "Patient.h"

class Pharmacy {

private:
	const int TYPES_OF_MEDICATION = 5.00;
	const double ASPIRIN_CHARGE = 25.00;
	const double INSULIN_CHARGE = 22.50;
	const double STERIODS_CHARGE = 40.00;
	const double ANTIBIOTICS_CHARGE = 20.00;
	const double PROZAC_CHARGE = 30.00;

public:
	Pharmacy() {}
	~Pharmacy() {}

	void addCharge(Patient&, double);

};

#endif