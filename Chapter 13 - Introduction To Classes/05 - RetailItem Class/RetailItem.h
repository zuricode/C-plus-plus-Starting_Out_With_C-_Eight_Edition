#ifndef RETAILITEM_H
#define RETAILITEM_H
#include<string>

using std::string;

class RetailItem {

private:

	string description;
	int unitsOnHand;
	double price;

public:

	RetailItem(string, int, double);

	void setDescription(string);
	void setUnits(int);
	void setPrice(double);

	string getDescription() const;
	int getUnits() const;
	double getPrice() const;

};

#endif