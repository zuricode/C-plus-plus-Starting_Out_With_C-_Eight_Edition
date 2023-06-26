#include "CargoShip.h"

void CargoShip::setCapacity(int c) {

	cout << "Cargo capacity: ";

	while (!(cin >> c) || c <= 0) {
		cout << "Error: Cargo capacity cannot be less than or equal to 0.\n";
		cout << "\n";
		cout << "Cargo capacity: ";
	}

	capacity = c;

}

void CargoShip::print(ostream& strm) const {

	strm << "CARGO SHIP\n";
	strm << "Name: " << name << "\n";
	strm << "Cargo capacity (tons): " << capacity << "\n";

}