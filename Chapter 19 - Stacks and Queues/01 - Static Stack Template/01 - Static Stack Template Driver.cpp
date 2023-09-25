//1. Static Stack Template
//
//Write your own version of a class template that will create a static stack of any data type.
//Demonstrate the class with a driver program.

#include "StaticStack.h"
#include<string>

using std::string;

int main() {

	string value_string;
	int value_int;

	cout << "==============================\n";
	cout << "CH 19-01 STATIC STACK TEMPLATE\n";
	cout << "==============================\n";
	cout << "\n";

	const int SIZE = 3;

	StaticStack<string> stack_string(SIZE);
	StaticStack<int> stack_int(SIZE);

	stack_string.push("Margs");
	cout << "Margs was pushed into the array\n";

	stack_string.push("Loons");
	cout << "Loons was pushed into the array\n";

	stack_string.push("Richard");
	cout << "Richard was pushed into the array\n";

	cout << "\n";

	for (int i = 0; i < SIZE; i++) {
		stack_string.pop(value_string);
		cout << "\"" << value_string << "\" was popped from the array.\n";
	}

	cout << "\n";

	stack_int.push(7);
	cout << "7 was pushed into the array\n";

	stack_int.push(45);
	cout << "45 was pushed into the array\n";

	stack_int.push(908);
	cout << "908 was pushed into the array\n";

	cout << "\n";
		
	for (int i = 0; i < SIZE; i++) {
		stack_int.pop(value_int);
		cout << "\"" << value_int << "\" was popped from the array.\n";
	}

	cout << "\n";

	cout << "Ending the program...\n";

}