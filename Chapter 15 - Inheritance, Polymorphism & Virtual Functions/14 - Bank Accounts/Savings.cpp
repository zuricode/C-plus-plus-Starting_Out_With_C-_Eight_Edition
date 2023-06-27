#include "Savings.h"

Savings::Savings(double b, double i) : Account(b, i) {

	if (balance > ACTIVE_ACCOUNT_THRESHOLD) {
		status = true;
	}
	else {
		status = false;
	}

}

void Savings::checkStatus() {

	if (balance <= ACTIVE_ACCOUNT_THRESHOLD) {
		status = false;
	}

}

void Savings::withdraw(double amount) {

	if (status) {
		Account::withdraw(amount);
	}
	else {
		cout << "Error: You cannot withdraw from an inactive savings account.\n";
		cout << "Active account threshold: $" << ACTIVE_ACCOUNT_THRESHOLD << "\n";
		cout << "Current balance: $" << balance << "\n";
	}

}

void Savings::deposit(double amount) {

	if (balance + amount > ACTIVE_ACCOUNT_THRESHOLD) {

		if (!status) {
			status = true;
		}

		Account::deposit(amount);
		
	}

}

void Savings::monthlyProc() {

	if (withdrawals > 4) {

		while (withdrawals > 4) {
			withdrawals -= 4;
			monthly_service_charges += 1.00;

		}

	}

	Account::monthlyProc();

	checkStatus();

}