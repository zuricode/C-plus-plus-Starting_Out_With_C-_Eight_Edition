#include <iostream>

using namespace std;

const int		MAX_NUM{ 100 }, MIN_NUM{ 1 };

int* allocateMemory(int);
void generateNumbers(int*, int);
void showArray(string, int*, int);
void sortArray(int*, int);
void swapInt(int&, int&);
int* copyAndReverse(int*, int);

int main() {

	const int	SIZE{10};
	int* original_array = nullptr;
	int* reverse_array = nullptr;

	original_array = allocateMemory(SIZE);

	generateNumbers(original_array, SIZE);
	showArray("Original array", original_array, SIZE);

	reverse_array = copyAndReverse(original_array, SIZE);
	showArray("Reversed array", reverse_array, SIZE);

		delete[] original_array;
	original_array = nullptr;

	delete[] reverse_array;
	reverse_array = nullptr;

}

int* allocateMemory(int size) {

	return new int[size];

}

void generateNumbers(int* ptr, int size) {

	srand(time(NULL));

	for (int i = 0; i < size; i++) {
		*(ptr + i) = rand() % MAX_NUM + MIN_NUM;
	}

}

void showArray(string name, int* ptr, int size) {

	cout << name << ": " << endl;

	for (int i = 0; i < size; i++) {
		cout << *(ptr + i) << " ";
	}

	cout << endl << endl;

}

void sortArray(int* ptr, int size) {

	int min_index, min_value;

	for (int start = 0; start < size - 1; start++) {

		min_index = start;
		min_value = *(ptr + start);

		for (int index = start; index < size; index++) {
			if (*(ptr + index) < min_value) {
				min_value = *(ptr + index);
				min_index = index;
			}
		}

		swapInt(*(ptr + start), *(ptr + min_index));

	}

}

void swapInt(int& a, int& b) {

	int temp;
	temp = a;
	a = b;
	b = temp;

}

int* copyAndReverse(int* ptr, int size) {

	int* reverse_ptr = nullptr;
	int j = 0;

	reverse_ptr = allocateMemory(size);

	for (int i = size - 1; i > -1; i--) {
		*(reverse_ptr + j) = *(ptr + i);
		j++;
	}

	return reverse_ptr;



}