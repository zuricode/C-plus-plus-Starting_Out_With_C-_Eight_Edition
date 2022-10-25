#include <iostream>

using namespace std;

double inputValidation(double);
double* allocateMemory();

int main() {

	double* ptr = allocateMemory();


	delete[] ptr;
	ptr = nullptr;
}

double inputValidation(double limit) {

	int num;

	while (!(cin >> num) || num < limit) {
		cout << "ERROR: Value must be an integer greater than" << limit << "Re-enter your value: ";
		cin.clear();
		cin.ignore(1200, '\n');
	}

	return num;

}

double* allocateMemory() {

	cout << "How many test scores would you like to collect? ";

	double num = inputValidation(0);

	cout << "Memory has been allocated for " << num << " test scores." << endl << endl;

	return new double[num];	

}






