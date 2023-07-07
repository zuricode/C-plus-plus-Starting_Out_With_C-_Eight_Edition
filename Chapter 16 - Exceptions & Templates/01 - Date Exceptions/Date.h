#ifndef DATE_H
#define DATE_H

#include<iostream>
#include<string>

using std::string;
using std::cout;
using std::cin;

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
	int dayValidation(string);
	int monthValidation(string);

	class InvalidDay {};
	class InvalidMonth {};

};

#endif