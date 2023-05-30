#include "ParkingTicket.h"

#include <iostream>
#include <iomanip>

using std::cout;
using std::left;
using std::right;
using std::setfill;
using std::setw;
using std::fixed;
using std::setprecision;

void ParkingTicket::takeCarDetails(const ParkedCar PC) {

	car = PC;

}

void ParkingTicket::takeOfficerDetails(const PoliceOfficer PO) {

	officer = PO;

}

void ParkingTicket::takeMeterDetails(const ParkingMeter PM) {

	meter = PM;

}

void ParkingTicket::calculateFine() {

	double amount = 0;
	int minutes;

	illegal_minutes = abs(meter.getParkingTimePurchased() - car.getMinutesParked());

	minutes = illegal_minutes;

	while (minutes > 60) {
		amount += ADDITIONAL_HOUR;
		minutes -= 60;
	}

	amount += FIRST_HOUR;

	fine = amount;

}

double convertMinutesToHours(int minutes) {

	double hours = 0;

	while (minutes >= 60) {
		minutes -= 60;
		hours++;
	}

	hours += static_cast<double>(minutes) / 60;

	return hours;

}

void ParkingTicket::issueTicket() {

	cout << left << fixed << setprecision(2);

	cout << "-----------------------\n";
	cout << "OFFICIAL PARKING TICKET\n";
	cout << "-----------------------\n";
	cout << "\n";
	cout << "Car Details\n";
	cout << "-----------\n";
	cout << "\n";

	cout << setw(25) << "Make: " << car.getMake() << "\n";
	cout << setw(25) << "Model: " << car.getModel() << "\n";
	cout << setw(25) << "License Number: " << car.getLicenseNumber() << "\n";
	cout << "\n";
	
	cout << "You were parked for a total of " << car.getMinutesParked() << " minutes (" << convertMinutesToHours(car.getMinutesParked()) << " hours).\n";
	cout << "You paid for " << meter.getParkingTimePurchased() << " minutes (" << convertMinutesToHours(meter.getParkingTimePurchased()) << " hours).\n";
	cout << "You were illegally parked for " << illegal_minutes << " minutes (" << convertMinutesToHours(illegal_minutes) << " hours).\n";
	cout << "\n";

	cout << "Illegal parking within the first hour costs $" << FIRST_HOUR << "\n";
	cout << "$" << ADDITIONAL_HOUR << " will be added per additional hour" << "\n";

	cout << "\n";

	cout << "FINE TO PAY: $" << getFine() << "\n";
	cout << "\n";

	cout << "Ticket issued by: " << "\n";
	cout << "Police Officer " << officer.getName() << "\n";
	cout << "Badge Number : " << officer.getBadgeNumber() << "\n";
	cout << "\n";

	cout << "--------------------------------------------------------------------\n";
	cout << "\n";

}



