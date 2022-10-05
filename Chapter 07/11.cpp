#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>

const int		NUMBER_OF_QUESTIONS{ 20 },
				NUMBER_OF_ANSWERS{ 4 };

const double	PASS_PERCENTAGE{ 70.00 };

const char		POSSIBLE_ANSWERS[NUMBER_OF_ANSWERS]{ 'A', 'B', 'C', 'D' };

using namespace std;

void getInfoFromFile(char[], string);
void examReport(char[], char[], int, int, vector<int>, vector<int>, double);
double correctPercentage(int);
string passOrFail(double);

int main() {

	//Variables

	char			student_answers[NUMBER_OF_QUESTIONS],
					correct_answers[NUMBER_OF_QUESTIONS];

	int				correct_questions{ 0 },
					incorrect_questions{0};

	double			percentage{};
	
	vector<int>		correct_questions_list,
					incorrect_questions_list;

	getInfoFromFile(correct_answers, "C:\\Users\\Admin\\source\\repos\\Project2\\Project2\\Chapter 07\\CorrectAnswers.txt");
	getInfoFromFile(student_answers, "C:\\Users\\Admin\\source\\repos\\Project2\\Project2\\Chapter 07\\StudentAnswers.txt");


	for (int i = 0; i < NUMBER_OF_QUESTIONS; i++) {

		if (student_answers[i] == correct_answers[i]) {
			correct_questions++;
			correct_questions_list.push_back(i + 1);
		}
		else {
			incorrect_questions++;
			incorrect_questions_list.push_back(i + 1);
		}

	}

	examReport(student_answers, correct_answers, correct_questions, incorrect_questions, correct_questions_list, incorrect_questions_list, percentage);

	cout << endl;

}

void getInfoFromFile(char array[], string filename) {

	ifstream inputFile;

	inputFile.open(filename);

	if (inputFile.fail()) {
		cout << "Error opening " << filename << "." << endl;
	}

	for (int i = 0; i < NUMBER_OF_QUESTIONS; i++) {

		inputFile >> array[i];

	}

	inputFile.close();

}

void examReport(char student_answers[], char correct_answers[],
				int correct_questions, int incorrect_questions, vector<int> correct_questions_list,
				vector<int> incorrect_questions_list, double percentage) {

	cout << "EXAM REPORT: " << endl;
	cout << "---------------------------" << endl << endl;

	for (int i = 0; i < NUMBER_OF_QUESTIONS; i++) {

		cout << "#" << i + 1 << ":\tStudent answer: " << student_answers[i] << "\tCorrect answer: " << correct_answers[i] << endl;

	}

	cout << endl;

	cout << "Correct questions: " << correct_questions << " - ";

	for (int i = 0; i < correct_questions_list.size(); i++) {
		cout << "#" << correct_questions_list[i];
		if (i != correct_questions_list.size() - 1) {
			cout << ", ";
		}
	}

	cout << endl;

	cout << "Incorrect questions: " << incorrect_questions << " - ";

	for (int i = 0; i < incorrect_questions_list.size(); i++) {
		cout << "#" << incorrect_questions_list[i]; 
		if (i != incorrect_questions_list.size() - 1) {
			cout << ", ";
		} 
	}

	cout << endl << endl;

	percentage = correctPercentage(correct_questions) * 100;

	cout << "Correct percentage: " << fixed << setprecision(2) << percentage << "%" << setprecision(0) << endl;

	cout << "Pass or Fail: " << passOrFail(percentage) << endl;

}

double correctPercentage(int correct_questions){

	return static_cast<double>(correct_questions) / static_cast<double>(NUMBER_OF_QUESTIONS);

}

string passOrFail(double percentage) {

	string result;

	if (percentage >= PASS_PERCENTAGE) {
		result = "PASS!";
	}
	else {
		result = "FAIL!";
	
	}

	return result;

}