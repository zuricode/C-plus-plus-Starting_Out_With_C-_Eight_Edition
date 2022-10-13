#include <iostream>

using namespace std;

void displayArray(int[], int);
void swap(int&, int&);
void sortArray(int[], int);

int main() {

	const int			SIZE{ 15};
	int					list[SIZE]{ 34,67,21,45,63,4564,2,45,12,6594, -56675, -567, 5675636, 10, 999 };

	displayArray(list, SIZE);
	sortArray(list, SIZE);
	displayArray(list, SIZE);


}

void displayArray(int array[], int size) {

	cout << "List of numbers: ";

	for (int i = 0; i < size; i++) {

		if (i != size - 1) {
			cout << array[i] << " ";
		}
		else {
			cout << array[i] << endl;
		}

	}

	cout << endl;

}

void sortArray(int array[], int size) {

	int min_index, min_value;

	for (int start = 0; start < size - 1; start++) {

		min_value = array[start];
		min_index = start;

		for (int index = start + 1; index < size; index++) {

			if (array[index] < min_value) {
				min_index = index;
				min_value = array[index];
			}

		}

		swap(array[min_index], array[start]);


	}

}

void swap(int& a, int& b) {

	int temp;
	temp = a;
	a = b;
	b = temp;

}