#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Variables

const int	AMOUNT_OF_MONKEYS{ 3 },
			DAYS_OF_THE_WEEK{5};

string		monkeys[AMOUNT_OF_MONKEYS],
			days[DAYS_OF_THE_WEEK] {"Monday" , "Tuesday", "Wednesday", "Thursday", "Friday"};

double monkey_food [AMOUNT_OF_MONKEYS] [DAYS_OF_THE_WEEK] ;

// Function Declarations

string inputValidation(string);
double inputValidation(double, int);
void nameMonkeys(string []);
void collectFoodEaten();
void averageDailyFood();
void monkeyLeastFood();

int main() {

	nameMonkeys(monkeys);
	collectFoodEaten();
	averageDailyFood();
	monkeyLeastFood();
}

// Function Definitions

string inputValidation(string name) {
	while (!(cin >> name)) {
		cout << "ERROR: Enter a string: ";
		cin.clear();
		cin.ignore(1200, '\n');
	}
	return name;
}

double inputValidation(double num, int limit) {
	while (!(cin >> num) || num < limit) {
		cout << "ERROR: Value must be a double greater than " << limit << ". Re-enter your value: ";
		cin.clear();
		cin.ignore(1200, '\n');
	}
	return num;
}

void nameMonkeys(string monkeys[]) {

	cout << "We will name your monkeys.";
	cout << endl;
	cout << endl;

	for (int i = 0; i < AMOUNT_OF_MONKEYS; i++) {
		cout << "Enter the name of monkey #" << i + 1 << ": ";
		monkeys[i] = inputValidation(monkeys[i]);
	}

}

void collectFoodEaten() {

	cout << "\nWe will collect the amount of food eaten for each monkey on each day of the week (in lbs).";
	cout << endl;
	cout << endl;

	for (int i = 0; i < AMOUNT_OF_MONKEYS; i++) {
		
		for (int j = 0; j < DAYS_OF_THE_WEEK; j++) {
			cout << monkeys[i] << " on " << days[j] << ": ";
			monkey_food[i][j] = inputValidation(monkey_food[i][j], 0);
		}

		cout << endl;

	}

}

void averageDailyFood() {

	for (int j = 0; j < DAYS_OF_THE_WEEK; j++) {
		double total{ 0 };
		for (int i = 0; i < AMOUNT_OF_MONKEYS; i++) {
			total += monkey_food[i][j];
		}
		total = total / AMOUNT_OF_MONKEYS;
		cout << fixed << setprecision(2);
		cout << "Average food eaten by the monkeys on " << days[j] << ": " << total << endl;
	}

}

void monkeyLeastFood() {
	
	double total{ 0 };
	double lowest;
	string lowest_monkey;

	for (int i = 0; i < AMOUNT_OF_MONKEYS; i++) {

		for (int j = 0; j < DAYS_OF_THE_WEEK; j++) {
			total += monkey_food[i][j];
		}

		if (i == 0) {
			lowest = total;
			lowest_monkey = monkeys[i];
		}
		else if (total < lowest) {
			lowest = total;
			lowest_monkey = monkeys[i];
		}

		total = 0;

	}

	cout << "Monkey with lowest food consumption: " << lowest_monkey << "\tAmount of food eaten (in lbs): " << lowest << endl;

}