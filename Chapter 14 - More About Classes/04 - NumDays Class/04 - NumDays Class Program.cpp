//4. NumDays Class
//
//Design a class called NumDays.The class’s purpose is to store a value that represents a
//number of work hours and convert it to a number of days.For example, 8 hours would
//be converted to 1 day, 12 hours would be converted to 1.5 days, and 18 hours would
//be converted to 2.25 days.The class should have a constructor that accepts a number
//of hours, as well as member functions for storingand retrieving the hoursand days.
//The class should also have the following overloaded operators :
//
//+Addition operator. When two NumDays objects are added together, the overloaded
//+ operator should return the sum of the two objects’ hours members.
//
//− Subtraction operator. When one NumDays object is subtracted from another,
//the overloaded − operator should return the difference of the two objects’ hours
//members.
//
//++Prefix and postfix increment operators.These operators should increment the
//number of hours stored in the object.When incremented, the number of days
//should be automatically recalculated.
//
//−− Prefixand postfix decrement operators.These operators should decrement the
//number of hours stored in the object.When decremented, the number of days
//should be automatically recalculated.

#include"NumDays.h"

int main() {

	NumDays job(34);
	NumDays job_2(12);
	NumDays job_3;

	job.showHoursAndDays();

	job_3 = job_2 + job;

	job_3.showHoursAndDays();

	job_3 = job_3 - job;

	job_3.showHoursAndDays();

	++job_3;

	job_3.showHoursAndDays();

	job_3++;

	job_3.showHoursAndDays();

	job_3--;

	job_3.showHoursAndDays();

	--job_3;

	job_3.showHoursAndDays();

	NumDays job_4;

	job_4--;

	job_4.showHoursAndDays();

}