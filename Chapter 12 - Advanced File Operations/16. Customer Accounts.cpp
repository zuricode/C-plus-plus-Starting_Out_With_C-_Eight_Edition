//16. Customer Accounts
//
//This program should be designed and written by a team of students.Here are some
//suggestions:
//
//• One student should design function main, which will call other program functions.
//The remainder of the functions will be designed by other members of the team.
//• The requirements of the program should be analyzed so each student is given about
//the same workload.
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
//The structure should be used to store customer account records in a file.The program
//should have a menu that lets the user perform the following operations :
//
//• Enter new records into the file.
//• Search for a particular customer’s recordand display it.
//• Search for a particular customer’s recordand delete it.
//• Search for a particular customer’s recordand change it.
//• Display the contents of the entire file.
//
//Input Validation : When the data for a new account is entered, be sure the user enters
//data for all the fields.No negative account balances should be entered.

#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<vector>

using namespace std;

const int NAME_SIZE = 201;
const int ADDRESS_FIRST_LINE_SIZE = 301;
const int CITY_SIZE = 101;
const int STATE_SIZE = 101;
const int ZIP_SIZE = 9;
const int TELEPHONE_SIZE = 12;
const int DATE_SIZE = 11;

const string	MONTHS[] = { "January", "February", "March", "April", "May",	"June",
							"July", "August", "September", "October", "November", "December" };

struct Address {
	char first_line[ADDRESS_FIRST_LINE_SIZE];
	char city[CITY_SIZE];
	char state[STATE_SIZE];
	char zip[ZIP_SIZE];
};

struct Customer {
	char name[NAME_SIZE];
	Address address;
	char telephone[TELEPHONE_SIZE];
	double balance {0};
	char date_of_last_payment[DATE_SIZE];
};

int menuInputValidation(int, int, string);
double balanceInputValidation(string);
void stringInputValidation(char*, const int, string);
bool isBlank(char*, const int);

void openFile(fstream &file);
bool checkFileExists(fstream&, const string);

void showMenu();

void addRecord(fstream &file, const string location);

void dateInput(char[], string);
bool checkDate(int month, int day, int year, const string MONTHS[]);

int main() {

	fstream file;
	string file_location;

	int choice;

	openFile(file);

	showMenu();
	choice = menuInputValidation(1, 6, "Enter your selection: ");

	switch (choice) {
		case 1:
			addRecord(file, file_location);
			break;

	}

	cout << endl;
	cout << "Quiting the program..." << endl;

	file.close();

}

int menuInputValidation(int min, int max, string request) {

	int choice;

	cout << request;

	while (!(cin >> choice) || choice < min || choice > max) {
		cout << "ERROR: Selection must be between " << min << " and " << " max. " << request;
		cin.clear();
		cin.ignore(1200, 'n');
	}

	cin.clear();
	cin.ignore(1200, '\n');

	return choice;


}

double balanceInputValidation(string request) {

	double num;

	cout << request;

	while (!(cin >> num) || num < 0) {
		cout << "ERROR: The starting account cannot be less than $0." << endl;
		cout << request;
		cin.ignore();
	}

	cin.ignore();

	return num;

}

void stringInputValidation(char* text, const int LIMIT, string request) {

	cout << request;

	while (cin.getline(text, LIMIT) && isBlank(text, LIMIT)) {
		cout << "ERROR: String cannot be left blank." << endl;
		cout << request;
		cin.ignore();
	}

	cin.ignore();
	
	cout << endl;
}

bool isBlank(char* text, const int LIMIT) {

	for (int i = 0; i < LIMIT; i++) {

		if (!isspace(text[i])) {
			return 0;
		}

	}

	return 1;

}

bool checkFileExists(fstream& file, const string LOCATION) {

	file.open(LOCATION, ios::in);

	if (file.fail()) {
		cout << "\"" << LOCATION << "\" does not already exist." << endl;
		return 0;
	}
	else {
		cout << "\"" << LOCATION << "\" was found." << endl;
		file.close();
		return 1;
	}

}

void openFile(fstream &file) {

	string location;
	long file_size;
	bool fileExists;
	bool fileError;

	do {

		fileError = false;

		cout << "Enter the location of your customer accounts file. (If there is not an existing file, one will be created)." << endl;
		cout << endl;
		cout << "File location: ";
		getline(cin, location);

		fileExists = checkFileExists(file, location);

		file.open(location, ios::in | ios::out | ios::binary | ios::app);

		if (!fileExists) {
			cout << "New inventory file \"" << location << "\" has been created." << endl;
		}

		else {

			file.seekg(0L, ios::end);
			file_size = file.tellg();

			if (file_size % sizeof(Customer) != 0 && file_size >= sizeof(Customer)) {
				file.close();
				cout << "This file is not a customer accounts file." << endl;
				cout << endl;
				fileError = true;
			}

		}

	} while (fileError);
			
	cout << endl;

	file.close();

}

