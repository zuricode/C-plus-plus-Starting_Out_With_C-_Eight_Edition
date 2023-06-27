#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>

using std::cout;
using std::cin;

class Account {

protected:
	double balance;
	int deposits;
	int withdrawals;
	double annual_interest_rate;
	double monthly_service_charges;

public:
	Account(double, double);

	virtual void deposit(double);

	virtual void withdraw(double);

	virtual void calcInt();

	virtual void monthlyProc();

};

#endif