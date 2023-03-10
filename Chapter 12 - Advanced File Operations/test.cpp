#include <iostream>

using namespace std;

int main() {


	unsigned seed = time(0);

	srand(seed * seed * seed);

	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl;

	return 0;

}