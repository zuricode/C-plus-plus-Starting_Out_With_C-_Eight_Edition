#ifndef PARKINGTICKET_H
#define PARKINGTICKET_H

#include "ParkedCar.h"
#include "ParkingMeter.h"
#include "PoliceOfficer.h"

const double FIRST_HOUR = 25.00;
const double ADDITIONAL_HOUR = 10.00;

class ParkingTicket {

private:
	ParkedCar car;
	PoliceOfficer officer;
	ParkingMeter meter;
	int illegal_minutes;
	double fine;

public:
	ParkingTicket() { fine = 0; illegal_minutes = 0; }

	void takeCarDetails(const ParkedCar);
	void takeOfficerDetails(const PoliceOfficer);
	void takeMeterDetails(const ParkingMeter);

	void calculateFine();
	double getFine() const { return fine; }

	void issueTicket();

};

#endif