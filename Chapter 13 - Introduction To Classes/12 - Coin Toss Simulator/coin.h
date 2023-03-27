#ifndef COIN_H
#define COIN_H
#include <string>

using std::string;

class Coin {

private:
	string sideUp;

public:
	Coin();

	void toss();
	string getSideUp() { return sideUp; }

};

#endif