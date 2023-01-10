//7. Customer Accounts
//
//Write a program that uses a structure to store the following data about a customer
//account :
//
//Name
//Address
//City, State, and ZIP
//Telephone Number
//Account Balance
//Date of Last Payment
//
//The program should use an array of at least 10 structures.It should let the user enter
//data into the array, change the contents of any element, and display all the data stored
//in the array.The program should have a menu - driven user interface.
//
//Input Validation : When the data for a new account is entered, be sure the user enters
//data for all the fields.No negative account balances should be entered.

#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

struct Customer {

	string name;
	string address;
	string city;
	string state;
	string zip;
	string telephone_number;
	double balance{};
	string date_of_last_payment;

};

int inputTwoLimits(int, int);
string inputString(string);
int inputBalance();
string inputDate();

int Menu();
void inputCustomerData(Customer[], const int);
void editCustomerMenu(Customer[], const int, bool);
void editCustomerEntry(Customer[], int);
void showCustomerData(Customer[], const int, bool);

int main() {

	const int		AMOUNT = 10;

	Customer		list[AMOUNT];
	int				menu_choice;
	bool			quit = false, isData = false;

	cout << endl;
	cout << "CUSTOMER ACCOUNTS PROGRAM" << endl;
	cout << "=================================" << endl;
	cout << endl;

	do {

		menu_choice = Menu();

		switch (menu_choice) {
		case 1:
			inputCustomerData(list, AMOUNT);
			isData = true;
			break;
		case 2:
			editCustomerMenu(list, AMOUNT, isData);
			break;
		case 3:
			showCustomerData(list, AMOUNT, isData);
			break;
		case 4:
			quit = true;
			break;
		} 

	} while (!quit);

	cout << "You have chosen to quit the program." << endl;
	cout << "Goodbye!" << endl;

}

int inputTwoLimits(int min, int max) {

	int num;

	while (!(cin >> num) || num < min || num > max ) {
		cout << "ERROR: Value must be greater than or equal to " << min << " and less than or equal to " << max << ". Re-enter your selection: ";
		cin.clear();
		cin.ignore(1200, '\n');
	}

	cin.clear();
	cin.ignore(1200, '\n');

	return num;
}

string inputString(string text) {
	
	string input;
	bool alnum, punct;

	do {

		alnum = false;
		punct = false;

		cout << text;
		getline(cin, input);

		for (int i = 0; i < input.length(); i++) {
			if (isalnum(input[i])) {
				alnum = true;
			}
			else if (ispunct(input[i])) {
				punct = true;
			}
		}

		if (!alnum && !punct) {
			cout << "ERROR: You have entered a blank string: Re-enter your string." << endl;
		}

	} while (!alnum && !punct);

	return input;

}

int inputBalance() {

	int num;

	while (!(cin >> num) || num < 0) {
		cout << "ERROR: Value must be an integer greater than 0. Re-enter your value: ";
		cin.clear();
		cin.ignore(1200, '\n');
	}

	cin.clear();
	cin.ignore(1200, '\n');

	return num;

}

void inputCustomerData(Customer c[], const int AMOUNT) {

	cout << "ENTER CUSTOMER DATA" << endl;
	cout << "-----------------------------" << endl;
	cout << endl;

	for (int i = 0; i < AMOUNT; i++) {

		cout << "CUSTOMER #" << i + 1 << ": " << endl;

		c[i].name = inputString("Name: ");		
		c[i].address = inputString("Address: ");		
		c[i].city = inputString("City: ");		
		c[i].state = inputString("State: ");		
		c[i].zip = inputString("ZIP: ");
		c[i].telephone_number = inputString("Telephone number: ");

		cout << "Account Balance: $";
		c[i].balance = inputBalance();

		c[i].date_of_last_payment = inputDate();
	
	}

	cout << AMOUNT << " customer entries were successfully entered." << endl;
	cout << endl;


}

string inputDate() {

	string date, error = "ERROR: Date must be entered in the following format (mm/dd/yyyy).";
	int SIZE = 10, month, day, year;
	bool invalid_date;

	do {

		cout << "Date of last payment in the following format (mm/dd/yyyy): ";

		string mm = "", dd = "", yyyy = "";
		month = -1;
		day = -1;
		year = -1;

		invalid_date = false;

		getline(cin, date);

		cin.clear();

		if (date.length() != SIZE || date[2] != '/' || date[5] != '/') {
			invalid_date = true;
			cout << error << endl;
		}

		else if (!invalid_date) {

			for (int i = 0; i < date.length(); i++) {

				// MONTH

				if (i == 0) {
					mm.append(1, date[i]);
				}

				if (i == 1) {

					mm.append(1, date[i]);
					month = stoi(mm);

					if (month < 1 || month > 12) {
						invalid_date = true;
						cout << "ERROR: Lowest month can be no less than 01. Largest month can be more than 12." << endl;
					}

				}

				// DAY

				if (i == 3) {
					dd.append(1, date[i]);
				}

				if (i == 4) {

					dd.append(1, date[i]);
					day = stoi(dd);

				}

				// YEAR

				if (i > 5 && i < 10) {

					yyyy.append(1, date[i]);

					if (i == 9) {
						year = stoi(yyyy);

						if (year < 1 || year > 9999) {
							invalid_date = true;
							cout << "ERROR: Lowest year can be no less than 0001. Largest day can be more than 9999." << endl;
						}

					}

				}

			}

			switch (month) {

			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:

				if (day > 31) {
					invalid_date = true;
					cout << "ERROR: Lowest day can be no less than 01. Largest day can be more than 31." << endl;
				}

				break;

			case 4:
			case 6:
			case 9:
			case 11:

				if (day < 1 || day > 30) {
					invalid_date = true;
					cout << "ERROR: Lowest day can be no less than 01. Largest day can be more than 30 for the months of April, June, September and November." << endl;
				}

				break;

			case 2:

				if (year % 4 == 0) {
					if (day < 1 || day > 29) {
						invalid_date = true;
						cout << "ERROR: " << year << " is a leap year." << endl;
						cout << "There is a maximum of 29 days in February during a leap year; " << endl;
					}
				}

				else {
					if (day < 1 || day > 28) {
						invalid_date = true;
						cout << "ERROR: " << year << " is not a leap year. There is a maximum of 28 days in February during a non-leap year." << endl;
					}
				}

				break;
			}

		}

		cout << endl;

	} while (invalid_date);

	return date;

}

