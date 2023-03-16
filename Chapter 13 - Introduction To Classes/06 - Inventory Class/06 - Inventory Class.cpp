#include "Inventory.h"
#include<iostream>
#include<iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::fixed;
using std::setprecision;
using std::setfill;
using std::setw;
using std::left;
using std::right;


void displayStock(Inventory*, const int);

int main() {

	const int SIZE = 3;

	Inventory stock[3]{ {453786543, 59.99, 55} };

	stock[1];
	
	stock[2];

	stock[2].setItemNumber(47547457);
	stock[2].setCost(159.49);
	stock[2].setQuantity(20);
	stock[2].setTotalCost();

	displayStock(stock, SIZE);

}

void displayStock(Inventory* stock, const int SIZE) {

	cout << "INVENTORY DEMO" << endl;
	cout << right << setfill('-') << setw(65) << '\n';
	cout << left << setfill(' ') << setw(10) << "" << setw(15) << "Item Number" << setw(10) << 
		"Cost" << setw(15) << "Quantity" << "Total Cost" << endl;
	cout << right << setfill('-') << setw(65) << '\n';
	
	for (int i = 0; i < SIZE; i++) {

		cout << left << setfill(' ') << "Item #" << setprecision(0) << setw(4) << i + 1 << setw(14) << stock[i].getItemNumber() <<
			"$" << fixed << setprecision(2) << setw(10) << stock[i].getCost() << setprecision(0) <<
			setw(14) << stock[i].getQuantity() << "$" << setprecision(2) << stock[i].getTotalCost() << endl;

	}

	cout << right << setfill('-') << setw(65) << '\n';
	cout << endl;

}
