#include <iostream>

using namespace std;

int inputValidation();
int linearSearch(int[], int, int, int&);
int binarySearch(int[], int, int, int&);
void displayArray(int[], int);
void sortArray(int[], int);
void swap(int&, int&);
void result(int, int, int);

int main() {

	const int	SIZE{ 18 };
	int			list[SIZE]{ 5658845, 4520125, 7895122, 8777541, 8451277, 1302850,
							8080152, 4562555, 5552012, 5050552, 7825877, 1250255,
							1005231, 6545231, 3852085, 7576651, 7881200, 4581002 };

	int			charge_account_number, element, count{0};

	cout << "Please enter your charge account number: ";
	charge_account_number = inputValidation();

	cout << endl;

	displayArray(list, SIZE);
	element = linearSearch(list, SIZE, charge_account_number, count);
	result(element, charge_account_number, count);

	sortArray(list, SIZE);
	displayArray(list, SIZE);
	element = binarySearch(list, SIZE, charge_account_number, count);
	result(element, charge_account_number, count);

}

int inputValidation() {

	int num;

	while (!(cin >> num)) {
		cout << "ERROR: Value must be an integer. Re-enter your value: ";
		cin.clear();
		cin.ignore(1200, '\n');
	}

	return num;

}

void displayArray(int array[], int size) {

	for (int i = 0; i < size; i++) {
		if (i == size - 1) {
			cout << array[i] << endl;
		}
		else {
			cout << array[i] << " ";
		}
	}

	cout << endl << endl;

}

int linearSearch(int array[], int size, int search_value, int& count) {

	int element = -1;
	count = 0;

	for (int i = 0; i < size; i++) {
		
		count++;

		if (array[i] == search_value) {
			element = i;
			return element;
		}

	}

	return element;

}

int binarySearch(int array[], int size, int search_value, int& count) {

	int first = 0, last = size - 1, middle;
	int element = -1;
	count = 0;

	while (element == -1 && first <= last) {

		middle = (first + last) / 2;

		count++;

		if (array[middle] == search_value) {
			element = middle;
		}
		else if (array[middle] > search_value) {
			last = middle - 1;
		}
		else {
			first = middle + 1;
		}

	}

	return element;

}

void sortArray(int array[], int size) {

	int minValue, minIndex;

	for (int start = 0; start < size - 1; start++) {
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

void result(int element, int number, int count) {

	cout << "Loop count: " << count << endl;

	if (element != -1) {
		cout << number << " IS a valid charge acount number." << endl << endl;
	}
	else {
		cout << number << " is NOT a valid charge acount number." << endl << endl;
	}

}

void swap(int& a, int& b) {

	int temp;
	temp = a;
	a = b;
	b = temp;

}