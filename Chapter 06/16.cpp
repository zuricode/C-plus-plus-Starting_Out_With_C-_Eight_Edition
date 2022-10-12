#include <iostream>

using namespace std;

int		start_population,
		years,
		new_population,
		arrivals,
		departures;

double	annual_birth_rate,
		annual_death_rate;

int inputValidation(int, int);
double inputValidation(double, double);
int popFormula(int, double, double, int, int, int);

int main() {

	
	cout << "\nWhat is the starting size of the population: ";
	start_population = inputValidation(start_population, 2);

	cout << "\nWhat is the annual birth rate: ";
	annual_birth_rate = inputValidation(annual_birth_rate, 0.0) / 100;

	cout << "\nWhat is the annual death rate: ";
	annual_death_rate = inputValidation(annual_death_rate, 0.0) / 100;

	cout << "\nHow many people arrive every year: ";
	arrivals = inputValidation(arrivals, 0);

	cout << "\nHow many people leave every year: ";
	departures = inputValidation(departures, 0);

	cout << "\nHow many years would you like to display: ";
	years = inputValidation(years, 1);

	new_population = popFormula(start_population, annual_birth_rate, annual_death_rate, arrivals, departures, years);

	cout << "\nThe new population after " << years << " years will be " << new_population << " people." << endl << endl;


}

int inputValidation(int num, int limit) {

	while (!(cin >> num) || num < limit) {
		cout << "Error: Value must be an integer greater than " << limit << ". Please re-enter your value: ";
		cin.clear();
		cin.ignore(1200, '\n');
	}

	return num;

}

double inputValidation(double num, double limit) {

	while (!(cin >> num) || num < limit) {
		cout << "Error: Value must be an integer greater than " << limit << ". Please re-enter your value: ";
		cin.clear();
		cin.ignore(1200, '\n');
	}

	return num;

}

int popFormula(int start_population, double annual_birth_rate, double annual_death_rate, int arrivals, int departures, int years) {

	int new_population;

	for (int i = 1; i <= years; i++) {
		
		new_population = double(start_population) + (annual_birth_rate * double(start_population)) - (annual_death_rate * double(start_population)) + arrivals - departures;
		start_population = new_population;
	}

	return new_population;

}
