#include <iostream>

using namespace std;

// Variables

const int	MIN_SCORE{ 0 },
			MAX_SCORE{ 100 };

int			score1,
			score2,
			score3,
			score4,
			score5;

int inputValidation(int);
void getScore(int &);
void calcAverage(int, int, int, int, int);
int findLowest(int, int, int, int, int);

int main() {

	getScore(score1);
	getScore(score2);
	getScore(score3);
	getScore(score4);
	getScore(score5);

	calcAverage(score1, score2, score3, score4, score5);

}

int inputValidation(int num) {

	while (!(cin >> num) || num < 0 || num > 100) {
		cout << "Error: Value must be an integer greater than 0 and less than 100. Please re-enter your score: ";
		cin.clear();
		cin.ignore(1200, '\n');
	}

	return num;

}

void getScore(int &score) {

	cout << "\nPlease enter your test score: ";

	score = inputValidation(score);

}

void calcAverage(int score1, int score2, int score3, int score4, int score5) {

	int lowest;
	double average;

	lowest = findLowest(score1, score2, score3, score4, score5);

	cout << "\nThe lowest of all the scores is " << lowest << endl;

	if (lowest == score1) {
		average = double(score2 + score3 + score4 + score5) / double(4);
	}
		else if (lowest == score2) {
			average = double(score1 + score3 + score4 + score5) / double(4);
		}
			else if (lowest == score3) {
				average = double(score1 + score2 + score4 + score5) / double(4);
			}
				else if (lowest == score4) {
					average = double(score1 + score2 + score3 + score5) / double(4);
				}
					else {
						average = double(score1 + score2 + score3 + score4) / double(4);
					}

	cout << "\nThe average of the four highest test scores is " << average << endl << endl;

}

int findLowest(int score1, int score2, int score3, int score4, int score5) {

	int lowest;

	lowest = score1;

	if (score2 <= lowest) {
		lowest = score2;
	}	
		if (score3 <= lowest) {
			lowest = score3;
		}
			if (score4 <= lowest) {
				lowest = score4;
			}
				if (score5 <= lowest) {
					lowest = score5;
				}
		
	return lowest;

}