//3. Minimum / Maximum Templates
//
//Write templates for the two functions minimumand maximum.The minimum function
//should accept two argumentsand return the value of the argument that is the lesser
//of the two.The maximum function should accept two arguments and return the value
//of the argument that is the greater of the two.Design a simple driver program that
//demonstrates the templates with various data types.

#include <iostream>

using std::cin;
using std::cout;

class Equal {};

template <class T>
T greater(const T A, const T B) {

	if (A > B) {
		return A;
	}
	else if (B > A) {
		return B;
	}
	else {
		throw Equal();
	}

}

template <class T>
T smaller(const T A, const T B) {

	if (A < B) {
		return A;
	}
	else if (B < A) {
		return B;
	}
	else {
		throw Equal();
	}

}

void getMaxValue();
void getMinValue();

int main() {

	char tryAgain;
	

	cout << "=========================================\n";
	cout << "16-03 - MINIMUM_MAXIMUM TEMPLATES PROGRAM\n";
	cout << "=========================================\n";
	cout << "\n";

	do {

		try {
			getMaxValue();
			getMinValue();
			//cout << greater(a, b) << " is the highest number.\n";
		}
		catch (Equal) {
			cout << "Both values are equal.\n";
		}

		cout << "Would you like to run the program again?\n";
		cout << "Enter Y/N: ";

		while (!(cin >> tryAgain) || (toupper(tryAgain) != 'Y' && toupper(tryAgain) != 'N')) {
			cout << "ERROR: Incorrect value. Enter either Y or N.\n";
			cout << "\n";
			cout << "Enter Y/N: ";
		};

		tryAgain = toupper(tryAgain);

		cout << "\n";

	} while (tryAgain == 'Y');

	cout << "Ending the program...\n";

}

void getMaxValue() {

	cout << "getMaxValue func - Find the greatest value\n";
	cout << "------------------------------------------\n";
	cout << "\n";

	double double_a = 0.0;
	double double_b = 0.0;
	char char_a = ' ';
	char char_b = ' ';

	cout << "Enter Double #1: ";
	cin >> double_a;

	cout << "Enter Double #2: ";
	cin >> double_b;
	cout << "\n";

	cout << "Enter Char #1: ";
	cin >> char_a;

	cout << "Enter Char #2: ";
	cin >> char_b;
	cout << "\n";

	cout << "The greater double is " << greater(double_a, double_b) << ".\n";
	cout << "The greater char is " << greater(char_a, char_b) << ".\n";
	cout << "\n";

}

void getMinValue() {

	double double_a = 0.0;
	double double_b = 0.0;
	char char_a = ' ';
	char char_b = ' ';

	cout << "getMinValue func - Find the smallest value\n";
	cout << "------------------------------------------\n";
	cout << "\n";

	cout << "Enter Double #1: ";
	cin >> double_a;

	cout << "Enter Double #2: ";
	cin >> double_b;
	cout << "\n";

	cout << "Enter Char #1: ";
	cin >> char_a;

	cout << "Enter Char #2: ";
	cin >> char_b;
	cout << "\n";

	cout << "The smaller double is " << smaller(double_a, double_b) << ".\n";
	cout << "The smaller char is " << smaller(char_a, char_b) << ".\n";
	cout << "\n";

}