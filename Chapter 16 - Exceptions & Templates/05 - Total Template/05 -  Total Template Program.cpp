//5. Total Template
//
//Write a template for a function called total.The function should keep a running
//total of values entered by the user, then return the total.The argument sent into the
//function should be the number of values the function is to read.Test the template in
//a simple driver program that sends values of various types as arguments and displays
//the results.

#include <iostream>

using std::cout;
using std::cin;

template<class T>
T total(const int NUM_OF_VALUES) {

	T total = 0;
	T num;

	for (int i = 0; i < NUM_OF_VALUES; i++) {
		cout << "Enter number #" << i + 1 << ": ";
		cin >> num;
		cin.ignore();
		cin.clear();

		total += num;

	}

	return total;

}

int main() {

	int num_of_values;
	int int_total;
	double double_total;

	cout << "Number of values: ";
	cin >> num_of_values;
	cin.ignore();
	cin.clear();

	int_total = total(num_of_values);
	cout << "The total of the " << num_of_values << " values is " << int_total << "\n";

	double_total = total(num_of_values);
	cout << "The total of the " << num_of_values << " values is " << double_total << "\n";

}