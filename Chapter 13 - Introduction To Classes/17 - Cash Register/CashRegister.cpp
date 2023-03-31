#include "CashRegister.h"
#include "Inventory.h"
#include<iostream>
#include<iomanip>

using namespace std;

int CashRegister::askForItem(vector<Inventory> stock) {

	int num;

	cout << "Enter the number of the item you wish to purchase: ";
	
	while (!(cin >> num) || (num < 1 || num > stock.size())) {
		cout << "ERROR: Item number does not exist.\n";
		cout << "\n";
		cin.ignore();
		cout << "Re-enter your item number: ";
	}

	cout << "\n";
	num--;

	cin.ignore();

	return num;
	
}

int  CashRegister::askForQuantity(Inventory item) {

	int num;

	cout << "How much of \"" << item.getName() << "\" would you like to purchase: ";

	while (!(cin >> num) || (num < 1 || num > item.getQuantity())) {
		cout << "ERROR: Not possible to buy " << num << ".\n";
		cout << "\n";
		cin.ignore();
		cout << "Re-enter your quantity: ";
	}

	cout << "\n";

	cin.ignore();

	return num;

}

void CashRegister::getCost(Inventory i) {

	cout << "A " << i.getName() << " costs $" << fixed << setprecision(2) << i.getCost() << ".\n";
	cout << "\n";

}

void CashRegister::addProfit(Inventory &i) {

	double cost = i.getCost();

	cout << "Adding 30% profit to the price of " << i.getName() << "...\n";
	cout << "Wholesale price: $" << fixed << setprecision(2) << i.getCost() << "\n";

	cost = i.getCost() * 1.3;
	i.setCost(cost);	

	cout << "Retail price: $" << i.getCost() << "\n";

	cout << "\n";

}

double CashRegister::getSubTotal(Inventory i, int user_quantity) {

	return user_quantity * i.getCost();

}

double CashRegister::getSalesTax(Inventory i, int user_quantity) {

	return (getSubTotal(i, user_quantity) / 100) * 6;

}

double CashRegister::getGrandTotal(Inventory i, int user_quantity) {

	return getSubTotal(i, user_quantity) + getSalesTax(i, user_quantity);
}


void CashRegister::showTotals(Inventory i, int user_quantity) {

	cout << fixed << setprecision(2);
	cout << user_quantity << "X of " << i.getName() << "\n";
	cout << "Subtotal: $" << getSubTotal(i, user_quantity) << "\n";
	cout << "Sales Tax: $" << getSalesTax(i, user_quantity) << "\n";
	cout << "Grand Total: $" << getGrandTotal(i, user_quantity) << "\n";
	cout << "\n";

}

void CashRegister::deductQuantityFromStock(Inventory &i, int user_quantity) {

	int old_quantity = i.getQuantity();

	cout << "Deducting purchase from stockroom..." << "\n";

	i.setQuantity(old_quantity - user_quantity);

	cout << i.getQuantity() << "X " << i.getName() << " remain(s) in the stockroom." << "\n";
	cout << "\n";

}
