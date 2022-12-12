//13. Date Printer
//Write a program that reads a string from the user containing a date in the form mm /dd/yyyy.
//It should print the date in the form March 12, 2014.

#include <iostream>
#include <string>

using namespace std;

void validateDate(string, const int, int&, int&, int&);
void displayDate(int, int, int);

int main() {

	const int		SIZE = 10;
	int				month = -1, day = -1, year = -1;

	string			date;

	validateDate(date, SIZE, month, day, year);

	displayDate(month, day, year);

}

void validateDate(string date, const int SIZE, int& month, int& day, int& year) {

	string error = "ERROR: Date must be entered in the following format (mm/dd/yyyy).";

	bool invalid_date;

	do {

		string mm = "", dd = "", yyyy = "";
		month = -1;
		day = -1;
		year = -1;

		invalid_date = false;

		cout << "Enter your date in the following format (mm/dd/yyyy): ";
		getline(cin, date);

		cin.clear();

		if (date.length() != SIZE &&
			date[2] != '/' &&
			date[5] != '/') {
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

	if (!invalid_date) {
		cout << date << " is a valid date format." << endl << endl;
	}


}

void displayDate(int month, int day, int year) {

	string		list_of_months[12]{ "January", "February", "March", "April",
							"May", "June", "July", "August", "September",
							"October", "November", "December"};

	cout << list_of_months[month - 1] << " " << day << ", " << year << endl;

}