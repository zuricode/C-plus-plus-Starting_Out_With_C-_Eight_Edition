#include <iostream>
#include <string>

using namespace std;

int* expandArray(int[], int);
void showArray(string, int[], int);

int main() {

	const int	SIZE{ 5 };

	int			original_array[SIZE]{ 4,78,4,-54,67 };
	int*		expanded_array = nullptr;

	showArray("Original array", original_array, SIZE);

	expanded_array = expandArray(original_array, SIZE);

	showArray("Expanded array", expanded_array, SIZE * 2);

	delete[] expanded_array;
	expanded_array = nullptr;

}

int* expandArray(int original[], int size) {

	int* expanded_array = nullptr;
	expanded_array = new int[size * 2];

		for (int i = 0; i < size * 2; i++) {

			if (i >= size) {
				*(expanded_array + i) = 0;
			}
			else {
				*(expanded_array + i) = original[i];
			}

		}

	return expanded_array;


}

void showArray(string name, int* ptr, int size) {

	cout << name << ": " << endl;

	for (int i = 0; i < size; i++) {
		cout << *(ptr + i) << " ";
	}

	cout << endl << endl;

}