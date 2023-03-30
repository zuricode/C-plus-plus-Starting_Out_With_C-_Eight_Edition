#ifndef CASHREGISTER_H
#define CASHREGISTER_H
#include "inventory.h"

class CashRegister {	

public:

	Inventory askForItem();

	void getCost(Inventory);
	void addProfit(Inventory &);
	double getSubTotal(Inventory);
	double getSalesTax(Inventory);
	void showTotals(Inventory);
	double getGrandTotal(Inventory);

};

#endif;