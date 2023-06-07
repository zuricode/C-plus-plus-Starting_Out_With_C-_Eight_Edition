#include "ShiftSupervisor.h"
#include <iostream>
#include <iomanip>

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

ostream& operator << (ostream& strm, const ShiftSupervisor& S) {

	strm << left << fixed << setprecision(2);
	strm << setw(30) << "Supervisor Name: " << S.getName() << "\n";
	strm << setw(30) << "Employee No.: " << S.getNumber() << "\n";
	strm << setw(30) << "Date hired: " << S.getHireDate() << "\n";
	strm << setw(30) << "Salary: $" << S.salary << "\n";
	strm << setw(30) << "Annual production bonus: $" << S.annual_bonus << "\n";
	strm << "\n";

	return strm;

}
