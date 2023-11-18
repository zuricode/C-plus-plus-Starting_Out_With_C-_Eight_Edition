//1. Binary Tree Template
//
//Write your own version of a class template that will create a binary tree that can hold values of 
//any data type. Demonstrate the class with a driver program.

#include "BinaryTreeTemplate.h"
#include <iostream>

int main() {

	cout << "=================================\n";
	cout << "21-01 BINARY TREE TEMPLATE DRIVER\n";
	cout << "=================================\n";
	cout << "\n";

	BinaryTreeTemplate<int> tree;

	tree.insert(8);
	tree.insert(1);
	tree.insert(3);
	tree.insert(2);
	tree.insert(0);
	tree.insert(10);
	tree.insert(8);
	tree.insert(1);
	tree.insert(3);
	tree.insert(2);
	tree.insert(0);
	tree.insert(10);

	tree.search();

	cout << "BinaryTree displayed in order: ";
	tree.displayInOrder();
	cout << "\n";
	cout << "\n";

	cout << "BinaryTree displayed in pre-order format: ";
	tree.displayPreOrder();
	cout << "\n";
	cout << "\n";

	cout << "BinaryTree displayed in post-order format: ";
	tree.displayPostOrder();
	cout << "\n";
	cout << "\n";

	tree.remove(3);

	cout << "BinaryTree displayed in pre-order format: ";
	tree.displayPreOrder();
	cout << "\n";
	cout << "\n";

}
