#include "Checking.h"

void Checking::withdraw(double amount) {

	if (balance - amount < 0) {
		balance -= UNARRANGED_OVERDRAFT;
		cout << "Error: You are not able to withdraw $" << amount << ".\n";
		cout << "Your balance is $" << balance << "\n";
		cout << UNARRANGED_OVERDRAFT << " was taken from the account. The balance fell below 0 due to an unarranged overdraft.\n";
	}
	else {
		Account::withdraw(amount);
	}

}

void Checking::monthlyProc() {

	monthly_service_charges += 5.00;
	monthly_service_charges += (WITHDRAWAL_CHARGE * withdrawals);

	Account::monthlyProc();

}