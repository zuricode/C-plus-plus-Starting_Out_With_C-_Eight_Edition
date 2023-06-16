#include "PreferredCustomer.h"
#include <iostream>

using std::cout;
using std::cin;
using std::fixed;
using std::setprecision;

PreferredCustomer::PreferredCustomer(string l, string f, string a, string c, string s, string z,
									string p, int num, bool b, double purchase) : CustomerData(l, f, a, c, s, z, p, num, b) {

	checkPurchaseAmount(purchase);
	addPurchaseAmount(purchase);
	setDiscountLevel();

}

double PreferredCustomer::enterPurchaseAmount() {

	double purchase;
	cin >> purchase;

	checkPurchaseAmount(purchase);

	return purchase;

}

void PreferredCustomer::checkPurchaseAmount(double& purchase) {

	while (purchase <= 0) {
		cout << "Error: Purchase amount must be greater than $0.\n";
		cout << "\n";
		cout << "Purchase amount: $";
		cin >> purchase;
	}

}

void PreferredCustomer::setDiscountLevel() {

	if (purchasesAmount >= FIVE_PERCENT_THRESHOLD && purchasesAmount < SIX_PERCENT_THRESHOLD) {
		discountLevel = 5.00;
	}
	else if (purchasesAmount >= SIX_PERCENT_THRESHOLD && purchasesAmount < SEVEN_PERCENT_THRESHOLD) {
		discountLevel = 6.00;
	}
	else if (purchasesAmount >= SEVEN_PERCENT_THRESHOLD && purchasesAmount < TEN_PERCENT_THRESHOLD) {
		discountLevel = 7.00;
	}
	else if (purchasesAmount >= TEN_PERCENT_THRESHOLD) {
		discountLevel = 10.00;
	}
	else {
		discountLevel = 0;
	}

}

void PreferredCustomer::enterData(istream& strm) {

	double purchase;
	bool isValid = false;

	CustomerData::enterData(strm);

	while (!isValid) {

		cout << "Cumulative total of purchases: $";
		strm >> purchase;

		if (purchase <= 0) {
			cout << "Error: Purchase amount must be greater than $0.\n";
			cout << "\n";
		}
		else {
			isValid = true;
		}

	}

	purchasesAmount += purchase;
	setDiscountLevel();

}

void PreferredCustomer::print(ostream& strm) const {

	CustomerData::print(strm);

	strm << "Cumulative total of purchases: $" << fixed << setprecision(2) << purchasesAmount << "\n";
	strm << "Discount level: " << getDiscountLevel() << "%\n";

}