//18. A Game of 21
//
//For this assignment, you will write a program that lets the user play against the computer
//in a variation of the popular blackjack card game.In this variation of the game,
//two six - sided dice are used instead of cards.The dice are rolled, and the player tries to
//beat the computer’s hidden total without going over 21.
//
//Here are some suggestions for the game’s design :
//
//• Each round of the game is performed as an iteration of a loop that repeats as long
//as the player agrees to roll the dice, and the player’s total does not exceed 21.
//• At the beginning of each round, the program will ask the users whether they want
//to roll the dice to accumulate points.
//• During each round, the program simulates the rolling of two six - sided dice.It rolls
//the dice first for the computer, and then it asks the user if he or she wants to roll.
//(Use the Die class that was demonstrated in this chapter to simulate the dice).
//• The loop keeps a running total of both the computer and the user’s points.
//• The computer’s total should remain hidden until the loop has finished.
//• After the loop has finished, the computer’s total is revealed, and the player with the
//most points without going over 21 wins.

#include "die.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int userRollDie(Die*, const int);
int comRollDie(Die*, const int);
bool rollAgain();

int main() {

	unsigned int SEED = time(NULL);
	srand(SEED);

	const int LIMIT = 21;
	const int AMOUNT_OF_DIE = 2;

	int user_total_score = 0;
	int user_round_score;
	int com_total_score = 0;
	int com_round_score;
	bool new_roll = false;
	bool isLoss = false;
	bool isWin = false;

	Die *user_die = nullptr;
	Die *com_die = nullptr;

	cout << "13-18 - A GAME OF 21 PROGRAM\n";
	cout << "===================================\n";
	cout << "\n";

	com_die = new Die[AMOUNT_OF_DIE];
	user_die = new Die[AMOUNT_OF_DIE];

	do {

		com_round_score = comRollDie(com_die, AMOUNT_OF_DIE);
		com_total_score += com_round_score;

		user_round_score = userRollDie(user_die, AMOUNT_OF_DIE);
		user_total_score += user_round_score;

		cout << "You currently have " << user_total_score << ".\n";
		cout << "\n";

		if (user_total_score < LIMIT) {
			new_roll = rollAgain();
		} 
		else {
			new_roll = false;
		}

	} while (new_roll);

		cout << "The computer has scored " << com_total_score << ".\n";
		cout << "You have scored " << user_total_score << ".\n";
		cout << "\n";

		if (user_total_score > LIMIT || (user_total_score < com_total_score && com_total_score <= LIMIT))
		{
			cout << "You have LOST! Better luck next time...\n";
		}
		else if ((user_total_score > com_total_score && user_total_score <= LIMIT) || 
			(com_total_score > LIMIT && user_total_score <= LIMIT)) {
			cout << "You have WON! Congratulations!\n";
		}
		else {
			cout << "DRAW!\n";
		}

	delete[] com_die;
	delete[] user_die;
	com_die = nullptr;
	user_die = nullptr;

}

bool rollAgain() {

	char input;

	cout << "Would you like to roll again: \n";
	cout << "\n";
	cout << "\t[Y]es\n";
	cout << "\t[N]o\n";
	cout << "\n";
	cout << "Enter your selection: ";

	while (!(cin >> input) || (toupper(input) != 'Y' && toupper(input) != 'N')) {
		cout << "ERROR: You enter either Y/y or N/n.\n";
		cout << "\n";
		cin.ignore();
		cout << "Enter your selection: ";
	}

	input = toupper(input);

	cin.ignore();

	cout << "\n";
	cout << "-------------------------------------------------------------\n";
	cout << "\n";

	if (input == 'Y') {
		return true;
	}
	else {
		return false;
	}

}

int userRollDie(Die* d, const int SIZE) {

	int total = 0;

		for (int i = 0; i < SIZE; i++) {
			d[i].roll();
			cout << "Rolling Dice #" << i + 1 << " ........ " << d[i].showRoll();
			total += d[i].showRoll();
			cout << "\n";
		}

	cout << "\n";

	return total;

}

int comRollDie(Die* d, const int SIZE) {

	int total = 0;

	for (int i = 0; i < SIZE; i++) {
		d[i].roll();
		total += d[i].showRoll();
	}

	return total;

}