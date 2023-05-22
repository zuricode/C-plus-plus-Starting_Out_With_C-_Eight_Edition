#include "LandTract.h"
#include <iostream>

using std::cin;

FeetInches LandTract::getArea() {

	FeetInches result;
	result = length.multiply(width);

	return result;

}

void LandTract::setLength() {

	cin >> length;

}

void LandTract::setWidth() {

	cin >> width;

}

