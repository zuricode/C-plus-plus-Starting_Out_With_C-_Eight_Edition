#ifndef NUMBERS_H
#define NUMBERS_H

#include <string>
#include <iostream>

using std::cout;
using std::cin;
using std::string;
using std::to_string;

class Numbers {

private:

	static const int MIN = 1;
	static const int MAX = 9999;

	int number;
	
public:

	static const int getMin() { return MIN; }
	static const int getMax() { return MAX; }

	Numbers();
	Numbers(int num) { number = num; }

	int getNum() { return number;  }

	int numValidation(string, const int, const int);
	
};

#endif