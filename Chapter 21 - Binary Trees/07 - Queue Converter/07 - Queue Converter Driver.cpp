//7. Queue Converter
//
//Write a program that stores a series of numbers in a binary tree. Then have the program insert the 
//values into a queue in ascending order. Dequeue the values and display them on the screen to 
//confirm that they were stored in the proper order.

#include "BinaryTree.h"

using std::move;

int main() {

	cout << "=====================\n";
	cout << "21-07 QUEUE CONVERTER\n";
	cout << "=====================\n";
	cout << "\n";

	BinaryTree tree;

	tree.insert(4);
	tree.insert(6);
	tree.insert(3);
	tree.insert(7);
	tree.insert(2);
	tree.insert(8);
	tree.insert(1);
	tree.insert(9);

	tree.search(5);
	tree.search(7);

	BinaryTree tree_2 = move(tree);

	tree_2.displayInOrder();
	tree_2.displayPreOrder();
	tree_2.displayPostOrder();

	tree.displayInOrder();
	tree.displayPreOrder();
	tree.displayPostOrder();


}