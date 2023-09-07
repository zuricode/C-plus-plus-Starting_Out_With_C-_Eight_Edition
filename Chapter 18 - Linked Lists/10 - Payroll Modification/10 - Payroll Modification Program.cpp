//07-09. Payroll
//
//Write a program that uses the following arrays :
//
//• empId : an array of seven long integers to hold employee identification numbers.The
//array should be initialized with the following numbers :
//5658845 4520125 7895122 8777541
//8451277 1302850 7580489
//• hours : an array of seven integers to hold the number of hours worked by each
//employee
//• payRate : an array of seven double s to hold each employee’s hourly pay rate
//• wages : an array of seven double s to hold each employee’s gross wages
//
//The program should relate the data in each array through the subscripts.For example,
//the number in element 0 of the hours array should be the number of hours worked by

//18-10. Payroll Modification
//
//Modify Programming Challenge 9 in Chapter 7 (Payroll) to use three linked lists instead of
//three arrays to hold the employee IDs, hours worked, and wages. When the program starts,
//it should ask the user to enter the employee IDs. There should be no limit on the number of
//IDs the user can enter.

#include "LinkedList.h"
#include <iomanip>

using std::fixed;

template <class T, class T1> void displayEmployeeData(const LinkedList<T>&, const LinkedList<T>&, const LinkedList<T1>&);

int main() {

	cout << "==================================\n";
	cout << "18-10 PAYROLL MODIFICATION PROGRAM\n";
	cout << "==================================\n";
	cout << "\n";

	LinkedList<int> empId;
	LinkedList<int> hours;
	LinkedList<double> wages;

	int value;
	double wages_value;

	cout << "EMPLOYEE DATA\n";
	cout << "-------------\n";
	cout << "\n";

	for(int i = 0; i < 3; i++) {

		cout << "Employee ID #" << i + 1 << ": ";

		while (!(cin >> value) && value <= 0) {
			cout << "ERROR: Employee ID must be an integer greater than 0.\n";
			cout << "\n";
			cin.ignore(1200, '\n');
			cin.clear();
			cout << "Employee ID #" << i + 1 << ": ";
		};

		cin.ignore(1200, '\n');
		cin.clear();
		empId.appendNode(value);

		cout << "Hours worked: ";

		while (!(cin >> value) && value <= 0) {
			cout << "ERROR: Hours worked must be an integer greater than 0.\n";
			cout << "\n";
			cin.ignore(1200, '\n');
			cin.clear();
			cout << "Hours worked: ";
		};

		cin.ignore(1200, '\n');
		cin.clear();
		hours.appendNode(value);

		cout << "Wages: $";

		while (!(cin >> wages_value) && wages_value <= 0) {
			cout << "ERROR: The wages must be a double greater than 0.\n";
			cout << "\n";
			cin.ignore(1200, '\n');
			cin.clear();
			cout << "Wages: $" << i + 1 << ": ";
		};

		cin.ignore(1200, '\n');
		cin.clear();
		wages.appendNode(wages_value);

		cout << "\n";

	}

	displayEmployeeData(empId, hours, wages);

}

template <class T, class T1>
void displayEmployeeData(const LinkedList<T>& ID, const LinkedList<T>& HOURS, const LinkedList<T1>& WAGES) {

	int spacer = 20;

	cout << "EMPLOYEE DATA\n";
	cout << "-------------\n";
	cout << "\n";

	cout << left << setw(15) << "ID" << " | ";
	ID.displayList(spacer);
	
	cout << setw(15) << "HOURS WORKED" << " | ";
	HOURS.displayList(spacer);

	cout << fixed << setw(15) << "WAGES ($)" << " | ";
	WAGES.displayList(spacer);

}