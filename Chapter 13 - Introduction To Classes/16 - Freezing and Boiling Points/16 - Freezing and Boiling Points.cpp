//16. Freezing and Boiling Points
//
//The following table lists the freezing and boiling points of several substances.
//
//Substance			Freezing Point	Boiling Point
//
//Ethyl Alcohol		−173			172
//Oxygen			−362			−306
//
//Design a class that stores a temperature in a temperature member variableand has the
//appropriate accessorand mutator functions.In addition to appropriate constructors,
//the class should have the following member functions :
//
//• isEthylFreezing.This function should return the bool value true if the temperature
//stored in the temperature field is at or below the freezing point of ethyl
//alcohol.Otherwise, the function should return false .
//• isEthylBoiling.This function should return the bool value true if the temperature
//stored in the temperature field is at or above the boiling point of ethyl alcohol.
//Otherwise, the function should return false .
//• isOxygenFreezing.This function should return the bool value true if the temperature
//stored in the temperature field is at or below the freezing point of oxygen.
//Otherwise, the function should return false .
//• isOxygenBoiling.This function should return the bool value true if the temperature
//stored in the temperature field is at or above the boiling point of oxygen.
//Otherwise, the function should return false .
//• isWaterFreezing.This function should return the bool value true if the temperature
//stored in the temperature field is at or below the freezing point of water.
//Otherwise, the function should return false .
//• isWaterBoiling.This function should return the bool value true if the temperature
//stored in the temperature field is at or above the boiling point of water.
//Otherwise, the function should return false .
//
//Write a program that demonstrates the class.The program should ask the user to enter
//a temperature and then display a list of the substances that will freeze at that temperature
//and those that will boil at that temperature.For example, if the temperature is −20
//the class should report that water will freezeand oxygen will boil at that temperature.

#include "temperature.h"
#include<iostream>
#include<iomanip>
#include<string>

using std::cout;
using std::cin;
using std::string;

void tempBools(Temperature);

int main() {

	Temperature substance;
	float temp;

	cout << "13-16 FREEZING POINTS AND BOILING POINTS\n";
	cout << "=============================================\n";
	cout << "\n";

	cout << "Enter your chosen temperature (in F): ";
	cin >> temp;

	cout << "\n";
	cin.ignore();

	substance.setTemp(temp);

	tempBools(substance);

	cout << "Qutting the program...\n";

}

void tempBools(Temperature substance) {

	cout << "Your chosen temperature is " << substance.getTemp() << "F.\n";
	cout << "\n";

	if (substance.isEthylFreezing()) {
		cout << "*\tEthyl Alcohol would freeze at this temperature.\n";
	}

	if (substance.isEthylBoiling()) {
		cout << "*\tEthyl Alcohol would boil at this temperature.\n";
	}

	if (substance.isOxygenFreezing()) {
		cout << "*\tOxygen would freeze at this temperature.\n";
	}

	if (substance.isOxygenBoiling()) {
		cout << "*\tOxygen would boil at this temperature.\n";
	}

	if (substance.isWaterFreezing()) {
		cout << "*\tWater would freeze at this temperature.\n";
	}

	if (substance.isWaterBoiling()) {
		cout << "*\tWater would boil at this temperature.\n";
	}

	cout << "\n";


}