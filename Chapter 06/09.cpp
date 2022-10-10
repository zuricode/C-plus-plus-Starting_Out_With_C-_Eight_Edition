#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Variables

double		p,
			f,
			r,
			n;

char		choice;

double inputValidation(double);
char inputValidation(char);
double presentValue(double, double, double);

int main() {



	cout << "\nInterest Program: ";
	cout << "\n-------------------";
	cout << fixed << setprecision(2) << endl;

	do {

		cout << "\nHow much would you like to accrue in the future: $";

		f = inputValidation(f);

		cout << "What is your annual interest rate as a percentage: ";

		r = inputValidation(r);

		cout << "How many years do you have to accrue $" << f << ": ";

		n = inputValidation(n);

		p = presentValue(f, r, n);

		cout << "\nTo accrue $" << f << " with an annual interest rate of " << r << "% within " << n << " years, you will need to start with $" << setprecision(2) << fixed << p;

		cout << endl;

		cin.clear();
		cin.ignore(1200, '\n');

		cout << "\nWould you like to run the function again (Y/y for Yes - N/n for No): ";

		choice = inputValidation(choice);

	} while (choice == 'Y' || choice == 'y');

	cout << "\nBye!" << endl;

}

double inputValidation(double num) {

	while (!(cin >> num) || num < 0) {
		cout << "Error: Value needs to be greater than 0. Please try again: ";
		cin.clear();
		cin.ignore(1200, '\n');
	}

	return num;

}

char inputValidation(char character) {

	cin >> character;

	while (!(character == 'Y' || character == 'y' || character == 'N' || character == 'n')) {
			cout << "Error: Entry needs to be Y/y/N/n. Please try again: ";
			cin.clear();
			cin.ignore(1200, '\n');
			cin >> character;
	}

	return character;

}

double presentValue(double future_value, double annual_interest_rate, double years) {

	annual_interest_rate *= 0.01;
	return future_value / pow((1 + annual_interest_rate), years);

}