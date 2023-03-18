#include "TestScores.h"
#include <iostream>

using std::cin;
using std::cout;

TestScores::TestScores() {

	first_score = 0;
	second_score = 0;
	third_score = 0;

}

void TestScores::setFirstScore() {

	int num;

	cout << "Score #1: ";
	
	while (!(cin >> num) || num < 0) {
		cout << "Error: Test score cannot be of a negative value: Re-enter your score: ";
		cin.ignore();
	}

	first_score = num;

}

void TestScores::setSecondScore() {

	int num;

	cout << "Score #2: ";

	while (!(cin >> num) || num < 0) {
		cout << "Error: Test score cannot be of a negative value: Re-enter your score: ";
		cin.ignore();
	}

	second_score = num;

}

void TestScores::setThirdScore() {

	int num;

	cout << "Score #3: ";

	while (!(cin >> num) || num < 0) {
		cout << "Error: Test score cannot be of a negative value: Re-enter your score: ";
		cin.ignore();
	}

	third_score = num;

}


int TestScores::getFirstScore() const {
	return first_score;
}

int TestScores::getSecondScore() const {
	return second_score;
}

int TestScores::getThirdScore() const {
	return third_score;
}

double TestScores::getAverageScore() const {
	return static_cast<double>(first_score + second_score + third_score) / 3;
}