//11. Payroll
//
//Design a PayRoll class that has data members for an employee’s hourly pay rate,
//number of hours worked, and total pay for the week.Write a program with an array of
//seven PayRoll objects.The program should ask the user for the number of hours each
//employee has workedand will then display the amount of gross pay each has earned.
//Input Validation : Do not accept values greater than 60 for the number of hours
//worked.

#include "Payroll.h"
#include <iostream>
#include <iomanip>

using namespace std;

void enterData(PayRoll[], const int);
void displayPayRoll(PayRoll[], const int);

int main() {

	const int SIZE = 7;

	cout << "13-11 - PAYROLL CLASS EXERCISE" << endl;
	cout << endl;

	PayRoll employee[SIZE];

	enterData(employee, SIZE);

	displayPayRoll(employee, SIZE);

}

void enterData(PayRoll employee[], const int SIZE) {

	cout << "DATA ENTRY" << endl;
	cout << "==============" << endl;
	cout << endl;

	for (int i = 0; i < SIZE; i++) {

		cout << "Employee #" << i + 1 << endl;
		cout << "============" << endl;
		employee[i].setName();
		employee[i].setHoursWorked();

		cout << endl;

	}

	cout << endl;

}

void displayPayRoll(PayRoll employee[], const int SIZE) {

	cout << "PAYROLL TABLE" << endl;
	cout << "===============" << endl;
	cout << endl;

	cout << left << setfill(' ') << setw(25) << "FULL NAME" << setw(15) << "HOURLY RATE"
		<< setw(15) << "HOURS WORKED" << "GROSS PAY" << endl;
	cout << right << setfill('-') << setw(70) << '\n';
	cout << left << setfill(' ');

	for (int i = 0; i < SIZE; i++) {

		cout << setw(25) << employee[i].getName() << "$" << setw(14) << fixed << setprecision(2) << employee[i].getHourlyRate()
			<< setprecision(0) << setw(15) << employee[i].getHoursWorked() << "$" << setprecision(2) << employee[i].getGrossPay() << endl;

	}

	cout << right << setfill('-') << setw(70) << '\n';

}

