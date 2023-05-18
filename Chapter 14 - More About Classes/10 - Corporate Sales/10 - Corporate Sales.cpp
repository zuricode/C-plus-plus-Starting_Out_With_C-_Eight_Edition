#include "DivSales.h"
#include <iomanip>
#include <iostream>

using namespace std;

void displayAllQuarterlyEarnings(DivSales [], const int, const int);
void enterData(DivSales [], const int);
void displayCompanyEarningsTable(DivSales [], const int);

int main() {

	cout << "10 - CORPORATE SALES PROGRAM\n";
	cout << "============================\n";
	cout << "\n";

	const int NUMBER_OF_DIVISIONS = 6;

	DivSales company[NUMBER_OF_DIVISIONS];

	enterData(company, NUMBER_OF_DIVISIONS);

	displayCompanyEarningsTable(company, NUMBER_OF_DIVISIONS);

}

void enterData(DivSales d[], const int NUMBER_OF_DIVISIONS) {

	for (int i = 0; i < NUMBER_OF_DIVISIONS; i++) {

		cout << "Division #" << i + 1 << "\n";
		cout << "------------------------------\n";

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

		for (int j = 0; j < NUMBER_OF_QUARTERS; j++) {

			cout << "$" << d[i].getSalesFromQuarter(j) << " was earned in Q" << j + 1 << "\n";

		}

		cout << "\n";

	}

}

void displayCompanyEarningsTable(DivSales d[], const int NUMBER_OF_DIVISIONS) {

	cout << "COMPANY EARNINGS REPORT\n";
	cout << setfill('-') << setw(110) << "\n";
	cout << setfill(' ');

	cout << left << setw(20) << "DIV #" << setw(15) << "Q1" << setw(15) << "Q2" << setw(15) << "Q3" << setw(15) << "Q4" << setw(15) << "ANNUAL DIVISION TOTAL\n";
	cout << right << setfill('-') << setw(110) << "\n";
	cout << setfill(' ');

	for (int i = 0; i < NUMBER_OF_DIVISIONS; i++) {

		cout << left << "Division #" << setw(10) << i + 1;

		for (int j = 0; j < NUMBER_OF_QUARTERS; j++) {

			cout << "$" << fixed << setprecision(2) << setw(14) << d[i].getSalesFromQuarter(j);

		}

		cout << "$" << d[i].getTotalDivSales() << "\n";

	}

	cout << right << setfill('-') << setw(110) << "\n";
	cout << setfill(' ');
	cout << "\n";

	cout << setw(50) << "" << setw(31) << "GRAND COMPANY ANNUAL TOTAL: $" << d[0].getTotalAnnualCorpSales() << "\n";


}
