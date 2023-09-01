//5. List Search
//
//Modify the linked list class you created in the previous programming challenges to include
//a member function named search that returns the position of a specific value, x in the
//linked list. The first node in the list is a position 0m the second node is at position
//1, and so on. If x is not found on the list, the search should return -1. Test the new
//member function using an appropriate driver program.

#include "NumberList.h"

int main() {

	srand(time(NULL));

	cout << "=========================\n";
	cout << "18-05 LIST SEARCH PROGRAM\n";
	cout << "=========================\n";
	cout << "\n";

	NumberList list;
	int position;
	int num;


	for (int i = 0; i < 10; i++) {
		list.insertNode((rand() % 100 + 1));
	}

	list.print("ORIGINAL LIST");

	cout << "Enter an interger to search for within the linked list: ";
	cin >> num;
	cin.ignore();
	cin.clear();

	position = list.search(num);

	if (position != -1) {
		cout << num << " was found at Position #" << position << ".\n";
	}
	else {
		cout << num << " was not found in the linked list.\n";
	}

	cout << "\n";

	cout << "Ending the program...\n";

}

