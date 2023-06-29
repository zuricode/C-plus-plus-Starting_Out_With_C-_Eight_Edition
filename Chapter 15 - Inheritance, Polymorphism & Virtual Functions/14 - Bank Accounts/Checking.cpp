#include "Checking.h"

void Checking::withdraw(double amount) {

	if (balance - amount < 0) {
		cout << "Error: You are not able to withdraw $" << amount << "\n";
		cout << "$" << WITHDRAWAL_FINE << " will be taken from the account.\n";
		cout << "Previous balance $:" << balance << "\n";
		balance -= WITHDRAWAL_FINE;
		cout << "New balance: $" << balance << "\n";

		cout << "\n";
	}
	else {
		Account::withdraw(amount);
	}

}

void Checking::monthlyProc() {

	cout << "Adding monthly operational fee of $5...\n";
	monthly_service_charges += 5.00;
	cout << "\n";

	cout << "Checking withdrawal fees...\n";
	if (withdrawals != 0) {
		cout << "Withdrawals: " << withdrawals << "\n";
		cout << "$" << WITHDRAWAL_CHARGE * withdrawals << " will be charged for " << withdrawals << " withdrawals.\n";
	}
	else {
		cout << "There are no withdrawal fees as no withdrawals were made.\n";
	}
	cout << "\n";
	
	monthly_service_charges += (WITHDRAWAL_CHARGE * withdrawals);

	Account::monthlyProc();

}

void Checking::print(ostream& strm) const {

	strm << left;
	strm << "CHECKING ACCOUNT STATEMENT\n";
	strm << "---------------------------------------\n";
	strm << setw(30) << "BALANCE: " << "$" << balance << "\n";
	strm << setw(30) << "Annual interest rate: " << annual_interest_rate << "%\n";
	strm << setw(30) << "Deposits this month: " << deposits << "\n";
	strm << setw(30) << "Withdrawals this month: " << withdrawals << "\n";
	strm << setw(30) << "Monthly service charges: " << "$" << monthly_service_charges << "\n";

}