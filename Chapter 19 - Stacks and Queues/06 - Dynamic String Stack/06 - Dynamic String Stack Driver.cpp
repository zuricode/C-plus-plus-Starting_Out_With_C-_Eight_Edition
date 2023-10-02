//6. Dynamic String Stack
//
//Design a class that stores strings on a dynamic stack. The strings should not be fixed in length
//. Demonstrate the class with a driver program.

#include "DynStrStack.h"

void menu(DynStrStack&);

int main() {

	cout << "=================================\n";
	cout << "19-06 DYNAMIC STRING STACK DRIVER\n";
	cout << "=================================\n";
	cout << "\n";

	DynStrStack stack;
	
	menu(stack);	

}

void menu(DynStrStack &s) {

	int choice = 0;
	int min = 1;
	int max = 4;

	while (choice != max) {

		cout << "MAIN MENU\n";
		cout << "--------------------------------------------------\n";
		cout << "\n";

		cout << "\t1. Push string\n";
		cout << "\t2. Pop string\n";
		cout << "\t3. Print stack\n";
		cout << "\t4. Exit program\n";
		cout << "\n";

		cout << "\tEnter your choice: ";

		while (cin >> choice && (choice < min || choice > max)) {
			cout << "\tERROR: Your choice be between " << min << " and " << max << ".\n";
			cin.ignore(1200, '\n');
			cin.clear();
			cout << "\n";
			cout << "\tEnter your choice: ";
		}

		cin.ignore(1200, '\n');
		cin.clear();
		
		cout << "\n";
		cout << "--------------------------------------------------\n";
		cout << "\n";

		switch (choice) {
			case 1:
				s.push();
				break;
			case 2:
				s.pop();
				break;
			case 3:
				s.print();
				break;
			case 4:
				cout << "Ending the program...\n";
				exit(EXIT_SUCCESS);
		}

	}

}