#ifndef ROOMDIMENSION_H
#define ROOMDIMENSION_H

#include "FeetInches.h"

class RoomDimension {

private:
	FeetInches length;
	FeetInches width;

public:

	FeetInches getArea();
	double getAreaSqFt();

	void setLengthAndWidth();

};

#endif