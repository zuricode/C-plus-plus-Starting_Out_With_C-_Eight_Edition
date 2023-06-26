#ifndef CRUISESHIP_H
#define CRUISESHIP_H

#include "Ship.h"

class CruiseShip : public Ship {

protected:
	int max_passengers;

public:
	CruiseShip() : Ship() { max_passengers = 0; }

	CruiseShip(string name, string year, int p) : Ship(name, year) {
		max_passengers = p;
	}

	void setMaxPassengers(int p) { max_passengers = p; }
	int getMaxPassengers() const { return max_passengers; }

	virtual void print(ostream&) const;

};

#endif