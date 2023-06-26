#ifndef SHIP_H
#define SHIP_H

#include "Ship.h"

#include <string>
#include <iostream>

using std::string;
using std::ostream;
using std::cout;
using std::cin;

class Ship {

protected:
	string name;
	string year;

public:
	Ship() { name = "NO NAME"; year = "0"; }
	Ship(string n, string y) { name = n; year = y; }

	void setName(string n) { name = n; }
	void setYear(string y) { year = y; }
	string getName() const { return name; }
	string getYear() const { return year; }

	virtual void print(ostream&) const;
	friend ostream& operator <<(ostream&, const Ship&);

};

#endif