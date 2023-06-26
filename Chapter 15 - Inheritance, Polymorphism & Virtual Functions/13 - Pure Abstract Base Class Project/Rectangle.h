#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "BasicShape.h"

class Rectangle : public BasicShape {

private:
	long width;
	long length;

public:
	Rectangle(long, long);
	~Rectangle() {}

	long getWidth() const { return width; }
	long getLength() const { return length; }

	virtual void calcArea();

};

#endif