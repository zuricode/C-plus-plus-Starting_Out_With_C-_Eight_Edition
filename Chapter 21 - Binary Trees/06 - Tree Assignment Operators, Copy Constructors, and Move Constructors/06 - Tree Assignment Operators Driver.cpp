//6. Tree Assignment Operators, Copy Constructors, and Move Constructors
//
//Design an overloaded copy assignment operator, a move assignment operator, a copy constructor, and 
//a move constructor for either the template you designed in Programming Challenge 1 or the 
//IntBinaryTree class. Demonstrate them in a driver program.

#include "BinaryTree.h"
#include <iostream>

using std::cout;
using std::move;

int main() {

	cout << "=========================================================================\n";
	cout << "21-06 TREE ASSIGNMENT OPERATORS, COPY CONSTRUCTORS, AND MOVE CONSTRUCTORS\n";
	cout << "=========================================================================\n";
	cout << "\n";

	BinaryTree<int> tree_int;
	BinaryTree<int> tree_int_3;

	tree_int.insert(3);
	tree_int.insert(2);
	tree_int.insert(8);
	tree_int.insert(5);
	tree_int.insert(6);
	tree_int.insert(8);
	tree_int.insert(1);
	tree_int.insert(0);
	cout << "\n";

	BinaryTree<int> tree_int_copied(tree_int);

	tree_int_copied = tree_int_3;

	tree_int_3 = move(tree_int_copied);

	BinaryTree<int> tree_int_2(move(tree_int));


}