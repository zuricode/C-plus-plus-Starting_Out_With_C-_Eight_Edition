#ifndef DATE_H
#define DATE_H

using namespace std;

class Date {

private:
	int month;
	int day;
	int year;

public:
	Date();
	Date(int, int, int);
	void setDate();
	void getDate();

};

#endif