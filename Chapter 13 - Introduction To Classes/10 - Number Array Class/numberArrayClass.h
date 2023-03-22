#ifndef NUMBERARRAYCLASS_H
#define NUMBERARRAYCLASS_H

class Number {

private:
	float *num = nullptr;

public:
	Number(const int);
	~Number();

	void setNumber(int);
	float getNumber(int) const;
	float getHighest(const int) const;
	float getLowest(const int) const;
	float getAverage(const int) const;

};

#endif