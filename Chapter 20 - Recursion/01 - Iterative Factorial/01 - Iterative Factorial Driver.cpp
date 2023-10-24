//1. Iterative Factorial
//
//Write an iterative version (using a loop instead of recursion) of the factorial function
//shown in this chaapter. Test it with a driver program.

#include <iostream>
#include <limits>

using std::cout;
using std::cin;
using std::numeric_limits;
using std::streamsize;

int getFactorial(int);

int main() {

	cout << "===============================\n";
	cout << "01 - ITERATIVE FACTORIAL DRIVER\n";
	cout << "===============================\n";
	cout << "\n";

	int number;

	cout << "Enter your chosen number to produce the factorial: ";
	cin >> number;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	
	cout << "\n";

	cout << "The factorial of " << number << " is " << getFactorial(number) << ".\n";

	cout << "\n";
	cout << "Ending the program...\n";

}

int getFactorial(int num) {

	for (int i = num - 1; i != 0; i--) {
		num *= i;
	}

	return num;

}