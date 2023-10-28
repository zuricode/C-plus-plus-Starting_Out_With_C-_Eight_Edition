//7. Sum of Numbers
//
//Write a function that accepts an integer argument and returns the sum of all the integers from 1
//up to the number passed as an argument.For example, if 50 is passed as an argument, the function
//will return the sum of 1, 2, 3, 4, ... 50. Use recursion to calculate the sum. Demonstrate the 
//function in a program.

#include <iostream>
#include <limits>

using std::cout;
using std::cin;
using std::numeric_limits;
using std::streamsize;

int sumOfNumbers(int);

int main() {

	cout << "===========================\n";
	cout << "20-05 SUM OF NUMBERS DRIVER\n";
	cout << "===========================\n";
	cout << "\n";

	int num;

	cout << "Enter your chosen number: ";
	cin >> num;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "The sum of all numbers from 1-" << num << " is " << sumOfNumbers(num) << "\n";

	cout << "\n";
	cout << "Ending the program...\n";	

}

int sumOfNumbers(int num) {

	if (num > 0) {
		return num + sumOfNumbers(num - 1);
	}
	else if (num < 0) {
		return num + sumOfNumbers(num + 1);
	}
	else {
		return 0;
	}

}