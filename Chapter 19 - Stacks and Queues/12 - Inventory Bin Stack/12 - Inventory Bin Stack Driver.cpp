//12. Inventory Bin Stack
//
//Design an inventory class that stores the following members:
//
//serialNum:		An integer that holds a part's serial number.
//manufactDate:		A member that holds the date the part was manufactured.
//lotNum:			An integer that holds the part's lot number.
//
//The class should have appropriate member functions for storing data into, and retrieving data 
//from, these members.
//
//Next, design a stack class that can hold objects of the class described above. If you wish,
//you may use the tempate you designed in Programming Challenge 1 or 2.
//
//Last, design a program that uses the stack class described above. The program should have a loop 
//that asks the user if he or she wishes to add a part to inventory, or take a apart from inventory.
//The loop should repeat until the user is finished.
//
//If the user wishes to add a part to inventory, the program should ask for the serial number, date 
//of manufacture, and lot number. The data should be stored in an inventory object, and pushed onto 
//the stack.
//
//If the user wishes to take a part from inventory, the program should pop the top-most part from 
//the stack and display the contents of its member variables.
//
//When the user finishes the program, it should display the contents of the member values of all the 
//objects that remain on the stack.

#include "Inventory.h"

void showMenu(Inventory&);
void addItem(Inventory&);
void removeItem(Inventory&);

int main() {

	cout << "================================\n";
	cout << "19-12 INVENTORY BIN STACK DRIVER\n";
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

		cout << "\t1 - Add Item to Inventory\n";
		cout << "\t2 - Remove Item from Inventory\n";
		cout << "\t3 - Quit program.\n";
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

	inventory.push();

}

void removeItem(Inventory& inventory) {

	inventory.pop();

}