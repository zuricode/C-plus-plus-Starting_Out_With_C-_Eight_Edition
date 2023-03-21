#include "Population.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	cout << "13-09 - POPULATION" << endl;
	cout << "========================" << endl;
	cout << endl;

	Population place;

	place.setName();
	place.setPopulation();
	place.setBirths();
	place.setDeaths();

	cout << endl;
	cout << "===============" << endl;
	cout << endl;

	cout << "Population of " << place.getName() << ": " << place.getPopulation() << endl;
	cout << "Births this year in " << place.getName() << ": " << place.getBirths() << endl;
	cout << "Deaths this year in " << place.getName() << ": " << place.getDeaths() << endl;
	cout << "Birth rate in " << place.getName() << ": " << fixed << setprecision(3) << place.birthRate() << endl;
	cout << "Death rate in " << place.getName() << ": " << fixed << setprecision(3) << place.deathRate() << endl;

	cout << endl;

}