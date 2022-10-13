#include <iostream>

using namespace std;

void displayArray(int[], int);
void sortArray(int[], int);
void swap(int&, int&);

int main() {

	const int			SIZE{ 15 };
	int					list[SIZE]{ 56,4,8,32,345,2, -657, 5642, 1, 45, 6874, 34534734, -569874, -4563487, 564 };

	displayArray(list, SIZE);
	sortArray(list, SIZE);
	displayArray(list, SIZE);

}

void displayArray(int array[], int size) {

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

		min_index = start;
		min_value = array[start];		

		for (int index = start + 1; index < size; index++) {

			if (array[index] < min_value) {
				min_index = index;
				min_value = array[index];
			}

		}

	swap(array[start], array[min_index]);
	
	}

}

void swap(int& a, int& b) {

	int temp;
	temp = a;
	a = b;
	b = temp;

}