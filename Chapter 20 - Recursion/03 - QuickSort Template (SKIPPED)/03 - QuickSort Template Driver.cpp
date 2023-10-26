//3. QuickSort Template
//
//Create a template version of the QuickSort algorithm that will work with any data type.
//Demonstrate the template with a driver function.

#include <iostream>

using std::cout;

void quickSort(int[], int, int);
int partition(int[], int, int);
void swap(int&, int&);

int main() {

	cout << "===============================\n";
	cout << "20-03 QUICKSORT TEMPLATE DRIVER\n";
	cout << "===============================\n";
	cout << "\n";

	const int SIZE = 10;

	int numbers[SIZE]{ 2,8,5,1,4,6,7,0,9,3 };

	cout << "List of numbers: ";

	for (int i = 0; i < SIZE; i++) {
		cout << numbers[i] << " ";
	}

	cout << "\n";
	cout << "\n";

	quickSort(numbers, 0, SIZE - 1);

	cout << "List of numbers: ";

	for (int i = 0; i < SIZE; i++) {
		cout << numbers[i] << " ";
	}

	cout << "\n";
	cout << "\n";	

	cout << "Ending the program...\n";

}

void quickSort(int set[], int start, int end) {

	int pivotPoint;

	if (start < end) {

		pivotPoint = partition(set, start, end);
		quickSort(set, start, pivotPoint - 1);
		quickSort(set, pivotPoint + 1, end);

	}

}

int partition(int set[], int start, int end) {

	int pivotValue, pivotIndex, mid;

	mid = (start + end) / 2;
	swap(set[start], set[end]);
	pivotIndex = start;
	pivotValue = set[start];

	for (int scan = start + 1; scan <= end; scan++) {

		if (set[scan] < pivotValue) {

			pivotIndex++;
			swap(set[pivotIndex], set[scan]);

		}

	}

	swap(set[start], set[pivotIndex]);

	return pivotIndex;

}

void swap(int& value1, int& value2) {

	int temp = value1;
	value1 = value2;
	value2 = temp;

}