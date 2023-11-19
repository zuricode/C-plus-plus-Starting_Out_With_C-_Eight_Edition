#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;

template <class T>
class BinaryTree {

private:

	struct TreeNode {
		T value;
		TreeNode* left;
		TreeNode* right;
	};

	TreeNode* root;

	void insertNode(TreeNode*&, TreeNode*&);
	bool searchNodes(TreeNode*, T);
	void deleteNode(TreeNode*&, T);
	void makeDeletion(TreeNode*&);
	void displayInOrder(TreeNode*) const;
	void displayPreOrder(TreeNode*) const;
	void displayPostOrder(TreeNode*) const;
	void countNodes(TreeNode*, int&);

public:

	BinaryTree() { root = nullptr; }

	void insert(T);
	void search(T);
	void remove(T);
	int nodeCounter();

	void displayInOrder() {
		cout << " BinaryTree InOrder: ";
		displayInOrder(root);
		cout << "\n";
	}
	void displayPreOrder() {
		cout << " BinaryTree PreOrder: ";
		displayPreOrder(root);
		cout << "\n";
	}

	void displayPostOrder() {
		cout << " BinaryTree PostOrder: ";
		displayPostOrder(root);
		cout << "\n";
	}

};

template <class T>
void BinaryTree<T>::insert(T value) {

	TreeNode* newNode = new TreeNode;
	newNode->value = value;
	newNode->left = nullptr;
	newNode->right = nullptr;

	insertNode(root, newNode);

	cout << "A new node with the value \"" << value << "\" was added to the binary tree.\n";

}

template <class T>
void BinaryTree<T>::insertNode(TreeNode*& currentNode, TreeNode*& newNode) {

	if (currentNode == nullptr) {
		currentNode = newNode;
	}
	else if (newNode->value < currentNode->value) {
		insertNode(currentNode->left, newNode);
	}
	else {
		insertNode(currentNode->right, newNode);
	}

}

template <class T>
void BinaryTree<T>::remove(T value) {

	if (root == nullptr) {
		cout << "ERROR: BinaryTree is empty. There are no nodes to delete!\n";
	}
	else {
		deleteNode(root, value);
	}

	cout << "\n";

}

template <class T>
void BinaryTree<T>::deleteNode(TreeNode*& currentNode, T value) {

	if (value < currentNode->value) {
		deleteNode(currentNode->left, value);
	}
	else if (value > currentNode->value) {
		deleteNode(currentNode->right, value);
	}
	else {
		makeDeletion(currentNode);
	}

}

template <class T>
void BinaryTree<T>::makeDeletion(TreeNode*& node) {

	T value = node->value;

	TreeNode* temp = nullptr;

	if (node->left == nullptr) {
		temp = node;
		node = node->right;
		delete temp;
	}
	else if (node->right == nullptr) {
		temp = node;
		node = node->left;
		delete temp;
	}
	else {

		temp = node->right;
		while (temp->left) {
			temp = temp->left;
		}
		temp->left = node->left;
		node = node->right;
		temp = node;
		node = node->right;
		delete temp;

	}

	cout << "Node with the value of \"" << value << "\" was deleted from the binary tree.\n";

}

template <class T>
void BinaryTree<T>::displayInOrder(TreeNode* currentNode) const {

	if (currentNode != nullptr) {

		displayInOrder(currentNode->left);
		cout << currentNode->value << " | ";
		displayInOrder(currentNode->right);

	}

}

template <class T>
void BinaryTree<T>::displayPreOrder(TreeNode* currentNode) const {

	if (currentNode != nullptr) {

		cout << currentNode->value << " | ";
		displayPreOrder(currentNode->left);
		displayPreOrder(currentNode->right);

	}

}

template <class T>
void BinaryTree<T>::displayPostOrder(TreeNode* currentNode) const {

	if (currentNode != nullptr) {

		displayPostOrder(currentNode->left);
		displayPostOrder(currentNode->right);
		cout << currentNode->value << " | ";

	}

}

template <class T>
void BinaryTree<T>::search(T value) {

	if (root == nullptr) {
		cout << "ERROR: Binary tree is empty. There are no nodes to search through!\n";
	}
	else {
		
		if (searchNodes(root, value)) {
			cout << "\"" << value << "\" WAS found in the binary tree.\n";
		} else {
			cout << "\"" << value << "\" WAS NOT found in the binary tree.\n";
		}

	}

	cout << "\n";

}

template <class T>
bool BinaryTree<T>::searchNodes(TreeNode* currentNode, T value) {

	while (currentNode != nullptr) {

		if (value < currentNode->value) {
			currentNode = currentNode->left;
		}
		else if (value > currentNode->value) {
			currentNode = currentNode->right;
		} 
		else {
			return true;
		}

	}

	return false;

}

template <class T>
int BinaryTree<T>::nodeCounter() {

	int count = 0;

	countNodes(root, count);

	return count;

}

template <class T>
void BinaryTree<T>::countNodes(TreeNode* currentNode, int& counter) {

	if (currentNode != nullptr) {

		countNodes(currentNode->left, counter);
		counter++;
		countNodes(currentNode->right, counter);

	}

}

#endif