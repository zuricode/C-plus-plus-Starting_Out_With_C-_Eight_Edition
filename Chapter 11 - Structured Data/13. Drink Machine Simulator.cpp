//13. Drink Machine Simulator
//
//Write a program that simulates a soft drink machine.The program should use a structure
//
//that stores the following data :
//Drink Name
//Drink Cost
//Number of Drinks in Machine
//
//The program should create an array of five structures.The elements should be initialized
//with the following data :
//
//Drink Name		Cost	Number in Machine
//Cola			.75				20
//Root Beer		.75				20
//Lemon - Lime	.75				20
//Grape Soda		.80				20
//Cream Soda		.80				20
//
//Each time the program runs, it should enter a loop that performs the following steps :
//A list of drinks is displayed on the screen.The user should be allowed to either quit the
//program or pick a drink.If the user selects a drink, he or she will next enter the amount
//of money that is to be inserted into the drink machine.The program should display
//the amount of change that would be returned and subtract one from the number of
//that drink left in the machine.If the user selects a drink that has sold out, a message
//should be displayed.The loop then repeats.When the user chooses to quit the program
//it should display the total amount of money the machine earned.
//
//Input Validation : When the user enters an amount of money, do not accept negative
//values or values greater than $1.00.

#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

struct Drink {

	string name;
	double cost;
	int number_in_machine;

};

double doubleTwoLimits(int, int, string);
void quitProgram(int);

int drinksMenu(Drink[], const int);
void displayDrinkInfo(Drink[], int);
double enterMoney(double);
void menuChoice(int);
void verifyPurchase(Drink[], double&);


int main() {

	const int		TYPES_OF_DRINK = 5;

	Drink drinks[TYPES_OF_DRINK]{ {"Cola", 0.75, 20}, {"Root Beer", 0.75, 20},
								{"Lemon-Lime", 0.75, 20}, {"Grape Soda", 0.80, 20},
								{"Cream Soda", 0.80, 20} };

	int menu_choice;
	double balance = 0;

	menu_choice = drinksMenu(drinks, TYPES_OF_DRINK);

	displayDrinkInfo(drinks, menu_choice);

	balance = enterMoney(balance);




}

int intTwoLimits(int min, int max, string request) {

	int num;

	cout << request;

	while (!(cin >> num) || num < min || num > max) {
		cout << "\tERROR: Value must be an integer between (and including) " << min << " and " << max << "." << endl;
		cout << endl;
		cout << request;
		cin.clear();
		cin.ignore(1200, '\n');
	}

	cin.clear();
	cin.ignore(1200, '\n');

	return num;

}

double doubleTwoLimits(int min, int max, string request) {

	double num;

	cout << request;

	while (!(cin >> num) || num < min || num > max) {
		cout << "\tERROR: Value must be an integer between (and including) " << min << " and " << max << "." << endl;
		cout << endl;
		cout << request;
		cin.clear();
		cin.ignore(1200, '\n');
	}

	cin.clear();
	cin.ignore(1200, '\n');

	return num;

}

int drinksMenu(Drink drinks[], const int TYPES) {

	int menu_choice;

	cout << "\t=============================" << endl;
	cout << "\t      BEVERAGE MACHINE       " << endl;
	cout << "\t=============================" << endl;
	cout << endl;
	cout << "\tDrinks: " << endl;
	cout << "\t" << endl;

	for (int i = 0; i < TYPES; i++) {

		cout << "\t" << i + 1 << ")\t" << drinks[i].name << endl;

	}

	cout << endl;
	
	menu_choice = intTwoLimits(0, 5, "\tChoose your drink (1-5) or enter \"0\" to quit the program: ");

	if (menu_choice == 0) {
		cout << "\tExiting the program..." << endl;
		exit(EXIT_SUCCESS);
	}
	else {
		menu_choice -= 1;
	}

	cout << endl;

	return menu_choice;

}

void displayDrinkInfo(Drink drinks[], int menu_choice) {

	cout << fixed << setprecision(2);

	cout << "\tYou have selected: " << endl;
	cout << "\t---------------------------------" << endl;
	cout << "\t" << "Name:              " << drinks[menu_choice].name << endl;
	cout << "\t" << "Cost:              $" << drinks[menu_choice].cost << endl;
	cout << "\t" << "Amount in-stock:   " << drinks[menu_choice].number_in_machine << endl;
	cout << endl;

}

double enterMoney(double balance) {

	double money;

	money = doubleTwoLimits(0, 1, "\tHow much will you put into the machine ($1.00 maximum): $");

	balance += money;

	return balance;

}

void menuChoice(int menu_choice) {

	menu_choice -= 1;

	switch (menu_choice) {

		case 0:
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;

	}

}