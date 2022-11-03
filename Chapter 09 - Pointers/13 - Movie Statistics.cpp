#include <iostream>
#include <string>

using namespace std;

int intValidation(int);
int* allocateMemory(int);
void enterMovies(int*, int);
void showArray(string, int*, int);
void sortArray(int*, int);
void swap_int(int&, int&);
double findAverage(int*, int);
double findMedian(int*, int);
int findMode(int*, int);

int main() {

	int students, mode;
	double average, median;

	int* movies_per_student_array = nullptr;

	cout << "Enter the number of students surveyed: ";
	students = intValidation(0);

	movies_per_student_array = allocateMemory(students);

	enterMovies(movies_per_student_array, students);
	cout << endl;

	showArray("Original array", movies_per_student_array, students);

	sortArray(movies_per_student_array, students);

	showArray("Sorted array", movies_per_student_array, students);

	average = findAverage(movies_per_student_array, students);
	median = findMedian(movies_per_student_array, students);
	mode = findMode(movies_per_student_array, students);
	
	cout << "Average number of movies watched: " << average << endl;
	cout << "Median number of movies watched: " << median << endl;
	cout << "Mode number of movies watched: " << mode << endl;

	cout << endl;

	delete[] movies_per_student_array;
	movies_per_student_array = nullptr;

}

int intValidation(int limit) {

	int num;

	while (!(cin >> num) || num < limit) {
		cout << "ERROR: Value must be an integer greater than " << limit << ". Re-enter the value: ";
		cin.clear();
		cin.ignore(1200, '\n');
	}

	return num;

}

int* allocateMemory(int size) {

	return new int[size];

}

void enterMovies(int* ptr, int size) {

	for (int i = 0; i < size; i++) {

		cout << "Number of movies watched by student #" << i + 1 << ": ";
		cin.clear();
		cin.ignore(1200, '\n');
		*(ptr + i) = intValidation(0);

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

		min_value = *(ptr + start);
		min_index = start;
		bool new_low = false;

		for (int index = start + 1; index < size; index++) {

			if (*(ptr + index) < min_value) {
				new_low = true;
				min_value = *(ptr + index);
				min_index = index;
			}

		}

		if (new_low) {
			swap_int(*(ptr + min_index), *(ptr + start));
		}

	}

}

void swap_int(int& a, int& b) {

	int temp;
	temp = a;
	a = b; 
	b = temp;

}

double findAverage(int* ptr, int size) {

	int total = 0;

	for (int i = 0; i < size; i++) {
		total += *(ptr + i);
	}

	return static_cast<double>(total) / static_cast<double>(size);
}

double findMedian(int* ptr, int size) {

	double median;

	if (size % 2 == 0) {

		int middle_1, middle_2;

		middle_1 = (size / 2) - 1;
		middle_2 = size / 2;

		median = (*(ptr + middle_1) + *(ptr + middle_2)) / static_cast<double>(2);

		return median;

	}
	else {
		
		int middle = size / 2;
		median = *(ptr + middle);
		return median;

	}

}

int findMode(int* ptr, int size) {

	int count, max_count = 0, mode_index = 0;

	for (int i = 0; i < size; i++) {

		count = 0;

		for (int j = i; j < size; j++) {
			if (*(ptr + i) == *(ptr + j)) {
				count++;
			}
		}

		if (count > max_count) {
			max_count = count;
			mode_index = i;
		}

	}

	return *(ptr + mode_index);

}