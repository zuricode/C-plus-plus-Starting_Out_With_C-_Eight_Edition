#include "Date.h"

Date::Date() {
	month = 1;
	day = 1;
	year = 2000;
}

Date::Date(int m, int d, int y) {
	month = m;
	day = d;
	year = y;
}

void Date::setDate() {

	int num;

	num = monthValidation("Enter your chosen month: ");
	month = num;

	num = dayValidation("Enter your chosen day: ");
	day = num;

	cout << "Enter your chosen year: ";
	cin >> num;
	cin.ignore();

	year = num;

	cout << "\n";

}

void Date::getDate() {
	cout << "Your date is " << month << "/" << day << "/" << year << "\n";
	cout << "\n";
}

int Date::dayValidation(string request) {

	int day;

	cout << request;

	while (!(cin >> day) || day < 1 || day > 31) {
		throw InvalidDay(day);
	}

	cin.ignore();

	return day;

}

int Date::monthValidation(string request) {

	int month;

	cout << request;

	while (!(cin >> month) || month < 1 || month > 12) {
		throw InvalidMonth(month);
	}

	cin.ignore();

	return month;

}