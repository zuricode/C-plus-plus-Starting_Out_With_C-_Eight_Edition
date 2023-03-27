//13. Tossing Coins for a Dollar
//
//For this assignment, you will create a game program using the Coin class from
//Programming Challenge 12. The program should have three instances of the Coin
//class : one representing a quarter, one representing a dime, and one representing a nickel.
//
//When the game begins, your starting balance is $0.During each round of the game,
//the program will toss the simulated coins.When a coin is tossed, the value of the coin
//is added to your balance if it lands heads - up.For example, if the quarter lands headsup,
//25 cents is added to your balance.Nothing is added to your balance for coins that
//land tails - up.The game is over when your balance reaches $1 or more.If your balance
//is exactly $1, you win the game.You lose if your balance exceeds $1.

#include "coin.h"

#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	srand(time(NULL));

	const int LIMIT = 1;

	Coin quarter;
	Coin dime;
	Coin nickel;
	double balance = 0;
	int counter = 0;

	cout << "13-13 - COIN TOSS FOR A DOLLAR GAME" << endl;
	cout << "========================================" << endl;
	cout << endl;
	cout << fixed << setprecision(2);

	while (balance < LIMIT) {

		quarter.toss();
		dime.toss();
		nickel.toss();

		cout << "COIN TOSS #" << counter + 1 << endl;
		cout << "=================" << endl;

		cout << "Quarter: " << quarter.getSideUp();

		if(quarter.getSideUp() == "HEADS")
		{
			balance += 0.25;
			cout << " - " << "$" << 0.25;
		}

		cout << endl;

		cout << "Dime: " << dime.getSideUp();

		if (dime.getSideUp() == "HEADS") {
			balance += 0.10;
			cout << " - " << "$" << 0.10;
		}

		cout << endl;

		cout << "Nickel: " << nickel.getSideUp();

		if (nickel.getSideUp() == "HEADS") {
			balance += 0.05;
			cout << " - " << "$" << 0.05;
		}

		cout << endl;
		cout << endl;

		cout << "Your balance is $" << balance << "." << endl;
		cout << endl;

		if (balance < LIMIT) {

			cout << "Press ENTER to toss the coins again...";
			cout << endl;

			cin.get();

			counter++;

		}
		
	}

	if (balance > LIMIT) {
		cout << "You have LOST. Balance is $" << balance << "." << endl;
	}
	else {
		cout << "CONGRATULATIONS! You have won! Balance is $" << balance << "." << endl;
	}

}