#include<iostream>
#include<string>
#include "Date.h"

using namespace std;

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

	cout << endl;

}

void Date::getDate() {

	cout << "Your date is " << month << "/" << day << "/" << year << "." << endl;

}

int Date::dayValidation(string request) {

	int day;

	cout << request;

	while (!(cin >> day) || day < 1 || day > 31) {
		cout << "ERROR: Day cannot be lesser than 1 or greater than 31." << endl;
		cout << endl;
		cin.ignore();
		cout << request;
	}

	cin.ignore();

	return day;

}

int Date::monthValidation(string request) {

	int month;

	cout << request;

	while (!(cin >> month) || month < 1 || month > 12) {
		cout << "ERROR: Day cannot be lesser than 1 or greater than 31." << endl;
		cout << endl;
		cin.ignore();
		cout << request;
	}

	cin.ignore();

	return month;

}