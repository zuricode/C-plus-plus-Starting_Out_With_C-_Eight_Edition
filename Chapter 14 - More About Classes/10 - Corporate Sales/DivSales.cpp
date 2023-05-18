#include "DivSales.h"
#include <iostream>

using std::cout;
using std::cin;

const int NUMBER_OF_QUARTERS = 4;


DivSales::DivSales() {

	for (int i = 0; i < NUMBER_OF_QUARTERS; i++) {
		sales_data[i] = 0; 
	}

	total_annual_corp_sales += 0;

}

void DivSales::enterSalesData() {

	double num;

	for (int i = 0; i < NUMBER_OF_QUARTERS; i++) {
		cout << "Enter the earnings for Q" << i + 1 << ": $";

		while (!(cin >> num) || num < 0) {
			cout << "ERROR: Earnings cannot be a negative number.\n";
			cout << "\n";
			cin.ignore();
			cout << "Re-enter your value: $";
		}

		cin.ignore();

		sales_data[i] = num;
		total_annual_corp_sales += sales_data[i];

	}

	cout << "\n";

}

void DivSales::addSalesData(const double q1, const double q2, const double q3, const double q4) {

	sales_data[0] = q1;
	sales_data[1] = q2;
	sales_data[2] = q3;
	sales_data[3] = q4;

	total_annual_corp_sales += q1 + q2 + q3 + q4;

}

double DivSales::getSalesFromQuarter(int num) const {

	while (num < 0 || num > 3) {
		cout << "ERROR: Argument must be a value between 0 - 3.\n";
		cout << "\n";
		cout << "Enter your chosen quarter: ";
		cin >> num;
	}

	return sales_data[num];

}

double DivSales::getTotalAnnualCorpSales() const {

	return total_annual_corp_sales;

}

double DivSales::total_annual_corp_sales = 0;

