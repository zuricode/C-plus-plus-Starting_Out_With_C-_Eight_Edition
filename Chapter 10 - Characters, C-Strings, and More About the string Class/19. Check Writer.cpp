//19. Check Writer
//
//Write a program that displays a simulated paycheck.The program should ask the user to
//enter the date, the payee’s name, and the amount of the check(up to $10, 000).It should
//then display a simulated check with the dollar amount spelled out, as shown here :
//
//Date: 11 / 24 / 2014
//Pay to the Order of : John Phillips $1920.85
//
//One thousand nine hundred twenty and 85 cents
//
//Be sure to format the numeric value of the check in fixed - point notation with two
//decimal places of precision.Be sure the decimal place always displays, even when the
//number is zero or has no fractional part.Use either C - strings or string class objects
//in this program.
//
//Input Validation : Do not accept negative dollar amounts, or amounts over $10, 000.

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int		DATE_LENGTH = 10;
const string	MONTHS[] = { "January", "February", "March", "April", "May",	"June",
							"July", "August", "September", "October", "November", "December" };

int intValidation(int);
char* dateInput();
bool checkDate(int, int, int, const string[]);

int main() {

	char date[DATE_LENGTH];

	dateInput();

}

int intValidation(int min_limit, int max_limit) {

	int num;

	while (!(cin >> num) || num < min_limit || num > max_limit) {
		cout << "Error: Value must be an integer greater than " << min_limit << " and less than " << max_limit << ". Re-enter your value: ";
		cin.clear();
		cin.ignore(1200, ' ');
	}

	return num;

}

char* dateInput() {

	char date[DATE_LENGTH];
	string mm = "", dd = "", yyyy = "";
	int i = 0, month, day, year;
	bool valid_date = false;

	do {

		cout << "Enter the date of the payment in mm/dd/yyyy format: ";
		cin.getline(date, DATE_LENGTH);

		if (*(date + 2) == '/' && *(date + 5) == '/') {

			for (int j = DATE_LENGTH - 1; j >= 0; j--) {

				if (j == 0 || j == 1) {
					mm += *(date + j);
				}

				else if (j == 2 || j == 5) {
					continue;
				}

				else if (j == 3 || j == 4) {
					dd += *(date + j);
				}

				else {
					yyyy += *(date + j);
				}

			}

			month = stoi(mm);
			day = stoi(dd);
			year = stoi(yyyy);

			valid_date = checkDate(month, day, year, MONTHS);

			if (valid_date) {
				cout << date << " is a valid date." << endl;
			}
			else {
				cout << date << " is not a valid date. Please try again." << endl;
			}

		}

		cout << "Error: " << date << " must be in the following format: mm/dd/yyyy" << endl;
		

	} while (!valid_date);
	
	return date;

}

bool checkDate(int month, int day, int year, const string MONTHS[]) {

	bool valid_date = true, leap_year = false;

	//LIMITS OF MONTH, DAY AND YEAR ENTRY
	if (month < 1 || month > 12) {
		valid_date = false;
		cout << "Error: Your month entered must be a value between 1 - 12." << endl;
	}

	if (day < 1 || day > 31) {
		valid_date = false;
		cout << "Error: Your day entered must be a value between 1 - 31." << endl;
	}

	if (year < 0 || year > 9999) {
		valid_date = false;
		cout << "Error: Your year entered must be a value between 0 - 9999." << endl;
	}

	//LEAP YEAR CHECK
	if (year % 4 == 0) {
		leap_year = true;
	}

	//IN-DEPTH DATE CHECK
	if (month == 4 || month == 6 || month == 9 || month == 11) {

		if (day > 30) {
			valid_date = false;
			cout << "Error: " << MONTHS[month - 1] << " cannot have more than 30 days." << endl;
		}
 
	}

	if (month == 2) {

		if (leap_year && day > 29) {
			valid_date = false;
			cout << "Error: " << MONTHS[month - 1] << " cannot have more than 29 days." << endl;
		}

		else if (!leap_year && day > 28) {
			valid_date = false;
			cout << "Error: " << MONTHS[month - 1] << "cannot have mnore than 28 days." << endl;
		}

	}

	return valid_date;

}