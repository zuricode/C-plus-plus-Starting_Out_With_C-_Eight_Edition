#include "DayOfYear.h"
#include <iostream>

using std::cout;
using std::cin;
using std::to_string;

const string DayOfYear::months_words[] = {"January", "February", "March", "April", "May", "June",
					"July", "August", "September", "October", "November", "December" };

const int DayOfYear::months_days[] = {31,28,31,30,31,30,31,31,30,31,30,31};

DayOfYear::DayOfYear(int num) {

	while (num < 0 || num > 365) {
		cout << "You entered " << num << ".\n";
		cout << "ERROR: Your chosen day must be an integer between 0 - 365.\n";
		cout << "\n";
		cout << "Enter your chosen day: ";
		cin >> num;
	}

	day = num;

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