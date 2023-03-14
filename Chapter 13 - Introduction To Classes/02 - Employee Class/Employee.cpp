#include<iostream>
#include<iomanip>
#include<string>
#include "Employee.h"

using namespace std;

Employee::Employee(string n, int id) {

	name = n;
	idNumber = id;
	department = "";
	position = "";

}

Employee::Employee(string n, int id, string dep, string pos) {

	name = n;
	idNumber = id;
	department = dep;
	position = pos;

}

Employee::Employee() {

	name = "";
	idNumber = 0;
	department = "";
	position = "";

}

void Employee::setData() {

	cout << "Full Name: ";
	getline(cin, name);

	cout << "ID Number: ";
	cin >> idNumber;
	cin.ignore();


	cout << "Department: ";
	getline(cin, department);


	cout << "Position: ";
	getline(cin, position);

	cout << endl;

}

void Employee::getData() {

	cout << "Full Name: " << name << endl;
	cout << "ID Number: " << idNumber << endl;
	cout << "Department: " << department << endl;
	cout << "Position: " << position << endl;

	cout << endl;

	/*cout << left << setfill('-') << setw(90) << '\n' << endl;
	cout << setfill(' ') << setw(35) << "Name" << setw(15) << "ID Number" << setw(25) << "Department" << setw(25) << "Position" << setfill('-') << setw(90) << '\n' << endl;
	cout << setfill(' ') << setw(35) << name << setw(15) << idNumber << setw(25) << department << setw(25) << position << setfill('-') << setw(90) << '\n' << endl;*/

}