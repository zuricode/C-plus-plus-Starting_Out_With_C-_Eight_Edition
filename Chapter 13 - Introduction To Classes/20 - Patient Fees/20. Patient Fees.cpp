//20. Patient Fees
//
//1. This program should be designed and written by a team of students.Here are some
//suggestions :
//
//– One or more students may work on a single class.
//– The requirements of the program should be analyzed so each student is given
//about the same workload.
//– The parameters and return types of each function and class member function
//should be decided in advance.
//– The program will be best implemented as a multi - file program.
//
//2. You are to write a program that computes a patient’s bill for a hospital stay.The
//
//The PatientAccount class
//The Surgery class
//The Pharmacy class
//The main program
//
//– The PatientAccount class will keep a total of the patient’s charges.It will also
//keep track of the number of days spent in the hospital.The group must decide
//on the hospital’s daily rate.
//– The Surgery class will have stored within it the charges for at least five types
//of surgery.It can update the charges variable of the PatientAccount class.
//– The Pharmacy class will have stored within it the price of at least five types of
//medication.It can update the charges variable of the PatientAccount class.
//– The student who designs the main program will design a menu that allows the
//user to enter a type of surgeryand a type of medication, and check the patient
//out of the hospital.When the patient checks out, the total charges should be
//displayed.

#include "Patient.h"
#include "Surgery.h"
#include "Pharmacy.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

string stringValidation(const string);

void init(fstream &);

int showMenu();
int menuChoice(const string, const int, const int);

void addPatient();
void admitPatient();
void createInvoice();

//######################################################################

int main() {

	fstream data;

	init(data);

	int menu_choice;

	cout << "13-20 PATIENT DATABASE PROGRAM\n";
	cout << "===================================\n";
	cout << "\n";

	menu_choice = showMenu();

}

//######################################################################

string stringValidation(const string REQUEST) {

	string text;

	cout << REQUEST;

	while (!(getline(cin, text)) || text == "") {

		cout << "ERROR: String entry cannot be blank.\n";
		cout << "\n";
		cout << REQUEST;
	}

	cout << "\n";

	return text;

}

void init(fstream &data) {

	string file_location;

	file_location = stringValidation("Enter the file location for the patient data: ");

	data.open(file_location, ios::out);

	if (!data.fail()) {
		cout << file_location << " does not exist.\n";
		cout << "Creating a new directory...\n";
		cout << "\n";
	}
	else {
		cout << "An existing directory was found.\n";
		cout << "Opening the directory...\n";
	}

	data << "dfgfdgsdgdf\n";

	data.close();

}

int showMenu() {

	int menu_choice;

	cout << "Menu: \n";
	cout << "-------\n";
	cout << "\n";

	cout << "\t[1] - ADD NEW PATIENT\n";
	cout << "\t[2] - ADMIT PATIENT INTO HOSPITAL\n";
	cout << "\t[3] - CREATE INVOICE FOR PATIENT ADMISSION\n";
	cout << "\n";
	cout << "\n";

	menu_choice = menuChoice("Enter your selection: ", 1, 3);

	return menu_choice;

	switch (menu_choice) {
		case 1:
			addPatient();
			break;
		case 2:
			admitPatient();
			break;
		case 3:
			createInvoice();
			break;

	}

}

int menuChoice(const string REQUEST, const int MIN, const int MAX) {

	int num;

	cout << REQUEST;

	while (!(cin >> num) || (num < MIN || num > MAX)) {

		cout << "ERROR: Your selection must be between " << MIN << " and " << MAX << "\n";
		cin.ignore();
		cout << "\n";
		cout << REQUEST;
	}

	cin.ignore();

	return num;

}

void addPatient() {

}

void admitPatient() {

}

void createInvoice() {

}
