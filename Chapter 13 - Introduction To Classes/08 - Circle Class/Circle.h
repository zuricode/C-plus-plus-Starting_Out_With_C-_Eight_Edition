#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {

private:
	double radius;
	double pi = 3.14159;

public:
	Circle();
	Circle(double);

	void setRadius(double);
	double getRadius() const;

	double getArea() const;
	double getDiameter() const;
	double getCircumference() const;

};

#endif





