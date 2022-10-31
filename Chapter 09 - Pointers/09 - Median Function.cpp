#include <iostream>

using namespace std;

int intValidation(int);
void enterNumberOfElements(int&);
int* allocateMemory(int);
void generateRandomNumbers(int*, int);
void sortArray(int*, int);
void swap_int(int&, int&);
double average(int, int);
double findMedian(int*, int);
void showArray(int*, int);
void showMedian(double);

int main() {

	int number_of_elements;
	int* median_array = nullptr;
	double median;

	enterNumberOfElements(number_of_elements);

	median_array = allocateMemory(number_of_elements);

	generateRandomNumbers(median_array, number_of_elements);

	showArray(median_array, number_of_elements);

	sortArray(median_array, number_of_elements);

	showArray(median_array, number_of_elements);

	median = findMedian(median_array, number_of_elements);

	showMedian(median);

	delete[] median_array;
	median_array = nullptr;

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

void sortArray(int* ptr, int size) {

	int min_index;
	int min_value;
	bool new_low;


	for (int start = 0; start < size - 1; start++) {

		new_low = false;
		min_value = *(ptr + start);

		for (int index = start + 1; index < size; index++) {
			if (*(ptr + index) < min_value) {
				new_low = true;
				min_value = *(ptr + index);
				min_index = index;
			}
		}
		if (new_low) {
			swap_int((*(ptr + start)), (*(ptr + min_index)));
		}
	}

}

void swap_int(int& a, int& b) {

	int temp;
	temp = a;
	a = b;
	b = temp;

}

double getAverage(int a, int b) {

	return static_cast<double>(a + b) / static_cast<double>(2);

}

double findMedian(int* ptr, int size) {

	int middle;
	double median;

	if (size % 2 == 0) {
		median = (static_cast<double>(*(ptr + (size / 2) - 1)) + static_cast<double>(*(ptr + (size / 2)))) / static_cast<double>(2);
		return median;
	}
	else {
		middle = size / 2;
		return *(ptr + middle);
	}

}

void showArray(int* ptr, int size) {

	for (int i = 0; i < size; i++) {
		cout << *(ptr + i) << endl;
	}

	cout << endl << endl;

}

void showMedian(double median) {

	cout << "Median of the array is: " << median << endl;
	
	cout << endl;

}