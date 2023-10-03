//8. Dynamic MathStack Template
//
//Currently, the MathStack class is derived from the IntStack class. Modify it so it is a 
//template, derived from the template you created in Programming Challenge 2 (Dynamic Stack
//Template).

#include "MathStack Template.h"

int main() {

	cout << "=======================================\n";
	cout << "19-08 DYNAMIC MATHSTACK TEMPLATE DRIVER\n";
	cout << "=======================================\n";
	cout << "\n";

	const int SIZE = 5;
	double value{};

	MathStack<double> stack(SIZE);

	stack.push(5.567);
	stack.push(7.0234);
	stack.push(9.1045);
	stack.push(2.05);
	stack.push(14.234);

	stack.mult();
	stack.div();
	stack.addAll();

	stack.push(5.567);
	stack.push(7.0234);
	stack.push(9.1045);
	stack.push(2.05);

	stack.multAll();

	cout << "Ending the program...\n";

}