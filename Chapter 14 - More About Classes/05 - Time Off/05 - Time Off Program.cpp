//5. Time Off
//
//Design a class named TimeOff.The purpose of the class is to track an employee’s
//sick leave, vacation, and unpaid time off.It should have, as members, the following
//instances of the NumDays class described in Programming Challenge 4 :
//
//maxSickDays		A NumDays object that records the maximum number of days of
//				sick leave the employee may take.
//				sickTaken A NumDays object that records the number of days of sick leave the
//				employee has already taken.
//
//maxVacation		A NumDays object that records the maximum number of days of
//				paid vacation the employee may take.
//
//vacTaken		A NumDays object that records the number of days of paid vacation
//				the employee has already taken.
//
//maxUnpaid		A NumDays object that records the maximum number of days of
//unpaid vacation the employee may take.
//
//unpaidTaken		A NumDays object that records the number of days of unpaid leave
//the employee has taken.
//
//Additionally, the class should have members for holding the employee’s nameand identification
//number.It should have an appropriate constructorand member functions for
//storingand retrieving data in any of the member objects.
//
//Input Validation : Company policy states that an employee may not accumulate more
//than 240 hours of paid vacation.The class should not allow the maxVacation object
//to store a value greater than this amount.
//

#include "TimeOff.h"
#include<iostream>

using std::cout;
using std::cin;

void displayEmployeeInfo(TimeOff);
void calculateLeaveAndVacation(TimeOff &, const int);

int main() {

	TimeOff employee_1("Samora Addo", 5321, 5, 5, 5, 5, 5, 5);
	int months_worked;

	displayEmployeeInfo(employee_1);

	cout << "Enter the number of months that " << employee_1.getName() << " has worked: ";

	while (!(cin >> months_worked) || months_worked <= 0) {
		cout << "ERROR: Months worked must be an interger greater than 0\n";
		cout << "\n";
		cout << "Enter the number of months that " << employee_1.getName() << " has worked: ";
	}

	cout << "\n";

	calculateLeaveAndVacation(employee_1, months_worked);

}

void displayEmployeeInfo(TimeOff a) {

	cout << "--------------\n";
	cout << "EMPLOYEE INFO: \n";
	cout << "--------------\n";
	cout << "\n";
	cout << "Name: " << a.getName() << "\n";
	cout << "ID Number: " << a.getIdNumber() << "\n";
	cout << "\n";

}

void calculateLeaveAndVacation(TimeOff &a, const int MONTHS) {

	int total_vacation;
	int total_sick_leave;

	total_vacation = 12 * MONTHS;
	total_sick_leave = 8 * MONTHS;

	a.setMaxVacation(total_vacation);
	a.setMaxSickDays(total_sick_leave);

	cout << "Days of vacation leave available for " << a.getName() << ": " << a.getVacDays() << "\n";
	cout << "Days of sick leave available for " << a.getName() << ": " << a.getSickDays() << "\n";

}