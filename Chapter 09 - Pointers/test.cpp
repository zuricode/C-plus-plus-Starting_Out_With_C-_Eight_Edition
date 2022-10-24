#include <iostream>

using namespace std;

void makeNegative(int*);

int main() {

	int number = 164;
	int* ptr = nullptr;
	ptr = &number;

	cout << ptr << endl;
	cout << *ptr << endl << endl;

	makeNegative(ptr);

	cout << ptr << endl;
	cout << *ptr << endl;

	ptr = nullptr;

}

void makeNegative(int* val) {

	if(*val > 0)

		*val -= 2 * (*val);

}