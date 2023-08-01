#include "Employee.h"

void Employee::setNumber(int n) {

	if (n < MIN_NUMBER || n > MAX_NUMBER) {
		throw InvalidEmployeeNumber(n);
	}
	else {
		number = n;
	}

}