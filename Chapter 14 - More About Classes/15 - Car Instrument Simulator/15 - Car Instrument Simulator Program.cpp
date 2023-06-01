//15. Car Instrument Simulator
//
//For this assignment you will design a set of classes that work together to simulate a
//car’s fuel gauge and odometer.The classes you will design are :
//
//• The FuelGauge Class : This class will simulate a fuel gauge.Its responsibilities are
//– To know the car’s current amount of fuel, in gallons.
//– To report the car’s current amount of fuel, in gallons.
//– To be able to increment the amount of fuel by 1 gallon.This simulates putting
//fuel in the car. (The car can hold a maximum of 15 gallons.)
//– To be able to decrement the amount of fuel by 1 gallon, if the amount offuel is
//greater than 0 gallons.This simulates burning fuel as the car runs.
//
//• The Odometer Class : This class will simulate the car’s odometer.Its responsibilities
//are :
//– To know the car’s current mileage.
//– To report the car’s current mileage.
//– To be able to increment the current mileage by 1 mile.The maximum mileage the
//odometer can store is 999, 999 miles.When this amount is exceeded, the odometer
//resets the current mileage to 0.
//– To be able to work with a FuelGauge object.It should decrease the FuelGauge
//object’s current amount of fuel by 1 gallon for every 24 miles traveled. (The car’s
//	fuel economy is 24 miles per gallon.)
//
//	Demonstrate the classes by creating instances of each.Simulate filling the car up with
//	fuel, and then run a loop that increments the odometer until the car runs out of fuel.
//	During each loop iteration, print the car’s current mileageand amount of fuel.

#include "FuelGauge.h"
#include "Odometer.h"
#include "Car.h"
#include <iostream>

using namespace std;

int showMenu();
void activateMenuChoice(const int, Car&);

int main() {

	Car car;
	int menu_choice = 0;

	cout << "========================================\n";
	cout << "14-15 - CAR INSTRUMENT SIMULATOR PROGRAM\n";
	cout << "========================================\n";
	cout << "\n";

	while (menu_choice != 4) {

		menu_choice = showMenu();

		activateMenuChoice(menu_choice, car);

	}	

}

int showMenu() {

	int choice;

	cout << "---------\n";
	cout << "Car Menu\n";
	cout << "---------\n";
	cout << "\n";
	cout << "1) Drive Car\n";
	cout << "\n";
	cout << "2) Add Fuel To Tank\n";
	cout << "\n";
	cout << "3) Show Tank and Odometer Gauges\n";
	cout << "\n";
	cout << "4) Leave Car\n";
	cout << "\n";
	cout << "-------------------------------------------\n";
	cout << "\n";

	cout << "Enter your selection: ";
	
	while (!(cin >> choice) || choice < 1 || choice > 4) {
		cout << "ERROR: Menu choice must be a value between 1 and 4.\n";
		cout << "\n";
		cout << "Menu choice: ";
	}

	cin.ignore();

	cout << "\n";

	return choice;

}


void activateMenuChoice(const int CHOICE, Car& car) {

	switch (CHOICE) {
		case 1:
			car.drive();
			break;
		case 2:
			car.addToTank();
			break;
		case 3:
			car.showDetails();
			break;
		case 4:
			cout << "You are the leaving the car.\n";
			cout << "Car program shutting down...\n";
			break;
	}

}

