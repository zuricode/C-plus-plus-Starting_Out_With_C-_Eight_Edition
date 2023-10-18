#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;

class Date {

private:
	int day;
	int month;
	int year;

public:
	Date() { day = -1; month = -1; year = -1; }
	Date(const Date&);
	
	void setDate();
	bool checkDate();
	string getDate() const;

};

#endif