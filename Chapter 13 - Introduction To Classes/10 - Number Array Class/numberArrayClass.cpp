#include "numberArrayClass.h"
#include <iostream>

using namespace std;

Number::Number(int size) {

	num = new float[size];
	cout << "The number array has been created..." << endl;
	cout << endl;
}

Number::~Number() {

	delete[] num;
	cout << "Number instances have been destructed...." << endl;
}

void Number::setNumber(int index, float input) {
	num[index] = input;
}

float Number::getNumber(int index) const {
	return num[index];
}


