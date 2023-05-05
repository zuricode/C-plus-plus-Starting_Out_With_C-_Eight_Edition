#ifndef NUMDAYS_H
#define NUMDAYS_H

class NumDays {

private:
	int hours;

public:
	NumDays() { hours = 0; }
	NumDays(int h) { hours = h; }

	void setHours(int h) { hours = h;  }
	int getHours() const { return hours; }

	double getDays() { return hours / static_cast<double>(8); }

	NumDays operator + (const NumDays);
	NumDays operator - (const NumDays);

	NumDays operator ++();
	NumDays operator ++(int);
	NumDays operator --();
	NumDays operator --(int);

};

#endif