int Menu() {

	int choice;

	cout << "-----------------------------" << endl;
	cout << "*******     MENU     ********" << endl;
	cout << "-----------------------------" << endl;
	cout << endl;
	cout << "1. Create new customer" << endl;
	cout << "2. Edit existing customer" << endl;
	cout << "3. Show all customer data" << endl;
	cout << "4. Quit program" << endl;
	cout << endl;
	cout << "Enter your selection (1-4): ";

	choice = inputTwoLimits(1, 4);

	cout << endl;

	return choice;

}

void editCustomerMenu(Customer c[], const int AMOUNT, bool isData) {

	int choice;

	if (isData) {

		cout << "Choose the customer you would like to edit. " << endl;
		cout << endl;

		for (int i = 0; i < AMOUNT; i++) {
			cout << i + 1 << ". - " << c[i].name << endl;
		}

		cout << endl;

		cout << "Enter your selection (1-" << AMOUNT << "): ";

		choice = inputTwoLimits(1, AMOUNT);
		choice -= 1;

		editCustomerEntry(c, choice);

	}

	else {
		cout << "ERROR: There is no existing data to edit!" << endl;
	}

	cout << endl;

}

void editCustomerEntry(Customer c[], int customer) {

	int choice;
	bool quit = false;

	do {

		cout << "Which attribute of \"" << c[customer].name << "\" would you like to edit: " << endl;
		cout << endl;
		cout << "1. Name: " << c[customer].name << endl;
		cout << "2. Address: " << c[customer].address << endl;
		cout << "3. City: " << c[customer].city << endl;
		cout << "4. State: " << c[customer].state << endl;
		cout << "5. ZIP: " << c[customer].zip << endl;
		cout << "6. Telephone number: " << c[customer].telephone_number << endl;
		cout << "7. Account Balance: $" << fixed << setprecision(2) << c[customer].balance << endl;
		cout << "8. Date of last payment: " << c[customer].date_of_last_payment << endl;
		cout << "9. Return to main menu: " << endl;
		cout << endl;
		cout << "Enter your selection (1-8): ";

		choice = inputTwoLimits(1, 9);

		switch (choice) {
		case 1:
			cout << "Previous name: " << c[customer].name << endl;
			c[customer].name = inputString("Enter the customer's new name: ");
			cout << "Name was successfully changed." << endl;
			break;
		case 2:
			cout << "Previous address: " << c[customer].address << endl;
			c[customer].address = inputString("Enter the customer's new address: ");
			cout << "Address was successfully changed." << endl;
			break;
		case 3:
			cout << "Previous city: " << c[customer].city << endl;
			c[customer].city = inputString("Enter the customer's new city: ");
			cout << "City was successfully changed." << endl;
			break;
		case 4:
			cout << "Previous state: " << c[customer].state << endl;
			c[customer].state = inputString("Enter the customer's new state: ");
			cout << "State was successfully changed." << endl;
			break;
		case 5:
			cout << "Previous ZIP: " << c[customer].zip << endl;
			c[customer].zip = inputString("Enter the customer's new ZIP: ");
			cout << "ZIP was successfully changed." << endl;
			break;
		case 6:
			cout << "Previous telephone number: " << c[customer].telephone_number << endl;
			c[customer].telephone_number = inputString("Enter the customer's new telephone number: ");
			cout << "Telephone number was successfully changed." << endl;
			break;
		case 7:
			cout << "Previous account balance $: " << c[customer].balance << endl;
			cout << "Enter the customer's new account balance $: ";
			c[customer].balance = inputBalance();
			cout << "Account balance was successfully changed." << endl;
			break;
		case 8:
			cout << "Previous date of last payment: " << c[customer].date_of_last_payment << endl;
			c[customer].date_of_last_payment = inputDate();
			cout << "Date of latest payment was successfully changed." << endl;
			break;
		case 9:
			quit = true;
			break;
		}

		cout << endl;

	} while (!quit);

	cout << "Returning to main menu..." << endl;

	cout << endl;

}

void showCustomerData(Customer c[], const int AMOUNT, bool isData) {

	if (isData) {

		for (int i = 0; i < AMOUNT; i++) {

			cout << "CUSTOMER #" << i + 1 << ": " << endl;
			cout << "----------------" << endl;
			cout << endl;
			cout << "Name: " << c[i].name << endl;
			cout << "Address: " << c[i].address << endl;
			cout << "City: " << c[i].city << endl;
			cout << "State: " << c[i].state << endl;
			cout << "ZIP: " << c[i].zip << endl;
			cout << "Telephone Number: " << c[i].telephone_number << endl;
			cout << "Account Balance: $" << c[i].balance << endl;
			cout << "Date of last payment: " << c[i].date_of_last_payment << endl;

			cout << endl;

		}

	}

	else {
		cout << "ERROR: There is no customer data to show!" << endl;
	}

	cout << endl;

}