void showMenu() {

	cout << "CUSTOMER ACCOUNTS" << endl;
	cout << "========================" << endl;
	cout << endl;

	cout << "1. Add a new customer account" << endl;
	cout << "2. Display a customer record" << endl;
	cout << "3. Delete a customer record" << endl;
	cout << "4. Edit a customer record" << endl;
	cout << "5. Display all customer records" << endl;
	cout << "6. Quit the program" << endl;
	cout << endl;

}

void addRecord(fstream& file, const string LOCATION) {

	Customer new_customer;

	file.open(LOCATION, ios::out | ios::app | ios::binary);

	if (file.fail()) {
		cout << "Error opening " << LOCATION << "." << endl;
		cout << endl;
	}
	else {

		cout << "Enter the details of the new customer record: " << endl;
		cout << endl;

		stringInputValidation(new_customer.name, NAME_SIZE, "Name: ");
		cout << endl;

		cout << "ADDRESS" << endl;
		cout << "==============" << endl;
		stringInputValidation(new_customer.address.first_line, ADDRESS_FIRST_LINE_SIZE, "First line: ");
		stringInputValidation(new_customer.address.city, CITY_SIZE, "City: ");
		stringInputValidation(new_customer.address.state, STATE_SIZE, "State: ");
		stringInputValidation(new_customer.address.zip, ZIP_SIZE, "ZIP: ");
		cout << endl;

		stringInputValidation(new_customer.telephone, TELEPHONE_SIZE, "Telephone Number: ");
		new_customer.balance = balanceInputValidation("Account Balance: $");

		dateInput(new_customer.date_of_last_payment, "Date of last payment: ");

	}

}

void dateInput(char struct_date[], string request) {

	string date, mm, dd, yyyy;
	int i = 0, month, day, year;
	bool valid_date = false;

	do {

		mm = "", dd = "", yyyy = "";

		cout << request;
		getline(cin, date);
		cin.clear();

		if (date.length() != DATE_SIZE - 1 || date[2] != '/' || date[5] != '/') {

			cout << "Error: " << date << " must be in the following format: mm/dd/yyyy" << endl;

		}

		else {

			for (int j = 0; j < DATE_SIZE - 1; j++) {

				if (j == 0 || j == 1) {
					mm += date[j];
				}

				else if (j == 2 || j == 5) {
					continue;
				}

				else if (j == 3 || j == 4) {
					dd += date[j];
				}

				else {
					yyyy += date[j];
				}

			}

			month = stoi(mm);
			day = stoi(dd);
			year = stoi(yyyy);

			valid_date = checkDate(month, day, year, MONTHS);

			if (!valid_date) {
				cout << date << " is not a valid date. Please try again." << endl;
			}

		}

	} while (!valid_date);

	for (int i = 0; i < DATE_SIZE - 1; i++) {
		struct_date[i] = date[i];
	}

}

bool checkDate(int month, int day, int year, const string MONTHS[]) {

	bool valid_date = true, leap_year = false;

	//LIMITS OF MONTH, DAY AND YEAR ENTRY
	if (month < 1 || month > 12) {
		valid_date = false;
		cout << "Error: Your month entered must be a value between 1 - 12." << endl;
	}

	if (day < 1 || day > 31) {
		valid_date = false;
		cout << "Error: Your day entered must be a value between 1 - 31." << endl;
	}

	if (year < 1 || year > 9999) {
		valid_date = false;
		cout << "Error: Your year entered must be a value between 1 - 9999." << endl;
	}

	//LEAP YEAR CHECK
	if (year % 4 == 0) {
		leap_year = true;
	}

	//IN-DEPTH DATE CHECK
	if (month == 4 || month == 6 || month == 9 || month == 11) {

		if (day > 30) {
			valid_date = false;
			cout << "Error: " << MONTHS[month - 1] << " cannot have more than 30 days." << endl;
		}

	}

	if (month == 2) {

		if (leap_year && day > 29) {
			valid_date = false;
			cout << "Error: " << MONTHS[month - 1] << " in " << year << " cannot have more than 29 days." << endl;
		}

		else if (!leap_year && day > 28) {
			valid_date = false;
			cout << "Error: " << MONTHS[month - 1] << " in " << year << " cannot have more than 28 days." << endl;
		}

	}

	return valid_date;

}
