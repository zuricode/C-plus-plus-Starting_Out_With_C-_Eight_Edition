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
	catch (Date::InvalidDay dayVal) {
		cout << "ERROR: " << dayVal.getInvalidDay() << " is an invalid day.\n";
		cout << "\n";
	}
	catch (Date::InvalidMonth monthVal) {
		cout << "ERROR: " << monthVal.getInvalidMonth() << " is invalid month.\n";
		cout << "\n";
	}

	date.getDate();

	cout << "Ending the program...\n";

}