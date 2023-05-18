#include "box.h"

Box::Box() { 
	length = 0;
	width = 0;
	area = 0;
}

Box::Box(const double L, const double W) { 
	length = L;
	width = W;
	area = length * width;
}

double Box::getArea() {
	return area;
}

double Box::area = 0;

