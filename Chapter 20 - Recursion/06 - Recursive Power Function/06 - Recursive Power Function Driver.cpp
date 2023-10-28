//6. Recursive Power Function
//
//Write a function that use recursion to raise a number to a power. The function should accept two 
//arguments: the number to be raised and the exponent. Assume that the exponent is a non-negative 
//integer. Demonstrate the function in a program.

double recursivePow(double, double);

#include <iostream>
#include <limits>

using std::cout;
using std::cin;
using std::numeric_limits;
using std::streamsize;

int main() {

	cout << "=====================================\n";
	cout << "20-06 RECURSIVE POWER FUNCTION DRIVER\n";
	cout << "=====================================\n";
	cout << "\n";

	double value_1, value_2, total;

	cout << "Base: ";
	cin >> value_1;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Exponent: ";
	cin >> value_2;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "\n";

	total = recursivePow(value_1, value_2);

	cout << value_1 << "^" << value_2 << " = " << total << "\n";

	cout << "\n";
	cout << "Ending the program...\n";

}

double recursivePow(double base, double exponent) {

	if (exponent < 0) {
		return (1 / base) * recursivePow(base, ++exponent);
	}
	else if (exponent > 0) {
		return base * recursivePow(base, --exponent);
	}
	else {
		return 1;
	}

}