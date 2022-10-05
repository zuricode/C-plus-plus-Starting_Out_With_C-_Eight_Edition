#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

double calculateRetail(double, double);
double inputValidator(double);

int main() {

	// Variables

	double		wholesale_cost{},
				markup_perc{},
				retail_price{};

	cout << "What is your item's wholesale cost: $";

	wholesale_cost = inputValidator(wholesale_cost);

	cout << "What is your item's markup percentage: ";

	markup_perc = inputValidator(markup_perc);
	
		cout << fixed << setprecision(2);

	cout << "\nThe wholesale cost is $" << wholesale_cost;
	cout << "\nThe markup percentage is: " << markup_perc << "%";

	markup_perc /= 100;

	retail_price = calculateRetail(wholesale_cost, markup_perc);

	cout << "\nThe retail price will be: $" << retail_price;

	cout << endl;

}

double calculateRetail(double num1, double num2) {
	return (num1 * num2) + num1;
}

double inputValidator(double num) {

	while (!(cin >> num) || (num < 0)) {
		cout << "Error: please enter a positive double as your value.";
		cin.clear();
		cin.ignore(123, '\n');
	}

	return num;
}