#ifndef PATIENT_H
#define PATIENT_H
#include <string>

using std::string;

class Patient {

private:
	string full_name;
	double total_charges;
	int total_operations;
	int days_in_hospital;

public:
	Patient() { full_name = ""; total_operations = 0; total_charges = 0; days_in_hospital = 0; }
	~Patient() {}

	void setName(string s) { full_name = s; }
	string getName() { return full_name; }

	void addOperation() { total_operations++; }
	int getTotalOperations() { return total_operations; }

	void addCharge(double);

};

#endif