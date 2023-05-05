#include "TimeOff.h"
#include "NumDays.h"
#include <iostream>

using std::cin;
using std::cout;
using std::strlen;

const int MAX_VACATION_HOURS = 240;

void TimeOff::maxVacationValidation() {

	if (maxVacation.getHours() > MAX_VACATION_HOURS) {
		maxVacation = MAX_VACATION_HOURS;
	}

}

void TimeOff::setName(string s) {

	while (s.length() == 0) {
		cout << "ERROR: An empty string cannot be entered.\n";
		cin.ignore();
		cout << "\n";
		cout << "Enter the name of your employee: ";
		getline(cin, s);
	}

	name = s;

}

void TimeOff::setIdNumber(int num) {

	while (num < 0) {
		cout << "ERROR: ID Number must be a positive int greater than 0\n";
		cout << "\n";
		cout << "Enter your ID Number: ";
		cin >> num;
	}

	cin.ignore();

	id_number = num;

}

TimeOff::TimeOff(string n, int id, int max_sick, int sick_taken, int max_vac,
	int vac_taken, int max_unpaid, int unpaid_taken) {

	name = n;
	id_number = id;
	maxSickDays.setHours(max_sick);
	sickTaken.setHours(sick_taken);
	maxVacation.setHours(max_vac);
	maxVacationValidation();
	vacTaken.setHours(vac_taken);
	maxUnpaid.setHours(max_unpaid);
	unpaidTaken.setHours(unpaid_taken);

}

TimeOff::TimeOff() {

	name = "";
	id_number = 0;

}

double TimeOff::getVacDays() {

	double days;

	days = maxVacation.getHours() / static_cast<double>(8);

	return days;

}

double TimeOff::getSickDays() {

	double days;

	days = maxSickDays.getHours() / static_cast<double>(8);

	return days;
		

}
