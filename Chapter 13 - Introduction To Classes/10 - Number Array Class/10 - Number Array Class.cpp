#include "numberArrayClass.h"
#include <iostream>
#include <iomanip>

using namespace std;

void setNumbers(Number &, const int);
void numbersReport(const Number &, const int);

int main() {

	const int SIZE = 3;

	Number list(SIZE);

	setNumbers(list, SIZE);

	numbersReport(list, SIZE);

}

void setNumbers(Number &list, const int SIZE) {

	cout << "NUMBER ENTRY" << endl;
	cout << "===============" << endl;
	cout << endl;

	for (int i = 0; i < SIZE; i++) {
		list.setNumber(i);
	}

	cout << endl;

}

void numbersReport(const Number &LIST, const int SIZE) {

	cout << "NUMBER REPORT" << endl;
	cout << "===============" << endl;
	cout << endl;

	for (int i = 0; i < SIZE; i++) {
		cout << "Number #" << i + 1 << ": " << LIST.getNumber(i) << endl;
	}

	cout << "Highest number: " << LIST.getHighest(SIZE) << endl;
	cout << "Lowest number: " << LIST.getLowest(SIZE) << endl;
	cout << "Average of array: " << LIST.getAverage(SIZE) << endl;

	cout << endl;

}
