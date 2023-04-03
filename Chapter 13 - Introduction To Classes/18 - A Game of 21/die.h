#ifndef DIE_H
#define DIE_H

class Die {

private:
	int num;

public:
	Die() { num = 0; }
	void roll();
	int showRoll() { return num; }

};

#endif