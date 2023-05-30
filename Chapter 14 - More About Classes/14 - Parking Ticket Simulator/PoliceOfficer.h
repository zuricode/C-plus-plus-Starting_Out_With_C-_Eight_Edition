#ifndef POLICEOFFICER_H
#define POLICEOFFICER_H

#include "ParkedCar.h"
#include "ParkingMeter.h"

#include <string>

using std::string;

class PoliceOfficer {

private:
	string name;
	string badge_number;

public:
	PoliceOfficer();												// Default Constructor
	PoliceOfficer(const string, const string);						// Constructor with arguments

	const PoliceOfficer operator = (const PoliceOfficer&);

	void setName(const string N) { name = N; }						// Set name of the police officer, arguments
	void setName();													// Set name of the police officer, data entry
	string getName() const { return name; }							// Get name of the police officer

	void setBadgeNumber(const string BN) { badge_number = BN; }		// Set badge number of the police officer, arguments
	void setBadgeNumber();											// Set badge number of the police officer, data entry
	string getBadgeNumber() const { return badge_number; }			// Get badge number of the police officer

	bool isParkedCarIllegal(const ParkedCar, const ParkingMeter);		// Check car is parked legally

};

#endif