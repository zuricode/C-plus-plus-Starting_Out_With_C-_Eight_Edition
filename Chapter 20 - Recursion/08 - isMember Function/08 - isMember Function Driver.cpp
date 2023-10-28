//8. isMember Function
//
//Write a recursive Boolean function named isMember. The functoin should accept two arguments: an 
//array and a value. The function should return true if the value is found in the array, or false 
//if the value is not found in the array. Demonstrate the function in a driver program.

#include <iostream>
#include <limits>

using std::cout;
using std::cin;
using std::numeric_limits;
using std::streamsize;

template<class T>
void showArray(T[], const int);

template<class T>
bool isMember(T[], T, int);

int main() {

	cout << "==============================\n";
	cout << "20-08 isMember FUNCTION DRIVER\n";
	cout << "==============================\n";
	cout << "\n";

	const int SIZE = 5;
	int value_int;
	char value_char;

	int list_int[SIZE]{ 3,8,0,1,5 };
	char list_char[SIZE]{ 'g', 'e', 's', 'k', 'c' };

	cout << "Enter an integer to find within the array: ";

	cin >> value_int;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "\n";

	if (isMember(list_int, value_int, SIZE)) {
		cout << value_int << " IS within the array.\n";
	}
	else {
		cout << value_int << " IS NOT within the array.\n";
	}

	showArray(list_int, SIZE);

	cout << "Enter a char to find within the array: ";

	cin >> value_char;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "\n";

	if (isMember(list_char, value_char, SIZE)) {
		cout << "\'" << value_char << "\' IS within the array.\n";
	}
	else {
		cout << "\'" << value_char << "\' IS NOT within the array.\n";
	}

	showArray(list_char, SIZE);

	cout << "Ending the program...\n";

}

template<class T>
void showArray(T set[], const int SIZE) {

	cout << "Array: ";

	for (int i = 0; i < SIZE; i++) {
		cout << set[i] << " ";
	}

	cout << "\n";
	cout << "\n";

}

template<class T>
bool isMember(T set[], T value, int size) {

	size--;

	if (set[size] == value) {
		return true;
	}
	else if (set[size] != value && size > 0) {
		return isMember(set, value, size);
	}
	else {
		return false;
	}

}