#include "CruiseShip.h"

void CruiseShip::print(ostream& strm) const {

	strm << "CRUISE SHIP\n";
	strm << "Name: " << name << "\n";
	strm << "Max passengers: " << max_passengers << "\n";

}