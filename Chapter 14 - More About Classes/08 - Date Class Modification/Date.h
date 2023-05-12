#ifndef DATE_H
#define DATE_H
#include <string>
#include <iostream>

using std::string;
using std::istream;
using std::ostream;

class Date {

private:

	static const int DAYS_PER_MONTH[13];
	static const string MONTHS_NAMES[13];

	int month;
	int day;
	int year;

public:

	Date();
	Date(int, int, int);
	void setDate();
	void getDate();
	int dayValidation(string);
	int monthValidation(string);
	int yearValidation(string);

	bool isLeapYear();

	Date operator ++();
	Date operator ++(int);
	Date operator --();
	Date operator --(int);

	friend ostream& operator << (ostream&, const Date&);
	friend istream& operator >> (istream&, Date&);

};

#endif