#include <iostream> 

using namespace std;

void displayArray(int[], int);
void bubbleSortArray(int[], int);
void selectionSortArray(int[], int);
void swap_int(int&, int&);

int main() {

	const int			SIZE{ 8 };

	int					list_1[SIZE]{ 3,8,9,34,27,856,2,-87 },
						list_2[SIZE]{ 3,8,9,34,27,856,2,-87 };
	
	cout << "BUBBLE SORT FUNCTION: " << endl << endl;
	cout << "List #1 original: ";
	displayArray(list_1, SIZE);
	bubbleSortArray(list_1, SIZE);

	cout << endl;
	cout << "-----------------------" << endl << endl;

	cout << "SELECTION SORT FUNCTION: " << endl << endl;
	cout << "List #1 original: ";
	displayArray(list_2, SIZE);
	selectionSortArray(list_2, SIZE);






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

void bubbleSortArray(int array[], int size) {

	bool repeat;
	int count = 0;

	do {
		repeat = false;
		count++;

		for (int i = 1; i < size; i++) {
			if (array[i] < array[i - 1]) {
				swap_int(array[i], array[i - 1]);
				repeat = true;
				break;
			}
		}

		if (repeat) {
			cout << "List iteration #" << count << ": ";
			displayArray(array, size);
		}
		

	} while (repeat);

}

void selectionSortArray(int array[], int size) {

	int min_index, min_value, count = 0;
	bool swap;

	for (int start = 0; start < size - 1; start++) {

		swap = false;
		min_value = array[start];
		min_index = start;

		for (int index = start + 1; index < size; index++) {

			if (array[index] < min_value) {
				min_value = array[index];
				min_index = index;
				swap = true;
			}

		}

		if (swap) {
			count++;
			swap_int(array[start], array[min_index]);
			cout << "List iteration #" << count << ": ";
			displayArray(array, size);
		}
		

	}

}

void swap_int(int& a, int& b) {

	int temp;
	temp = a;
	a = b;
	b = temp;

}