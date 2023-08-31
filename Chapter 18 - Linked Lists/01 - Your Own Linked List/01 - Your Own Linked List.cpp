//1. Your Own Linked List
//
//Design your own linked list class to hold a series of integers. The class should have
//member fundtions for appending, inserting and deleting nodes. Don't forget to a add a
//destructor that destorys the list. Demonstrate the class with a driver program.

#include "NumberList.h"

int main() {

	cout << "==========================\n";
	cout << "18-01 YOUR OWN LINKED LIST\n";
	cout << "==========================\n";
	cout << "\n";

	NumberList list;

	list.appendNode(4);
	list.appendNode(8);
	list.appendNode(16);
	list.appendNode(32);

	list.displayList();

	list.deleteNode(16);
	list.deleteNode(4);

	list.displayList();

	list.insertNode(15);
	list.insertNode(10);
	list.insertNode(5);

	list.displayList();


}