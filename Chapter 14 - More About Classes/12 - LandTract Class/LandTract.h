#ifndef LANDTRACT_H
#define LANDTRACT_H

#include "FeetInches.h"

class LandTract {

private:
	FeetInches length;
	FeetInches width;

public:

	void setLength();
	void setWidth();

	FeetInches getLength() const { return length; }
	FeetInches getWidth() const { return width;  }

	double getArea();


};

#endif