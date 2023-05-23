#ifndef ROOMDIMENSION_H
#define ROOMDIMENSION_H

#include

class RoomDimension {

private:
	FeetInches length;
	FeetInches width;

public:

	double getArea() const;

};