#include "numberArrayClass.h"
#include <iostream>

using namespace std;

Number::Number(const int size) {

	num = new float[size];
	cout << "The number array has been created..." << endl;
	cout << endl;
}

Number::~Number() {

	delete[] num;
	cout << "Number instances have been destructed...." << endl;
}

void Number::setNumber(int index) {

	float input;

	cout << "Enter Number #" << index + 1 << ": ";

	while (!(cin >> input)) {
		cout << "ERROR: Value must be a float. Re-enter your value: ";
		cin.clear();
		cin.ignore(1200, '\n');
	}

	cin.ignore();

	num[index] = input;

}

float Number::getNumber(int index) const {
	return num[index];
}

float Number::getHighest(const int SIZE) const {

	float highest = num[0];

	for (int i = 0; i < SIZE; i++) {
		if (num[i] > highest) {
			highest = num[i];
		}
	}

	return highest;

}

float Number::getLowest(const int SIZE) const {

	float lowest = num[0];

	for (int i = 1; i < SIZE; i++) {
		if (num[i] < lowest) {
			lowest = num[i];
		}
	}

	return lowest;

}

float Number::getAverage(const int SIZE) const {

	float total = 0;

	for (int i = 0; i < SIZE; i++) {
		total += num[i];
	}

	return total / SIZE;

}


