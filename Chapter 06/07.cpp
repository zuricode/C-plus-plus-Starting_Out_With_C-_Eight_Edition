#include <iostream>
#include <iomanip>

using namespace std;

double celcius(double);

// Variables

const double		CONSTANT{ 5.0 / 9.0 };

double				celcius_var;

int main() {

	cout << "\nFahrenheit to Celcius";
	cout << "\n----------------------";

	for (double i = 0; i <= 20; i++) {
		celcius_var = celcius(i);
		cout << "\n    " << i << right << setw(14) << setprecision(4) << celcius_var;
	}

	cout << endl << endl;

}

double celcius(double fahrenheit) {

	return CONSTANT * (fahrenheit - 32);

}