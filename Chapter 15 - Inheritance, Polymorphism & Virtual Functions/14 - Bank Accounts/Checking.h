#ifndef CHECKING_H
#define CHECKING_H

#include "Account.h"

const double UNARRANGED_OVERDRAFT = 15.00;
const double WITHDRAWAL_CHARGE = 0.10;

class Checking : public Account {

public:
	Checking(double b, double i) : Account(b, i) {}

	virtual void withdraw(double);

	virtual void monthlyProc();

};

#endif