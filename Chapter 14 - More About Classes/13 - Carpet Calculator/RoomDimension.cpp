#include "RoomDimension.h"

FeetInches RoomDimension::getArea() const {

	FeetInches result;

	result = length.multiply(width);

	return result;

}

double RoomDimension::getAreaSqFt() const {

	double area = 0;

	FeetInches result;

	result = length.multiply(width);

	area += result.getFeet();
	area += static_cast<double>(result.getInches()) / 12;

	result area;

}