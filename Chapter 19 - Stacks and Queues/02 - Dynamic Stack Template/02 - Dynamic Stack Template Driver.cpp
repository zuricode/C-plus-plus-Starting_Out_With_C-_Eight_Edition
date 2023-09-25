//2. Dynamic Stack Template
//
//Write your own version of a class template that will create a dynamic stack of any data type.
//Demonstrate the class with a driver program.

#include "DynamicStack.h"

int main() {

	cout << "=====================================\n";
	cout << "19-02 - DYNAMIC STACK TEMPLATE DRIVER\n";
	cout << "=====================================\n";
	cout << "\n";

	DynamicStack<int> intStack;
	int intValue;

	intStack.push(5);
	cout << "5 was pushed to the stack.\n";

	intStack.push(37);
	cout << "37 was pushed to the stack.\n";

	intStack.push(602);
	cout << "602 was pushed to the stack.\n";

	intStack.push(9941);
	cout << "9941 was pushed to the stack.\n";

	intStack.push(88602);
	cout << "88602 was pushed to the stack.\n";

	cout << "\n";

	intStack.pop(intValue);
	intStack.pop(intValue);
	intStack.pop(intValue);
	intStack.pop(intValue);
	intStack.pop(intValue);

	cout << "\n";

	intStack.pop(intValue);

	cout << "\n";

	cout << "Ending the program...\n";

}