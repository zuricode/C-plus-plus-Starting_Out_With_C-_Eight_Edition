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

using namespace std;

int main() {

	CashRegister store;
	Inventory item;

	cout << "13-17 CASH REGISTER PROGRAM\n";
	cout << "==================================\n";
	cout << "\n";

	item = store.askForItem();

	store.getCost(item);

	store.addProfit(item);

	store.showTotals(item);

}