#include "NumDays.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::fixed;
using std::setprecision;

NumDays NumDays::operator + (const NumDays n) {

	return hours + n.getHours();

}

NumDays NumDays::operator - (const NumDays n) {

	return hours - n.getHours();

}

NumDays NumDays::operator ++ () {

	++hours;
	setDays();
	return *this;

}

NumDays NumDays::operator ++ (int) {

	NumDays temp;
	hours++;
	setDays();
	return temp;

}

NumDays NumDays::operator -- () {

	if (hours < 1) {
		cout << "ERROR: Cannot reduce " << hours << " by 1 hour.\n";
		return *this;
	}

	--hours;
	setDays();
	return *this;

}

NumDays NumDays::operator -- (int) {

	if (hours < 1) {
		cout << "ERROR: Cannot reduce " << hours << " hours by 1 hour.\n";
		cout << "\n";
		return *this;
	}

	NumDays temp;	

	hours--;
	setDays();
	return temp;

}

void NumDays::showHoursAndDays() {

	cout << "Hours: " << hours << "\n";
	cout << "Days: " << fixed << setprecision(2) << days << "\n";
	cout << "\n";

}
