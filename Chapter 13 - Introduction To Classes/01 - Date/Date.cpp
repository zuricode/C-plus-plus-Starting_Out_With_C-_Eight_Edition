#include<iostream>
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

	cout << "Enter your chosen month: ";
	cin >> num;
	cin.ignore();

	month = num;

	cout << "Enter your chosen day: ";
	cin >> num;
	cin.ignore();

	day = num;

	cout << "Enter your chosen year: ";
	cin >> num;
	cin.ignore();

	year = num;

}

void Date::getDate() {

	cout << "Your date is " << month << "/" << day << "/" << year << "." << endl;

}
