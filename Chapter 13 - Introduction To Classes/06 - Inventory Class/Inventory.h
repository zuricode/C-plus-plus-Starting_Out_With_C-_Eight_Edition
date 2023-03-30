#ifndef INVENTORY_H
#define INVENTORY_H
#include<string>

using std::string;

class Inventory {

private:

	string name;
	int itemNumber;
	double cost;
	int quantity;
	double totalCost;

public:

	Inventory();
	Inventory(string, int, double, int);

	void setName(string n);
	void setItemNumber(int);	
	void setCost(double);
	void setQuantity(int);
	void setTotalCost();

	string getName() const { return name; }
	int getItemNumber() const;
	double getCost() const;
	int getQuantity() const;
	double getTotalCost() const;

	int numValidation(int);
	double numValidation(double);
	string stringValidation();

	~Inventory();

};

#endif