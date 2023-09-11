//12. Double Merge
//
//Modify the Numberlist class shown in this chapter to include a member function named mergeArray. The mergeArray
//function should take an array of doubles as its first argument, and an integer as its second argument. (The second 
//arguemnt will specify the size of the array being passed into the first arguemnt.)
//
//The function should merge the values in the array into the linked list. The value in each element of the array should
//be inserted (not appended) into the linked list. When the values are inserted,  they should be in numerical order.
//Demonstrate the function with a driver function. When you are satisfied with the function, incorporate it into the
//LinkedList template.

#include "NumberList.h"
#include <iostream>

using std::cout;
using std::cin;


int main() {

	srand(time(NULL));

	cout << "=====================\n";
	cout << "18-12 - DOUBLE MMERGE\n";
	cout << "=====================\n";
	cout << "\n";

	NumberList list;
	double doubles[5];

	for (int i = 0; i < 5; i++) {
		doubles[i] = rand() % 100 / 1.3234 + 1;
	}

	for (int i = 0; i < 5; i++) {
		cout << "Double value #" << i + 1 << ": " << doubles[i] << "\n";
	}

	cout << "\n";

	list.insertNode(300.543);
	list.insertNode(1003.35343);
	list.insertNode(63.543904933);
	list.insertNode(3.43);

	cout << "ORIGINAL LIST\n";
	cout << "-------------\n";
	list.displayList();

	list.mergeArray(doubles, 5);

	cout << "UPDATED LIST\n";
	cout << "----------- \n";
	list.displayList();

	cout << "Ending the program...\n";

}

