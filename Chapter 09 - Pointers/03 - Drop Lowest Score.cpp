#include <iostream>

using namespace std;

double inputValidation(double);
int inputValidation(int);
double* allocateMemory(int&);
void enterTestScores(double *, int);
void sortTestScores(double*, int);
void swap_double(double&, double&);
void showTestScores(double*, int, double, double);
double getAverage(double*, int, double);

int main() {

	int test_scores;
	double average;
	double lowest_score;
	double* ptr = allocateMemory(test_scores);

	enterTestScores(ptr, test_scores);
	sortTestScores(ptr, test_scores);
	lowest_score = *(ptr + (test_scores - 1));
	average = getAverage(ptr, test_scores, lowest_score);

	showTestScores(ptr, test_scores, average, lowest_score);

	delete[] ptr;
	ptr = nullptr;

}

double inputValidation(double limit) {

	double num;

	while (!(cin >> num) || num < limit) {
		cout << "ERROR: Value must be an integer greater than" << limit << "Re-enter your value: ";
		cin.clear();
		cin.ignore(1200, '\n');
	}

	return num;

}

int inputValidation(int limit) {

	int num;

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
		num = inputValidation(0.00);
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

void showTestScores(double* ptr, int size, double average, double lowest_score) {

	cout << "TEST SCORES: " << endl;
	cout << "------------------" << endl << endl;

	for (int i = 0; i < size; i++) {

		if (i == size - 1) {
			cout << "Lowest test score #" << i + 1 << ": " << *(ptr + i) << " DROPPED FROM AVERAGE! " << endl;
		}
		else {
			cout << "Test score #" << i + 1 << ": " << *(ptr + i) << endl;
		}

	}

	cout << endl;

	cout << "The average score (excluding the lowest) is " << average << endl;

}

double getAverage(double* ptr, int size, double lowest_score) {

	double total = 0;

	for (int i = 0; i < size; i++) {
		total += *(ptr + i);
	}

	cout << lowest_score << " was the lowest and will be dropped from the average." << endl << endl;

	total -= lowest_score;
	size -= 1;

	return total / static_cast<double>(size);
		 
}






