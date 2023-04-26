#include "DayOfYear.h"
#include <iostream>

using std::cout;
using std::cin;
using std::to_string;
using std::toupper;

const string DayOfYear::months_words[] = {"January", "February", "March", "April", "May", "June",
					"July", "August", "September", "October", "November", "December" };

const int DayOfYear::months_days[] = {31,28,31,30,31,30,31,31,30,31,30,31};

string convertToUppercase(string TEXT) {

	string temp = "";

	for (int i = 0; i < TEXT.length(); i++) {
		temp += toupper(TEXT[i]);
	}

	return temp;

}

void DayOfYear::upwardFormat() {

	if (day > 365) {
		day = day % 365;
	}

}

void DayOfYear::downwardFormat() {

	if (day == 0) {
		day = 365;
	}

}

DayOfYear::DayOfYear(int num) {

	while (num < 1 || num > 365) {
		cout << "You entered " << num << ".\n";
		cout << "ERROR: Your chosen day must be an integer between 1 - 365.\n";
		cout << "\n";
		cout << "Enter your chosen day: ";
		cin >> num;
	}

	day = num;

}

DayOfYear::DayOfYear(string month, int chosen_day) {

	string current_month;
	int cumulative_days = 0;
	int i = 0;
	bool isDayInit = false;

	month = convertToUppercase(month);

	while (i < MONTHS && !isDayInit) {

		if (month.length() == months_words[i].length()) {

			current_month = convertToUppercase(months_words[i]);

			if (month == current_month) {
				isDayInit = true;
			}

		}	

		if (!isDayInit) {
			cumulative_days += months_days[i];
		}

		i++;

	}

	if (!isDayInit) {
		cout << "ERROR: You have not spelt your chosen month correctly.\n";
		cout << "Program terminating...\n";
		exit(EXIT_FAILURE);
	} else {

		day = cumulative_days + chosen_day;

		cout << "DayOfYear object has been initialised.\n";
		cout << month << ", " << chosen_day << " is Day " << day << " in a year.\n";
		cout << "\n";

	}	

}

void DayOfYear::print() {

	int i = 0;
	int remainder;
	int current_total_days = 0;
	string answer = "";

	while (answer == "" && i < MONTHS) {

		current_total_days += months_days[i];

		if (day <= current_total_days) {

			if (i == 0) {
				answer += months_words[i] + ", " + to_string(day);
			}
			else {
				answer += months_words[i] + ", ";
				remainder = day - (current_total_days - months_days[i]);
				answer += to_string(remainder) + ".";
			}

		}

		i++;

	}

	cout << "Day " << day << " in \"month-day\" format is: " << answer << "\n";
	cout << "\n";

}

DayOfYear DayOfYear::operator ++ () {
	day++;
	upwardFormat();
	return *this;
}

DayOfYear DayOfYear::operator ++ (int) {

	DayOfYear temp(day);
	day++;
	upwardFormat();
	return temp;

}

DayOfYear DayOfYear::operator -- () {
	day--;
	downwardFormat();
	return *this;
}

DayOfYear DayOfYear::operator -- (int) {
	DayOfYear temp(day);
	day--;
	downwardFormat();
	return temp;

}