#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<string>

using namespace std;

class Employee {

private:
	string name;
	int idNumber;
	string department;
	string position;

public:
	Employee();
	Employee(string, int, string, string);
	Employee(string, int);
	void setData();
	void getData();
};

#endif
