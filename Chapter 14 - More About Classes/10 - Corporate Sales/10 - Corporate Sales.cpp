#include "DivSales.h"
#include <iomanip>
#include <iostream>

using namespace std;

void displayAllQuarterlyEarnings(DivSales [], const int, const int);
void enterData(DivSales [], const int);
void displayCompanyEarningsTable(const DivSales, const int);

int main() {

	const int NUMBER_OF_DIVISIONS = 6;

	DivSales company[NUMBER_OF_DIVISIONS];

	enterData(company, NUMBER_OF_DIVISIONS);

	displayAllQuarterlyEarnings(company, NUMBER_OF_DIVISIONS, 0);

	cout << "Total annual sales for all divisions: $" << fixed << setprecision(2) << company[0].getTotalAnnualCorpSales() << "\n";
	cout << "\n";

}

void enterData(DivSales d[], const int NUMBER_OF_DIVISIONS) {

	cout << "DATA ENTRY FOR COMPANY\n";
	cout << "======================\n";
	cout << "\n";

	for (int i = 0; i < NUMBER_OF_DIVISIONS; i++) {

		cout << "Division #" << i + 1 << "\n";

		if (i != 2 && i != 5) {
			d[i].enterSalesData();
		}
		else {
			cout << "NOTE: Division #" << i + 1 << " was inactive this year.\n";
			cout << "\n";
			d[i].addSalesData(0, 0, 0, 0);
		}

		cout << "\n";
	}

}


void displayAllQuarterlyEarnings(DivSales d[], const int NUMBER_OF_DIVISIONS, const int I) {

	cout << fixed << setprecision(2);

	for (int i = 0; i < NUMBER_OF_DIVISIONS; i++) {

		cout << "DIVISION #" << i + 1 << "\n";
		cout << "====================\n";
		cout << "\n";

		for (int j = 0; j < 4; j++) {

			cout << "$" << d[i].getSalesFromQuarter(j) << " was earned in Q" << j + 1 << "\n";

		}

		cout << "\n";

	}

}

void displayCompanyEarningsTable(const DivSales D, const int NUMBER_OF_DIVISIONS) {

	cout << "COMPANY EARNINGS REPORT\n";
	cout << left << setfill('=') << setw(70) <<

}
