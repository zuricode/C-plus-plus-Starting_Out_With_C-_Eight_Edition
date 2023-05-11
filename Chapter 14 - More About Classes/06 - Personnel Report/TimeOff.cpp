#include "TimeOff.h"
#include <iostream>

using std::cin;
using std::cout;
using std::strlen;

const int MAX_VACATION_HOURS = 240;

int maxVacationValidation(int num) {

	while (num < 0 || num > MAX_VACATION_HOURS) {
		cout << "ERROR: An employee can not accumulate more than " << MAX_VACATION_HOURS << " hours.\n";
		cout << "Enter the amount of vacation hours available: ";
		cin >> num;
		cout << "\n";
	}

	return num;

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
	vacTaken.setHours(vac_taken);
	maxUnpaid.setHours(max_unpaid);
	unpaidTaken.setHours(unpaid_taken);

}

TimeOff::TimeOff() {

	name = "";
	id_number = 0;

}

