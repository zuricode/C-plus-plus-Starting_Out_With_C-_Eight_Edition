//6. IntArray Class Exception
//
//Chapter 14 presented an IntArray class that dynamically creates an array of integers
//and performs bounds checking on the array.If an invalid subscript is used with
//the class, it displays an error messageand aborts the program.Modify the class so it
//throws an exception instead.

#include "intArray.h"

#include <iostream>

using std::cout;

int main() {

	const int ELEMENTS_IN_ARRAY = 5;

	IntArray list(ELEMENTS_IN_ARRAY);

	cout << "========================================\n";
	cout << "16-06 - INTARRAY CLASS EXCEPTION PROGRAM\n";
	cout << "========================================\n";
	cout << "\n";

	cout << "Showing all elements in the array...\n";
	cout << "\n";

	for (int i = 0; i < list.size(); i++) {
		cout << "Subscript #" << i + 1 << ": " << list[i] << "\n";
	}

	cout << "\n";

	cout << "Checking subscripts in an array of " << list.size() << " elements...\n";
	cout << "\n";

	try {
		cout << "\tElement #1 is " << list[0] << ".\n";
		cout << "\tElement #3 is " << list[2] << ".\n";
		cout << "\tElement #6 is " << list[5] << ".\n";
	}
	catch (IntArray::InvalidSub s) {
		cout << "\n";
		cout << "ERROR: Subscript #" << s.getInvalidSub() << " does not exist within the array.\n";
		cout << "They are only " << list.size() << " elements in the array.\n";
	}

	cout << "\n";
	cout << "Ending the program..." << "\n";

}