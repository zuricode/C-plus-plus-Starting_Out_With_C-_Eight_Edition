//16. Exception Project
//
//This assignment assumes you have completed Programming Challenge 1 of Chapter 15
//(Employee and ProductionWorker Classes).Modify the Employee and
//ProductionWorker classes so they throw exceptions when the following errors occur :
//
//• The Employee class should throw an exception named InvalidEmployeeNumber
//when it receives an employee number that is less than 0 or greater than 9999.
//• The ProductionWorker class should throw an exception named InvalidShift
//when it receives an invalid shift.
//• The ProductionWorker class should throw an exception named InvalidPayRate
//when it receives a negative number for the hourly pay rate.
//
//Write a driver program that demonstrates how each of these exception conditions
//works.

#include "Employee.h"
#include "ProductionWorker.h"

using std::cin;

int main() {

	int number;
	string name;
	string date;
	int shift;
	double pay;
	bool tryAgain = true;

	cout << "--------------------------------\n";
	cout << "16 -13 EXCEPTION PROJECT PROGRAM\n";
	cout << "--------------------------------\n";
	cout << "\n";

	Employee employee;
	ProductionWorker prodworker;

	while (tryAgain) {

		cout << "Standard Employee Details\n";
		cout << "-------------------------\n";
		cout << "\n";

		cout << "Name: ";
		getline(cin, name);

		cout << "Number: ";
		cin >> number;
		cin.ignore();

		cout << "Hire date: ";
		getline(cin, date);

		cout << "\n";

		try {
			employee.setName(name);
			employee.setNumber(number);
			employee.setHireDate(date);
			tryAgain = false;

		}
		catch (Employee::InvalidEmployeeNumber i) {
			cout << i.getNumber() << " is not a valid employee number.\n";
			cout << "All employee numbers must be between " << MIN_NUMBER << " and " << MAX_NUMBER << ".\n";
			cout << "\n";
		}


	}

	tryAgain = true;

	while (tryAgain) {

		cout << "Production Worker Details\n";
		cout << "-------------------------\n";
		cout << "\n";

		cout << "Name: ";
		getline(cin, name);

		cout << "Number: ";
		cin >> number;
		cin.ignore();

		cout << "Hire date: ";
		getline(cin, date);

		cout << "Shift: ";
		cin >> shift;

		cout << "Hourly Pay Rate: ";
		cin >> pay;

		cout << "\n";

		try {
			prodworker.setName(name);
			prodworker.setNumber(number);
			prodworker.setHireDate(date);
			tryAgain = false;
		}
		catch (Employee::InvalidEmployeeNumber i) {
			cout << i.getNumber() << " is not a valid employee number.\n";
			cout << "All employee numbers must be between " << MIN_NUMBER << " and " << MAX_NUMBER << ".\n";
			cout << "\n";
		}

		try {
			prodworker.setShift(shift);
			tryAgain = false;
		}
		catch (ProductionWorker::InvalidShift i) {
			cout << i.getShift() << " is not a valid shift.\n";
			cout << "A shift is either " << DAY << "(DAY) or " << NIGHT << "(NIGHT).\n";
			cout << "\n";
		}

		try {
			prodworker.setHourlyPayRate(pay);
			tryAgain = false;
		}
		catch (ProductionWorker::InvalidPayRate i) {
			cout << i.getPayRate() << " is not a valid pay rate.\n";
			cout << "A pay rate cannot be less than or equal to 0.\n";
			cout << "\n";
		}

	}

	cout << "Ending the program...\n";
	cout << "\n";
	
}