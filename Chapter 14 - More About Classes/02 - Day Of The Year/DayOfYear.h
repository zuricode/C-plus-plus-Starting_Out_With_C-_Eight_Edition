#ifndef DAYOFYEAR_H
#define DAYOFYEAR_H

#include <string>

using std::string;

class DayOfYear {

private:
	
	int day;

	static const int MONTHS = 12;
	static const string months_words[MONTHS];
	static const int months_days[MONTHS];

public:

	DayOfYear(int n);

	void print();

};

#endif