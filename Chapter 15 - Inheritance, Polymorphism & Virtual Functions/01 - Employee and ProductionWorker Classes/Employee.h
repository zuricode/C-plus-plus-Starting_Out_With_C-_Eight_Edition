#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<string>

using std::string;

class Employee {

private:
	string name;
	int number;
	string hire_date;

public:
	Employee() {name = ""; number = 0; hire_date = "--/--/----"; }
	Employee(const string s, const int num, const string d) { name = s; number = num; hire_date = d; }

	void setName(string s) { name = s; }
	void setNumber(int n) { number = n; }
	void setHireDate(string d) { hire_date = d; }

	string getName() const { return name; }
	int getNumber() const { return number; }
	string getHireDate() const { return hire_date; }


};

#endif