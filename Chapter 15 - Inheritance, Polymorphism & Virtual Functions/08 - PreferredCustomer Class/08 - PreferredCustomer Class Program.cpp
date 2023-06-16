//8. PreferredCustomer Class
//
//A retail store has a preferred customer plan where customers may earn discounts on all
//their purchases.The amount of a customer’s discount is determined by the amount of
//the customer’s cumulative purchases in the store.
//
//• When a preferred customer spends $500, he or she gets a 5 % discount on all future
//purchases.
//• When a preferred customer spends $1, 000, he or she gets a 6 % discount on all
//future purchases.
//• When a preferred customer spends $1, 500, he or she gets a 7 % discount on all
//future purchases.
//• When a preferred customer spends $2, 000 or more, he or she gets a 10 % discount
//on all future purchases.
//
//Design a class named PreferredCustomer, which is derived from the CustomerData
//class you created in Programming Challenge 7. The PreferredCustomer class should
//	have the following member variables :
//
//• purchasesAmount(a double)
//• discountLevel(a double)
//
//The purchasesAmount variable holds the total of a customer’s purchases to date.The
//discountLevel variable should be set to the correct discount percentage, according to
//the store’s preferred customer plan.Write appropriate member functions for this class
//and demonstrate it in a simple program.
//
//Input Validation : Do not accept negative values for any sales figures.

#include "PreferredCustomer.h"

using namespace std;

int main() {

	PreferredCustomer customer;

	cout << "====================================\n";
	cout << "15-08 PREFERREDCUSTOMER PROGRAM DEMO\n";
	cout << "====================================\n";
	cout << "\n";

	cout << "Enter the details for your customer...\n";
	cout << "\n";
	cin >> customer;
	cout << "\n";

	cout << "Example of a customer record...\n";
	cout << "\n";
	cout << customer << "\n";

}