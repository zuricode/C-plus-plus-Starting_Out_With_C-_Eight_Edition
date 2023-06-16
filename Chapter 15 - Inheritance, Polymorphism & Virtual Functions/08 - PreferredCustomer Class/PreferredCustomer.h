#ifndef PREFERREDCUSTOMER_H
#define PREFERREDCUSTOMER_H

#include "C:\\Users\\Admin\\source\\repos\\Project2\\Project2\\C-plus-plus-Starting_Out_With_C-_Eight_Edition\\Chapter 15 - Inheritance, Polymorphism & Virtual Functions\\07 - PersonData and CustomerData Program\\CustomerData.h"

const double FIVE_PERCENT_THRESHOLD = 500.00;
const double SIX_PERCENT_THRESHOLD = 1000.00;
const double SEVEN_PERCENT_THRESHOLD = 1500.00;
const double TEN_PERCENT_THRESHOLD = 2000.00;

class PreferredCustomer : public CustomerData {

private:
	double purchasesAmount = 0;
	double discountLevel = 0;

public:
	PreferredCustomer() : CustomerData() { purchasesAmount = 0; discountLevel = 0; }
	PreferredCustomer(string, string, string, string, string, string, string, int, bool, double);

	void setDiscountLevel();
	double getDiscountLevel() const { return discountLevel; }

	void checkPurchaseAmount(double&);

	double enterPurchaseAmount();
	void setPurchasesAmount(const double P) { purchasesAmount = P; setDiscountLevel(); }
	void addPurchaseAmount(const double P) { purchasesAmount += P; setDiscountLevel(); }
	double getPurchasesAmount() const { return purchasesAmount; }

	void enterData(istream&);
	void print(ostream&) const;

};

#endif