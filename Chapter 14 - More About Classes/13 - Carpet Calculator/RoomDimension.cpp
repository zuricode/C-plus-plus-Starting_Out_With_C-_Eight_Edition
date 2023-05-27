#include "RoomDimension.h"

FeetInches RoomDimension::getArea() {

	return length.multiply(width);

}

double RoomDimension::getAreaSqFt() {

	double area = 0;

	FeetInches result;

	result = length.multiply(width);

	area += result.getFeet();
	area += static_cast<double>(result.getInches()) / 12;

	return area;

}

void RoomDimension::setLengthAndWidth() {

	int feet = 0;
	int inches = 0;

	cout << "Enter the dimensions of your room...\n";
	cout << "\n";

	cout << "Length\n";
	cout << "--------\n";
	cin >> length;
	
	cout << "\n";

	cout << "Width\n";
	cout << "--------\n";
	cin >> width;

	cout << "\n";

}