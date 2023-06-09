#include "ShiftSupervisor.h"
#include <iostream>

using std::cout;
using std::cin;
using std::fixed;
using std::setprecision;
using std::left;
using std::setw;

ShiftSupervisor::ShiftSupervisor(double s, double b, string na, int num, string date) : Employee(na, num, date) {

	setSalary(s);
	setAnnualBonus(b);

}

void ShiftSupervisor::setSalary(double s) {

	if (s <= 0) {
		cout << "ERROR: Salary must be a value greater than 0.\n";
		cout << "\n";
		cout << "Supervisor salary: $";
		cin >> s;
	}

	salary = s;

}

void ShiftSupervisor::setAnnualBonus(double b) { 

	if (b < 0) {
		cout << "ERROR: Annual production bonus must be a value greater than or equal to 0.\n";
		cout << "\n";
		cout << "Annual production bonus: $";
		cin >> b;
	}

	annual_bonus = b;

}

void ShiftSupervisor::print(ostream& strm) const {

	Employee::print(strm);

	strm << "Salary: $" << fixed << setprecision(2) << getSalary() << "\n";
	strm << "Annual production bonus: $" << getAnnualBonus() << "\n";

}
