//7. TestScores Class
//
//Write a class named TestScores.The class constructor should accept an array of test
//scores as its argument.The class should have a member function that returns the average
//of the test scores.If any test score in the array is negative or greater than 100, the
//class should throw an exception.Demonstrate the class in a program.

#include "TestScores.h"
#include <iostream>

using std::cout;
using std::cin;

int main() {
	
	int num_of_scores;
	int score;
	bool tryAgain = true;

	cout << "================================\n";
	cout << "16 - 07 TESTSCORES CLASS PROGRAM\n";
	cout << "================================\n";
	cout << "\n";

	cout << "Number of examination scores to enter: ";
	cin >> num_of_scores;
	cin.ignore();

	int* scores = new int[num_of_scores];

	cout << "\n";

	cout << "Scores\n";
	cout << "------\n";

	cout << "\n";

	for (int i = 0; i < num_of_scores; i++) {
		cout << "Score #" << i + 1 << ": ";
		cin >> score;
		*(scores + i) = score;
		cin.ignore();
	}

	TestScores tests(num_of_scores, scores);
	
	cout << "\n";

	while (tryAgain) {

		try {
			cout << "The average test score from " << num_of_scores << " examinations is " << tests.getAverage() << ".\n";
			tryAgain = false;
		}
		catch (TestScores::BadSubscript bS) {
			cout << "ERROR: " << bS.getBadScore() << " is an invalid score.\n";
			cout << "ALl scores must be between " << MIN_SCORE << " and " << MAX_SCORE << ".\n";
			cout << "Enter new score for Score #" << bS.getBadSubscript() + 1 << ": ";
			cin >> tests[bS.getBadSubscript()];
			cout << "\n";
		}

	}	

	cout << "\n";

	cout << "Ending the program...\n";

	delete[] scores;
	scores = nullptr;

}

void evalScores(TestScores& t) {



}