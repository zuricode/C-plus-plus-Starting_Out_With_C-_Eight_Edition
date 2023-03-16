#include "RetailItem.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;
using std::setw;
using std::setfill;
using std::left;
using std::right;

void displayStockTable(RetailItem*, const int);

int main() {

	const int INVENTORY_SIZE = 3;

	RetailItem stock[INVENTORY_SIZE]{
		{"Jacket", 12, 59.95},
		{"Designer Jeans", 40, 34.95},
		{"Shirt", 20, 24.95 }
	};

	displayStockTable(stock, INVENTORY_SIZE);

}

void displayStockTable(RetailItem* stockPtr, const int SIZE) {

	cout << "INVENTORY OF RETAIL STOCK: " << endl;
	cout << endl;
	cout << right << setfill('-') << setw(70) << '\n';
	cout << left << setfill(' ') << setw(20) << "" << setw(20) << "Description" << setw(20) << "Units On Hand" << setw(30) << "Price" << endl;
	cout << setfill('-') << right << setw(70) << '\n';
	cout << setfill(' ');

	for (int i = 0; i < SIZE; i++) {

		cout << left << "Item #" << setw(14) << i + 1 << setw(20) << stockPtr[i].getDescription()
			<< setprecision(0) << setw(20) << stockPtr[i].getUnits() << fixed
			<< setprecision(2) << stockPtr[i].getPrice() << endl;
	
	}

	cout << setfill('-') << right << setw(70) << '\n';

	cout << endl;

}
