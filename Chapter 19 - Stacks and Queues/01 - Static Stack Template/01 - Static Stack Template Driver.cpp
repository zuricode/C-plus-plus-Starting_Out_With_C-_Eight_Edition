//1. Static Stack Template
//
//Write your own version of a class template that will create a static stack of any data type.
//Demonstrate the class with a driver program.

#include "Stack.h"
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

	Stack<string> stack_string(SIZE);
	Stack<int> stack_int(SIZE);

	stack_string.push("Margs");
	stack_string.push("Loons");
	stack_string.push("Richard");

	for (int i = 0; i < SIZE; i++) {
		stack_string.pop(value_string);
		cout << "\"" << value_string << "\" was popped from the array.\n";
	}

	cout << "\n";

	stack_int.push(7);
	stack_int.push(45);
	stack_int.push(908);
	
	for (int i = 0; i < SIZE; i++) {
		stack_int.pop(value_int);
		cout << "\"" << value_int << "\" was popped from the array.\n";
	}

	cout << "\n";

	cout << "Ending the program...\n";

}