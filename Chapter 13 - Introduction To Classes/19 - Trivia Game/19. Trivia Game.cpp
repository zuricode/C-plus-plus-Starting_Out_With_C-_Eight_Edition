//19. Trivia Game
//
//In this programming challenge you will create a simple trivia game for two players.The
//program will work like this:
//
//• Starting with player 1, each player gets a turn at answering five trivia questions.
//(There are a total of 10 questions.) When a question is displayed, four possible
//answers are also displayed.Only one of the answers is correct, and if the player
//selects the correct answer he or she earns a point.
//• After answers have been selected for all of the questions, the program displays the
//number of points earned by each playerand declares the player with the highest
//number of points the winner.
//
//In this program you will design a Question class to hold the data for a trivia question.
//The Question class should have member variables for the following data :
//
//• A trivia question
//• Possible answer #1
//• Possible answer #2
//• Possible answer #3
//• Possible answer #4
//• The number of the correct answer(1, 2, 3, or 4)
//
//The Question class should have appropriate constructor(s), accessor, and mutator
//functions.
//
//The program should create an array of 10 Question objects, one for each trivia question.
//Make up your own trivia questions on the subject or subjects of your choice for
//the objects.

#include "Question.h"
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>

using namespace std;

void showQuestions(Question[], const int);
void determineWinner(const int, const int);

int main() {

	const int AMOUNT_OF_QUESTIONS = 10;

	Question quiz[AMOUNT_OF_QUESTIONS];

	quiz[0].setQuestion("Which is the biggest country by land mass?",
						"Saudi Arabia", "DR Congo", "Libya", "Algeria", 3);

	quiz[1].setQuestion("In what year did the Biafran war start?",
						"1976", "1974", "1967", "1947", 2);

	quiz[2].setQuestion("Congo has the world's largest reserve of which mineral?",
		"Gold", "Coltan", "Silicon", "Cobalt", 1);

	quiz[3].setQuestion("Who was the prime minister of the Burkina Faso who succeeded Thomas Sankara?",
		"Blaise Compaore", "Roch Marc Christian Kabore", "Jean-Baptiste Ouedraogo", "Saye Zerbo", 0);

	quiz[4].setQuestion("During Emmanuel's Macron time in office, in what year did he withdraw French military forces from Mali?",
						"2023", "2022", "2021", "2020", 1);

	quiz[5].setQuestion("In miles, what is the shortest distance that separates Europe from Africa?",
						"7", "9", "11", "13", 1);

	quiz[6].setQuestion("Mali is home to one of the world's oldest universities.\nIn what year was the university of Timbuktu built?",
						"1194", "670", "982", "1304", 2);

	quiz[7].setQuestion("Which language is most commonly used on the continent of Africa?",
						"French", "English", "Arabic", "Swahili", 3);
	
	quiz[8].setQuestion("Which of the following is a Nigerian Afrobeat legend?",
						"Fela Kuti", "Willie Colon", "Celia Cruz", "Peter Tosh", 0);

	quiz[9].setQuestion("Which African country was NOT formerly a portugese colony?",
						"Mozambique", "Angola", "Cape Verde", "Namibia", 3);
	bool is_player_one;
	bool is_player_two;
	bool is_correct;
	int player_one_score = 0;
	int player_two_score = 0;
	int question = 0;

	cout << "13-19 TRIVIA GAME PROGRAM\n";
	cout << "===============================\n";
	cout << "\n";
	cout << "Welcome to the quiz! This is a game for two players.\n";
	cout << "\n";

	do {

		is_player_one = false;
		is_player_two = false;

		if (question == 0 || question % 2 == 0) {
			is_player_one = true;
			cout << "------------   PLAYER ONE   ------------\n";
		}
		else {
			is_player_two = true;
			cout << "------------   PLAYER TWO   ------------\n";
		}

		cout << "\n";

		cout << "Q" << question + 1 << ": ";
		is_correct = quiz[question].showQuestion();

		if (is_correct) {
			if (is_player_one) {
				cout << "Adding a point for Player ONE...\n";
				player_one_score++;
			}
			else {
				cout << "Adding a point for Player TWO...\n";
				player_two_score++;
			}
		}

		cout << "P1 Points: " << player_one_score << "\tP2 Points: " << player_two_score << "\n";
		cout << "\n";

		if (question != 9) {
			cout << "Next question...\n";
			cout << "\n";
		}

		question++;

	} while (question < 10);

	determineWinner(player_one_score, player_two_score);

}

void showQuestions(Question q[], const int SIZE) {

	cout << "QUIZ QUESTIONS\n";
	cout << "====================\n";
	cout << "\n";

	for (int i = 0; i < SIZE; i++) {
		cout << "Q" << i + 1 << ": ";
		q[i].showQuestion();
	}

}

void determineWinner(const int a, const int b) {

	cout << "FINAL SCORE\n";
	cout << "--------------\n";
	cout << "\n";
	cout << "Player One has " << a << " points.\n";
	cout << "Player Two has " << b << " points.\n";
	cout << "\n";

	if (a > b) {
		cout << "Player ONE is the winner. Congratulations!\n";
	}
	else if (b > a) {
		cout << "Player TWO is the winner. Good job!\n";
	}
	else {
		cout << "It's a DRAW! Well done to you both!\n";
	}

}
