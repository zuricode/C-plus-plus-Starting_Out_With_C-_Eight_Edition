#ifndef SURGERY_H
#define SURGERY_H
#include <string>

#include "Patient.h"

class Surgery {

private:

	const int TYPES_OF_SURGERY = 5;

	string surgery_type[TYPES_OF_SURGERY]{ "Appendectomy", "Colostomy", "MRI Scan", "X-Ray", "Hip Replacement" };
	double charges[TYPES_OF_CHARGES]{ 1500.00, 4000.00, 750.00, 1000.00, 9425.00 };
	int surgery_days[TYPES_OF_SURGERY]{ 4, 5, 1, 1, 14 };

public:
	Surgery() {}
	~Surgery() {}

	void addCharge(Patient&, double);

};

#endif