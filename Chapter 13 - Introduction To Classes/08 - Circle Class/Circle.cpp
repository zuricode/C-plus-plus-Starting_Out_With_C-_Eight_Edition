#include "Circle.h"
#include <iostream>

using std::cout;
using std::cin;

Circle::Circle() {
	radius = 0.0;
}

Circle::Circle(double r) {
	radius = r;
}

void Circle::setRadius(double r) {
	radius = r;
}

double Circle::getRadius() const {
	return radius;
}

double Circle::getArea() const {
	return pi * (radius * radius);
}

double Circle::getDiameter() const {
	return radius * 2;
}

double Circle::getCircumference() const {
	return 2 * pi * radius;
}