#include <iostream>
#include <cmath>

using namespace std;

// Variables

const double	G{ 9.8 };

double d;

double fallingDistance(double);


int main() {

	for (double i = 1; i <= 10; i++) {
		d = fallingDistance(i);
		if (i == 1)
		cout << "\nAfter " << i << " second, the object will have travelled " << d << " metres";
		else {
			cout << "\nAfter " << i << " seconds, the object will have travelled " << d << " metres";
		}
	}

	cout << endl;

}

double fallingDistance(double time) {

	return 0.5 * G * pow(time, 2);

}