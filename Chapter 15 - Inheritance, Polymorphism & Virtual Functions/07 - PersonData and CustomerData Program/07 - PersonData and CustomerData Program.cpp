//7. PersonData and CustomerData classes
//
//Design a class named PersonData with the following member variables :
//
//• lastName
//• firstName
//• address
//• city
//• state
//• zip
//• phone
//
//Write the appropriate accessor and mutator functions for these member variables.
//
//Next, design a class named CustomerData, which is derived from the PersonData
//class.The CustomerData class should have the following member variables :
//
//• customerNumber
//• mailingList
//
//The customerNumber variable will be used to hold a unique integer for each customer.
//The mailingList variable should be a bool.It will be set to true if the customer
//wishes to be on a mailing list, or false if the customer does not wish to be on a mailing
//list.Write appropriate accessorand mutator functions for these member variables.
//Demonstrate an object of the CustomerData class in a simple program.

#include "CustomerData.h"

using namespace std;

int main() {

	cout << "======================================\n";
	cout << "07 - PERSONDATA & CUSTOMERDATA PROGRAM\n";
	cout << "======================================\n";
	cout << "\n";

	CustomerData profile;
	CustomerData profile_2;

	cin >> profile;
	cout << "\n";
	
	cout << "CUSTOMER PROFILE\n";
	cout << "----------------\n";
	cout << profile << "\n";


	cout << "CUSTOMER PROFILE\n";
	cout << "----------------\n";
	cout << profile_2 << "\n";

}