#ifndef PAYROLL_H
#define PAYROLL_H
#include <string>

using std::string;

class PayRoll {

private:
	string name;
	float hourly_pay_rate;
	float hours_worked;
	float gross_pay;

public:

	PayRoll();
	void setName();
	void setHourlyRate();
	void setHoursWorked();

	string getName() const { return name; }
	float getHourlyRate() const { return hourly_pay_rate; }
	float getHoursWorked() const { return hours_worked; }
	float getGrossPay() const { return hourly_pay_rate * hours_worked; }

};

#endif