#include <iostream>

using namespace std;

void selectionSort(int[], int);
void swap(int&, int&);
void displayArray(int[], int);

int main() {

	const int	SIZE{ 10 };
	int			list[SIZE]{ 45,3,7,1,98,-76,3459,0,-34534,42 };

	displayArray(list, SIZE);
	selectionSort(list, SIZE);
	displayArray(list, SIZE);
	

}

void selectionSort(int array[], int size) {

	int minIndex, minValue;

	for (int start = 0; start < (size - 1); start++) {
		minIndex = start;
		minValue = array[start];
		for (int index = start + 1; index < size; index++) {
			if (array[index] < minValue) {
				minValue = array[index];
				minIndex = index;
			}
		}
		swap(array[minIndex], array[start]);
	}

}

void swap(int& a, int& b) {

	int temp;
	temp = a;
	a = b;
	b = temp;

}

void displayArray(int array[], int size) {

	for (int i = 0; i < size; i++) {
		if (i == size - 1) {
			cout << array[i] << endl << endl;
		}
		else {
			cout << array[i] << " ";
		}
	}
}