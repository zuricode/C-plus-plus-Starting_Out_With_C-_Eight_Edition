#include "die.h"
#include "die.h"

#include<iostream>
#include<string>

using namespace std;

void Die::roll() {
	number = rand() % 6 + 1;
}

string Die::getCatch() {

	switch (number) {

		case 1:
			return "OLD BOOT";
			break;
		case 2:
			return "GOLDFISH";
			break;
		case 3:
			return "RED BREAM";
			break;
		case 4:
			return "RED SALMON";
			break;
		case 5:
			return "KING LOBSTER";
			break;
		case 6:
			return "ANTIQUE ROLEX";
			break;

	}

}