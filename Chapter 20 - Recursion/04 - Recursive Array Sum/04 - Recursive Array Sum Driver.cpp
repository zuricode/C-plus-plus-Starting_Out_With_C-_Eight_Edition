//4. Recursive Array Sum
//
//Write a function that accepts an array of integers and a number indicating the number of elements
//as arguments. The function should recursively calculate the sum of all the numbers in the array.
//Demonstrate the function in a driver program.
//

#include <iostream>

using std::cout;

int recursiveAdd(int[], int);

int main() {

	cout << "=========================\n";
	cout << "20-04 RECURSIVE ARRAY SUM\n";
	cout << "=========================\n";
	cout << "\n";

	const int SIZE = 5;
	int total;

	int numbers[SIZE]{ 10, 20, 30, 40, 50};

	cout << "List of numbers: ";

	for (int i = 0; i < SIZE; i++) {
		cout << numbers[i] << " ";
	}

	cout << "\n";
	cout << "\n";

	total = recursiveAdd(numbers, SIZE);

	cout << "The sum of all numbers in the array is " << total << ".\n";

	cout << "\n";
	cout << "Ending the program...\n";

	return 0;

}

int recursiveAdd(int numbers[], int size) {

	size--;

	if (size >= 0) {
		return numbers[size] + recursiveAdd(numbers, size);
	} else {
		return 0;
	}

}
