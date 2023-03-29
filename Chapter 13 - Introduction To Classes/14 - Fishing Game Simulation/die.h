#ifndef DIE_H
#define DIE_H
#include<string>

using std::string;

class Die {

private:
	int number;

public:
	Die() { number = 0; }
	void roll();
	int getNumber() { return number; }
	string getCatch();

};

#endif