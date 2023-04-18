#ifndef PATIENT_H
#define PATIENT_H
#include <string>
#include <vector>

using std::string;
using std::vector;

class Patient {

private:
	string full_name;
	double total_charges;
	vector<string> list_of_operations;
	int total_operations;
	int days_in_hospital;

public:
	Patient() { full_name = ""; total_operations = 0; total_charges = 0; days_in_hospital = 0; }
	~Patient() {}

	void setName(string s) { full_name = s; }
	string getName() { return full_name; }

	void addCharge(double charge) { total_charges += charge; }
	double getTotalCharges() { return total_charges; }

	void addOperationTitle(string title) { list_of_operations.push_back(title); }
	void getAllOperations();

	void addDaysInHospital(int days) { days_in_hospital += days; }
	int getDaysInHospital() { return days_in_hospital;  }

	void addOperationAmount() { total_operations++; }
	int getTotalOperations() { return total_operations; }
};

#endif