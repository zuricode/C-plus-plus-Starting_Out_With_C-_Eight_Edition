//14. Bank Accounts
//
//This program should be designed and written by a team of students.Here are some
//suggestions :
//
//	• One or more students may work on a single class.
//	• The requirements of the program should be analyzed so each student is given about
//	the same work load.
//	• The parameters and return types of each function and class member function should
//	be decided in advance.
//	• The program will be best implemented as a multi - file program.
//
//Design a generic class to hold the following information about a bank account :
//
//	Balance
//	Number of deposits this month
//	Number of withdrawals
//	Annual interest rate
//	Monthly service charges
//
//The class should have the following member functions :
//
//	Constructor: Accepts arguments for the balanceand annual interest rate.
//	deposit : A virtual function that accepts an argument for the amount of the
//	deposit.The function should add the argument to the account balance.
//	It should also increment the variable holding the number of deposits.
//
//	withdraw : A virtual function that accepts an argument for the amount of the
//	withdrawal.The function should subtract the argument from the
//	balance.It should also increment the variable holding the number of
//	withdrawals.
//
//	calcInt : A virtual function that updates the balance by calculating the monthly
//	interest earned by the account, and adding this interest to the balance.
//	This is performed by the following formulas :
//
//		Monthly Interest Rate = (Annual Interest Rate / 12)
//		Monthly Interest = Balance * Monthly Interest Rate
//		Balance = Balance + Monthly Interest
//
//	monthlyProc : A virtual function that subtracts the monthly service charges from the
//	balance, calls the calcInt function, and then sets the variables that
//	hold the number of withdrawals, number of deposits, and monthly
//	service charges to zero.
//
//Next, design a savings account class, derived from the generic account class.The savings
//account class should have the following additional member :
//
//	status(to represent an active or inactive account)
//
//If the balance of a savings account falls below $25, it becomes inactive. (The status
//member could be a flag variable.) No more withdrawals may be made until the balance
//is raised above $25, at which time the account becomes active again.The savings
//account class should have the following member functions :
//
//	withdraw: A function that checks to see if the account is inactive before a withdrawal
//	is made. (No withdrawal will be allowed if the account is not
//	active.) A withdrawal is then made by calling the base class version of
//	the function.
//
//	deposit : A function that checks to see if the account is inactive before a deposit
//	is made.If the account is inactiveand the deposit brings the balance
//	above $25, the account becomes active again.The deposit is then
//	made by calling the base class version of the function.
//
//	monthlyProc : Before the base class function is called, this function checks the number
//	of withdrawals.If the number of withdrawals for the month is
//	more than 4, a service charge of $1 for each withdrawal above 4 is
//	added to the base class variable that holds the monthly service charges.
//	(Don’t forget to check the account balance after the service charge
//	is taken.If the balance falls below $25, the account becomes inactive.)
//
//Next, design a checking account class, also derived from the generic account class.It
//should have the following member functions :
//
//	withdraw: Before the base class function is called, this function will determine if a
//	withdrawal(a check written) will cause the balance to go below $0.If
//	the balance goes below $0, a service charge of $15 will be taken from
//	the account. (The withdrawal will not be made.) If there isn’t enough
//	in the account to pay the service charge, the balance will become negative
//	and the customer will owe the negative amount to the bank.
//
//	monthlyProc : Before the base class function is called, this function adds the monthly
//	fee of $5 plus $0.10 per withdrawal(check written) to the base class
//	variable that holds the monthly service charges.
//
//Write a complete program that demonstrates these classes by asking the user to enter
//the amounts of deposits and withdrawals for a savings accountand checking account.
//The program should display statistics for the month, including beginning balance, total
//amount of deposits, total amount of withdrawals, service charges, and ending balance.
//970 Chapter 15 Inheritance, Polymorphism, and Virtual Functions
//
//NOTE : You may need to add more member variablesand functions to the classes
//than those listed above.

#include "Savings.h"
#include "Checking.h"

#include <iomanip>
#include <string>

using std::left;
using std::setw;
using std::setfill;
using std::string;
using std::setprecision;
using std::fixed;

void showMainMenu(Savings&, Checking&);
void enterMenuSelection(string, int, int, int&);

void savingsMenu(Savings&);
void checkingMenu(Checking&);

