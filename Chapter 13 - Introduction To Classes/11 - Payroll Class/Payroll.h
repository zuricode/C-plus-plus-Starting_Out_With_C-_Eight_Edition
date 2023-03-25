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

	string getName() { return name; }
	float getHourlyRate() { return hourly_pay_rate; }
	float getHoursWorked() { return hours_worked; }
	float getGrossPay() { return hourly_pay_rate * hours_worked; }

	void displayPayRoll(const int);
};

#endif