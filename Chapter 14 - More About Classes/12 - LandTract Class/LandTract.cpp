#include "LandTract.h"
#include <iostream>

using std::cin;

double LandTract::getArea() {

	double area = 0;
	FeetInches result;
	
	result = length.multiply(width);

	area += result.getFeet();
	area += static_cast<double>(result.getInches()) / 12;

	return area;

}

void LandTract::setLength() {

	cin >> length;

}

void LandTract::setWidth() {

	cin >> width;

}

