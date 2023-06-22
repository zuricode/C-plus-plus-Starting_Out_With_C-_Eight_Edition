#include "Essay.h"

Essay::Essay(int g, int s, int cl, int co) : GradedActivity() {

	cout << "Enter the marks for your essay...\n";
	cout << "\n";

	setGrammarPoints(g);
	setSpellingPoints(s);
	setCorrectLengthPoints(cl);
	setContentPoints(co);

	cout << "\n";

}

void Essay::setGrammarPoints(int p = 0) {
	
	cout << "Grammar (Max: " << MAX_GRAMMAR_POINTS << "): ";

	while (!(cin >> p) || (p > MAX_GRAMMAR_POINTS) || p <= 0) {
		cout << "Error: Grammar points must be an integer between (but not including) 0 and " << MAX_GRAMMAR_POINTS << ".\n";
		cout << "\n";
		cout << "Grammar (Max: " << MAX_GRAMMAR_POINTS << "): ";
	}

	if (grammar != 0) {
		score -= grammar;
	}

	grammar = p;
	score += grammar;

}

void Essay::setSpellingPoints(int p = 0) {

	cout << "Spelling (Max: " << MAX_SPELLING_POINTS << "): ";

	while (!(cin >> p) || (p > MAX_SPELLING_POINTS) || p <= 0) {
		cout << "Error: Spelling points must be an integer between (but not including) 0 and " << MAX_SPELLING_POINTS << ".\n";
		cout << "\n";
		cout << "Spelling (Max: " << MAX_SPELLING_POINTS << "): ";
	}

	if (spelling != 0) {
		score -= spelling;
	}

	spelling = p;
	score += spelling;

}

void Essay::setCorrectLengthPoints(int p = 0) {
	
	cout << "CorrectLength (Max: " << MAX_CORRECT_LENGTH_POINTS << "): ";

	while (!(cin >> p) || (p > MAX_CORRECT_LENGTH_POINTS) || p <= 0) {
		cout << "Error: Points for correct length must be an integer between (but not including) 0 and " << MAX_CORRECT_LENGTH_POINTS << ".\n";
		cout << "\n";
		cout << "CorrectLength (Max: " << MAX_CORRECT_LENGTH_POINTS << "): ";
	}

	if (correct_length != 0) {
		score -= correct_length;
	}

	correct_length = p;
	score += correct_length;

}

void Essay::setContentPoints(int p = 0) {

	cout << "Content (Max: " << MAX_CONTENT_POINTS << "): ";

	while (!(cin >> p) || (p > MAX_CONTENT_POINTS) || p <= 0) {
		cout << "Error: Content points must be an integer between (but not including) 0 and " << MAX_CONTENT_POINTS << ".\n";
		cout << "\n";
		cout << "Content (Max: " << MAX_CONTENT_POINTS << "): ";
	}

	if (content != 0) {
		score -= content;
	}

	content = p;
	score += content;

}

ostream& operator << (ostream& strm, const Essay& E) {

	strm << "-------------\n";
	strm << "ESSAY RESULTS\n";
	strm << "-------------\n";

	strm << left;
	strm << setw(20) << "Grammar:  " << E.grammar << " pts\n";
	strm << setw(20) << "Spelling: " << E.spelling << " pts\n";
	strm << setw(20) << "Correct Length: " << E.correct_length << " pts\n";
	strm << setw(20) << "Content: " << E.content << " pts\n";
	strm << setw(20) << "Total Score: " << E.score << " pts\n";
	strm << "\n";
	strm << setw(20) << "Grade: " << E.getLetterGrade() << "\n";

	return strm;

}
