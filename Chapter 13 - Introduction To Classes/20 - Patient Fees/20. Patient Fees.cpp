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
#include <vector>

using namespace std;

string stringValidation(const string);
bool boolValidation(const string);

int showMenu();
int menuChoice(const string, const int, const int);

void addPatient(vector<Patient> &);
void admitPatient(vector<Patient> &);
void createInvoice();

const double DAILY_RATE = 150.00;

//######################################################################

int main() {

	int menu_choice;
	vector<Patient> database;
	bool go_back = false;

	cout << "13-20 PATIENT DATABASE PROGRAM\n";
	cout << "===================================\n";
	cout << "\n";

	do {

		menu_choice = showMenu();

		switch (menu_choice) {
		case 1:
			addPatient(database);
			break;
		case 2:
			admitPatient(database);
			break;
		case 3:
			createInvoice();
			break;
		}

		go_back = boolValidation("Would you like to use another service from the menu: ");

	} while (go_back);

	cout << "Thank you for using the hospital database. Have a great day!" << "\n";
	
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

bool boolValidation(const string REQUEST) {

	char letter;

	cout << REQUEST;

	while (!(cin >> letter) || (toupper(letter) != 'Y' && toupper(letter) != 'N')) {
		cout << "ERROR: Enter either Y\\y or N\\n.\n";
		cout << "\n";
		cin.ignore();
		cout << REQUEST;
	}

	cin.ignore();

	letter = toupper(letter);

	cout << "\n";

	if (letter == 'Y') {
		return true;
	}
	else {
		return false;
	}

}

int showMenu() {

	int menu_choice;

	cout << "MENU: \n";
	cout << "-------\n";
	cout << "\n";

	cout << "\t[1] - ADD NEW PATIENT\n";
	cout << "\t[2] - ADMIT PATIENT INTO HOSPITAL\n";
	cout << "\t[3] - CREATE INVOICE FOR PATIENT ADMISSION\n";
	cout << "\n";
	cout << "\n";

	menu_choice = menuChoice("Enter your selection: ", 1, 3);
	menu_choice++;

	cout << "\n";

	return menu_choice;

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

	num--;

	return num;

}

void addPatient(vector<Patient> &database) {

	Patient new_patient;
	Surgery surgery;
	string temp;

	cout << "ENTER NEW PATIENT DATA\n";
	cout << "----------------\n";
	cout << "\n";

	cout << "There are " << database.size() << " patients currently in the database.\n";
	cout << "\n";

	cout << "Full name: ";
	getline(cin, temp);
	new_patient.setName(temp);
	cout << "\n";

	cout << "Adding patient to the database..." << "\n";
	database.push_back(new_patient);
	cout << "Patient \"" << new_patient.getName() << " was added to the database.\n";

	cout << "\n";

}

void admitPatient(vector<Patient> &database) {	

	Surgery surgery;
	int patient_choice;
	int second_choice;

	if (database.size() > 0) {

		cout << "PATIENT ADMISSION: " << "\n";
		cout << "-------------------" << "\n";
		cout << "\n";

		cout << "Patient in the database: " << "\n";
		cout << "\n";

		for (int i = 0; i < database.size(); i++) {
			cout << "\t[" << i + 1 << "]" << " - " << database[i].getName() << "\n";
		}

		cout << "\n";

		patient_choice = menuChoice("Select your chosen patient: ", 1, database.size());

		cout << "What form of surgery did " << database[patient_choice].getName() << " undergo?\n";
		cout << "\n";

		for (int i = 0; i < TYPES_OF_SURGERY; i++) {
			cout << "[" << i + 1 << "] - " << surgery.getType(i) << "\n";
		}

		cout << "\n";
		second_choice = menuChoice("Enter your selection: ", 1, TYPES_OF_SURGERY);

		database[patient_choice].addOperationAmount();
		database[patient_choice].addOperationTitle(surgery.getType(second_choice));
		database[patient_choice].addDaysInHospital(surgery.getTimeframeDays(second_choice));
		database[patient_choice].addCharge(surgery.getCharge(second_choice));

		cout << "Full Name: " << database[patient_choice].getName() << "\n";
		cout << "Total charges: $" << fixed << setprecision(2) << database[patient_choice].getTotalCharges() << "\n";
		cout << "Total number of days in hospital: " << database[patient_choice].getDaysInHospital() << "\n";
		cout << "Total number of operations: " << database[patient_choice].getTotalOperations() << " - List of operation(s): ";
		database[patient_choice].getAllOperations();
		cout << "\n";
		cout << "\n";

	}

	else {
		cout << "ERROR: There are no patients in the database to admit! Add a patient from the menu first.\n";
	}

	cout << "\n";
	
}

void createInvoice() {

}
