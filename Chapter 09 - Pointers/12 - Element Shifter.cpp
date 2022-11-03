#include <iostream>
#include <string>

using namespace std;

void showArray(string, int*, int);
int* shiftedArray(int[], int);

int main() {

	const int		SIZE{ 5 };

	int				original_array[SIZE]{ 34,78,456,20,1 };
	int*			shifted_array = nullptr;


	showArray("Original array", original_array, SIZE);

	shifted_array = shiftedArray(original_array, SIZE);

	showArray("Shifted array", shifted_array, SIZE + 1);

	delete[] shifted_array;
	shifted_array = nullptr;

}

void showArray(string name, int* ptr, int size) {

	cout << name << ": " << endl;

	for (int i = 0; i < size; i++) {
		cout << *(ptr + i) << " ";
	}

	cout << endl << endl;

}

int* shiftedArray (int array[], int size) {

	int* shifted_array = nullptr;
	shifted_array = new int[size + 1];

	

	for (int i = 0; i < size + 1; i++) {

		if (i == 0) {
			*(shifted_array + i) = 0;
		}
		else {
			*(shifted_array + i) = array[i - 1];
		}

	}

	return shifted_array;

}