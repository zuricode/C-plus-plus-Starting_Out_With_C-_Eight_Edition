#ifndef PRODUCTIONWORKER_H
#define PRODUCTIONWORKER_H

#include "Employee.h"

enum shifts { DAY = 1, NIGHT };

class ProductionWorker : public Employee {

private:
	int shift;
	double hourly_pay_rate;

public:
	ProductionWorker() : Employee() { shift = DAY; hourly_pay_rate = 0.0; }
	ProductionWorker(string, int, string, int, double);

	void setShift(int);
	void setHourlyPayRate(double);

	string getShift() const;
	double getHourlyPayRate() const { return hourly_pay_rate; }

	virtual void print(ostream&) const;

};

#endif