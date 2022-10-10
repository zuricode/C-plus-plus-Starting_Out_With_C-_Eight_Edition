#include <iostream>


using namespace std;

void sortHighToLow(int[], const int);
void swap(int&, int&);
void displayArray(int[], const int);
int  findElement(int[], const int, int, int&);

int main() {

	const int		SIZE{ 6 };
	int				list[SIZE]{ 3,7890769,9,5,12,765}, magic_number{ 7890769 };
	int				magic_element, loop_counter = 0;

	displayArray(list, SIZE);
	sortHighToLow(list, SIZE);
	displayArray(list, SIZE);

	magic_element = findElement(list, SIZE, magic_number, loop_counter);

	cout << "\"Magic number\" " << magic_number << " can be found at element " << magic_element << " of the list array. " << endl;
	cout << "This search ran the search loop " << loop_counter << " times." << endl << endl;

	return 0;

}

void sortHighToLow(int array[], const int SIZE) {

	for (int maxElement = SIZE - 1; maxElement > 0; maxElement--) {
		for (int index = 0; index < maxElement; index++) {
			if (array[index] > array[index + 1]) {
				swap(array[index], array[index + 1]);
			}

		}
	}

}

void swap(int& a, int& b) {

	int temp;

	temp = a;
	a = b;
	b = temp;

}

void displayArray(int array[], const int SIZE) {

	cout << "Array: ";

	for (int i = 0; i < SIZE; i++) {
		if (i == SIZE - 1) {
			cout << array[i] << endl << endl;
		}
		else {
			cout << array[i] << " ";

		}
	}

}

int findElement(int array[], const int SIZE, int magic_number, int& loop_counter) {

	int element = -1;
	int first = 0, last = SIZE - 1, middle;
	bool found = false;

	while (!found && first <= last) {

		middle = (first + last) / 2;

		if (magic_number == array[middle]) {
			element = middle;
			found = true;
		}
		else if (magic_number > array[middle]) {
			first = middle + 1;
		} 
		else if (magic_number < array[middle]) {
			last = middle + 1;
		}

		loop_counter++;

	}

	return element;

}