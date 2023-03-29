//14. Fishing Game Simulation
//
//For this assignment, you will write a program that simulates a fishing game.In this
//game, a six - sided die is rolled to determine what the user has caught.Each possible
//item is worth a certain number of fishing points.The points will not be displayed until 
//the user has finished fishing, and then a message is displayed congratulating the user
//depending on the number of fishing points gained.
//
//Here are some suggestions for the game’s design :
//
//• Each round of the game is performed as an iteration of a loop that repeats as long
//as the player wants to fish for more items.
//• At the beginning of each round, the program will ask the user whether he or she
//wants to continue fishing.
//• The program simulates the rolling of a six - sided die(use the Die class that was
//demonstrated in this chapter).
//• Each item that can be caught is represented by a number generated from the die.For
//example, 1 for “a huge fish, ” 2 for “an old shoe, ” 3 for “a little fish, ”and so on.
//• Each item the user catches is worth a different amount of points.
//• The loop keeps a running total of the user’s fishing points.
//• After the loop has finished, the total number of fishing points is displayed, along
//with a message that varies depending on the number of points earned.

#include "die.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

bool menuSelection();
bool continueFishing();
void scoreReport(int, int, vector<string>, vector<int>);

int main() {

	unsigned int seed = time(NULL);
	srand(seed);

	Die dice;
	string catch_name;
	vector<int> list_of_scores;
	vector<string> list_of_catches;
	int round = 1;
	int points = 0;

	cout << "13-14 FISHING GAME SIMULATION" << endl;
	cout << "=====================================" << endl;
	cout << endl;

	cout << "Time to fish!" << endl;
	cout << "Press ENTER to fish...";
	cin.get();

	cout << endl;
	
	do {

		dice.roll();

		catch_name = dice.getCatch();
		points += dice.getNumber();

		cout << "Round #" << round << "\n";
		cout << "------------" << "\n";
		cout << "You caught a " << catch_name << "!\n";
		list_of_scores.push_back(dice.getNumber());
		list_of_catches.push_back(catch_name);

		cout << dice.getNumber() << " points obtained.\n";
		cout << "\n";

		round++;

	} while(continueFishing());

	scoreReport(round, points, list_of_catches, list_of_scores);

	cout << "Thanks for playing!\n";
	cout << "Quitting the program...\n";

}

bool menuSelection() {

	char choice;

	while (!(cin >> choice) && (toupper(choice) != 'Y' || toupper(choice) != 'N)')) {
		cout << "ERROR: Please enter Y/y or N/n. Choice: ";
		cin.ignore();
	}

	choice = toupper(choice);

	cout << "\n";

	cin.ignore();

	if (choice == 'Y') {
		return true;
	}
	else {
		return false;
	}

}


bool continueFishing() {

	cout << "Would you like to continue fishing: \n";
	cout << "\n";
	cout << "\t[Y]es\n";
	cout << "\t[N]o\n";
	cout << "\n";
	cout << "Enter your selection: ";

return menuSelection();

}

void scoreReport(int rounds, int points, vector<string> list_of_catches, vector<int> list_of_scores) {

	int total = 0;

	cout << "FISHING REPORT\n";
	cout << "==========================\n";
	cout << left << "\n";
	cout << setw(10) << "ROUND" << setw(20) << "ITEM CAUGHT" << setw(10) << "POINTS" << "TOTAL POINTS" << "\n";
	cout << right << setfill('-') << setw(55) << "\n";
	cout << left << setfill(' ');

	for (int i = 0; i < list_of_catches.size(); i++) {

		total += list_of_scores[i];
		cout << "#" << setw(9) << i + 1 << setw(20) << list_of_catches[i] << setw(10) << list_of_scores[i] << total << "\n";

	}

	cout << right << setfill('-') << setw(55) << "\n";
	cout << "\n";
	cout << "TOTAL POINTS: " << points << "\n";
	cout << "\n";

}