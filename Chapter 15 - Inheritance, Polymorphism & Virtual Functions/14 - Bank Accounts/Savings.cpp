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
		checkStatus();
	}
	else {
		cout << "Account status: Inactive\n";
		cout << "Current balance: $" << balance << "\n";
		cout << "Error: You cannot withdraw from an inactive savings account.\n";
		cout << "To make a withdrawal, bring the account balance above $" << ACTIVE_ACCOUNT_THRESHOLD << "\n";

		cout << "\n";
	}



}

void Savings::deposit(double amount) {

	if (balance + amount > ACTIVE_ACCOUNT_THRESHOLD && !status) {
			status = true;		
	}

	Account::deposit(amount);

	checkStatus();

}

void Savings::monthlyProc() {

	if (withdrawals > 4) {

		while (withdrawals > 4) {
			withdrawals -= 4;
			monthly_service_charges += 1.00;
		}

		cout << "A charge of $" << withdrawals / 4 << " was added for " << withdrawals << "withdrawals ($1 for every 4 withdrawals).\n";

	}

	Account::monthlyProc();

	checkStatus();

}

void Savings::print(ostream& strm) const {

	strm << left;
	strm << "SAVINGS ACCOUNT STATEMENT\n";
	strm << "---------------------------------------\n";
	strm << setw(30) << "Account status: ";

	if (status == true) {
		strm << "Active\n";
	}
	else {
		strm << "Inactive\n";
	}

	strm << setw(30) << "BALANCE: " << "$" << balance << "\n";
	strm << setw(30) << "Annual interest rate: " << annual_interest_rate << "%\n";
	strm << setw(30) << "Deposits this month: " << deposits << "\n";
	strm << setw(30) << "Withdrawals this month: " << withdrawals << "\n";
	strm << setw(30) << "Monthly service charges: " << "$" << monthly_service_charges << "\n";

}