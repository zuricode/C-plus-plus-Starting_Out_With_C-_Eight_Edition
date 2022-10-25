#include <iostream>

using namespace std;

int inputValidation(int);
double* allocateMemory(int&);
void enterTestScores(double *, int);
void sortTestScores(double*, int);
void swap_double(double&, double&);
void showTestScores(double*, int, double);
double getAverage(double*, int);

int main() {

	int test_scores;
	double average;
	double* ptr = allocateMemory(test_scores);

	enterTestScores(ptr, test_scores);
	sortTestScores(ptr, test_scores);
	average = getAverage(ptr, test_scores);

	showTestScores(ptr, test_scores, average);

	delete[] ptr;
	ptr = nullptr;

}

int inputValidation(int limit) {

	double num;

	while (!(cin >> num) || num < limit) {
		cout << "ERROR: Value must be an integer greater than" << limit << "Re-enter your value: ";
		cin.clear();
		cin.ignore(1200, '\n');
	}

	return num;

}

double* allocateMemory(int& test_scores) {

	cout << "How many test scores would you like to collect? ";

	test_scores = inputValidation(0);

	cout << "Memory has been allocated for " << test_scores << " test scores." << endl << endl;

	return new double[test_scores];	

}

void enterTestScores(double* ptr, int size) {

	double num;

	for (int i = 0; i < size; i++) {

		cout << "Enter test score #" << i + 1 << ": ";
		num = inputValidation(0);
		*(ptr + i) = num;

	}

	cout << endl;

}

void sortTestScores(double* ptr, int size) {

	double max_value;
	int max_index;

	for (int start = 0; start < size - 1; start++) {
		max_index = start;
		max_value = *(ptr + start);
		for (int index = start + 1; index < size; index++) {
			if (*(ptr + index) > max_value) {
				max_value = *(ptr + index);
				max_index = index;
			}
		}

		swap_double(*(ptr + start), *(ptr + max_index));

	}


}

void swap_double(double& a, double& b) {

	double temp;
	temp = a;
	a = b;
	b = temp;

}

void showTestScores(double* ptr, int size, double average) {

	cout << "TEST SCORES: " << endl;
	cout << "------------------" << endl << endl;

	for (int i = 0; i < size; i++) {

		cout << "Test score #" << i + 1 << ": " << *(ptr + i) << endl;

	}

	cout << endl;

	cout << "The average score from " << size << " tests is " << average << endl;

}

double getAverage(double* ptr, int size) {

	double total = 0;

	for (int i = 0; i < size; i++) {
		total += *(ptr + i);
	}

	return total / size;
		 
}






