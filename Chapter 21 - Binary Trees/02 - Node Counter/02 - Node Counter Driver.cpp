//2. Node Counter
//
//Write a member function, for either the template you designed in Programming Challenge 1 or the 
//IntBinaryTree class, that counts and returns the number of nodes in the tree. Demonstrate the 
//function in a driver function.

#include "BinaryTree.h"
#include <string>

using std::string;
using std::numeric_limits;
using std::streamsize;

int main() {

	string val_str{ "" };
	int val_int = 0;

	cout << "===========================\n";
	cout << "21-02 - NODE COUNTER DRIVER\n";
	cout << "===========================\n";
	cout << "\n";

	BinaryTree<string> tree_strings;

	tree_strings.insert("Blue");
	tree_strings.insert("Green");
	tree_strings.insert("Amber");
	tree_strings.insert("Yellow");
	tree_strings.insert("Red");
	tree_strings.insert("Orange");
	tree_strings.insert("Violet");
	tree_strings.insert("Grey");
	
	cout << "\n";

	tree_strings.search("Orange");
	tree_strings.search("Purple");

	tree_strings.displayInOrder();
	tree_strings.displayPreOrder();
	tree_strings.displayPostOrder();
	cout << "\n";

	cout << "The binary tree currently has " << tree_strings.nodeCounter() << " node(s).\n";
	cout << "\n";

	tree_strings.remove("Grey");
	tree_strings.remove("Green");

	tree_strings.displayInOrder();
	tree_strings.displayPreOrder();
	tree_strings.displayPostOrder();
	cout << "\n";

	cout << "The binary tree currently has " << tree_strings.nodeCounter() << " node(s).\n";
	cout << "\n";

	cout << "Ending the program...\n";
	cout << "\n";

}