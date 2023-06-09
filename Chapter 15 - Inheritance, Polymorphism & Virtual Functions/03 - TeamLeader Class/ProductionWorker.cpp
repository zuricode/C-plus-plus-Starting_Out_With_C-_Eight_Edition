#include "ProductionWorker.h"

#include<iomanip>

using std::cout;
using std::cin;
using std::fixed;
using std::setprecision;
using std::left;
using std::setw;

ProductionWorker::ProductionWorker(string na, int nu, string d, int s, double h) : Employee(na, nu, d) {

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

void ProductionWorker::print(ostream& strm) const {

	Employee::print(strm);

	strm << "Shift: " << getShift() << "\n";
	strm << "Hourly pay rate: $" << fixed << setprecision(2) << getHourlyPayRate() << "\n";

}