#include <iostream>
#include <string>
#include "Employee.h"

using namespace std;

int main() {

	Employee employee_1("Susan Meyers", 47899, "Accounting", "Vice President");
	Employee employee_2("Mark Jones", 39119, "IT", "Programmer");
	Employee employee_3("Joy Rogers", 81774, "Manufacturing", "Engineer");

	cout << "EMPLOYEE INFORMATION" << endl;
	cout << "========================" << endl;
	cout << endl;

	employee_1.getData();
	employee_2.getData();
	employee_3.getData();

}