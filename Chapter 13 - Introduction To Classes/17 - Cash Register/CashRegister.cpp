#include "CashRegister.h"
#include "Inventory.h"
#include<iostream>
#include<iomanip>

using namespace std;

Inventory CashRegister::askForItem() {

	Inventory item;
	item.setName("Walkerswood Jerk Sauce 200g Jar");
	item.setItemNumber(43543);
	item.setCost(2.49);
	item.setQuantity(10);

	cout << "Item: " << item.getName() << "\n";
	cout << "Quantity: " << item.getQuantity() << "\n";
	cout << "\n";

	return item;
	
}

void CashRegister::getCost(Inventory i) {

	cout << "A " << i.getName() << " costs $" << fixed << setprecision(2) << i.getCost() << ".\n";
	cout << "\n";

}

void CashRegister::addProfit(Inventory &i) {

	double cost = i.getCost();

	cout << "Adding 30% profit was added to the price of " << i.getName() << "...\n";
	cout << "Current price: $" << fixed << setprecision(2) << i.getCost() << "\n";

	cost = i.getCost() * 1.3;
	i.setCost(cost);	

	cout << "New price: $" << i.getCost() << "\n";

	cout << "\n";

}

double CashRegister::getSubTotal(Inventory i) {

	return i.getQuantity() * i.getCost();

}

double CashRegister::getSalesTax(Inventory i) {

	return (getSubTotal(i) / 100) * 6;

}

double CashRegister::getGrandTotal(Inventory i) {

	return getSubTotal(i) + getSalesTax(i);
}


void CashRegister::showTotals(Inventory i) {

	cout << fixed << setprecision(2);
	cout << "Subtotal: $" << getSubTotal(i) << "\n";
	cout << "Sales Tax: $" << getSalesTax(i) << "\n";
	cout << "Grand Total: $" << getGrandTotal(i) << "\n";

}