int main() {

	cout << fixed << setprecision(2);

	Savings savings(154.67, 3.5);
	Checking checking(1540, 2.4);

	cout << "===========================\n";
	cout << "15-14 BANK ACCOUNTS PROGRAM\n";
	cout << "===========================\n";
	cout << "\n";

	showMainMenu(savings, checking);

}

void showMainMenu(Savings& s, Checking& c) {

	int menu_selection = 0;

	cout << "-------------------------------\n";
	cout << "   CONTINENTAL BANK OF AFRICA  \n";
	cout << "-------------------------------\n";
	cout << "\n";	

	while (menu_selection != 3) {

		cout << "MAIN MENU\n";
		cout << "---------\n";
		cout << "\n";
		cout << "1. Access Savings Account\n";
		cout << "2. Access Checking Account\n";
		cout << "3. Quit program\n";
		cout << "\n";

		enterMenuSelection("Enter your selection: ", 1, 3, menu_selection);

		if (menu_selection == 1) {
			savingsMenu(s);
		}
		else if (menu_selection == 2) {
			checkingMenu(c);
		}

	}

	cout << "Quitting the program...\n";
	exit(EXIT_SUCCESS);

}

void enterMenuSelection(string request, int lower_limit, int upper_limit, int& menu_selection) {

	cout << request;

	while (!(cin >> menu_selection) || menu_selection < lower_limit || menu_selection > upper_limit) {
		cout << "Error: Selection must be a value between " << lower_limit << " - " << upper_limit << ". Re-enter your value.\n";
		cout << "\n";
		cout << request;
	}	

	cin.ignore();
	cout << "\n";

	cout << "--------------------------------------------------------------------------------------------------------\n";
	cout << "\n";

}

void savingsMenu(Savings& s) {

	int menu_selection = 0;
	double amount;
	
	while (menu_selection != 5) {

		cout << "SAVINGS ACCOUNT\n";
		cout << "---------------\n";
		cout << "\n";
		cout << "1. Make a deposit\n";
		cout << "2. Make a withdrawal\n";
		cout << "3. Conduct monthly review\n";
		cout << "4. Show savings account statement\n";
		cout << "5. Return to main menu\n";
		cout << "\n";

		enterMenuSelection("Enter your selection: ", 1, 5, menu_selection);

		if (menu_selection == 1) {

			cout << "How much would you like to deposit: $";

			while (!(cin >> amount) || amount <= 0) {
				cout << "Error: Deposits must be a positive value greater than 0.\n";
				cout << "\n";
				cout << "How much would you like to deposit: $";
			}

			cin.ignore();
			cout << "\n";

			s.deposit(amount);

		}

		else if (menu_selection == 2) {

			cout << "How much would you like to withdraw: $";

			while (!(cin >> amount) || amount <= 0) {
				cout << "Error: Withdrawals must be a positive value greater than 0.\n";
				cout << "\n";
				cout << "How much would you like to withdraw: $";
			}

			cin.clear();
			cin.ignore();
			cout << "\n";

			s.withdraw(amount);

		}

		else if (menu_selection == 3) {

			s.monthlyProc();

		}

		else if (menu_selection == 4) {

			cout << s;

		}

	}	

}

void checkingMenu(Checking& c) {

	int menu_selection = 0;
	double amount;

	while (menu_selection != 4) {

		cout << "CHECKING ACCOUNT\n";
		cout << "----------------\n";
		cout << "\n";
		cout << "1. Make a withdrawal\n";
		cout << "2. Conduct monthly review\n";
		cout << "3. Show checking account statement\n";
		cout << "4. Return to main menu\n";
		cout << "\n";

		enterMenuSelection("Enter your selection: ", 1, 4, menu_selection);

		if (menu_selection == 1) {

			cout << "How much would you like to withdraw: $";

			while (!(cin >> amount) || amount <= 0) {
				cout << "Error: Withdrawals must be a positive value greater than 0.\n";
				cout << "\n";
				cout << "How much would you like to withdraw: $";
			}

			cin.clear();
			cin.ignore();
			cout << "\n";

			c.withdraw(amount);

		}

		else if (menu_selection == 2) {

			c.monthlyProc();

		}

		else if (menu_selection == 3) {

			cout << c << "\n";

		}

	}	


}