#ifndef MONTH_H
#define MONTH_H
#include <string>
#include <iostream>

using std::string;
using std::ostream;
using std::istream;

class Month {

private:
	string name;
	int monthNumber;

public:
	Month() { name = "January"; monthNumber = 1; }
	Month(string);
	Month(int);

	void setName(string);
	void setMonthNumber(int);

	string getName() { return name; }
	int getMonthNumber() { return monthNumber; }

	Month operator ++();
	Month operator --();

	Month operator ++(int);
	Month operator --(int);

	friend ostream& operator << (ostream&, const Month &);
	friend istream& operator >> (istream&, Month&);

};

#endif