#include <iostream>

using namespace std;

int intValidation(int);
void enterNumberOfElements(int&);
int* allocateMemory(int);
void generateRandomNumbers(int*, int);
int findMode(int*, int);
void showArray(int*, int);
void showMode(int);

int main() {

	int number_of_elements;
	int* mode_array = nullptr;
	int mode;

	enterNumberOfElements(number_of_elements);

	mode_array = allocateMemory(number_of_elements);

	generateRandomNumbers(mode_array, number_of_elements);

	showArray(mode_array, number_of_elements);

	mode = findMode(mode_array, number_of_elements);

	showMode(mode);

	delete[] mode_array;
	mode_array = nullptr;

}

int intValidation(int limit) {

	int num;

	while (!(cin >> num) || num < limit) {
		cout << "ERROR: Value must be an integer greater than " << limit << ".Re - enter your value : ";
		cin.clear();
		cin.ignore(1200, '\n');
	}

	return num;

}

void enterNumberOfElements(int& elements) {

	cout << "Enter the amount of numbers your array: ";

	elements = intValidation(3);

	cout << endl;

}

int* allocateMemory(int size) {

	return new int[size];

}

void generateRandomNumbers(int* ptr, int size) {

	srand(time(NULL));

	for (int i = 0; i < size; i++) {
		*(ptr + i) = rand() % 100 + 1;
	}

}

int findMode(int* ptr, int size) {

	int count;
	int	highest_count = 2, mode = -1;
	
	for (int start = 0; start < size; start++) {
		
		count = 0;
		
		for (int index = 0; index < size; index++) {
			if (*(ptr + start) == *(ptr + index)) {
				count++;
			}
		}

		if (count >= highest_count) {
			highest_count = count;
			mode = *(ptr + start);
		}

	}
	
	return mode;

}

void showArray(int* ptr, int size) {

	for (int i = 0; i < size; i++) {
		cout << *(ptr + i) << endl;
	}

	cout << endl;

}

void showMode(int mode) {

	if (mode != -1) {
		cout << "Mode of the array is: " << mode << endl;
	}
	else {
		cout << "There is no mode is this array." << endl;
	}

	cout << endl;

}