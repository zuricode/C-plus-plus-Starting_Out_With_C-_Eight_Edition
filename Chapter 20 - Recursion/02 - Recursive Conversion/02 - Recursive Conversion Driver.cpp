//2. Recursive Conversion
//
//Convert the following function to one that uses recursion.
//
//void sign (int n) {
//	while (n > 0) {
//		cout << "No Parking\n";
//		n--;
//	}
//}

#include <iostream>
#include <limits>

using std::cout;
using std::cin;
using std::numeric_limits;
using std::streamsize;

void signRecursive(int);

int main() {

	cout << "=================================\n";
	cout << "20-02 RECURSIVE CONVERSION DRIVER\n";
	cout << "=================================\n";
	cout << "\n";

	int num;

	cout << "Enter a number to feed into the recursive sign function: ";
	cin >> num;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "\n";

	signRecursive(num);

	cout << "Ending the program...\n";

}

void signRecursive(int n) {

	if (n > 0) {
		cout << "No Parking\n";
		n--;
		signRecursive(n);
	}
	else {
		cout << "\n";
	}

}