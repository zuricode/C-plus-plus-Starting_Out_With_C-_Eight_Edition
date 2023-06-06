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
		cout << "ERROR: Shift must be an either 1 (Day) or 2 (Night).\n";
		cout << "\n";
		cout << "Shift: ";
		cin >> s;
	}

	shift = s;

}

void ProductionWorker::setHourlyPayRate(double p) {

	if (p <= 0) {
		cout << "ERROR: Hourly pay rate must be a value greater than 0.\n";
		cout << "\n";
		cout << "Hourly pay rate: ";
		cin >> p;
	}

	hourly_pay_rate = p;

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