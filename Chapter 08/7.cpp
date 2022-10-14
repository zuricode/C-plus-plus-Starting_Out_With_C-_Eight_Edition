#include <iostream>
#include <string>

using namespace std;

void selectionSort(string[], int);
void swap_string(string&, string&);
void displayArray(string[], int);
bool binarySearch(string[], string, int, int&);
void searchResult(string, bool, int);

int main() {

	const int NUM_NAMES{ 20 };
	int	count{ 0 };
	bool found;
	string search_name = "Allison, Jeff";

	string names[NUM_NAMES]{	"Collins, Bill", "Smith, Bart", "Allen, Jim", "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
						"Taylor, Terri", "Johnson, Jill", "Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
						"James, Jean", "Weaver, Jim", "Pore, Bob", "Rutherford, Greg", "Javens, Renee",
						"Harrison, Rose", "Setzer, Cathy", "Pike, Gordon", "Holland, Beth" };

	cout << "Array of names BEFORE sort function: " << endl << endl;

	displayArray(names, NUM_NAMES);

	selectionSort(names, NUM_NAMES);

	cout << "Array of names AFTER sort function: " << endl << endl;

	displayArray(names, NUM_NAMES);

	found = binarySearch(names, search_name, NUM_NAMES, count);

	searchResult(search_name, found, count);

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

bool binarySearch(string array[], string name, int size, int& count) {

	int first = 0, last = size - 1;
	int middle;
	bool found = false;

	while (!found && first < last) {

		middle = (first + last) / 2;

		if (name == array[middle]) {
			found = true;
		}
		else if (name < array[middle]) {
			last = middle - 1;
		}
		else if (name > array[middle]) {
			first = middle + 1;
		}

		count++;

	}

	return found;

}

void searchResult(string name, bool found, int count) {

	if (found) {
		cout << name << " is a name within the directory." << endl;
	}
	else {
		cout << name << " could not be found within the directory." << endl;
	}

	cout << "Loop iterations: " << count << endl;

	cout << endl;

}