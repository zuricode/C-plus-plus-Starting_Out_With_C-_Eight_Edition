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

bool rollAgain();

int main() {

	const int LIMIT = 21;
	const int AMOUNT_OF_DIE = 2;

	bool new_roll = false;

	*DiePtr = nullptr;
	DiePtr = new Die[AMOUNT_OF_DIE];

	cout << "13-18 - A GAME OF 21 PROGRAM\n";
	cout << "===================================\n";
	cout << "\n";

	do {

		new_roll = rollAgain();

	} while (new_roll);




	delete DiePtr[];
	DiePtr = nullptr;

}

bool rollAgain() {

	char input;

	cout << "Would you like to roll again: \n";
	cout << "\n";
	cout << "\t[Y]es\n";
	cout << "\t[N]o\n";
	cout << "\n";
	cout << "Enter your selection: ";

	while (!(cin >> num) || (toupper(input) != 'Y' || toupper(input) != 'N')) {
		cout << "ERROR: You enter either Y/y or N/n.\n";
		cout << "\n";
		cin.ignore();
		cout << "Enter your selection: ";
	}

	input = toupper(input);

	cin.ignore();

	if (input == 'Y') {
		return true;
	}
	else {
		return false;
	}

}


