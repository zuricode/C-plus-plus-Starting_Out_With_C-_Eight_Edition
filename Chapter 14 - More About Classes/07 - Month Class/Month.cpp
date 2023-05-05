#include "Month.h"
#include <iostream>

using std::cout;

const int MIN_MONTH = 1, MAX_MONTH = 12;
const string MONTHS[MAX_MONTH]{ "JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE",
						"JULY",	"AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER" };

Month::Month(string s) {

	bool isSet = false;
	int index = 0;


	for (int i = 0; i < s.length(); i++) {
		s[i] = toupper(s[i]);
	}

	while (!isSet || index >=MAX_MONTH) {

		if (s == MONTHS[index]) {
			name = MONTHS[index];
			monthNumber = index + 1;
			isSet = true;
		}

		index++;

	}
		
	if (!isSet) {
		cout << "ERROR: You have entered the monht name incorrectly.\n";
		cout << "Either initialize your month object properly or use a set function to add your monht name again.\n";
		cout << "\n";
	}

}

Month::Month(int num) {

	monthNumber = num;

	if (num >= MIN_MONTH && num <= MAX_MONTH) {
		name = MONTHS[num - 1];
	}
	else {
		cout << "ERROR: Month number be between " << MIN_MONTH << " and " << MAX_MONTH << ".\n";
		cout << "\n";
	}

}