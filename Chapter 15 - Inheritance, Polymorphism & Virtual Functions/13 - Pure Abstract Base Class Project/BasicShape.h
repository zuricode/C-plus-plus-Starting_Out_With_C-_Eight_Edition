#ifndef BASICSHAPES_H
#define BASICSHAPES_H

class BasicShape {

protected:
	double area;

public:
	BasicShape() { area = 0; }
	~BasicShape() {}

	double getArea() const { return area; }
	
	virtual void calcArea() = 0;

};

#endif