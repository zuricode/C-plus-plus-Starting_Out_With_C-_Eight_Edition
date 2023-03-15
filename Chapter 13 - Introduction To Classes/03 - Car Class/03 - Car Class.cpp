#include "Car.h"
#include<iostream>

int main() {

	Car beetle(1990, "Volkswagen Beetle");

	cout << "Current speed of " << beetle.getMake() << ": " << beetle.getSpeed() << "mph" << endl;

	for (int i = 0; i < 5; i++) {

		cout << endl;

		beetle.accelerate();
		cout << beetle.getMake() << " is accelerating..." << endl;
		cout << "Current speed of " << beetle.getMake() << ": " << beetle.getSpeed() << "mph" << endl;

	}

	for (int i = 0; i < 5; i++) {

		cout << endl;

		beetle.brake();
		cout << beetle.getMake() << " is braking..." << endl;
		cout << "Current speed of " << beetle.getMake() << ": " << beetle.getSpeed() << "mph" << endl;

	}

}