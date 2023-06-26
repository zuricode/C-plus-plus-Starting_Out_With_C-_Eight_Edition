#include "Ship.h"

void Ship::print(ostream& strm) const {

	strm << "SHIP\n";
	strm << "Name: " << name << "\n";
	strm << "Year of build: " << year << "\n";

}

ostream& operator << (ostream& strm, const Ship& S) {

	S.print(strm);
	return strm;

}