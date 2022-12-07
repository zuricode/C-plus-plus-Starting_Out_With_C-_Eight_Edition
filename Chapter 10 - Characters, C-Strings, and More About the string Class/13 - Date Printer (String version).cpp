//13. Date Printer
//Write a program that reads a string from the user containing a date in the form mm /dd/yyyy.
//It should print the date in the form March 12, 2014.

#include <iostream>
#include <string>

using namespace std;

void validateDate(string, const int);
void displayDate(string, const int);

int main() {

	const int		SIZE = 10;

	string			date;

	validateDate(date, SIZE);

}

void validateDate(string date, const int SIZE) {

	string error = "ERROR: Date must be entered in the following format (mm/dd/yyyy).";
	bool invalid_date;

	do {

		invalid_date = false;

		cout << "Enter your date in the following format (mm/dd/yyyy): ";
		getline(cin, date);

		if (date.length() != SIZE) {
			invalid_date = true;
			cout << error << endl;
		}

		else if (!invalid_date) {

			for (int i = 0; i < date.length(); i++) {

				cout << date[i] << endl;

				if (i == 0) {
					if (date[i] < 0 || date[i] > 1) {
						invalid_date = true;
						cout << "ERROR: Lowest month can be no less than 01. Largest month can be more than 12." << endl;
					}
				}

				if (i == 1) {
					if (date[0] == 0) {
						if (date[i] < 1 || date[i] > 9) {
							invalid_date = true;
							cout << "ERROR: Lowest month can be no less than 01. Largest month can be more than 12." << endl;
						}
					}

					if (date[0] == 1) {
						if (date[i] < 0 || date[i] > 2) {
							invalid_date = true;
							cout << "ERROR: Lowest month can be no less than 01. Largest month can be more than 12." << endl;
						}
					}
				}

				if (i == 2 || i == 5) {
					if (date[i] != '/') {
						invalid_date = true;
						cout << "ERROR: Months, days and years must be separated by the \"/\" symbol." << endl;
					}
				}

				if (i == 3) {
					if (date[i] < 0 || date[i] > 3) {
						invalid_date = true;
						cout << "ERROR: Lowest day can be no less than 01. Largest day can be more than 31." << endl;
					}
				}

				if (i == 4) {
					if (date[3] == 1 || date[3] == 2) {
						if (date[i] < 0 || date[i] > 9) {
							invalid_date = true;
							cout << "ERROR: Lowest day can be no less than 01. Largest day can be more than 31." << endl;
						}
					}

					if (date[3] == 0) {
						if (date[i] < 1 || date[i] > 9) {
							invalid_date = true;
							cout << "ERROR: Lowest day can be no less than 01. Largest day can be more than 31." << endl;
						}
					}

					if (date[3] == 3) {
						if (date[i] != 0 || date[i] != 1) {
							invalid_date = true;
							cout << "ERROR: Lowest day can be no less than 01. Largest day can be more than 31." << endl;
						}
					}
				}

				if (i == 6 || i == 7 || i == 8) {
					if (date[i] < 0 || date[i] > 9) {
						invalid_date = true;
						cout << "ERROR: Lowest year can be no less than 0001. Largest day can be more than 9999." << endl;
					}
				}

				if (i == 9) {
					if (date[6] == 0 && date[7] == 0 && date[8] == 0) {
						if (date[i] < 1 || date[i] > 9) {
							invalid_date = true;
							cout << "ERROR: Lowest year can be no less than 0001. Largest day can be more than 9999." << endl;
						}
					}
				}

			}

		}

	} while (invalid_date);

	cout << date << " is a valid date format." << endl << endl;

}