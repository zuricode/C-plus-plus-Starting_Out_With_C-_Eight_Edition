#include<iostream>
#include "Date.h"

using std::cout;
using std::cin;
using std::endl;

const int MIN_YEAR = 1950;
const int MAX_YEAR = 2100;
const int AMOUNT_OF_MONTHS = 13;

const int Date::DAYS_PER_MONTH[AMOUNT_OF_MONTHS]{ 0,31,28,31,30,31,30,31,31,30,31,30,31 };
 const string Date::MONTHS_NAMES[AMOUNT_OF_MONTHS]{ "","Janaury", "February", "March", "April", "May", "June", "July",
												"August", "September", "October", "November", "December" };

enum Months {JANUARY = 1, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY,
				AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER};

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

	num = yearValidation("Year: ");
	year = num;

	num = monthValidation("Month: ");
	month = num;

	num = dayValidation("Day: ");
	day = num;

	cout << endl;

}

void Date::getDate() {

	cout << "Your date is " << month << "/" << day << "/" << year << "." << endl;

}

int Date::dayValidation(string request) {

	int day;

	cout << request;

	if (isLeapYear() && month == 2) {

		while (!(cin >> day) || (day < 1 || day > 29)) {
			cout << "ERROR: Day cannot be lesser than 1 or greater than 29 in " << MONTHS_NAMES[month] << "." << endl;
			cout << endl;
			cin.ignore();
			cout << request;
		}

		cin.ignore();

		return day;

	} 

	else {

		while (!(cin >> day) || (day < 1 || day > DAYS_PER_MONTH[month])) {
			cout << "ERROR: Day cannot be lesser than 1 or greater than " << DAYS_PER_MONTH[month] << " in " << MONTHS_NAMES[month] << "." << endl;
			cout << endl;
			cin.ignore();
			cout << request;
		}

		cin.ignore();

		return day;

	}

}

int Date::monthValidation(string request) {

	int month;

	cout << request;

	while (!(cin >> month) || month < 1 || month > 12) {
		cout << "ERROR: Month cannot be lesser than 1 or greater than 12." << endl;
		cout << endl;
		cin.ignore();
		cout << request;
	}

	cin.ignore();

	return month;

}

int Date::yearValidation(string request) {

	int year;

	cout << request;

	while (!(cin >> year) || year < MIN_YEAR || year > MAX_YEAR) {
		cout << "ERROR: Your chosen year must be between " << MIN_YEAR << " and " << MAX_YEAR << "." << endl;
		cout << endl;
		cin.ignore();
		cout << request;
	}

	cin.ignore();

	return year;

}

bool Date::isLeapYear() {

	if (year % 4 == 0) {
		return true;
	}
	else {
		return false;
	}

}

ostream &operator << (ostream &strm, const Date &obj) {

	return strm << Date::MONTHS_NAMES[obj.month] << " " << obj.day << ", " << obj.year;

}

istream& operator >> (istream& strm, Date& obj) {

	obj.setDate();

	return strm;
}

Date Date::operator ++ () {

	if (month == FEBRUARY && isLeapYear()) {

		if (day == 28) {
			day++;
		}
		else if (day == 29) {
			++month;
			day = 1;
		}
		else {
			day++;
		}
		
	}

	else if (day == DAYS_PER_MONTH[month]) {

		if (month == DECEMBER) {
			++year;
			day = 1;
			month = 1;
		} 

		else {
			++month;
			day = 1;
		}

	}

	else {
		++day;
	}

	return *this;

}

Date Date::operator -- () {
	
	if (day == 1) {

		if (month == JANUARY) {
			--year;
			month = DECEMBER;
			day = DAYS_PER_MONTH[month];
		}

		else if (month == MARCH) {

			--month;

			if (isLeapYear()) {
				day = 29;
			}

			else {
				day = DAYS_PER_MONTH[month];
			}

		}

		else {
			--month;
			day = DAYS_PER_MONTH[month];

		}

	}
	
	else {
		--day;
	}

	return *this;

}

Date Date::operator ++ (int) {

	Date original = *this;

	++*this;

	return original;

}

Date Date::operator -- (int) {

	Date original = *this;

	--*this;

	return original;

}

int Date::operator - (const Date obj) {

	int date_1 = 0;
	int date_2 = 0;

	for (int i = MIN_YEAR; i < year; i++) {
		if (i % 4 == 0) {
			date_1 += 366;
		}
		else {
			date_1 += 365;
		}
	}

	for (int i = MIN_YEAR; i < obj.year; i++) {
		if (i % 4 == 0) {
			date_2 += 366;
		}
		else {
			date_2 += 365;
		}
	}

	for (int i = 0; i <= month; i++) {
		date_1 += DAYS_PER_MONTH[i];
	}

	for (int i = 0; i <= obj.month; i++) {
		date_2 += DAYS_PER_MONTH[i];
	}

	date_1 += day;

	date_2 += obj.day;

	if (date_2 > date_1) {
		cout << "WARNING: Date #2 > Date #1. Result will be a negative number.\n";
		cout << "\n";
	}

	return date_1 - date_2;

}