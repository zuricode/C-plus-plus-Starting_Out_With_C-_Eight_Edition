#include "PoliceOfficer.h"

PoliceOfficer::PoliceOfficer() {	

	name = "";
	badge_number = "";

}

PoliceOfficer::PoliceOfficer(const string N = "", const string B = "") {

	name = N;
	badge_number = B;

}

const PoliceOfficer PoliceOfficer::operator = (const PoliceOfficer& PO) {

	name = PO.getName();
	badge_number = PO.getBadgeNumber();

	return *this;

}

void PoliceOfficer::setName() {

	string input;

	cout << "Officer's Full Name: ";

	while (!(getline(cin, input)) && input == "") {
		cout << "ERROR: You must enter a string.\n";
		cout << "\n";
		cin.ignore();
		cout << "Officer's Full Name: ";
	}

	name = input;

}

void PoliceOfficer::setBadgeNumber() {

	string input;

	cout << "Officer's Badge Number: ";

	while (!(getline(cin, input)) && input == "") {
		cout << "ERROR: You must enter a string.\n";
		cout << "\n";
		cin.ignore();
		cout << "Officer's Badge Number: ";
	}

	badge_number = input;

}

bool PoliceOfficer::isParkedCarIllegal(const ParkedCar PC, const ParkingMeter PM) {

	if (PM.getParkingTimePurchased() - PC.getMinutesParked() < 0) {
		return true;
	}
	else {
		return false;
	}

}