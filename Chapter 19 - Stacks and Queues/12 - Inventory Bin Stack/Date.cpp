#include "Date.h"

using std::to_string;

Date::Date(const Date& SOURCE) {

	day = SOURCE.day;
	month = SOURCE.month;
	year = SOURCE.year;

}

void Date::setDate() {

	string date;	

	do {

		cout << "Date of Manufacture (in the format of DD/MM/YYYY): ";

		while (getline(cin, date) && (date.length() != 10 || date[2] != '/' || date[5] != '/')) {
			cout << "ERROR: Invalid date format. Please enter your date as DD/MM/YYYY (e.g 04/06/1987).\n";
			cout << "\n";
			cout << "Date of Manufacture (in the format of DD/MM/YYYY): ";
		}

		day = stoi(date.substr(0, 2));
		month = stoi(date.substr(3, 2));
		year = stoi(date.substr(6, 4));

	} while (!checkDate());

	cout << "A manufacture date of " << getDate() << " has been set successfully.\n";
	cout << "\n";

}

bool Date::checkDate() {

	bool isValid = true;

	const int MIN_YEAR = 1800;
	const int MAX_YEAR = 2023;

	string months[13]{ "", "January", "February", "March", "April", "May", "June", "July",
					"August", "September", "October", "November", "December" };

	int months_30days[4]{ 4, 6, 9, 11 };

	if (year < MIN_YEAR || year > MAX_YEAR) {
		cout << "ERROR: Year must be between and including " << MIN_YEAR << " and " << MAX_YEAR << ".\n";
		isValid = false;
	}

	if (day < 1 || day > 31) {
		cout << "ERROR: Day must be between and including " << 1 << " and " << 31 << ".\n";
		isValid = false;
	}

	if (month < 1 || month > 12) {
		cout << "ERROR: Month must be between and including " << 1 << " and " << 12 << ".\n";
		isValid = false;
	}

	for (int i = 0; i < 4; i++) {
		if (month == months_30days[i] && day > 30) {
			cout << "ERROR: " << months[i] << " only has 30 days.\n";
			cout << day << "/" << month << "/" << year << " is NOT a valid date.\n\n";
			isValid = false;
		}
	}

	if (month == 2) {

		if (year % 4 != 0) {

			if (day > 28) {
				cout << "ERROR: " << year << " is not a leap year and so February only has 28 days.\n\n";
				cout << day << "/" << month << "/" << year << " is NOT a valid date.\n\n";
				isValid =  false;

			}

		}
		else {

			if (day > 29) {
				cout << "ERROR: " << year << " is a leap year. February has a maximum of 29 days in the month.\n";
				cout << day << "/" << month << "/" << year << " is NOT a valid date.\n";
				isValid = false;
			}

		}

	}	

	if(isValid) {
	return true;
	}
	else {
		cout << "\n";
		return false;
	}



}

string Date::getDate() const {

	if (day == -1 || month == -1 || year == -1) {
		return "ERROR: No date has been set.\n";
	}

	else {

		string date = "";

		if (day < 10) {
			date += "0";
		}

		date += to_string(day);
		date += "/";

		if (month < 10) {
			date += "0";
		}

		date += to_string(month);
		date += "/";

		date += to_string(year);

		return date;

	}	

}