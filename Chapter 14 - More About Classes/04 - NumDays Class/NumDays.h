#ifndef NUMDAYS_H
#define NUMDAYS_H

class NumDays {

private:
	int hours;
	double days;

public:
	NumDays() { hours = 0; days = 0; }
	NumDays(int h) { hours = h; setDays(); }

	void setHours(int h) { hours = h;  }
	int getHours() const { return hours; }

	void setDays() { days = hours / static_cast<double>(8); }
	int getDays() { return days; }

	void showHoursAndDays();

	NumDays operator + (const NumDays);
	NumDays operator - (const NumDays);

	NumDays operator ++();
	NumDays operator ++(int);
	NumDays operator --();
	NumDays operator --(int);

};

#endif