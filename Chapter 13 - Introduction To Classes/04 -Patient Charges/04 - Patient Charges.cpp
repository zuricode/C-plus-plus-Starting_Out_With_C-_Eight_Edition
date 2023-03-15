#include "Patient.h"
#include "Procedure.h"
#include<iostream>
#include<iomanip>

using namespace std;

void displayPatient(const Patient);
void displayProcedure(const Procedure);

int main() {

	const string CURRENT_DATE{ "15/03/2023" };

	Patient patient_1("John", "Really", "Doe",
		"607 Norwood Road", "London", "LONDON", "SE27 0AX",
		"07754023943", "Mother John", "07956034231");

	cout << "Patient Information: " << endl;
	cout << "=========================" << endl;
	displayPatient(patient_1);

	Procedure physical("Physical Exam", CURRENT_DATE, "Dr. Irvine", 250.00);
	Procedure x_ray("X-ray", CURRENT_DATE, "Dr. Jamison", 500.00);
	Procedure blood_test("Blood test", CURRENT_DATE, "Dr. Smith", 200.00);

	displayProcedure(physical);
	displayProcedure(x_ray);
	displayProcedure(blood_test);

}

void displayPatient(const Patient p) {

	cout << "Full name: " << p.getFirstName() << " " << p.getMiddleName() << " " << p.getLastName() << endl;
	cout << "Address: " << p.getAddress() << ", " << p.getCity() << ", " << p.getState() << ", " << p.getZIP() << endl;
	cout << "Phone number: " << p.getPhoneNumber() << endl;
	cout << "Emergency name: " << p.getEmergencyName() << " - " << p.getEmergencyNumber() << endl;

	cout << endl;

}

void displayProcedure(const Procedure p) {

	cout << "Procedure name: " << p.getName() << endl;
	cout << "Date: " << p.getDate() << endl;
	cout << "Practitioner: " << p.getPractitioner() << endl;
	cout << "Cost: $" << fixed << setprecision(2) << p.getCost() << endl;

	cout << endl;

}
