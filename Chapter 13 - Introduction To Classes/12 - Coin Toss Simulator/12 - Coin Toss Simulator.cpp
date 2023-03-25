//12. Coin Toss Simulator
//
//Write a class named Coin.The Coin class should have the following member variable :
//
//• A string named sideUp.The sideUp member variable will hold either “heads” or
//“tails” indicating the side of the coin that is facing up.
//
//The Coin class should have the following member functions :
//
//• A default constructor that randomly determines the side of the coin that is facing up
//(“heads” or “tails”) and initializes the sideUp member variable accordingly.
//• A void member function named toss that simulates the tossing of the coin.When
//the toss member function is called, it randomly determines the side of the coin that
//is facing up(“heads” or “tails”) and sets the sideUp member variable accordingly.
//• A member function named getSideUp that returns the value of the sideUp member
//variable.
//
//Write a program that demonstrates the Coin class.The program should create an
//instance of the classand display the side that is initially facing up.Then, use a loop
//to toss the coin 20 times.Each time the coin is tossed, display the side that is facing
//up.The program should keep count of the number of times heads is facing upand the
//number of times tails is facing up, and display those values after the loop finishes.

#include "coinTossSimulator.h"
#include <iostream>

using namespace std;

int main() {

	const int ROUNDS = 20;
	unsigned int SEED = time(NULL);
	srand(SEED);

	Coin coin;
	int heads_counter = 0;
	int tails_counter = 0;

	cout << "13-12 - COIN TOSS SIMULATOR" << endl;
	cout << "================================" << endl;
	cout << endl;

	cout << "Inital toss: " << coin.getSideUp() << endl;
	cout << endl;

	for (int i = 0; i < ROUNDS; i++) {

		cout << "Toss #" << i + 1 << ": ";
		coin.toss();
		cout << coin.getSideUp() << endl;

		if (coin.getSideUp() == "HEADS") {
			heads_counter++;
		}
		else {
			tails_counter++;
		}

	}

	cout << endl;

	cout << "Heads counter: " << heads_counter << endl;
	cout << "Tails counter: " << tails_counter << endl;

}