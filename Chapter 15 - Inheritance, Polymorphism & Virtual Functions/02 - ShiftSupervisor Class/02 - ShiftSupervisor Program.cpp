#include "ProductionWorker.h"
#include "ShiftSupervisor.h"

using namespace std;

void enterSupervisorData(ShiftSupervisor&);

int main() {

	cout << "==================================================\n";
	cout << "01 - Employee and ProductionWorker Classes Program\n";
	cout << "==================================================\n";
	cout << "\n";

	cout << "Example of ProductionWorker objects...\n";
	cout << "\n";

	ProductionWorker worker_1;
	ProductionWorker worker_2(1, 14.50, "Zaire Sarr", 56332, "06/08/2019");
	cout << worker_1 << worker_2;

	ShiftSupervisor supervisor_1;
	enterSupervisorData(supervisor_1);
	ShiftSupervisor supervisor_2(34999.00, 4590, "Dele Adesanya", 94323, "11/05/2022");

	cout << "Example of ShiftSupervisor objects...\n";
	cout << "\n";

	cout << supervisor_1 << supervisor_2;

}

void enterSupervisorData(ShiftSupervisor& s) {

	string text;
	int num_i;
	double num_d;

	cout << "Supervisor Name: ";
	getline(cin, text);
	s.setName(text);

	cout << "Employee Number: ";
	cin >> num_i;
	cin.ignore();
	s.setNumber(num_i);

	cout << "Date hired: ";
	getline(cin, text);
	s.setHireDate(text);

	cout << "Salary: $";
	cin >> num_d;
	s.setSalary(num_d);

	cout << "Annual Production Bonus: $";
	cin >> num_d;
	s.setAnnualBonus(num_d);

	cout << "\n";

}