#ifndef BOX_H
#define BOX_H

class Box {

private:
	double length;
	double width;

	static double area;

public:

	Box();
	Box(const double, const double);
	double getArea();

};

#endif