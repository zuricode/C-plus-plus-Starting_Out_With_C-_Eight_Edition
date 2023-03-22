//10. Number Array Class
//
//Design a class that has an array of floating - point numbers.The constructor should
//accept an integer argument and dynamically allocate the array to hold that many
//numbers.The destructor should free the memory held by the array.In addition, there
//should be member functions to perform the following operations :
//
//• Store a number in any element of the array
//• Retrieve a number from any element of the array
//• Return the highest value stored in the array
//• Return the lowest value stored in the array
//• Return the average of all the numbers stored in the array
//
//Demonstrate the class in a program.

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
