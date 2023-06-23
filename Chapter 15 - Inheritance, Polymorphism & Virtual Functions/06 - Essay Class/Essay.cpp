#include "Essay.h"

Essay::Essay(int g, int s, int cl, int co) : GradedActivity() {

	cout << "Enter the marks for the essay...\n";
	cout << "\n";

	setGrammarPoints(g);
	setSpellingPoints(s);
	setCorrectLengthPoints(cl);
	setContentPoints(co);

	cout << "\n";

}

void Essay::setGrammarPoints(int p) {

	while (p > MAX_GRAMMAR_POINTS || p <= 0) {
		cout << "Error: Grammar points must be an integer between (but not including) 0 and " << MAX_GRAMMAR_POINTS << ".\n";
		cout << "\n";
		cout << "Grammar (Max: " << MAX_GRAMMAR_POINTS << "): ";
		cin >> p;
	}	

	if (grammar != 0) {
		score -= grammar;
	}

	grammar = p;
	score += grammar;

}

void Essay::setSpellingPoints(int p) {

	while (p > MAX_SPELLING_POINTS || p <= 0) {
		cout << "Error: Spelling points must be an integer between (but not including) 0 and " << MAX_SPELLING_POINTS << ".\n";
		cout << "\n";
		cout << "Spelling (Max: " << MAX_SPELLING_POINTS << "): ";
		cin >> p;
	}

	if (spelling != 0) {
		score -= spelling;
	}

	spelling = p;
	score += spelling;

}

void Essay::setCorrectLengthPoints(int p) {

		while (p > MAX_CORRECT_LENGTH_POINTS || p <= 0) {
		cout << "Error: Points for correct length must be an integer between (but not including) 0 and " << MAX_CORRECT_LENGTH_POINTS << ".\n";
		cout << "\n";
		cout << "CorrectLength (Max: " << MAX_CORRECT_LENGTH_POINTS << "): ";
		cin >> p;
	}

	if (correct_length != 0) {
		score -= correct_length;
	}

	correct_length = p;
	score += correct_length;

}

void Essay::setContentPoints(int p) {

	while (p > MAX_CONTENT_POINTS || p <= 0) {
		cout << "Error: Content points must be an integer between (but not including) 0 and " << MAX_CONTENT_POINTS << ".\n";
		cout << "\n";
		cout << "Content (Max: " << MAX_CONTENT_POINTS << "): ";
		cin >> p;
	}

	if (content != 0) {
		score -= content;
	}

	content = p;
	score += content;

}

void Essay::print(ostream& strm) const {

	strm << setw(20) << "Grammar:  " << grammar << " pts\n";
	strm << setw(20) << "Spelling: " << spelling << " pts\n";
	strm << setw(20) << "Correct Length: " << correct_length << " pts\n";
	strm << setw(20) << "Content: " << content << " pts\n";
	strm << "\n";

}
