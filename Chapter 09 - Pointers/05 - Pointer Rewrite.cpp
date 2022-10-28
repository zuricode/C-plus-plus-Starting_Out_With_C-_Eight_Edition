#include <iostream>

using namespace std;

int doSomething(int*, int*);

int main() {

	int* x = nullptr;
	int* y = nullptr;
	int* z = nullptr;

	x = new int;
	y = new int;
	z = new int;

	*x = 10;
	*y = 20;

	*z = doSomething(x, y);

	cout << *x << endl;
	cout << *y << endl;
	cout << *z << endl;

	cout << endl;

	delete x;
	x = nullptr;

	delete y;
	y = nullptr;

	delete z;
	z = nullptr;

}

int doSomething(int* x, int* y) {

	int temp = *x;
	*x = *y * 10;
	*y = temp * 10;

	return *x + *y;

}