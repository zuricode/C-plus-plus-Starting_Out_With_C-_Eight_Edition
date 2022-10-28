#include <iostream>
#include <string>

using namespace std;

double inputValidation(double);
int inputValidation(int);
double* allocateMemory(int&);
string* allocateNameMemory(int);
void enterTestScores(string*, double *, int);
void sortTestScores(string*, double*, int);
void swap_string(string&, string&);
void swap_double(double&, double&);
void showTestScores(string*, double*, int, double, double);
double getAverage(double*, int, double);

int main() {

	int test_scores;
	double average;
	double lowest_score;
	string lowest_name;
	double* scores = nullptr;
	scores = allocateMemory(test_scores);
	string* names = nullptr;
	names = allocateNameMemory(test_scores);

	cout << endl;

	enterTestScores(names, scores, test_scores);
	sortTestScores(names, scores, test_scores);
	lowest_score = *(scores + 0);
	lowest_name = *(names + + 0);

	average = getAverage(scores, test_scores, lowest_score);

	showTestScores(names, scores, test_scores, average, lowest_score);

	delete[] scores;
	delete[] names;
	scores = nullptr;
	names = nullptr;

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

	cout << "Memory has been allocated for " << test_scores << " test scores." << endl;

	return new double[test_scores];	

}

string* allocateNameMemory(int test_scores) {

	cout << "Memory has been allocated for " << test_scores << " names." << endl;

	return new string[test_scores];

}

void enterTestScores(string* names, double* scores, int size) {

	double num;

	for (int i = 0; i < size; i++) {

		cin.clear();
		cin.ignore(1200, '\n');

		cout << "Enter name of student #" << i + 1 << ": ";
		getline(cin, *(names + i));
		cout << "Enter " << *(names + i) << "'s test score: ";
		num = inputValidation(0.00);
		*(scores + i) = num;

		cout << endl;

	}

	cout << endl;

}

void sortTestScores(string* names, double* scores, int size) {

	double min_value;
	int min_index;

	for (int start = 0; start < size - 1; start++) {
		min_index = start;
		min_value = *(scores + start);
		for (int index = start + 1; index < size; index++) {
			if (*(scores + index) < min_value) {
				min_value = *(scores + index);
				min_index = index;
			}
		}

		swap_double(*(scores + start), *(scores + min_index));
		swap_string(*(names + start), *(names + min_index));

	}

}

void swap_double(double& a, double& b) {

	double temp;
	temp = a;
	a = b;
	b = temp;

}

void swap_string(string& a, string& b) {

	string temp;
	temp = a;
	a = b;
	b = temp;

}

void showTestScores(string* names, double* scores, int size, double average, double lowest_score) {

	cout << "TEST SCORES: " << endl;
	cout << "------------------" << endl << endl;

	for (int i = 0; i < size; i++) {

		if (i == 0) {
			cout << "Lowest test score #" << i + 1 << " - " << *(names + i) << " : " << *(scores + i) << " DROPPED FROM AVERAGE! " << endl;
		}
		else {
			cout << "Test score #" << i + 1 << " - " << *(names + i) << " : " << *(scores + i) << endl;
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






