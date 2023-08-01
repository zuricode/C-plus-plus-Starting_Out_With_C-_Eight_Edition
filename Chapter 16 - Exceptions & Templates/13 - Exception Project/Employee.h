#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include<string>

using std::string;
using std::cout;

const int MIN_NUMBER = 0;
const int MAX_NUMBER = 9999;

class Employee {

private:
	string name;
	int number;
	string hire_date;

public:
	Employee() {name = ""; number = 0; hire_date = "--/--/----"; }
	Employee(const string s, const int num, const string d) { name = s; number = num; hire_date = d; }

	void setName(string s) { name = s; }
	void setNumber(int);
	void setHireDate(string d) { hire_date = d; }

	string getName() const { return name; }
	int getNumber() const { return number; }
	string getHireDate() const { return hire_date; }

	class InvalidEmployeeNumber {

	private:
		int invalid_num;

	public:
		InvalidEmployeeNumber(const int N) {
			invalid_num = N;
		}

		int getNumber() { return invalid_num; }

	};


};

#endif