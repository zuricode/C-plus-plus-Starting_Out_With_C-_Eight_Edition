#ifndef CARGOSHIP_H
#define CARGOSHIP_H

#include "Ship.h"

class CargoShip : public Ship {

protected:
	int capacity;

public:
	CargoShip() : Ship() { capacity = 0; }

	CargoShip(string n, string y, int c) : Ship(n, y) {
		capacity = c;
	}

	void setCapacity(int);
	int getCapacity() const { return capacity; }

	virtual void print(ostream&) const;

};

#endif