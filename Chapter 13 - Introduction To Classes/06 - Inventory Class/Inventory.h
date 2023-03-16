#ifndef INVENTORY_H
#define INVENTORY_H

class Inventory {

private:

	int itemNumber;
	double cost;
	int quantity;
	double totalCost;

public:

	Inventory();
	Inventory(int, double, int);

	void setItemNumber(int);	
	void setCost(double);
	void setQuantity(int);
	void setTotalCost();

	int getItemNumber() const;
	double getCost() const;
	int getQuantity() const;
	double getTotalCost() const;

	int numValidation(int);
	double numValidation(double);

};

#endif