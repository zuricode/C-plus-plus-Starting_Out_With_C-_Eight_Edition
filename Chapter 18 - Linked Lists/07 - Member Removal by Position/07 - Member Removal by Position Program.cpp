//7. Member Removal by Position
//
//Modify the list class you created in the previous programming challenges by adding a member function for deleting
//a node at a specified position. A value of 0 for the position means the first node in the list (the current head)
//is deleted. The function does nothing if the specified position is greater than or equal tot he length of the list.

#include "NumberList.h"

int main() {

	cout << "===============================\n";
	cout << "07 - MEMBER REMOVAL BY POSITION\n";
	cout << "===============================\n";
	cout << "\n";

	NumberList list;

	list.print("EMPTY LIST");

	list.insertNode(3);
	list.insertNode(0);
	list.insertNode(1);
	list.insertNode(4);
	list.insertNode(2);
	list.insertNode(6);

	list.print("FIRST LIST");

	list.removeNodeAtPosition(2);

	list.print("UPDATED LIST");

	list.removeNodeAtPosition(3);

	list.print("UPDATED LIST");

	list.removeNodeAtPosition(2);

	list.print("UPDATED LIST");
	
	list.removeNodeAtPosition(1);

	list.print("UPDATED LIST");

	list.removeNodeAtPosition(1);

	list.print("UPDATED LIST");

	list.removeNodeAtPosition(0);

	list.print("UPDATED LIST");

	cout << "Ending the program.\n";
	cout << "\n";
}
