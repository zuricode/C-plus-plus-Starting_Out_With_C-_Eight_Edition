#ifndef MONTH_H
#define MONTH_H

#include <string>

using std::string;

class Month {

private:
	string name;
	int monthNumber;

public:
	Month() { name = "January"; monthNumber = 1; }
	Month(string);
	Month(int);

};

#endif