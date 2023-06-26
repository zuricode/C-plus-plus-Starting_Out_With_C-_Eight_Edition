#include "Circle.h"

Circle::Circle(long x, long y, double r) : BasicShape() {

	centerX = x;
	centerY = y;
	radius = r;

	calcArea();

}

void Circle::calcArea() {

	area = 3.14159 * (radius * radius);

}