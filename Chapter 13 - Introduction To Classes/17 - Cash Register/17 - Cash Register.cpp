//17. Cash Register
//
//Design a CashRegister class that can be used with the InventoryItem class discussed
//in this chapter.The CashRegister class should perform the following :
//
//1. Ask the user for the itemand quantity being purchased.
//2. Get the item’s cost from the InventoryItem object.
//3. Add a 30 % profit to the cost to get the item’s unit price.
//4. Multiply the unit price times the quantity being purchased to get the purchase subtotal.
//5. Compute a 6 % sales tax on the subtotal to get the purchase total.
//6. Display the purchase subtotal, tax, and total on the screen.
//7. Subtract the quantity being purchased from the onHand variable of the
//InventoryItem class object.
//
//Implement both classes in a complete program.Feel free to modify the InventoryItem
//class in any way necessary.
//
//Input Validation : Do not accept a negative value for the quantity of items being
//purchased.

#include "CashRegister.h"
#include "Inventory.h"
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>

using namespace std;

void displayInventory(vector<Inventory>);

int main() {

	CashRegister store;
	vector<Inventory> stockroom;
	int item_choice;
	int item_quantity;

	cout << "13-17 CASH REGISTER PROGRAM\n";
	cout << "==================================\n";
	cout << "\n";

	Inventory jerk_sauce("Walkerswood Jerk Sauce Jar (250g)", 34543, 2.49, 20);
	Inventory toilet_tissue("48 Rolls of Extra Soft Toilet Tissue", 45430, 12.99, 5);
	Inventory spring_water("1L Spring Water", 00533, 1.29, 50);
	Inventory lamb_chops("1kg Organic Lamb Chops", 88001, 11.49, 12);

	stockroom.push_back(jerk_sauce);
	stockroom.push_back(toilet_tissue);
	stockroom.push_back(spring_water);
	stockroom.push_back(lamb_chops);

	displayInventory(stockroom);

	item_choice = store.askForItem(stockroom);
	item_quantity = store.askForQuantity(stockroom[item_choice]);

	store.getCost(stockroom[item_choice]);
	store.addProfit(stockroom[item_choice]);
	store.showTotals(stockroom[item_choice], item_quantity);

	store.deductQuantityFromStock(stockroom[item_choice], item_quantity);

	displayInventory(stockroom);


}

void displayInventory(vector<Inventory> stockroom) {

	const int DIV = 80;

	cout << "INVENTORY STOCKROOM\n";
	cout << right << setfill('=') << setw(20) << "\n";
	cout << left << setfill(' ') << "\n";
	cout << setw(10) << "#" << setw(40) << "ITEM NAME" << setw(15) << "ITEM NUMBER" << setw(10) << "COST" << "QUANTITY\n";
	cout << right << setfill('-') << setw(DIV) << "\n";
	cout << left << setfill(' ');
	
	for (int i = 0; i < stockroom.size(); i++) {
		cout << "[" << i + 1 << setw(8) << "]" << setw(40) << stockroom[i].getName() << setw(15) << setprecision(0) << stockroom[i].getItemNumber() << "$" << fixed << setprecision(2) << setw(9) << stockroom[i].getCost() << setprecision(0) << stockroom[i].getQuantity() << "\n";
	}

	cout << right << setfill('-') << setw(DIV) << "\n";
	cout << "\n";

}
