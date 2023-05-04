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

int main() {

	TimeOff employee("First Last", 5, 5, 5, 5, 5, 5, 5);

}