#include "ParkingMeter.h"
#include <iostream>

using std::cin;
using std::cout;

const ParkingMeter ParkingMeter::operator = (const ParkingMeter& PM) {

	parking_time_purchased = PM.getParkingTimePurchased();

	return *this;

}

void ParkingMeter::setParkingTimePurchased(int i) {

	while (i < 0) {
		cout << "ERROR: Minutes must be a positive integer.\n";
		cout << "\n";
		cout << "Enter the amount of parking minutes purchased: ";
		cin >> i;
	}

	parking_time_purchased = i;

	cout << "\n";

}

void ParkingMeter::setParkingTimePurchased() {
	
	int num;

	while (!(cin >> num) && num <= 0) {
		cout << "ERROR: Value must be an integer greater than 0.\n";
		cout << "\n";
		cin.clear();
		cin.ignore();
		cout << "Minutes: ";
	}

	parking_time_purchased = num;

}