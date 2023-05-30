//14. Parking Ticket Simulator
//
//For this assignment you will design a set of classes that work together to simulate a
//police officer issuing a parking ticket. The classes you should design are :
//
//• The ParkedCar Class : This class should simulate a parked car.The class’s responsibilities
//are :
//– To know the car's make, model, color, license number, and the number of minutes
//that the car has been parked
//
//• The ParkingMeter Class : This class should simulate a parking meter.The class’s
//only responsibility is :
//– To know the number of minutes of parking time that has been purchased
//
//• The ParkingTicket Class : This class should simulate a parking ticket.The class’s
//responsibilities are :
//– To report the make, model, color, and license number of the illegally parked car
//– To report the amount of the fine, which is $25 for the first hour or part of an
//hour that the car is illegally parked, plus $10 for every additional hour or part of
//an hour that the car is illegally parked
//– To report the name and badge number of the police officer issuing the ticket
//
//• The PoliceOfficer Class : This class should simulate a police officer inspecting
//parked cars.The class’s responsibilities are :
//– To know the police officer’s name and badge number
//– To examine a ParkedCar object and a ParkingMeter object, and determine
//whether the car's time has expired
//– To issue a parking ticket(generate a ParkingTicket object) if the car’s time has
//expired
//
//Write a program that demonstrates how these classes collaborate.
//

#include "ParkedCar.h"
#include "PoliceOfficer.h"
#include "ParkingMeter.h"
#include "ParkingTicket.h"

#include <iostream>

using namespace std;

void enterCarDetails(ParkedCar&);
void payForParking(ParkingMeter&);
int enterTimeFrame();
void keepTrackOfTime(ParkedCar&);

int main() {

	ParkedCar car;
	PoliceOfficer officer;
	ParkingMeter meter;
	ParkingTicket ticket;

	cout << "=====================================\n";
	cout << "14 - PARKING TICKET SIMULATOR PROGRAM\n";
	cout << "=====================================\n";
	cout << "\n";

	enterCarDetails(car);

	payForParking(meter);


	keepTrackOfTime(car);

	if(officer.isParkedCarIllegal(car, meter)) {

		officer.setName();
		officer.setBadgeNumber();
		cout << "\n";

		ticket.takeCarDetails(car);
		ticket.takeOfficerDetails(officer);
		ticket.takeMeterDetails(meter);

		ticket.calculateFine();

		ticket.issueTicket();

	}

}

void enterCarDetails(ParkedCar& car) {

	cout << "Please enter the details of your car: \n";
	cout << "\n";

	cout << "Make: ";
	car.setMake();

	cout << "Model: ";
	car.setModel();

	cout << "Colour: ";
	car.setColour();

	cout << "License Number: ";
	car.setLicenseNumber();

	cout << "\n";

}

void payForParking(ParkingMeter& meter) {

	cout << "How would you like to park your car for?\n";
	cout << "Minutes: ";
	meter.setParkingTimePurchased();
	cout << "\n";

	cout << "You have paid for " << meter.getParkingTimePurchased() << " minutes for parking.\n";
	cout << "\n";

}

int enterTimeFrame() {

	int minutes;

	cout << "Enter the amount of time that will pass in minutes: ";

	while (!(cin >> minutes) && minutes < 0) {
		cout << "ERROR: The amount of minutes must be a positive integer.\n";
		cout << "\n";
		cout << "Enter the amount of time that will pass in minutes: ";
	}

	cin.ignore();
	cout << "\n";

	return minutes;

}

void keepTrackOfTime(ParkedCar& car) {

	int minutes_passed = enterTimeFrame();

	for (int i = 0; i < minutes_passed; i++) {
		car.increaseMinutesParked();
		cout << car.getLicenseNumber() << " has been parked for " << car.getMinutesParked() << " minutes...\n";
	}

	cout << "\n";

}
