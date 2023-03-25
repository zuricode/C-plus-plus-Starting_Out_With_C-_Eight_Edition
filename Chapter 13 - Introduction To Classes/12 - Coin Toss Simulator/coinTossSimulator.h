#ifndef COINTOSSSIMULATOR_H
#define COINTOSSSIMULATOR_H
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