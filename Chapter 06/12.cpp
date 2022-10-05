#include <iostream>

using namespace std;

// Variables

float		score1,
			score2,
			score3,
			score4,
			score5;

float inputValidation(float);
void getJudgeData(float &);
void calcScore(float, float, float, float, float);
float findLowest(float, float, float, float, float);
float findHighest(float, float, float, float, float);

int main() {

	getJudgeData(score1);
	getJudgeData(score2);
	getJudgeData(score3);
	getJudgeData(score4);
	getJudgeData(score5);

	calcScore(score1, score2, score3, score4, score5);

}

float inputValidation(float num) {

	while (!(cin >> num) || num < 0 || num > 10) {
		cout << "Error: Value must be greater than 0 and less than 100.Please re-enter your value: ";
		cin.clear();
		cin.ignore(1200, '\n');
	}

	return num;

}

void getJudgeData(float& score) {

	cout << "Enter the judge's score: ";

	score = inputValidation(score);

}

float findLowest(float score1, float score2, float score3, float score4, float score5) {

	if (score1 < score2 && score1 < score3 && score1 < score4 && score1 < score5) {
			return score1;
		}

		if (score2 < score1 && score2 < score3 && score2 < score4 && score2 < score5) {
				return score2;
			}

			if (score3 < score1 && score3 < score2 && score3 < score4 && score3 < score5) {
					return score3;
				}

				if (score4 < score1 && score4 < score2 && score4 < score3 && score4 < score5) {
						return score4;
					}

					if (score5 < score1 && score5 < score2 && score5 < score3 && score5 < score4) {
							return score5;
						}

}

float findHighest(float score1, float score2, float score3, float score4, float score5) {

	if (score1 > score2 && score1 > score3 && score1 > score4 && score1 > score5) {
			return score1;
		}

		if (score2 > score1 && score2 > score3 && score2 > score4 && score2 > score5) {
				return score2;
			}

			if (score3 > score1 && score3 > score2 && score3 > score4 && score3 > score5) {
					return score3;
				}

				if (score4 > score1 && score4 > score2 && score4 > score3 && score4 > score5) {
						return score4;
					}

					if (score5 > score1 && score5 > score2 && score5 > score3 && score5 > score4) {
							return score5;
						}

}

void calcScore(float score1, float score2, float score3, float score4, float score5) {

	float		lowest,
				highest;

	lowest = findLowest(score1, score2, score3, score4, score5);
	highest = findHighest(score1, score2, score3, score4, score5);

	cout << "\nThe lowest score from a judge is " << lowest;
	cout << "\nThe highest score from a judge is " << highest;
	cout << "\nThe average of the three middle scores is " << (score1 + score2 + score3 + score4 + score5 - lowest - highest) / 3 << endl << endl;

}