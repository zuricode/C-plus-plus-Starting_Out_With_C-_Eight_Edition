#include <iostream>
#include <iomanip>

const int		RANGE{ 7 },
				empId[RANGE]{ 5658845, 4520125, 7895122, 8777541,
								8451277, 1302850, 7580489 };

const double	PAY_RATE_LIMIT{ 15.00 };

using namespace std;

void getData(const int[], int[], double[], double[]);
int inputValidation(int);
double inputValidation(double);
double wagesFunction(int, double);
void grossWages(const int[], int[], double[], double[]);


int main() {

	int		hours[RANGE];
	double	payRate[RANGE],
			wages[RANGE];

	getData(empId, hours, payRate, wages);
	grossWages(empId, hours, payRate, wages);

}

void getData(const int empId[], int hours[], double payRate[], double wages[]) {

	for (int i = 0; i < RANGE; i++) {
		cout << "Employee #" << empId[i] << ":" << endl;
		cout << "Enter the number of hours employee #" << empId[i] << " worked: ";
		hours[i] = inputValidation(0);
		cout << "Enter the amount of money employee #" << empId[i] << " earns per hour (in $): ";
		payRate[i] = inputValidation(PAY_RATE_LIMIT);
		wages[i] = wagesFunction(hours[i], payRate[i]);

		cout << endl;

	}

}

int inputValidation(int limit) {

	int num;

	while (!(cin >> num) || num < limit) {
		cout << "ERROR: Value must be an integer greater than " << limit << ". Re-enter your value: ";
		cin.clear();
		cin.ignore(1200, '\n');
	}
	return num;
}

double inputValidation(double limit) {

	double num;

	while (!(cin >> num) || num < limit) {
		cout << "ERROR: The minmum wage is $" << limit << ". Re-enter your value: ";
		cin.clear();
		cin.ignore(1200, '\n');
	}
	return num;
}

double wagesFunction(int hours, double hourly_pay) {
	return hours * hourly_pay;
}

void grossWages(const int empId[], int hours[], double payRate[], double wages[]) {

	cout << "GROSS WAGES: " << endl;
	cout << "-------------------" << endl;
	cout << endl;

	for (int i = 0; i < RANGE; i++) {

		cout << "Employee #" << empId[i] << " - Hours: " << hours[i] << " - Hourly pay: " << payRate[i] << " - Gross wages: $" << fixed << setprecision(2) <<  wagesFunction(hours[i], payRate[i]) << endl;
		cout << setprecision(0);

		}

	cout << endl;	

}