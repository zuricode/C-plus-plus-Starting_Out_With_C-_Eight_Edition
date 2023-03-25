#include "Payroll.h"
#include <iostream>

using namespace std;

PayRoll::PayRoll() {
	name = "";
	hourly_pay_rate = 0;
	hours_worked = 0;
	gross_pay = 0;
}

void PayRoll::setName() {

	cout << "Name of employee: ";
	getline(cin, name);

}

void PayRoll::setHourlyRate() {

	cout << name << "'s hourly rate: $";

	while (!(cin >> hourly_pay_rate) || hourly_pay_rate < 0) {
		cout << "Error: Hourly pay rate must be a float greater than 0. Re-enter your value: ";
		cin.clear();
		cin.ignore();
	}

	cin.ignore();

}

void PayRoll::setHoursWorked() {

	cout << name << "'s hours worked: ";

	while (!(cin >> hours_worked) || hours_worked < 0 || hours_worked > 60) {
		cout << "Error: Hours worked must be a float greater than 0 but less than 60. Re-enter your value: ";
		cin.clear();
		cin.ignore();
	}

	cin.ignore();

}

