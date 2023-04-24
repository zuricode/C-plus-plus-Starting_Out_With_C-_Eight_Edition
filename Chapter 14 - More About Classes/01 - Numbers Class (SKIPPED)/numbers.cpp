#include "Numbers.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::to_string;

Numbers::Numbers() {

	string request = "Enter a number between " + to_string(Numbers::getMin()) + " - " + to_string(Numbers::getMax()) + ": ";
	number = numValidation(request, Numbers::getMin(), Numbers::getMax());

}

int Numbers::numValidation(string request, const int MIN, const int MAX) {

	int num;

	cout << request;

	while (!(cin >> num) || (num < MIN || num > MAX)) {
		cout << "ERROR: Your number must be between " << MIN << " and " << MAX << ".\n";
		cout << "\n";
		cin.ignore();
		cout << request;
	}

	cin.ignore();

	cout << "\n";

	return num;

}