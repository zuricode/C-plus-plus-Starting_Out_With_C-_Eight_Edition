//2. List Print
//
//Modify the linked list class you created in Programming Challenge 1 to add a print member function. The function
//should display all the values in the linked list. Test the class by starting with an empty list, adding some
//elements, then printing the resulting list out.

#include "NumberList.h"

int main() {

	NumberList list;

	cout << "================\n";
	cout << "18-02 LIST PRINT\n";
	cout << "================\n";
	cout << "\n";

	list.print();

	list.insertNode(4);
	list.insertNode(20);
	list.insertNode(1);
	list.insertNode(8);
	list.insertNode(25);

	list.print();

}