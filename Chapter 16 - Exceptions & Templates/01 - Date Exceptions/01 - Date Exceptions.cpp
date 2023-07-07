//1. Date Exceptions
// 
//Modify the Date class you wrote for Programming Challenge 1 of Chapter 13. The
//class should implement the following exception classes :
// 
//InvalidDay -  Throw when an invalid day(< 1 or > 31) is passed to the class.
//InvalidMonth -  Throw when an invalid month(< 1 or > 12) is passed to the class.
// 
//Demonstrate the class in a driver program.

#include "Date.h"

int main() {

	Date date;

	cout << "===============================\n";
	cout << "16-01 - DATE EXCEPTIONS PROGRAM\n";
	cout << "===============================\n";
	cout << "\n";

	try {
		date.setDate();
	}
	catch (Date::InvalidDay) {
		cout << "ERROR: Day cannot be lesser than 1 or greater than 31." << "\n";
		cout << "\n";
	}
	catch (Date::InvalidMonth) {
		cout << "ERROR: Day cannot be lesser than 1 or greater than 12." << "\n";
		cout << "\n";
	}

	date.getDate();

	cout << "Ending the program...\n";

}