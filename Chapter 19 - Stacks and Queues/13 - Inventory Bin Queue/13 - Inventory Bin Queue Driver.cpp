//13. Inventory Bin Queue
//
//Modify the program you wrote for Programming Challenge 12 (Inventory Bin Stack) so it uses a
//queue instead of a stack. Compare the order in which the parts are removed from the bin for each
//program.

#include "Inventory.h"

void showMenu(Inventory&);
void addItem(Inventory&);
void removeItem(Inventory&);

int main() {

	cout << "================================\n";
	cout << "19-13 INVENTORY BIN QUEUE DRIVER\n";
	cout << "================================\n";
	cout << "\n";

	Inventory stock;

	showMenu(stock);

	cout << "Quitting the program...\n";
	cout << "Removing any items in the inventory...\n";
	cout << "\n";

}

void showMenu(Inventory& inventory) {

	int choice;
	int counter = 0;

	do {

		cout << "-------------\n";
		cout << "     MENU    \n";
		cout << "-------------\n";
		cout << "\n";
		cout << "Inventory Items: " << inventory.getNodes() << "\n";
		cout << "\n";

		cout << "\t1 - Add Item to Inventory\n";
		cout << "\t2 - Remove Item from Inventory\n";
		cout << "\t3 - Quit program\n";
		cout << "\n";

		cout << "Enter your selection: ";

		while (!(cin >> choice) || (choice < 1 || choice > 3)) {
			cout << "ERROR: Selection must be between 1 - 3.\n";
			cout << "\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter your selection: ";
		}

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "\n";

		switch (choice) {

		case 1:
			addItem(inventory);
			break;
		case 2:
			removeItem(inventory);
			break;
		case 3:
			break;
		default:
			cout << "ERROR: Invalid output was chosen\n";
			break;

		}

	} while (choice != 3);

}

void addItem(Inventory& inventory) {

	inventory.enqueue();

}

void removeItem(Inventory& inventory) {

	inventory.dequeue();

}