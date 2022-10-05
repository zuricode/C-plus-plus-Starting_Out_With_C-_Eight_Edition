#include <iostream>

using namespace std;

// Variables

const double	PRICE_PER_SPOOL{ 100.00 },
				SHIPPING_PER_SPOOL{10.00};

int				orderedSpools,
				stockSpools;

double			charges = SHIPPING_PER_SPOOL;

char			user_choice;

char inputValidation(char);
int inputValidation(int, int);
double inputValidation(double, double);
void stockStatus(int &, int &, double &);
void secondStatus(int, int, double);

int main() {

	stockStatus(orderedSpools, stockSpools, charges);

	secondStatus(orderedSpools, stockSpools, charges);

	cout << endl;

}

char inputValidation(char letter) {

	while (!(cin >> letter) || (letter != 'Y' && letter != 'y' && letter != 'N' && letter != 'n')) {
		cout << "Error: Value must one of the following characters: Y, y, N, n. Please re-enter your character: ";
		cin.clear();
		cin.ignore(1200, '\n');
	}

	return letter;

}

int inputValidation(int num, int limit) {

	while (!(cin >> num) || num < limit) {
		cout << "Error: Value must be an integer greater than " << limit << ". Please enter a different value: ";
		cin.clear();
		cin.ignore(1200, '\n');
	}

	return num;

}

double inputValidation(double num, double limit) {

	while (!(cin >> num) || num < limit) {
		cout << "Error: Value must be an integer greater than " << limit << ". Please enter a different value: ";
		cin.clear();
		cin.ignore(1200, '\n');
	}

	return num;

}

void stockStatus(int &orderedSpools, int &stockSpools, double &charges) {

	cout << "\nHow many spools have been ordered: ";

		orderedSpools = inputValidation(orderedSpools, 1);

	cout << "\nHow many spools are currently in stock: ";

		stockSpools = inputValidation(stockSpools, 0);

	cout << "\nAre there are special shipping/handling charges? (Enter Y/y/N/n): ";

	user_choice = inputValidation(user_choice);

		if (user_choice == 'Y' || user_choice == 'y') {
			
			cout << "What are the shipping/handling charges (if none, enter 0): $ ";

			charges = inputValidation(charges, 0.00);

		}

}

void secondStatus(int orderedSpools, int stockSpools, double charges) {

	cout << "\nNumber of spools ready to ship from current stock: " << stockSpools;

	if (orderedSpools > stockSpools) {

		cout << "\nNumber of spools on backorder: " << -stockSpools - -orderedSpools;

	}

	double subtotalSpools = stockSpools * PRICE_PER_SPOOL;

	cout << "\nSubtotal of the portion ready to ship: $" << subtotalSpools;

	double subtotalCharges = stockSpools * charges;

	cout << "\nTotal shipping and handling charges on the portion ready to ship: $" << subtotalCharges;

	cout << "\nTotal of the order ready to ship: $" << subtotalSpools + subtotalCharges;

}