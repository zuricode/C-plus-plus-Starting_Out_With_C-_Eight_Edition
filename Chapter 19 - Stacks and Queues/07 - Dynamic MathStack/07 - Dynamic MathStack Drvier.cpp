//7. Dynamic MathStack
//
//The MathStack class shown in this vhapter has only two member functions: add and sub.
//Write the following additional member functions:
//
//Function	Description
//------------------------------------------------------------------------------------
//mult		Pops the top two values off the stack, multiples them and pushes their
//			product onto the stack.
// 
//div		Pops the top two values off the stack, divides the second value by the
//			first and pushes the quotient onto the stack.
// 
//addAll	Pops all values off the stack, adds them, and pushes their sum onto
//			the stack.
// 
//multAll	Pops all values off the stack, multiplies them, and pushes their product
//			onto the stack.
//------------------------------------------------------------------------------------
//
//Demonstrate the class wit a driver program.

#include "MathStack.h"

void print(const MathStack);

int main() {

	cout << "==============================\n";
	cout << "19-07 DYNAMIC MATHSTACK DRIVER\n";
	cout << "==============================\n";
	cout << "\n";

	const int SIZE = 5;
	int value;

	MathStack stack(SIZE);

	stack.push(5);
	stack.push(7);
	stack.push(9);
	stack.push(2);
	stack.push(14);

	stack.mult();
	stack.div();
	stack.addAll();

	stack.push(5);
	stack.push(7);
	stack.push(9);
	stack.push(2);

	stack.multAll();

	cout << "Ending the program...\n";

}