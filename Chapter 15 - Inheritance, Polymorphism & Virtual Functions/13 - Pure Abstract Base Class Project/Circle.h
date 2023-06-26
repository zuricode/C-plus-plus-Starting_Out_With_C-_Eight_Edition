#ifndef CIRCLE_H
#define CIRCLE_H

#include "BasicShape.h"

class Circle : public BasicShape {

private:
	long centerX;
	long centerY;
	double radius;

public:
	Circle(long, long, double);
	~Circle() {}

	long getCenterX() const { return centerX; }
	long getCenterY() const { return centerY; }
	long getRadius() const { return radius; }

	virtual void calcArea();

};

#endif