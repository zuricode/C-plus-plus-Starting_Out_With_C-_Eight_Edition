#ifndef SURGERY_H
#define SURGERY_H
#include <string>
#include "Patient.h"

using std::string;

const int TYPES_OF_SURGERY = 5;

class Surgery {

private:

	const string type[TYPES_OF_SURGERY]{ "Appendectomy", "Colostomy", "MRI Scan", "X-Ray", "Hip Replacement" };
	const double charge[TYPES_OF_SURGERY]{ 1500.00, 4000.00, 750.00, 1000.00, 9425.00 };
	const int timeframe_days[TYPES_OF_SURGERY]{ 4, 5, 1, 1, 14 };

public:
	Surgery() {}
	~Surgery() {}

	void addCharge(Patient&, double);

	string getType(const int I) { return type[I]; }
	const double getCharge(const int I) { return charge[I]; }
	const int getTimeframeDays(const int I) { return timeframe_days[I]; }

};

#endif