//6. Member Insertion by Position
//
//Modify the list class you created in the previous programming challenges by adding a member function
//for inserting a new item at a specified position. A position of 0 means that the value will become the
//first item on the list, a position of 1 means the value will become the second item on the list, and
//so on. A position equal to or greater than the length of the list means the value is placed at the end
//of the list.

#include "NumberList.h"

int main() {

	cout << "====================================\n";
	cout << "18-06 - MEMBER INSERTION BY POSITION\n";
	cout << "====================================\n";
	cout << "\n";

	NumberList list;

	list.insertNode(5);
	list.insertNode(2);
	list.insertNode(3);
	list.insertNode(6);
	list.insertNode(1);

	list.print("ORIGINAL LIST");

	list.insertValueAtPosition(0,0);
	list.print("UPDATED LIST");

	list.insertValueAtPosition(1,345);
	list.print("UPDATED LIST");

	list.insertValueAtPosition(14,-235);
	list.print("UPDATED LIST");
	
	list.insertValueAtPosition(4, 543389534);
	list.print("UPDATED LIST");


}