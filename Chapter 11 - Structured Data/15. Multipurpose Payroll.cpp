//15. Multipurpose Payroll
//
//Write a program that calculates pay for either an hourly paid worker or a salaried
//worker.Hourly paid workers are paid their hourly pay rate times the number of hours
//worked.Salaried workers are paid their regular salary plus any bonus they may have
//earned.The program should declare two structures for the following data :
//
//Hourly Paid :
//HoursWorked
//HourlyRate
//
//Salaried :
//Salary
//Bonus
//
//The program should also declare a union with two members.Each member should be a
//structure variable : one for the hourly paid workerand another for the salaried worker.
//
//The program should ask the user whether he or she is calculating the pay for an hourly
//paid worker or a salaried worker.Regardless of which the user selects, the appropriate
//members of the union will be used to store the data that will be used to calculate
//the pay.
//
//Input Validation : Do not accept negative numbers.Do not accept values greater than
//80 for HoursWorked.

#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

struct HourlyPaid {
	double hours_worked;
	double hourly_rate;
};

struct Salaried {
	double salary;
	double bonus;
};

union Worker {
	HourlyPaid hp;
	Salaried salaried;
};

enum WorkType { HOURLY_PAID, SALARIED };

void intro();

int enterHoursWorked(const int, string);
void enterTypeOfWorker();
double enterHourlyRate(string);
double enterSalary(string);
double enterBonus(string);
WorkType enterWorkerType(WorkType, WorkType, string);
void enterWorkData(WorkType, Worker&, const int);
char newEmployee(string);

int main() {

	const int		MAX = 80;
	Worker			employee;

	char			nextEmployee;

	do {

		intro();
		
		enterTypeOfWorker();

		WorkType worker_choice = enterWorkerType(HOURLY_PAID, SALARIED, "Enter your selection: ");

		cout << endl;

		enterWorkData(worker_choice, employee, MAX);

		nextEmployee = newEmployee("Would you like to calculate pay for another employee (Y/N): ");

		cout << endl;

	} while (nextEmployee == 'Y');

	cout << "Quitting the program..." << endl;		

}

void intro() {

	cout << "===========================" << endl;
	cout << "    MULTIPURPOSE PAYROLL   " << endl;
	cout << "===========================" << endl;
	cout << endl;

}

void enterTypeOfWorker() {

	cout << "What type of worker are you: " << endl;
	cout << endl;
	cout << "0) Hourly-paid worker" << endl;
	cout << "1) Salaried worker" << endl;
	cout << endl;

}

WorkType enterWorkerType(WorkType HOURLY_PAID, WorkType SALARIED, string request) {

	int num;

	cout << request;

	while (!(cin >> num) || num < HOURLY_PAID || num > SALARIED) {
		cout << "ERROR: Value must be between (and including) " << HOURLY_PAID << " and " << SALARIED << "." << endl;
		cout << endl;
		cout << request;
		cin.clear();
		cin.ignore(1200, '\n');
	}

	cin.clear();
	cin.ignore(1200, '\n');

	return static_cast<WorkType>(num);

}

int enterHoursWorked(const int MAX, string request) {

	int hours;

	cout << request;

	while (!(cin >> hours) || hours < 0 || hours > MAX) {
		cout << "ERROR: Hours worked cannot be less than 0 or greater than " << MAX << " hours." << endl;
		cout << endl;
		cout << request;
		cin.clear();
		cin.ignore(1200, '\n');
	}

	cin.clear();
	cin.ignore(1200, '\n');

	return hours;

}

double enterHourlyRate(string request) {

	double rate;

	cout << request;

	while (!(cin >> rate) || rate < 0) {
		cout << "ERROR: Hourly rate cannot be a negative value." << endl;
		cout << endl;
		cout << request;
		cin.clear();
		cin.ignore(1200, '\n');
	}

	cin.clear();
	cin.ignore(1200, '\n');

	return rate;

}

double enterSalary(string request) {

	double salary;

	cout << request;

	while (!(cin >> salary) || salary < 0) {
		cout << "ERROR: Salary cannot be a negative value." << endl;
		cout << endl;
		cout << request;
		cin.clear();
		cin.ignore(1200, '\n');
	}

	cin.clear();
	cin.ignore(1200, '\n');

	return salary;

}

double enterBonus(string request) {

	double bonus;

	cout << request;

	while (!(cin >> bonus) || bonus < 0) {
		cout << "ERROR: Salary cannot be a negative value." << endl;
		cout << endl;
		cout << request;
		cin.clear();
		cin.ignore(1200, '\n');
	}

	cin.clear();
	cin.ignore(1200, '\n');

	return bonus;

}

void enterWorkData(WorkType worker_choice, Worker& employee, const int MAX) {

	cout << fixed << setprecision(2);

	if (worker_choice == HOURLY_PAID) {

		employee.hp.hours_worked = enterHoursWorked(MAX, "How many hours did your employee work? ");
		employee.hp.hourly_rate = enterHourlyRate("What is their hourly pay? $");

		cout << endl;

		cout << "Employee's total pay: $" << employee.hp.hours_worked * employee.hp.hourly_rate << endl;

	}

	else {

		employee.salaried.salary = enterSalary("What is this employee's salary? $");
		employee.salaried.bonus = enterBonus("How much was their bonus? $");

		cout << endl;

		cout << "Employee's total pay: $" << employee.salaried.salary + employee.salaried.bonus << endl;

	}

	cout << endl;

}

char newEmployee(string request) {

	char answer;

	cout << request;

	cin >> answer;
	answer = toupper(answer);

	while(answer != 'Y' && answer != 'N') {
		cout << "ERROR: Answer either \"y\", \"Y\", \"n\", \"N\"." << endl;
		cout << endl;
		cout << request;
		cin.clear();
		cin.ignore(1200, '\n');
		cin >> answer;
	}

	cin.clear();
	cin.ignore(1200, '\n');

	return answer;	

}

