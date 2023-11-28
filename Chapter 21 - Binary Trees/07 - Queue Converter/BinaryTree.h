#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "Queue.h"
#include <iostream>

using std::cout;

class BinaryTree {

private:

	struct TreeNode {
		int value;
		TreeNode* left;
		TreeNode* right;
	};

	TreeNode* root;

	void removeSubTree(TreeNode*);
	void copySubTree(const TreeNode*, TreeNode*&);
	void insertNode(TreeNode*&, TreeNode*&);
	bool searchNodes(TreeNode*, const int);
	void displayInOrder(const TreeNode*);
	void displayPreOrder(const TreeNode*);
	void displayPostOrder(const TreeNode*);
	void deleteNode(TreeNode*&, const int);
	void makeDeletion(TreeNode*&);
	void exportQueue(const TreeNode*, Queue&);


public:

	BinaryTree();									//Default constructor
	~BinaryTree();									//Destructor
	BinaryTree(const BinaryTree&);					//Copy constructor
	BinaryTree& operator=(const BinaryTree&);		//Copy assignment operator
	BinaryTree(BinaryTree&&);						//Move constructor
	BinaryTree& operator=(BinaryTree&&);			//Move assignment operator
	
	void insert(const int);
	void search(const int);
	void displayInOrder();
	void displayPreOrder();
	void displayPostOrder();
	void remove(const int);
	void deleteTree();
	void exportToQueue(Queue&);


};

#endif