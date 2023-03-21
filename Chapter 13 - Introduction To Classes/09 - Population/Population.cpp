#include "Population.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

Population::Population() {

	name = "";
	population = 1;
	births = 0;
	deaths = 0;

}

int setValue(string text, int limit) {

	int val;

	cout << text << ": ";

	while (!(cin >> val) || val < limit) {
		cout << "ERROR: " << text << " must be greater than " << limit << ". " << text << ": ";
		cin.ignore();
	}

	cin.ignore();

	return val;
	
}

void Population::setName() {
	cout << "Name of place: ";
	getline(cin, name);
}

void Population::setPopulation() {	
	population = setValue("Population", 1);
}

void Population::setBirths() {
	births = setValue("Births", 0);
}

void Population::setDeaths() {
	deaths = setValue("Deaths", 0);
}

string Population::getName() {
	return name;
}

int Population::getPopulation() {
	return population;
}

int Population::getBirths() {
	return births;
}

int Population::getDeaths() {
	return deaths;
}

double Population::birthRate() {
	return static_cast<double>(births) / population;
}

double Population::deathRate() {
	return static_cast<double>(deaths) / population;
}

