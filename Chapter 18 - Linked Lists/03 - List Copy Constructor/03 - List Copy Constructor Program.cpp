//3. List Copy Constructor
//
//Modify the linked list of Porgramming Challenges 1 and 2 to add a copy constructor. Test your class by making
//a list, making a copy of the list, then displaying the values in the copy.

#include "NumberList.h"

int main() {

	cout << "===================================\n";
	cout << "18-03 LIST COPY CONSTRUCTOR PROGRAM\n";
	cout << "===================================\n";
	cout << "\n";

	NumberList list;

	list.insertNode(4);
	list.insertNode(1);
	list.insertNode(2);
	list.insertNode(5);
	list.insertNode(5);
	list.insertNode(5);
	list.insertNode(5);
	list.insertNode(5);
	list.insertNode(5);
	list.insertNode(3);
	list.insertNode(3);
	list.insertNode(3);
	list.insertNode(3);
	list.insertNode(3);
	list.insertNode(3);
	list.insertNode(7);

	NumberList list_2(list);

	cout << "ORIGINAL LIST\n";
	cout << "-------------\n";
	list.print();

	cout << "COPIED LIST\n";
	cout << "-----------\n";
	list_2.print();

}
