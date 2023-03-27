#include "coin.h"

void Coin::toss() {

	int num;

	num = rand() % 2;

	if (num) {
		sideUp = "HEADS";
	}
	else {
		sideUp = "TAILS";
	}

}

Coin::Coin() {
	toss();
}


