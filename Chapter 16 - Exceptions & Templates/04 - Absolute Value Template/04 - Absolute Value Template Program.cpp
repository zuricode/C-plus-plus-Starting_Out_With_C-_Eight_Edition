//4. Absolute Value Template
//
//Write a function template that accepts an argument and returns its absolute value.The
//absolute value of a number is its value with no sign.For example, the absolute value of
//-5 is 5, and the absolute value of 2 is 2. Test the template in a simple driver program.

#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::fixed;
using std::setprecision;

template<class T>
void getAbsoluteValue(const T &VAL) {

	cout << "Original value: " << VAL << "\n";
	cout << "Absolute value: " << abs(VAL) << "\n";
	cout << "\n";

}

int main() {

	cout << "====================================\n";
	cout << "04 - ABSOLUTE VALUE TEMPLATE PROGRAM\n";
	cout << "====================================\n";
	cout << "\n";

	int int_value = 0;
	double double_value = 0.0;

	cout << "Enter your chosen int: ";
	cin >> int_value;
	cin.ignore();
	cin.clear();

	cout << "\n";
	
	getAbsoluteValue(int_value);

	cout << "Enter your chosen double: ";
	cin >> double_value;
	cin.ignore();
	cin.clear();

	cout << "\n";

	cout << fixed << setprecision(2);

	getAbsoluteValue(double_value);
		
}