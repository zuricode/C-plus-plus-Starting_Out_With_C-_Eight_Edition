//8. Circle Class
//
//Write a Circle class that has the following member variables :
//
//• radius : a double
//• pi : a double initialized with the value 3.14159
//The class should have the following member functions :
//• Default Constructor.A default constructor that sets radius to 0.0.
//• Constructor.Accepts the radius of the circle as an argument.
//• setRadius.A mutator function for the radius variable.
//• getRadius.An accessor function for the radius variable.
//• getArea.Returns the area of the circle, which is calculated as
//area = pi * radius * radius
//• getDiameter.Returns the diameter of the circle, which is calculated as
//diameter = radius * 2
//• getCircumference.Returns the circumference of the circle, which is calculated as
//circumference = 2 * pi * radius
//
//Write a program that demonstrates the Circle class by asking the user for the circle’s
//radius, creating a Circle object, and then reporting the circle’s area, diameter, and
//circumference.

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