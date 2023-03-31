#ifndef CASHREGISTER_H
#define CASHREGISTER_H
#include "inventory.h"
#include<vector>

using std::vector;

class CashRegister {	

public:

	int askForItem(vector<Inventory>);
	int askForQuantity(Inventory);

	void getCost(Inventory);
	void addProfit(Inventory &);
	double getSubTotal(Inventory, int);
	double getSalesTax(Inventory, int);
	void showTotals(Inventory, int);
	double getGrandTotal(Inventory, int);

	void deductQuantityFromStock(Inventory &, int);

};

#endif;