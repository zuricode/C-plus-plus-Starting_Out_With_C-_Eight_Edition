#include <iostream>

using namespace std;

void bubbleSortArray(int[], int, int&);
void selectionSortArray(int[], int, int&);
void swap_int(int&, int&);
void displayArray(int[], int);

int main() {

	const int	SIZE{ 20 };
	int			list_1[SIZE]{ 5,8,7,3,1,-2,-7,-9,56,43,67,-34,45,-98,123,678,-345,99,45,6 }, list_2[SIZE]{ 5,8,7,3,1,-2,-7,-9,56,43,67,-34,45,-98,123,678,-345,99,45,6 }, count{ 0 };

	cout << "List (BEFORE sorting): ";
	displayArray(list_1, SIZE);

	cout << "------------------------------------------" << endl << endl;

	bubbleSortArray(list_1, SIZE, count);
	cout << "List #1 (AFTER bubble sorting): ";
	displayArray(list_1, SIZE);
	cout << "Loop iterations: " << count << endl << endl;

	count = 0;
	selectionSortArray(list_2, SIZE, count);
	cout << "List #2 (AFTER selection sorting): ";
	displayArray(list_2, SIZE);
	cout << "Loop iterations: " << count << endl;

}

void bubbleSortArray(int array[], int size, int& count) {

	bool repeat;

	do {
		repeat = false;
		for (int i = 1; i < size; i++) {
			if (array[i] < array[i - 1]) {
				swap_int(array[i], array[i - 1]);
				repeat = true;
				count++;
			}
		} 
	} while (repeat);	

}

void selectionSortArray(int array[], int size, int& count) {

	int min_index, min_value;
	count = 0;

	for (int start = 0; start < size - 1; start++) {

		min_index = start;
		min_value = array[start];

		for (int index = start + 1; index < size; index++) {

			if (array[index] < min_value) {
				min_value = array[index];
				min_index = index;
			}

		}

		swap_int(array[start], array[min_index]);
		count++;

	}

}

void swap_int(int& a, int& b) {

	int temp;
	temp = a;
	a = b;
	b = temp;

}

void displayArray(int array[], int size) {

	for (int i = 0; i < size; i++) {

		if (i != size - 1) {
			cout << array[i] << ", ";
		}
		else {
			cout << array[i] << endl;
		}

	}

}