
//13. Date Printer
//Write a program that reads a string from the user containing a date in the form mm / dd / yyyy.
//It should print the date in the form March 12, 2014.

#include <iostream>
#include <string>

using namespace std;

char* validateString(char*, const int);


int main() {

	const int		SIZE = 11;
	char			date_string[SIZE];

	validateString(date_string, SIZE);

	cout << endl;

	cout << date_string << endl;

}

char* validateString(char* date_string, const int SIZE) {

	bool error = false;

	int i = 0;

	cout << "Enter your chosen date in the following format (mm/dd/yyyy): ";
	cin.getline(date_string, SIZE);

	while (*date_string != '\0' && error == false) {

		cout << *date_string << endl;

		if (i == 0) {
			if (*(date_string + i) > 1 || *(date_string + i) < 0) {
				error = true;
			}
		}

		else if (i == 1) {

			if (*(date_string + 0) == 0) {

				if (!isdigit(*(date_string + i)) || !(*(date_string + i) < 10 && *(date_string + i) > -1)) {
					error = true;
				}

			}

			if (*(date_string + 0) == 1) {

				if (!isdigit(*(date_string + i)) || !(*(date_string + i) < 3 && *(date_string + i) > -1)) {
					error = true;
				}

			}

		}

		else if ((i == 2 || i == 5) && *(date_string + i) != '/') {

			error = true;

		}

		else if (i == 3) {

			if (!isdigit(*(date_string + i)) || !(*(date_string + i) < 4 && *(date_string + i) > -1)) {
				error = true;
			}

		}

		else if (i == 4) {

			if (!isdigit(*(date_string + i)) || !(*(date_string + i) < 10 && *(date_string + i) > -1)) {
				error = true;
			}

		}

		else if (i == 6 || i == 7 || i == 8 || i == 9) {

			if (!isdigit(*(date_string + i)) || !(*(date_string + i) < 10 && *(date_string + i) > -1)) {
				error = true;
			}

		}

		i++;

	}

	if (error) {
		cout << date_string << " is NOT a valid date (mm/dd/yyyy)." << endl;
	}
	else {
		cout << "Success! " << date_string << " IS a valid date (mm/dd/yyyy)." << endl;

	}

	cout << endl;

	return date_string;

}
