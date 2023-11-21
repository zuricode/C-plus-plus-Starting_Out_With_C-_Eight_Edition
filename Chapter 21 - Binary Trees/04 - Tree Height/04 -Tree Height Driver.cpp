//4. Tree Height
//
//Write a member function, for either the template you designed in Programming Challenge 1 or the 
//IntBinaryTree class, that returns the height of the tree. The height of the tree is the number of 
//levels it contains. For example, the tree shown in Figure 21-10 has three levels.

#include "BinaryTree.h"

int main() {

	cout << "=========================\n";
	cout << "21-04 TREE HEIGHT DRIVER\n";
	cout << "=========================\n";
	cout << "\n";

	BinaryTree<char> tree_char;

	tree_char.insert('M');
	tree_char.insert('L');
	tree_char.insert('O');
	tree_char.insert('K');
	tree_char.insert('P');
	tree_char.insert('J');
	tree_char.insert('Q');
	tree_char.insert('Z');
	tree_char.insert('A');
	tree_char.insert('C');
	tree_char.insert('U');
	tree_char.insert('D');
	tree_char.insert('H');
	tree_char.insert('B');
	cout << "\n";

	cout << "BinaryTree Height: " << tree_char.getHeight() << " levels.\n";
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