#include <iostream>
#include <string>

using namespace std;

double iv(double);
double getSales(string);
void findHighest(double, double, double, double);

// Variables

const double	MINIMUM{ 0 };

const string	NE{ "North-East" },
				NW{ "North-West" },
				SE{ "South-East" },
				SW{ "South-West" };

double			ne{},
				nw{},
				se{},
				sw{};

int main() {

	ne = getSales(NE);
	nw = getSales(NW);
	se = getSales(SE);
	sw = getSales(SW);

	findHighest(ne, nw, se, sw);

	cout << endl;
}

double iv(double num) {

	while (!(cin >> num) || num < 0) {
		cout << "Error: please enter a value greater than " << MINIMUM << ".";
		cin.clear();
		cin.ignore(1200, '\n');
		cout << "Please re-enter the value: ";
	}

	return num;

}

double getSales(string name) {

	cout << "\nPlease enter the quartley sales figure in the " << name << " for this month: $";

	double num{};

	num = iv(num);

	return num;

}

void findHighest(double num1, double num2, double num3, double num4) {

	if ((num1 > num2) && (num1 > num3) && (num1 > num4)) {
		cout << endl << NE << " had the highest quarterly earnings this month with $" << ne;
	}

	if ((num2 > num1) && (num2 > num3) && (num2 > num4)) {
		cout << endl << NW << " had the highest quarterly earnings this month with $" << nw;
	}

	if ((num3 > num1) && (num3 > num2) && (num3 > num4)) {
		cout << endl << SE << " had the highest quarterly earnings this month with $" << se;
	}

	if ((num4 > num1) && (num4 > num2) && (num4 > num3)) {
		cout << endl << SW << " had the highest quarterly earnings this month with $" << sw;
	}


}