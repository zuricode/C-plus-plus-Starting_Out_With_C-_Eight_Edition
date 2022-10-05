#include <iostream>
#include <string>
#include <vector>

const int		STUDENTS{ 5 },
				TESTS{ 4 };

const char		GRADES[]{ 'A','B', 'C', 'D', 'F' };

using namespace std;

string inputName();
double inputGrade(int, int);
void nameAndGradeEntry(string[], double[][TESTS]);
void calculateAverage(double[][TESTS], vector<double>&);
void calculateGrade(vector<double>, vector<char>&);
void displayAverageAndGrade(string[], vector<double>, vector<char>);

int main() {

	double			test_results[STUDENTS][TESTS];
	string			student_names[STUDENTS];
	vector<double>	average_scores;
	vector<char>	grades;

	nameAndGradeEntry(student_names, test_results);
	calculateAverage(test_results, average_scores);
	calculateGrade(average_scores, grades);
	displayAverageAndGrade(student_names, average_scores, grades);

}

string inputName() {

	string name;

	while (!(cin >> name)) {
		cout << "ERROR: Value must be a string. Try again: ";
		cin.clear();
		cin.ignore(1200, '\n');
	}

	return name;

}

double inputGrade(int lower_limit, int upper_limit) {

	double grade;

	while (!(cin >> grade) || (grade < lower_limit || grade > upper_limit)) {
		cout << "ERROR: Value must be a double greater than " << lower_limit << " but lower than " << upper_limit << ". Re-enter your value: ";
		cin.clear();
		cin.ignore(1200, '\n');
	}

	return grade;

}

void nameAndGradeEntry(string array[], double grades[][TESTS]) {

	for (int i = 0; i < STUDENTS; i++) {
		cout << "Name of student #" << i + 1 << ": ";
		array[i] = inputName();
		for (int j = 0; j < TESTS; j++) {
			cout << "Score #" << j + 1 << ": ";
			grades[i][j] = inputGrade(0, 100);
		}
		cout << endl;
	}

}

void calculateAverage(double array[][TESTS], vector<double>& scores) {

	double total;
	double average;

	for (int i = 0; i < STUDENTS; i++) {
		total = 0;
		for (int j = 0; j < TESTS; j++) {
			total += array[i][j];
		}
		average = total / static_cast<double>(TESTS);
		scores.push_back(average);
	}

}

void calculateGrade(vector<double> scores, vector<char>& grades) {

	for (int i = 0; i < STUDENTS; i++) {

			if (scores[i] >= 90) {
				grades.push_back('A');
			}
			if (scores[i] >= 80 && scores[i] <= 89) {
				grades.push_back('B');
			}
			if (scores[i] >= 70 && scores[i] <= 79) {
				grades.push_back('C');
			}
			if (scores[i] >= 60 && scores[i] <= 69) {
				grades.push_back('D');
			}
			if (scores[i] >= 0 && scores[i] <= 59) {
				grades.push_back('F');
			}

	}

}

void displayAverageAndGrade(string array[], vector<double> averages, vector<char> grades) {

	cout << "TEST RESULTS (average of " << TESTS << " tests): " << endl;
	cout << "-----------------" << endl;
	cout << endl;
	for (int i = 0; i < STUDENTS; i++) {
		cout << array[i] << ": " << averages[i] << "\tGrade: " << grades[i] << endl;
	}

}