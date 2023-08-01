#include "ProductionWorker.h"

#include<iomanip>

using std::cout;
using std::cin;
using std::fixed;
using std::setprecision;

ProductionWorker::ProductionWorker(int s, double h, string na, int nu, string d) : Employee(na, nu, d) {

	setShift(s);
	setHourlyPayRate(h);

}


void ProductionWorker::setShift(int s) {

	if (s != DAY && s != NIGHT) {
		throw InvalidShift(s);
	}
	else {
		shift = s;
	}

}

void ProductionWorker::setHourlyPayRate(double p) {

	if (p <= 0) {
		throw InvalidPayRate(p);
	}
	else {
		hourly_pay_rate = p;
	}


}

string ProductionWorker::getShift() const {

	if (shift == DAY) {
		return "DAY";
	}
	else {
		return "NIGHT";
	}

}

ostream& operator << (ostream& strm, const ProductionWorker& P) {

	strm << "Name: " << P.getName() << "\n";
	strm << "Number: " << P.getNumber() << "\n";
	strm << "Hire Date: " << P.getHireDate() << "\n";
	strm << "Shift: " << P.getShift() << "\n";
	strm << "Hourly Pay Rate: $" << fixed << setprecision(2) << P.getHourlyPayRate() << "\n";
	strm << "\n";

	return strm;

}