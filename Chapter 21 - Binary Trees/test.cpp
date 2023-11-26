#include <iostream>
using std::cout;

int square(const int&);
int square(int&&);

int main() {

	int x = 10;

	cout << square(x) << "\n";
	cout << square(5 + 5) << "\n";

	return 0;

}

int square(const int& NUM) {

	cout << "lvalue function: ";
	return NUM * NUM;

}

int square(int&& num) {

	cout << "rvalue function: ";
	return num * num;

}