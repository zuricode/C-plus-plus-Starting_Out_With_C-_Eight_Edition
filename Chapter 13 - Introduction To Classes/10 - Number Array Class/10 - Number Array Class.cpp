#include "numberArrayClass.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	const int SIZE = 3;

	Number list(SIZE);

	list.setNumber(0, 5647547);
	list.setNumber(1, 46342);
	list.setNumber(2, 4543);

	cout << "The first number is " << list.getNumber(0) << endl;
	cout << "The second number is " << list.getNumber(1) << endl;
	cout << "The third number is " << list.getNumber(2) << endl;

	cout << endl;

}