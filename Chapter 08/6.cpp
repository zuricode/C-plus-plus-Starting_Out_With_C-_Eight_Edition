#include <iostream>
#include <string>

using namespace std;

void selectionSort(string[], int);
void swap_string(string&, string&);
void displayArray(string[], int);

int main() {

	const int NUM_NAMES{ 20 };

	string names[NUM_NAMES]{	"Collins, Bill", "Smith, Bart", "Allen, Jim", "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
						"Taylor, Terri", "Johnson, Jill", "Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
						"James, Jean", "Weaver, Jim", "Pore, Bob", "Rutherford, Greg", "Javens, Renee",
						"Harrison, Rose", "Setzer, Cathy", "Pike, Gordon", "Holland, Beth" };

	cout << "Array of names BEFORE sort function: " << endl << endl;

	displayArray(names, NUM_NAMES);

	selectionSort(names, NUM_NAMES);

	cout << "Array of names AFTER sort function: " << endl << endl;

	displayArray(names, NUM_NAMES);

}

void selectionSort(string array[], int size) {

	string min_value;
	int min_index;

	for (int start = 0; start < size - 1; start++) {

		min_value = array[start];
		min_index = start;

		for (int index = start + 1; index < size; index++) {

			if (array[index] < min_value) {
				min_value = array[index];
				min_index = index;
			}

		}

		swap_string(array[min_index], array[start]);

	}


}

void swap_string(string& a, string& b) {

	string temp;
	temp = a;
	a = b;
	b = temp;

}

void displayArray(string array[], int size) {

	for (int i = 0; i < size; i++) {
		cout << array[i] << endl;
	}

	cout << endl;

}