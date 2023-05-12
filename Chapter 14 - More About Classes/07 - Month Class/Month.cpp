#include "Month.h"
#include <iostream>

using std::cin;
using std::cout;

const int AMOUNT_OF_MONTHS = 12;
const string MONTHS_WORDS[AMOUNT_OF_MONTHS]{ "January", "February", "March", "April", "May", "June", 
										"July", "August", "September", "October", "November", "December" };

string convertToUppercase(string s) {

	string temp {""};

	for (int i = 0; i < s.length(); i++) {
		temp += toupper(s[i]);
	}

	return temp;

}

void Month::setName(string s) {

	bool isMatched = false;
	string temp_month_array;

	s = convertToUppercase(s);

	for (int i = 0; i < AMOUNT_OF_MONTHS; i++) {

		temp_month_array = convertToUppercase(MONTHS_WORDS[i]);

		if (s == temp_month_array) {
			name = MONTHS_WORDS[i];
			monthNumber = i + 1;
			isMatched = true;
			break;
		}

	}

	if (!isMatched) {
		cout << "ERROR: You have not entered a valid month.\n";
		cout << "The month will be initialised to \"JANUARY\".\n";
		name = "January";
		monthNumber = 1;
		cout << "\n";
	}

}

void Month::setMonthNumber(int i) {

	while (i < 1 || i > AMOUNT_OF_MONTHS) {
		cout << "ERROR: Int argument must be between 1 - " << AMOUNT_OF_MONTHS << ".\n";
		cout << "\n";
		cout << "Enter your chosen month number: ";
		cin >> i;
	}

	monthNumber = i;
	name = MONTHS_WORDS[monthNumber - 1];

}

Month::Month(string s) {
	
	setName(s);

}

Month::Month(int i) {

	setMonthNumber(i);

}

Month Month::operator ++() {

	if (monthNumber == 12) {
		monthNumber = 1;
	}
	else {
		++monthNumber;
	}

	name = MONTHS_WORDS[monthNumber - 1];

	return *this;


}

Month Month::operator --() {

	if (monthNumber == 1) {
		monthNumber = 12;
	}
	else {
		--monthNumber;
	}

	name = MONTHS_WORDS[monthNumber - 1];

	return *this;


}

Month Month::operator ++(int) {

	Month temp = *this;

	if (monthNumber == 12) {
		monthNumber = 1;
	}
	else {
		++monthNumber;
	}

	name = MONTHS_WORDS[monthNumber - 1];

	return temp;


}

Month Month::operator --(int) {

	Month temp = *this;

	if (monthNumber == 1) {
		monthNumber = 12;
	}
	else {
		--monthNumber;
	}

	name = MONTHS_WORDS[monthNumber - 1];

	return temp;

}

ostream& operator << (ostream &strm, const Month &obj) {

	strm << "Month name: " << obj.name << "\n";
	strm << "Month number: " << obj.monthNumber << "\n";
	strm << "\n";

	return strm;

}

istream& operator >> (istream& strm, Month& obj) {

	int num;

	cout << "Enter the number of your chosen month: ";
	strm >> num;

	obj.setMonthNumber(num);

	return strm;

}