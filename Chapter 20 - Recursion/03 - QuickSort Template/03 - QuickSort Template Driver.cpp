//3. QuickSort Template
//
//Create a template version of the QuickSort algorithm that will work with any data type.
//Demonstrate the template with a driver function.

#include <iostream>
#include <string>

using std::cout;
using std::string;

template<class T>
void quickSort(T[], int, int);

template<class T>
int partition(T[], int, int);

template<class T>
void swap(T&, T&);

template<class T>
void showList(T[], const int, const string);

int main() {

	cout << "===============================\n";
	cout << "20-03 QUICKSORT TEMPLATE DRIVER\n";
	cout << "===============================\n";
	cout << "\n";

	const int SIZE = 10;

	int numbers[SIZE]{ 2,8,5,1,4,6,7,0,9,3 };
	char characters[SIZE]{ 'n', 's', 'e', 'y', 'a', 'b', 'n', 'e', 'l', 'z' };

	showList(numbers, SIZE, "Original list of numbers");
	showList(characters, SIZE, "Original list of characters");

	cout << "\n";

	quickSort(numbers, 0, SIZE - 1);
	quickSort(characters, 0, SIZE - 1);

	showList(numbers, SIZE, "Sorted list of numbers");
	showList(characters, SIZE, "Sorted list of characters");

	cout << "\n";

	cout << "Ending the program...\n";

}

template <class T>
void quickSort(T set[], int start, int end) {

	int pivotPoint;

	if (start < end) {

		pivotPoint = partition(set, start, end);
		quickSort(set, start, pivotPoint - 1);
		quickSort(set, pivotPoint + 1, end);

	}

}

template <class T>
int partition(T set[], int start, int end) {

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

template <class T>
void swap(T& value1, T& value2) {

	T temp = value1;
	value1 = value2;
	value2 = temp;

}

template <class T>
void showList(T set[], const int SIZE, const string DESCRIPTOR) {

	cout << DESCRIPTOR << ": ";

	for (int i = 0; i < SIZE; i++) {
		cout << set[i] << " ";
	}

	cout << "\n";

}