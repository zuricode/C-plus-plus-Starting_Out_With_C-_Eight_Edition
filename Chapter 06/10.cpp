#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Variables

double		f,
			p,
			i,
			t;			

char		choice;

double inputValidation(double);
char inputValidation(char);
double futureValue(double, double, double);

int main() {

	do {

		cout << "\nEnter the account present value: $";
		p = inputValidation(p);

		cout << "\nEnter the monthly interest rate, as a percentage: ";
		i = inputValidation(i);

		cout << "\nHow many months will you save your money for? ";
		t = inputValidation(t);

		f = futureValue(p, i, t);

		cout << fixed << setprecision(2) << "\nStarting with $" << p << ", after " << t << " months with a monthly interest rate of " << i << "%, you will have $" << f << endl;

		cout << "\nWOuld you like to run the program again: ";
		choice = inputValidation(choice);

	} while (choice == 'Y' || choice == 'y');

	cout << "\nGoodbye!" << endl << endl;
}

double inputValidation(double num) {

	while (!(cin >> num) || num < 0) {
		cout << "Error: Value must be greater than 0. Please try again: ";
		cin.clear();
		cin.ignore(1200, '\n');
	}

	return num;

}

char inputValidation(char letter) {

	cin >> letter;

	while (!(letter == 'Y' || letter == 'y' || letter == 'N' || letter == 'n')) {
		cout << "Error: Entry has to be either Y/y/N/n. Please try again: ";
		cin.clear();
		cin.ignore(1200, '\n');
		cin >> letter;

	}

	return letter;

}

double futureValue(double presentValue, double interest_rate, double months) {

	interest_rate *= 0.01;
	return presentValue * pow(1 + interest_rate, months);

}