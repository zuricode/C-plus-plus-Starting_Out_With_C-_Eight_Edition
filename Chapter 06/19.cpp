#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

char	type_of_patient;

int		days_in_hospital;

double	daily_rate,
		medication_charges,
		hospital_services,
		total_charges;

double inputValidation(double, int = 0);
int inputValidation(int, int = 0);
char inputValidation(char);

ofstream outputFile;
outputFile.open("C:/Users/Admin/Desktop/15_hospital_exercises.txt");

double totalCharges(int &, double &, double &, double &, ofstream &);
double totalCharges(double &, double &, ofstream &);

int main() {

	cout << "\nWere you admitted as an in-patient or an out-paitent (\"I\" for in-patient/ \"O\" for out-patient): ";

	type_of_patient = inputValidation(type_of_patient);

	if (type_of_patient == 'I') {

		cout << "\nHow many days did you spend at the hospital: ";
		days_in_hospital = inputValidation(days_in_hospital);

		cout << "\nWhat was the daily rate: $";
		daily_rate = inputValidation(daily_rate);

		cout << "\nHow much were the hospital medication charges: $";
		medication_charges = inputValidation(medication_charges);

		cout << "\nHow much were the charges fo hospital services (lab tests, etc.): $";
		hospital_services = inputValidation(hospital_services);

		total_charges = totalCharges(days_in_hospital, daily_rate, medication_charges, hospital_services, outputFile);

		outputFile << "\nTotal charges: $" << total_charges;
		

	}

	if (type_of_patient == 'O') {

		cout << "\nHow much were the charges fo hospital services (lab tests, etc.): $";
		hospital_services = inputValidation(hospital_services);

		cout << "\nHow much were the hospital medication charges: $";
		medication_charges = inputValidation(medication_charges);

		total_charges = totalCharges(medication_charges, hospital_services, outputFile);

		outputFile << "\nTotal charges: $" << total_charges;

	}

	
	cout << endl << endl;

	outputFile.close();

}

int inputValidation(int num, int limit) {

	while (!(cin >> num) || num < limit) {
		cout << "Error: Value must be an integer greater than " << limit << ". Please re-enter your value: ";
		cin.clear();
		cin.ignore(1200, '\n');
	}

	return num;

}

double inputValidation(double num, int limit) {

	while (!(cin >> num) || num < limit) {
		cout << "Error: Value must be an integer greater than " << limit << ". Please re-enter your value: ";
		cin.clear();
		cin.ignore(1200, '\n');
	}

	return num;

}

char inputValidation(char letter) {

	while (!(cin >> letter) || (letter != 'I' && letter != 'O')) {
		cout << "Error: Character must be \"I\" or \"O\". Please re-enter your character: ";
		cin.clear();
		cin.ignore(1200, '\n');
	}

	return letter;

}

double totalCharges(int &days_in_hospital, double &daily_rate, double &medication_charges, double &hospital_services, ofstream outputFile) {

	double total;
	
	outputFile << fixed << setprecision(2);
	outputFile << "\nDays in hospital: " << days_in_hospital;
	outputFile << "\nDaily rate: $" << daily_rate;
	outputFile << "\nMedication charges: $" << medication_charges;
	outputFile << "\nHospital services: $" << hospital_services;

	total = (double(days_in_hospital) * daily_rate) + medication_charges + hospital_services;

	return total;

}

double totalCharges(double &medication_charges, double &hospital_services, ofstream outputFile) {

	double total;

	outputFile << fixed << setprecision(2);
	outputFile << "\nMedication charges: $" << medication_charges;
	outputFile << "\nHospital services: $" << hospital_services;

	total = medication_charges + hospital_services;

	return total;

}