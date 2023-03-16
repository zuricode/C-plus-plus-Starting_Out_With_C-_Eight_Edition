#include "Inventory.h"
#include <iostream>

using std::cout;
using std::cin;


Inventory::Inventory() {

	itemNumber = 0;
	cost = 0;
	quantity = 0;
	totalCost = 0;

}

Inventory::Inventory(int i, double c, int q) {

	i = numValidation(i);
	c = numValidation(c);
	q = numValidation(q);

	itemNumber = i;
	cost = c;
	quantity = q;

	setTotalCost();

}

void Inventory::setItemNumber(int i) {
	i = numValidation(i);
	itemNumber = i;
}

void Inventory::setCost(double c) {
	c = numValidation(c);
	cost = c;
}

void Inventory::setQuantity(int q) {
	q = numValidation(q);
	quantity = q;
}

void Inventory::setTotalCost() {
	totalCost = quantity * cost;
}

int Inventory::getItemNumber() const {
	return itemNumber;
}

double Inventory::getCost() const {
	return cost;
}

int Inventory::getQuantity() const {
	return quantity;
}

double Inventory::getTotalCost() const {
	return totalCost;
}

int Inventory::numValidation(int num) {

	while (num < 0) {
		cout << "ERROR: " << num << " is a negative value. Negative values are not accepted. Re-enter your value : ";
		cin >> num;
		cin.ignore();
		cout << '\n';
	}

	return num;

}

double Inventory::numValidation(double num) {

	while (num < 0) {
		cout << "ERROR: " << num << " is a negative value. Negative values are not accepted. Re-enter your value : ";
		cin >> num;
		cin.ignore();
		cout << '\n';
	}

	return num;

}