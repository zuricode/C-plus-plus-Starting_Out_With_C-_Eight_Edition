#ifndef BINARYTREE_H
#define BINARYTREE_H

//#include "EmployeeInfo.h"

template <class T>
class BinaryTree {

private:

	struct TreeNode {
		T item;
		TreeNode* left;
		TreeNode* right;
	};

	TreeNode* root;

	void copySubTree(TreeNode*, TreeNode*&);
	void removeSubTree(TreeNode*&);
	void insert(TreeNode*&, TreeNode*&);

public:

	BinaryTree() {
		root = nullptr;
	}

	~BinaryTree() {
		if (root != nullptr) {
			removeSubTree(root);
		}
	}

	BinaryTree(const BinaryTree&);							// Copy constructor
	BinaryTree& operator=(const BinaryTree&);				// Copy assignment constructor
	BinaryTree(BinaryTree&&);								// Move constructor
	BinaryTree& operator=(BinaryTree&&);					// Move assignemnt constructor

	void insert(const T);

};

template <class T> // Copy constructor
BinaryTree<T>::BinaryTree(const BinaryTree& SOURCE) {

	delete root;
	copySubTree(SOURCE.root, root);

}

template <class T> // Copy assignment operator
BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree& SOURCE) {

	copySubTree(SOURCE.root, this->root);

	return *this;

}

template <class T> // Move constructor
BinaryTree<T>::BinaryTree(BinaryTree&& source) {

	root = source.root;
	source.root = nullptr;

}

template <class T> // Move assignment operator
BinaryTree<T>& BinaryTree<T>::operator=(BinaryTree&& source) {

	this->root = source.root;
	source.root = nullptr;

	return *this;

}


template <class T>
void BinaryTree<T>::copySubTree(TreeNode* source, TreeNode*& dest) {

	if (source != nullptr) {

		dest = new TreeNode;
		dest->item = source->item;
		dest->left = nullptr;
		dest->right = nullptr;

		copySubTree(source->left, dest->left);
		copySubTree(source->right, dest->right);

	}

}

template <class T>
void BinaryTree<T>::removeSubTree(TreeNode*& currentNode) {

	if (currentNode != nullptr) {

		removeSubTree(currentNode->left);
		removeSubTree(currentNode->right);
		delete currentNode;
		currentNode = nullptr;

	}

}

template <class T>
void BinaryTree<T>::insert(const T ITEM) {

	TreeNode* newNode = new TreeNode;
	newNode->item = ITEM;
	newNode->left = nullptr;
	newNode->right = nullptr;

	insert(root, newNode);

}

template <class T>
void BinaryTree<T>::insert(TreeNode*& currentNode, TreeNode*& NEWNODE) {

	while (currentNode != nullptr) {

		if (NEWNODE->item < currentNode->item) {
			currentNode = currentNode->left;
		}
		else {
			currentNode = currentNode->right;
		}

	}

	currentNode = NEWNODE;

}


#endif