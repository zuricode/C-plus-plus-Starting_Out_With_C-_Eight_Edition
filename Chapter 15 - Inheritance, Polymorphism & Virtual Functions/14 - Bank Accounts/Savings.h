#ifndef SAVINGS_H
#define SAVINGS_H

#include "Account.h"

const double ACTIVE_ACCOUNT_THRESHOLD = 25.00;

class Savings : public Account {

private:
	bool status;

public:
	Savings(double, double);

	void checkStatus();

	virtual void withdraw(double);
	virtual void deposit(double);

	virtual void monthlyProc();


};

#endif