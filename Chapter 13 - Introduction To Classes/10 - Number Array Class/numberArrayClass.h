#ifndef NUMBERARRAYCLASS_H
#define NUMBERARRAYCLASS_H

class Number {

private:
	float *num = nullptr;

public:
	Number(int);
	~Number();

	void setNumber(int, float);
	float getNumber(int) const;

};

#endif