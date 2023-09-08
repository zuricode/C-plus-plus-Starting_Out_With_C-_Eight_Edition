//11. List Search
//
//Modify the LinkedList template shown in this chapter to include a member function named search. The fucntion should
//search the list for a specified value. If the value is found, it should return a number indicating its position in
//the list. (The first node is node 1, the second node is node 1, and so forth). If the value is not found, the
//function should return 0. Demonstrate the function in a driver program.

#include "LinkedList.h"
#include <string>

using std::string;

template <class T> void searchValuePosition(const LinkedList<T>&);

int main() {

	cout << "=================\n";
	cout << "18-11 LIST SEARCH\n";
	cout << "=================\n";
	cout << "\n";

	LinkedList<string> list;

	list.insertNode("kojo");
	list.insertNode("nana");
	list.insertNode("diop");
	list.insertNode("shona");
	list.insertNode("shango");
	list.insertNode("dele");
	list.insertNode("wolof");

	searchValuePosition(list);
	searchValuePosition(list);


	cout << "Ending the program...\n";

}

template <class T>
void searchValuePosition(const LinkedList<T>& LIST) {

	T value;
	int position;

	cout << "Enter a value to search for: ";
	cin >> value;
	cin.ignore(1200, '\n');
	cin.clear();

	position = LIST.search(value);

	if (position != 0) {
		cout << "Value \"" << value << "\" was found at position #" << position << ".\n";
	}
	else {
		cout << "Value \"" << value << "\" does not existed in this LinkedList object.\n";
	}

	cout << "\n";

}