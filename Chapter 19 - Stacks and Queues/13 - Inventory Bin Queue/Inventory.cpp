#include "Inventory.h"

Inventory::~Inventory() {

	inventoryNode* temp = nullptr;

	while (front != nullptr) {

		dequeue();

	}

	cout << "Inventory destructor was successful. Stack was emptied.\n";

}

void Inventory::enqueue() {

	int value;
	inventoryNode* newNode = new inventoryNode;

	cout << "Adding item to inventory...\n";
	cout << "---------------------------\n";
	cout << "\n";

	cout << "Serial Number: ";

	while (!(cin >> value) && value <= 0) {
		cout << "ERROR: Serial number must be a positive integer.\n";
		cout << "\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Serial Number: ";
	}

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	newNode->serialNum = value;
	newNode->manufactDate.setDate();

	cout << "Lot Number: ";

	while (!(cin >> value) || value <= 0) {
		cout << "ERROR: Lot number must be a positive integer.\n";
		cout << "\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Lot Number: ";
	}

	cout << "\n";
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	newNode->lotNum = value;
	newNode->next = nullptr;

	if (isEmpty()) {
		front = newNode;
		rear = front;
	}

	else {
		rear->next = newNode;
		rear = newNode;
	}

	nodes++;

	cout << "ITEM ADDED: Serial Number: " << newNode->serialNum << "\n";
	cout << right << setw(12) << "" << "Manufacturer Date : " << newNode->manufactDate.getDate() << "\n";
	cout << setw(12) << "" << "Lot Number : " << newNode->lotNum << "\n";
	cout << "\n";

}

void Inventory::dequeue() {

	int serialNum;
	string manufactDate;
	int lotNum;

	inventoryNode* temp = nullptr;

	if (isEmpty()) {
		cout << "ERROR: pop function failed. Inventory stack is empty.\n";
		cout << "\n";
	}
	else {

		serialNum = front->serialNum;
		manufactDate = front->manufactDate.getDate();
		lotNum = front->lotNum;

		temp = front->next;
		delete front;
		front = temp;

		nodes--;

		cout << "ITEM REMOVED: Serial Number: " << serialNum << "\n";
		cout << right << setw(14) << "" << "Manufacturer Date : " << manufactDate << "\n";
		cout << setw(14) << "" << "Lot Number : " << lotNum << "\n";
		cout << "\n";

	}

}

bool Inventory::isEmpty() const {

	if (front == nullptr) {
		return true;
	}
	else {
		return false;
	}

}