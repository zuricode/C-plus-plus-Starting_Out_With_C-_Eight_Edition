#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::ostream;
using std::left;
using std::setw;

class Account {

protected:
	double balance;
	int deposits;
	int withdrawals;
	int month = 0;
	double annual_interest_rate;
	double monthly_service_charges;

public:
	Account(double, double);

	virtual void deposit(double);

	virtual void withdraw(double);

	virtual void calcInt();

	virtual void monthlyProc();

	virtual void print(ostream&) const = 0;

	friend ostream& operator << (ostream&, const Account&);

};

#endif