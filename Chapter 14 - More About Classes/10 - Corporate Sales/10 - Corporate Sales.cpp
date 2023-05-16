#include "DivSales.h"
#include <iomanip>
#include <iostream>

using namespace std;

int main() {

	const int NUMBER_OF_DIVISION = 6;

	DivSales company[NUMBER_OF_DIVISION];

	company[0].addSalesData(3453.45, 456.34, 45323.55, 34645);

	cout << "Total annual sales for all divisions: $" << fixed << setprecision(2) << company[0].getTotalAnnualCorpSales() << "\n";
	cout << "\n";

}