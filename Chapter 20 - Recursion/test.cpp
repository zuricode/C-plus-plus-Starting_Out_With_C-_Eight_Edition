#include <iostream>

using std::cout;
using std::cin;

int largestNumber(int[], int, const int, int&);

int main() {

	const int SIZE = 15;
	int highest;

	int numbers[SIZE] = { 317,756,3,8002,5,1,12,5,3123,654,876,213,5435,645,123 };

	cout << "List of numbers: ";

	for (int i = 0; i < SIZE; i++) {
		cout << numbers[i] << " ";
	}

	cout << "\n";

	cout << "The largest number in the array is " << largestNumber(numbers, 0, SIZE, highest) << "\n";
	cout << "\n";

	cout << "Ending the program...\n";

}

int largestNumber(int list[], int current_sub, const int SIZE, int& highest) {

	if (current_sub == 0) {
		highest = list[0];
	}

	if (current_sub >= SIZE) {
		return highest;
	}

	else {

		if (list[current_sub] > highest) {
			highest = list[current_sub];
		}

		largestNumber(list, ++current_sub, SIZE, highest);

	}

}
