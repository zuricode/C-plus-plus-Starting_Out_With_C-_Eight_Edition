#include <iostream>

using namespace std;

// Variables

const int			ARRAY_LENGTH{ 10 };


// Functions Declarations

int inputValidation(int);
void getArrayValues(int[]);
int findMinValue(int[]);
int findMaxValue(int[]);
void minmaxReport(int[]);

int main() {

	int array_numbers[ARRAY_LENGTH],
		num{},
		min{},
		max{};

	getArrayValues(array_numbers);
	min = findMinValue(array_numbers);
	max = findMaxValue(array_numbers);

	cout << "\nThe smallest number in the array is " << min << ".";
	cout << "\nThe largest number in the array is " << max << ".";

	cout << endl;

}

// Functions Definitions

int inputValidation(int num) {

	while (!(cin >> num)) {
		cout << "ERROR: Value has to be an integer. Re-enter your value: ";
		cin.clear();
		cin.ignore(1200, '\n');
	}

	return num;

}

void getArrayValues(int list[]) {

	int num{};

	for (int i = 0; i < ARRAY_LENGTH; i++) {
		cout << "Enter number for value #" << i + 1 << ": ";
		num = inputValidation(num);
		list[i] = num;
	}

}

int findMinValue(int list[]) {

	int min;

	for (int i = 0; i < ARRAY_LENGTH; i++) {

		if (i == 0) {
			min = list[i];
		}

		else if (list[i] < min) {
			min = list[i];
		}
			
	}

	return min;

}

int findMaxValue(int list[]) {

	int max;

	for (int i = 0; i < ARRAY_LENGTH; i++) {

		if (i == 0) {
			max = list[i];
		}

		else if (list[i] > max) {
			max = list[i];
		}

	}

	return max;

}

