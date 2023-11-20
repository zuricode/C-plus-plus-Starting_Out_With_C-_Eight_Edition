//3. Leaf Counter
//
//Write a member function, for either the template you designed in Porgramming Challenge 1 or the 
//IntBinaryTree class, that counts and returns the number of leaf nodes in the tree. Demonstrate the 
//function in a driver program.

#include "BinaryTree.h"

int main() {

	cout << "=========================\n";
	cout << "21-03 LEAF COUNTER DRIVER\n";
	cout << "=========================\n";
	cout << "\n";

	BinaryTree<char> tree_char;

	tree_char.insert('M');
	tree_char.insert('Z');
	tree_char.insert('A');
	tree_char.insert('C');
	tree_char.insert('U');
	tree_char.insert('D');
	tree_char.insert('H');
	tree_char.insert('B');
	cout << "\n";

	cout << "This BinaryTree currently has " << tree_char.getLeafNodes() << " leaf node(s).\n";
	cout << "\n";

	tree_char.displayInOrder();
	tree_char.displayPreOrder();
	tree_char.displayPostOrder();
	cout << "\n"; 

	tree_char.search('D');
	tree_char.search('X');
	tree_char.search('C');

	tree_char.remove('A');
	tree_char.remove('E');
	tree_char.remove('U');
	tree_char.remove('B');
	cout << "\n";

	tree_char.displayInOrder();
	tree_char.displayPreOrder();
	tree_char.displayPostOrder();
	cout << "\n";

	cout << "This BinaryTree currently has " << tree_char.getLeafNodes() << " leaf node(s).\n";
	cout << "\n";

	cout << "Ending the program...\n";
	cout << "\n";

}