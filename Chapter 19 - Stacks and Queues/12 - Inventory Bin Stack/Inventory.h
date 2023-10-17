#ifndef INVENTORY_H
#define INVENTORY_H

#include "Date.h"
#include <iostream>

using std::cout;
using std::cin;

class Inventory {

	struct inventoryNode {
		int serialNum = -1;
		Date manufactDate;
		int lotNum = -1;
		inventoryNode* next = nullptr;
	};

private:
	inventoryNode* top;
	int nodes;

public:
	Inventory() { top = nullptr; nodes = 0; }
	~Inventory();

	void push();
	void pop();

	bool isEmpty() const;

};

#endif