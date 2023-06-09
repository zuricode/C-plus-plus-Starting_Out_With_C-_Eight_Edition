#include "Employee.h"

using std::left;
using std::setw;

void Employee::print(ostream& strm) const {

	strm << "Name: " << name << "\n";
	strm << "Employee number: " << number << "\n";
	strm << "Date hired: " << hire_date << "\n";

}

ostream& operator << (ostream& strm, const Employee& E) {

	E.print(strm);
	return strm;

}