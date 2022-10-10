#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double	mass,
		velocity,
		ke;

double iv(double);
double kineticEnergy(double, double);
void displayData(double, double, double);

int main() {

	cout << "This is a program to determine the kinetic energy a moving object carries, from knowing its mass and velocity.";

	cout << endl;

	cout << "\nEnter the mass of your object in kilograms: ";
	mass = iv(mass);

	cout << "Now enter the velocity of said object as m/s (metres per seconds): ";
	velocity = iv(velocity);

	ke = kineticEnergy(mass, velocity);

	displayData(mass, velocity, ke); 

}

double iv(double num) {

	while (!(cin >> num) || num < 0) {
		cout << "Error: Values must be greater than 0. Please try again: ";
		cin.clear();
		cin.ignore(1200, '\n');
	}

	return num;

}

double kineticEnergy(double mass, double velocity) {
	
	return 0.5 * mass * pow(velocity, 2);

}

void displayData(double mass, double velocity, double ke) {

	cout << fixed << setprecision(3) << "A object with a mass of " << mass << " kilograms, moving at a speed of " << velocity << "m/s has " << ke << " of KE (Kinetic Energy).";

	cout << endl;

}