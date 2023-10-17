#include "Inventory.h"
#include <limits>

using std::numeric_limits;
using std::streamsize;

Inventory::~Inventory() {

	inventoryNode* temp = nullptr;

	while (top != nullptr) {
		temp = top->next;
		delete top;
		top = temp;
	}

}

void Inventory::push() {

	int value;
	inventoryNode* newNode = new inventoryNode;

	cout << "Adding item to inventory...\n";
	cout << "---------------------------\n";
	cout << "\n";

	cout << "Serial Number: ";

	while (cin >> value && value <= 0) {
		cout << "ERROR: Serial number must be a positive integer.\n";
		cout << "\n";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.clear();
		cout << "Serial Number: ";
	}

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.clear();
	newNode->serialNum = value;
	newNode->manufactDate.setDate();

	cout << "Lot Number: ";

	while (!(cin >> value) || value <= 0) {
		cout << "ERROR: Lot number must be a positive integer.\n";
		cout << "\n";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Lot Number: ";
	}

	cout << "\n";
	cin.ignore(1200, '\n');
	cin.clear();

	newNode->lotNum = value;
	newNode->next = nullptr;

	if (isEmpty()) {
		top = newNode;
	}

	else {

		top->next = newNode;
		top = newNode;

	}

	cout << "Item \"" << newNode->serialNum << "\" was successfully added to the inventory.\n";
	cout << "\n";

}

void Inventory::pop() {

	int serialNum;
	string manufactDate;
	int lotNum;

	inventoryNode* temp = nullptr;

	if (isEmpty()) {
		cout << "ERROR: pop function failed. Inventory stack is empty.\n";
		cout << "\n";
	}
	else {

		serialNum = top->serialNum;
		manufactDate = top->manufactDate.getDate();
		lotNum = top->lotNum;

		temp = top->next;
		delete top;
		top = temp;

		cout << "ITEM REMOVED: Serial Number: " << serialNum << " >>> Manufacturer Date: " << manufactDate << " >>> Lot Number: " << lotNum << "\n";
		cout << "\n";

	}

}

bool Inventory::isEmpty() const {

	if (top == nullptr) {
		return true;
	}
	else {
		return false;
	}

}