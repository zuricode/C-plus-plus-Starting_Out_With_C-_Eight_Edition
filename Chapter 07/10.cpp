#include <iostream>
#include <vector>

const int	QUESTIONS{ 20 }, PASS_MARK{15};
const char ANSWERS[QUESTIONS]{ 'A', 'D', 'B', 'B', 'C',
								'B', 'A', 'B', 'C', 'D',
								'A', 'C', 'D', 'B', 'D',
								'C', 'C', 'A', 'D', 'B' };

using namespace std;

char inputValidation(char);
void test(const char[QUESTIONS], char[QUESTIONS], int&, vector<int>&, vector<int>&);
bool passOrFail(int);
void result(int, vector<int>, vector<int>);

int main() {

	char student_answers[QUESTIONS];
	bool test_result;
	int correct_count{0};
	vector<int> correct_questions;
	vector<int> incorrect_questions;

	test(ANSWERS, student_answers, correct_count, correct_questions, incorrect_questions);
	test_result = passOrFail(correct_count);
	result(correct_count, correct_questions, incorrect_questions);

}

char inputValidation(char answer) {

	while (!(cin >> answer) || (answer != 'A' && answer != 'B' && answer != 'C' && answer != 'D')) {
	cout << "ERROR: Value must be either \'A\', \'B\', \'C\', or \'D\'. Re-enter your value: ";
	cin.clear();
	cin.ignore(1200, '\n');
}

return answer;

}

void test(const char ANSWERS[QUESTIONS], char student_answer[QUESTIONS], int& count, vector<int>& correct, vector<int>& incorrect){

	char answer{};

	for (int i = 0; i < QUESTIONS; i++) {
		cout << "Answer for question #" << i + 1 << ": ";
		answer = inputValidation(answer);
		if (answer == ANSWERS[i]) {
			count++;
			correct.push_back(i + 1);
		}
		else {
			incorrect.push_back(i + 1);
		}
	}

	cout << endl;

}

bool passOrFail(int count) {

	bool result;

	if (count >= PASS_MARK) {
		result = true;
		return result;
	}
	else {
		result = false;
		return result;
	}

}

void result(int count, vector<int> correct_questions, vector<int> incorrect_questions) {

	cout << "TEST RESULTS: " << endl;
	cout << "-------------------------" << endl;
	cout << endl;

	if (count >= PASS_MARK) {
		cout << "Pass! " << endl;
	}
	else {
		cout << "Fail!" << endl;
	}
		cout << count << " correct answers." << endl;
		
		cout << "Questions answered correctly: ";

		for (int i = 0; i < correct_questions.size(); i++) {
			cout << "#" << correct_questions[i] << ", ";
		}

		cout << endl;
		cout << endl;

		cout << QUESTIONS - count << " incorrect answers." << endl;

		cout << "Questions answered incorrectly: ";

		for (int i = 0; i < incorrect_questions.size(); i++) {
			cout << "#" << incorrect_questions[i] << ", ";
		}

		cout << endl << endl;
	
}