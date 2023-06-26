#include "Rectangle.h"

Rectangle::Rectangle(long w, long l) : BasicShape() {

	width = w;
	length = l;

	calcArea();

}

void Rectangle::calcArea() {

	area = width * length;

}