#include "Payroll.h"
#include <iostream>
#include <iomanip>

using namespace std;

void enterData(PayRoll[], const int);
void displayPayRoll(PayRoll)

int main() {

	const int SIZE = 7;

	PayRoll employee[SIZE];

	enterData(employee, SIZE);

}

void enterData(PayRoll employee[], const int SIZE) {

	cout << "DATA ENTRY" << endl;
	cout << "==============" << endl;
	cout << endl;

	for (int i = 0; i < SIZE; i++) {

		employee[i].setName();
		employee[i].setHourlyRate();
		employee[i].setHoursWorked();

		cout << endl;

	}

	cout << endl;

}

void displayPayRoll(const int SIZE) {

	cout << "PAYROLL TABLE" << endl;
	cout << left << setfill('-') << setw(80) << '\n';
	cout << setfill(' ') << setw(30) << "FULL NAME" << setw(20) << "HOURLY RATE" << setw(20) << "HOURS WORKED" << setw(20) << "GROSS PAY" << endl;
	cout << setfill('-') << setw(80) << '\n';

	for (int i = 0; i < SIZE; i++) {

		cout << 

	}


}

