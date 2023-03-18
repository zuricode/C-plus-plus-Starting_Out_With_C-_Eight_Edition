#include "Circle.h"
#include <iostream>
#include <iomanip>

using namespace std;

double setRadius();

int main() {

	cout << "13-08 - CIRCLE PROGRAM" << endl;
	cout << "========================" << endl;
	cout << endl;

	double radius;

	radius = setRadius();

	Circle circle;

	circle.setRadius(radius);

	cout << left << fixed << setprecision(2);

	cout << setw(30) << "Area of circle: " << circle.getArea() << " square cm" << endl;
	cout << setw(30) << "Diameter of circle: " << circle.getDiameter() << "cm" << endl;
	cout << setw(30) << "Circumference of circle: " << circle.getCircumference() << "scm" << endl;

}

double setRadius() {

	double r;

	cout << "Enter the radius of your circle (square cm): ";

	while (!(cin >> r) || r < 0) {
		cout << "Error: Radius must a positive number. Re-enter your value: ";
		cin.ignore();
	}

	cout << endl;

	return r;

}