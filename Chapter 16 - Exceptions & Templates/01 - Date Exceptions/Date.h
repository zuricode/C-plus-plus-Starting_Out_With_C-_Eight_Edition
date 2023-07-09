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

	class InvalidDay {

	private:
		int invalid_day;

	public:
		InvalidDay(int inv_day) {
			invalid_day = inv_day;
		}

		int getInvalidDay() const {
			return invalid_day;
		}	
	
	};

	class InvalidMonth {
	
	private:
		int invalid_month;

	public:
		InvalidMonth(int inv_mon) {
			invalid_month = inv_mon;
		}

		int getInvalidMonth() const {
			return invalid_month;
		}

	};

};

#endif