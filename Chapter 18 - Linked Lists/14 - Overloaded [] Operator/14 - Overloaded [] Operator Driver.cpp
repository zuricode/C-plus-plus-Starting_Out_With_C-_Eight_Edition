//14 . Overloaded [] Operator
//
//Modify the linked list class you created in Programming Challenge 1 (or the LinkedList template presented in this
//chapter) by adding an overloaded [] operator function. This will give the linked list the ability to access nodes
//using a subscript, like an array. The subscript 0 will reference the first node in the list, the subscript 1 will
//reference the second node in the list, and so forth. The subscript of the last node will be the number of nodes
//minus 1. If an invalid subscript is used, the function should throw an exception.

#include "NumberList.h"

int main() {

	srand(time(NULL));

	cout << "===================================\n";
	cout << "18-14 OVERLOADED [] OPERATOR DRIVER\n";
	cout << "===================================\n";
	cout << "\n";

	NumberList list;
	int size;

	cout << "Enter the size of your NumberList: ";

	while (!(cin >> size) || size <= 0 || size >= 20) {
		cout << "ERROR: Size of the NumberList must be greater than 0 amd less than 20.\n";
		cout << "\n";
		cin.ignore(1200, '\n');
		cin.clear();
		cout << "Enter the size of your NumberList: ";
	}

	cin.ignore(1200, '\n');
	cin.clear();
	cout << "\n";

	for (int i = 0; i < size; i++) {
		list.appendNode(rand() % size + 1);
	}

	list.displayList();

	for (int i = 0; i < size + 5; i++) {
		try {
			cout << "Node #" << i + 1 << " = " << list[i] << "\n";
		}
		catch (NumberList::invalidSubscript e) {
			cout << "ERROR: [" << e.getSubscript() << "]" << " is not an invalid subcript within this NumberList.\n";
		}
	}

	cout << "\n";
	cout << "Ending the program...\n";

}

