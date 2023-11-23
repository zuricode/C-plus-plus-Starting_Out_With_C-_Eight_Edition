//5. Tree Width
//
//Write a member function, for either the template you designed in Programming Challenge 1 or the 
//IntBinaryTree class, that returns the width of the tree. The width of the tree is the largest 
//number of nodes in the same level. Demonstrate the function in a driver program.

#include "BinaryTree.h"

int main() {

	cout << "=========================\n";
	cout << "21-05 TREE WIDTH DRIVER\n";
	cout << "=========================\n";
	cout << "\n";

	BinaryTree<char> tree_char;

	tree_char.insert('M');
	tree_char.insert('Y');
	tree_char.insert('A');
	tree_char.insert('N');
	tree_char.insert('E');
	tree_char.insert('M');
	tree_char.insert('P');
	tree_char.insert('S');
	tree_char.insert('D');
	tree_char.insert('E');
	tree_char.insert('U');
	tree_char.insert('D');
	tree_char.insert('S');
	tree_char.insert('U');
	cout << "\n";

	cout << "BinaryTree Height: " << tree_char.getHeight() << " levels.\n";
	cout << "BinaryTree Width: " << tree_char.getWidth() << " nodes.\n";
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

	cout << "BinaryTree Height: " << tree_char.getHeight() << " levels.\n";
	cout << "\n";

	tree_char.displayInOrder();
	tree_char.displayPreOrder();
	tree_char.displayPostOrder();
	cout << "\n";

	cout << "Ending the program...\n";
	cout << "\n";

}