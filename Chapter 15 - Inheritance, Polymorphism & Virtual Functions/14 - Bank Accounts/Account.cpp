#include "Account.h"

Account::Account(double b, double i) {
	balance = b;
	annual_interest_rate = i;
	deposits = 0;
	withdrawals = 0;
	monthly_service_charges = 0;
}

void Account::deposit(double amount) {

	balance += amount;
	deposits++;

}

void Account::withdraw(double amount) {

		balance -= amount;
		withdrawals++;

}

void Account::calcInt() {

	double monthly_interest;

	int monthly_interest_rate = annual_interest_rate / 12;

	monthly_interest = balance * monthly_interest_rate;

	balance += monthly_interest;

}

void Account::monthlyProc() {

	balance -= monthly_service_charges;

	calcInt();

	deposits = 0;
	withdrawals = 0;
	monthly_service_charges = 0;

}