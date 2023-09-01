//4. List Reverse
//
//Modify the linked list class you created in the previous programming challenges by adding a member function
//named reverse that rearranges the ndoes in the list so their order is reversed. Demonstrate the function in
//a simple driver program.

#include "NumberList.h"

int main() {

	srand(time(NULL));

	cout << "==========================\n";
	cout << "18-04 LIST REVERSE PROGRAM\n";
	cout << "==========================\n";
	cout << "\n";

	NumberList list;

	for (int i = 0; i < 20; i++) {
		list.insertNode((rand() % 100 + 1));
	}

	NumberList list_2(list);
	
	list.print("ORIGINAL LIST");

	list.reverse();

	list.print("REVERSED LIST");

}