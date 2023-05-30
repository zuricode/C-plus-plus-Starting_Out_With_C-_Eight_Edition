#ifndef PARKINGMETER_H
#define PARKINGMETER_H

#include "ParkedCar.h"

class ParkingMeter {

private:
	int parking_time_purchased;

public:
	ParkingMeter(int i = 0) { parking_time_purchased = i; }			// Constructor

	const ParkingMeter operator = (const ParkingMeter&);

	void setParkingTimePurchased(int);
	void setParkingTimePurchased();
	int getParkingTimePurchased() const { return parking_time_purchased; }		// Get the number of minutes of purchased parking time

};

#endif