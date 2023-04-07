#ifndef QUESTION_H
#define QUESTION_H
#include <string>

using std::string;

class Question {

private:
	string question;
	string answer[4];
	int correct_answer;

public:
	Question();
	void setQuestion(string q, string a1, string a2, string a3, string a4, int ca);
	bool showQuestion();
	int showAnswer() { return correct_answer; }

};

#endif