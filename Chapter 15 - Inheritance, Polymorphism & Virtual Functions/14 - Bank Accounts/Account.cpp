#include "Account.h"

Account::Account(double b, double i) {
	balance = b;
	annual_interest_rate = i;
	deposits = 0;
	withdrawals = 0;
	monthly_service_charges = 0;
}

void Account::deposit(double amount) {

	cout << "Previous balance: $" << balance << "\n";
	cout << "Deposit amount: $" << amount << "\n";

	balance += amount;
	deposits++;

	cout << "Your deposit of $" << amount << " was successful.\n";
	cout << "New balance: $" << balance << "\n";
	cout << "\n";

	cout << "--------------------------------------------------------------------------------------------------------\n";
	cout << "\n";

}

void Account::withdraw(double amount) {

	cout << "Previous balance: $" << balance << "\n";
	cout << "Withdrawal amount: $" << amount << "\n";

	balance -= amount;
	withdrawals++;

	cout << "Your withdrawal of $" << amount << " was successful.\n";
	cout << "New balance: $" << balance << "\n";
	cout << "\n";

	cout << "--------------------------------------------------------------------------------------------------------\n";
	cout << "\n";

}

void Account::calcInt() {

	double monthly_interest = 0;
	double monthly_interest_rate = annual_interest_rate / 12;

	cout << "Annual interest rate: " << annual_interest_rate << "%\n";
	cout << "Monthly interest rate: " << monthly_interest_rate << "%\n";

	if (balance >= 0) {
		monthly_interest = balance * (monthly_interest_rate / 100);
		cout << "Monthly interest accured: $" << monthly_interest << "\n";

	} else {
		cout << "This account currently holds a negative balance. No interest will be accured.\n";
	}
		
	cout << "Previous balance: $" << balance << "\n";
	balance += monthly_interest;
	cout << "New balance: $" << balance << "\n";
	
	cout << "\n";
	

}

void Account::monthlyProc() {

	cout << "MONTHLY PROCESS REVIEW - MONTH #" << ++month << "\n";
	cout << "----------------------------------\n";
	cout << "\n";

	cout << "Subtracting monthly service charges...\n";
	cout << "$" << monthly_service_charges << " will be deducted.\n";
	cout << "\n";

	cout << "Previous balance: $" << balance << "\n";
	balance -= monthly_service_charges;
	cout << "New balance: $" << balance << "\n";
	cout << "\n";

	calcInt();

	deposits = 0;
	withdrawals = 0;
	monthly_service_charges = 0;

	cout << "Deposits, withdrawls and monthly charges were reset.\n";
	cout << "\n";

	cout << "--------------------------------------------------------------------------------------------------------\n";
	cout << "\n";

}

void Account::print(ostream& strm) const {

	strm << left;
	strm << "ACCOUNT STATEMENT\n";
	strm << "---------------------------------------\n";
	strm << setw(30) << "BALANCE: " << "$" << balance << "\n";
	strm << setw(30) << "Annual interest rate: " << annual_interest_rate << "%\n";
	strm << setw(30) << "Deposits this month: " << deposits << "\n";
	strm << setw(30) << "Withdrawals this month: " << withdrawals << "\n";
	strm << setw(30) << "Monthly service charges: " << "$" << monthly_service_charges << "\n";

}

ostream& operator << (ostream& strm, const Account& A) {

	A.print(strm);
	strm << "\n";
	strm << "--------------------------------------------------------------------------------------------------------\n";
	strm << "\n";
	return strm;

}