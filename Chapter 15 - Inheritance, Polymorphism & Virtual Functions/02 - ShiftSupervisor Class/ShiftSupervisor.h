#ifndef SHIFTSUPERVISOR_H
#define SHIFTSUPERVISOR_H

#include "Employee.h"
#include <iostream>

using std::ostream;

class ShiftSupervisor : public Employee {

private:
	double salary;
	double annual_bonus;

public:
	ShiftSupervisor() : Employee() { salary = 0; annual_bonus = 0; }
	ShiftSupervisor(double, double, string, int, string);

	void setSalary(double);
	void setAnnualBonus(double);

	double getSalary() const { return salary; }
	double getAnnualBonus() const { return annual_bonus; }
	double getTotalSalary() const { return salary + annual_bonus; }

	friend ostream& operator << (ostream&, const ShiftSupervisor&);

};

#endif