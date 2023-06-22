#ifndef ESSAY_H
#define ESSAY_H

#include "C:\\Users\\Admin\\source\\repos\\Project2\\Project2\\C-plus-plus-Starting_Out_With_C-_Eight_Edition\\SourceCode\\chapter 15\\GradedActivity Version 3\\GradedActivity.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::ostream;
using std::istream;
using std::setw;
using std::left;

const int MAX_GRAMMAR_POINTS = 30;
const int MAX_SPELLING_POINTS = 20;
const int MAX_CORRECT_LENGTH_POINTS = 20;
const int MAX_CONTENT_POINTS = 30;
const int MAX_POINTS = MAX_GRAMMAR_POINTS + MAX_SPELLING_POINTS + MAX_CORRECT_LENGTH_POINTS + MAX_CONTENT_POINTS;

class Essay : public GradedActivity {

private:
	int grammar = 0;
	int spelling = 0;
	int correct_length = 0;
	int content = 0;

public:
	Essay() : GradedActivity() { grammar = 0; spelling = 0; correct_length = 0; content = 0; }
	Essay(int, int, int, int);

	void setGrammarPoints(int);
	void setSpellingPoints(int);
	void setCorrectLengthPoints(int);
	void setContentPoints(int);

	int getGrammarPoints() const { return grammar; }
	int getSpellingPoints() const { return spelling; }
	int getCorrectLengthPoints() const { return correct_length; }
	int getContentPoints() const { return content; }

	friend ostream& operator << (ostream&, const Essay&);

};

#endif