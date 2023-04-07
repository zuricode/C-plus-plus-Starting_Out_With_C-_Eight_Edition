#include "Question.h"
#include <iostream>

using std::cout;
using std::cin;

Question::Question() {

	question = "";
	answer[0] = "";
	answer[1] = "";
	answer[2] = "";
	answer[3] = "";
	correct_answer = 0;

}

void Question::setQuestion(string q, string a1, string a2, string a3, string a4, int ca) {

	question = q;
	answer[0] = a1;
	answer[1] = a2;
	answer[2] = a3;
	answer[3] = a4;
	correct_answer = ca;

}

int enterSelection() {

	int num;

	while (!(cin >> num) || num < 1 || num > 4) {
		cout << "ERROR: Choice must be an integer between 1 - 4.\n";
		cout << "\n";
		cout << "Re-enter your answer: ";
		cin.ignore();
	}

	cin.ignore();

	return num;

}

bool Question::showQuestion() {

	int option = 1;
	int choice;

	cout << question << "\n";
	cout << "\n";

	for (int i = 0; i < 4; i++) {
		cout << "\t[" << option << "] " << answer[i] << "\n";
		option++;
	}

	cout << "\n";
	cout << "Enter your selection: ";

	choice = enterSelection();
	choice--;

	if (choice == correct_answer) {
		cout << "CORRECT! The correct answer is " << answer[correct_answer] << ".\n";
		cout << "\n";
		return true;
	}
	else {
		cout << "INCORRECT! Your answer was \"" << answer[choice] << "\". The correct answer is \"" << answer[correct_answer] << "\".\n";
		cout << "\n";
		return false;
	}

}

