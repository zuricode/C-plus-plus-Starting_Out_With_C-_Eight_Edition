#include "TestScores.h"
#include <iostream>

using std::cout;

TestScores::TestScores(const int SIZE, const int* t) {

	arraysize = SIZE;
	scores = new int[arraysize];

	scores = new int[arraysize];

	for (int i = 0; i < arraysize; i++) {
		*(scores + i) = *(t + i);
	}

}

TestScores::~TestScores() {

	if (arraysize > 0) {
		delete[] scores;
		scores = nullptr;
	}

}

double TestScores::getAverage() const {

	double average = 0;
	int badCounter = 0;

	for (int i = 0; i < arraysize; i++) {
		if (*(scores + i) < MIN_SCORE || *(scores + i) > MAX_SCORE) {
			throw BadSubscript(i, *(scores + i));
			badCounter++;
		}
		else {
			average += *(scores + i);
		}
	}

	cout << "Final scores\n";
	cout << "------------\n";
	cout << "\n";
	for (int i = 0; i < arraysize; i++) {
		cout << "Score #" << i + 1 << ": " << *(scores + i) << "\n";
	}

	cout << "\n";

	average /= (arraysize - badCounter);		

	return average;

}

int& TestScores::operator[](const int& SUB) {

	return *(scores + SUB);

}