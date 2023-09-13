//15. pop and push Member Functions
//
//The STL list container has member functions named pop_back, pop_front, push_back, push_front, as described in Table
//18 - 2. Modify the linked list class you created in Programming Challenge 1 (or the LinkedList template presented in
//this chapter) by adding your own versions of these member functions.

#include "NumberList.h"

int main() {

	cout << "==========================================\n";
	cout << "18-15 POP AND PUSH MEMBER FUNCTIONS DRIVER\n";
	cout << "==========================================\n";
	cout << "\n";

	NumberList list;

	cout << "Adding three arbitrary nodes with values...\n";
	cout << "\n";

	list.insertNode(3);
	list.insertNode(5);
	list.insertNode(1);

	list.displayList();

	list.pop_back();

	list.displayList();

	list.pop_front();

	list.displayList();

	list.pop_back();

	list.displayList();

	list.push_back(12);

	list.displayList();

	list.push_back(19);

	list.displayList();

	list.push_front(9);

	list.displayList();

	list.push_front(3);

	list.displayList();

	list.pop_front();

	list.displayList();

	list.pop_front();

	list.displayList();

}