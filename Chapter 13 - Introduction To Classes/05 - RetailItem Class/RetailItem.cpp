#include "RetailItem.h"


RetailItem::RetailItem(string d, int u, double p) {

	description = d;
	unitsOnHand = u;
	price = p;

}

void RetailItem::setDescription(string d) {
	description = d;
}

string RetailItem::getDescription() const {
	return description;
}

void RetailItem::setUnits(int u) {
	unitsOnHand = u;
}

int RetailItem::getUnits() const {
	return unitsOnHand;
}

void RetailItem::setPrice(double p) {
	price = p;
}

double RetailItem::getPrice() const {
	return price;
}
