//7. TestScores Class
//
//Design a TestScores class that has member variables to hold three test scores.The
//class should have a constructor, accessor, and mutator functions for the test score fields
//and a member function that returns the average of the test scores.Demonstrate the class by writing a separate program that creates an instance of the class.The program
//should ask the user to enter three test scores, which are stored in the TestScores
//object.Then the program should display the average of the scores, as reported by the
//TestScores object.

#include "TestScores.h"
#include<iostream>
#include<iomanip>

using std::cout;
using std::cin;
using std::fixed;
using std::setprecision;

void setAllScores(TestScores &);

int main() {

	cout << "13-07 - TEST SCORE PROGRAM" << '\n';
	cout << "=====================" << '\n';
	cout << '\n';

	TestScores exams;

	setAllScores(exams);

	cout << '\n';

	cout << "The average score from all tests is " << fixed << setprecision(1) << exams.getAverageScore() << '\n';

}

void setAllScores(TestScores &t) {

	t.setFirstScore();
	t.setSecondScore();
	t.setThirdScore();

}