#include <iostream>

using namespace std;

int inputValidation();
void sortArray(int[], int);
void swap_int(int&, int&);
bool linearSearch(int[], int, int, int&);
bool binarySearch(int[], int, int, int&);
void searchResult(int, bool, int);

int main() {

	const int	ARRAY_SIZE{ 20 };
	int user_number, linear_count = 0, binary_count = 0;
	int			numbers[ARRAY_SIZE]{34,7,9,11,23,569,8,3,45,567,
									9564,1231245,464,342,1, -345,-456,-23,-67,-2145};

	bool linear_result, binary_result;

	user_number = inputValidation();

	sortArray(numbers, ARRAY_SIZE);

	binary_result = binarySearch(numbers, user_number, ARRAY_SIZE, binary_count);
	searchResult(user_number, binary_result, binary_count);

	linear_result = linearSearch(numbers, user_number, ARRAY_SIZE, linear_count);
	searchResult(user_number, linear_result, linear_count);

}

int inputValidation() {

	int num;

	cout << "Please enter your chosen number: ";

	while (!(cin >> num)) {
		cout << "ERROR: This value must be an integer. Re-enter your value: ";
		cin.clear();
		cin.ignore(1200, '\n');
	}

	cout << endl;

	return num;

}

bool linearSearch(int array[], int num, int size, int& count) {

	bool found = false;
	int i = 0;

	while (!found && i < size) {

		count++;

		if (num == array[i])
			found = true;

		else
			i++;

	}

	return found;

}

bool binarySearch(int array[], int num, int size, int& count) {

	int first = 0, last = size - 1, middle;
	bool found = false;

	while (!found && first <= last) {

		count++;

		middle = (first + last) / 2;

		if (num == array[middle])
			found = true;

		else if (num < array[middle])
			last = middle - 1;

		else if (num > array[middle])
			first = middle + 1;

	}

	return found;

}

void searchResult(int num, bool result, int count) {

	if (result)
		cout << num << " IS a number within the array." << endl;
	else
		cout << num << " is NOT a number within the array." << endl;

	cout << "Loop iterations: " << count << endl;

	cout << endl;

}

void sortArray(int array[], int size) {

	int min_value, min_index;

	for (int start = 0; start < size; start++) {

		min_value = array[start];
		min_index = start;

		for (int index = start + 1; index < size; index++) {
			if (array[index] < min_value) {
				min_value = array[index];
				min_index = index;
			}
		}

		swap_int(array[start], array[min_index]);

	}

}

void swap_int(int& a, int& b) {

	int temp;
	temp = a;
	a = b; 
	b = temp;

}