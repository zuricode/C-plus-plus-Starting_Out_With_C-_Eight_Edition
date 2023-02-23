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
char* stringInputValidation(string);

string initFile();
void showMenu();

void addRecord(fstream &file, const string location);

int main() {

	fstream file;
	string file_location;

	int choice;

	file_location = initFile();

	showMenu();
	choice = menuInputValidation(1, 6, "Enter your selection: ");

	switch (choice) {
		case 1:
			addRecord(file, file_location);
			break;

	}

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

char* stringInputValidation(string request) {

	bool isBlank
	string text;

	cout << request;

	getline(cin, text);



}


string initFile() {

	fstream file;
	string location;

	cout << "Enter the location of your customer accounts file: ";
	getline(cin, location);

	cout << endl;

	file.open(location, ios::out | ios::app);

	if (!file) {
		cout << "Error creating the file. Please check your chosen file location, re-run the program and try again." << endl;
		cout << "Aborting the program..." << endl;
		exit(EXIT_FAILURE);
	}
		
	else {
		cout << location << "was successfuly initialzed." << endl;
	}

	cout << endl;

	file.close();

	return location;

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
		cout << "Error opening " << location << "." < endl;
		cout << endl;
	}
	else {

		cout << "Enter the details of the new customer record: " << endl;
		cout << endl;

		cout << "Name: ";
		cin.getline(new_customer.name, NAME_SIZE);
	}

}
