//10. maxNode Function
//
//Add a member function named maxNode to the NumberList class discussed in this chapter. The function 
//should return the largest value stored in the list. Use recursion in the function to traverse the 
//list. Demonstrate the function in a driver program.

#include "NumberList.h"
#include <iostream>

using std::cout;

int main() {

	cout << "=============================\n";
	cout << "20-10 MAXNODE FUNCTION DRIVER\n";
	cout << "=============================\n";
	cout << "\n";

	NumberList list;
	double max = -1;

	list.appendNode(4.67);
	list.insertNode(41.7);
	list.appendNode(870000.065);
	list.insertNode(54.47);
	list.insertNode(350453.04);
	list.appendNode(4532.4);

	list.displayList();

	cout << "\n";
	cout << "\n";

	cout << "The largest number in the list is " << list.getMax() << "\n";
	cout << "\n";

	cout << "Ending the program...\n";

}