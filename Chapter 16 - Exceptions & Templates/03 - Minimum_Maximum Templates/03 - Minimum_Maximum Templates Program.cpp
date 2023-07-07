//3. Minimum / Maximum Templates
//
//Write templates for the two functions minimumand maximum.The minimum function
//should accept two argumentsand return the value of the argument that is the lesser
//of the two.The maximum function should accept two arguments and return the value
//of the argument that is the greater of the two.Design a simple driver program that
//demonstrates the templates with various data types.

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::to_string;

class equalNumber {};

template <class T>
T maximum(const T A, const T B) {

	if (A > B) {
		return A;
	}
	else if (B > A) {
		return B;
	}
	else {
		throw equalNumber();
	}

}

template <class T>
T minimum(const T A, const T B) {

	if (A < B) {
		return A;
	}
	else if (B < A) {
		return B;
	}
	else {
		throw equalNumber();
	}

}


int main() {

	int a = 5;
	int b = 435;

	double c = 9;
	double d = 9;

	cout << "=========================================\n";
	cout << "16-03 - MINIMUM_MAXIMUM TEMPLATES PROGRAM\n";
	cout << "=========================================\n";
	cout << "\n";

	try {
		cout << maximum(a, b) << " is the highest number.\n";
	}
	catch (equalNumber) {
		cout << to_string(a) + " and " + to_string(b) + " are equal.\n";
	}

	try {
		cout << minimum(a, b) << " is the lowest number.\n";
	}
	catch (equalNumber) {
		cout << to_string(a) + " and " + to_string(b) + " are equal.\n";
	}

	cout << "\n";

	try {
		cout << maximum(c, d) << " is the highest number.\n";
	}
	catch (equalNumber) {
		cout << to_string(c) + " and " + to_string(d) + " are equal.\n";
	}

	try {
		cout << minimum(c, d) << " is the lowest number.\n";
	}
	catch (equalNumber) {
		cout << to_string(c) + " and " + to_string(d) + " are equal.\n";
	}

	cout << "\n";
	cout << "Ending the program...\n";

}
