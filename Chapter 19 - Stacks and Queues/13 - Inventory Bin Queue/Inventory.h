#ifndef INVENTORY_H
#define INVENTORY_H

#include "Date.h"
#include <iostream>
#include <limits>
#include <iomanip>

using std::setw; 
using std::left;
using std::right;
using std::numeric_limits;
using std::streamsize;
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
	inventoryNode* front;
	inventoryNode* rear;
	int nodes = 0;

public:
	Inventory() { front = nullptr; rear = nullptr; nodes = 0; }
	~Inventory();

	void enqueue();
	void dequeue();

	int getNodes() const { return nodes; }

	bool isEmpty() const;

};

#endif