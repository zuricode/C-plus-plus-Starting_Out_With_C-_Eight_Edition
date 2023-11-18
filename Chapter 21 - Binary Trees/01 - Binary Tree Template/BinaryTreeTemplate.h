#ifndef BINARYTREETEMPLATE_H
#define BINARYTREETEMPLATE_H

#include <iostream>

using std::cout;
using std::cin;
using std::numeric_limits;
using std::streamsize;

template<class T>
class BinaryTreeTemplate {

private:
	struct nodePtr {
		T value;
		nodePtr* left;
		nodePtr* right;
	};

	nodePtr* root;

	void destroySubTree(nodePtr*);
	void insertNode(nodePtr*&, nodePtr*&);
	void deleteNode(nodePtr*&, T value);
	void makeDeletion(nodePtr*&);

	void displayInOrder(nodePtr*) const;
	void displayPreOrder(nodePtr*) const;
	void displayPostOrder(nodePtr*) const;
	bool searchTree(T);


public:

	BinaryTreeTemplate() { root = nullptr; }
	~BinaryTreeTemplate() { destroySubTree(root); }

	void insert(T);
	void search();
	void remove(T);
	void displayInOrder() const { displayInOrder(root); }
	void displayPreOrder() const { displayPreOrder(root); }
	void displayPostOrder() const { displayPostOrder(root); }


	//void deleteNode(nodePtr*&, T);

};

template <class T>
void BinaryTreeTemplate<T>::destroySubTree(nodePtr* node) {

	if (node != nullptr) {

		if (node->left != nullptr) {
			destroySubTree(node->left);
		}
		if (node->right != nullptr) {
			destroySubTree(node->right);
		}

		delete node;

	}

}

template <class T>
void BinaryTreeTemplate<T>::insertNode(nodePtr*& currentNode, nodePtr*& newNode) {

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
void BinaryTreeTemplate<T>::insert(T value) {

	nodePtr* newNode = new nodePtr;
	newNode->value = value;
	newNode->left = nullptr;
	newNode->right = nullptr;

	insertNode(root, newNode);

}

template <class T>
void BinaryTreeTemplate<T>::remove(T value) {

	if (root == nullptr) {
		cout << "ERROR: Binary tree is empty! There are no nodes to delete.\n";
	}
	else {
		deleteNode(root, value);
		cout << "Value \"" << value << "\" was revoed from the binary tree.\n";
	}

	cout << "\n";

}

template <class T>
void BinaryTreeTemplate<T>::deleteNode(nodePtr*& currentNode, T value) {

	if (currentNode == nullptr) {
		cout << "ERROR: Node with value \"" << value << "\" could not be found.\n";
	}
	else if (value < currentNode->value) {
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
void BinaryTreeTemplate<T>::makeDeletion(nodePtr*& node) {

	nodePtr* temp = nullptr;

	if (node == nullptr) {
		cout << "ERROR: There is no node to delete!\n";
	}
	else if (node->left == nullptr) {
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
		temp = node;
		node = node->right;
		delete temp;

	}


}

template <class T>
void BinaryTreeTemplate<T>::displayInOrder(nodePtr* node) const {

	if (node != nullptr) {

		displayInOrder(node->left);
		cout << node->value << " | ";
		displayInOrder(node->right);

	}

}

template <class T>
void BinaryTreeTemplate<T>::displayPreOrder(nodePtr* node) const {

	if (node != nullptr) {

		cout << node->value << " | ";
		displayPreOrder(node->left);
		displayPreOrder(node->right);

	}

}

template <class T>
void BinaryTreeTemplate<T>::displayPostOrder(nodePtr* node) const {

	if (node != nullptr) {

		displayPostOrder(node->left);
		displayPostOrder(node->right);
		cout << node->value << " | ";

	}

}

template <class T>
void BinaryTreeTemplate<T>::search() {

	T value;

	cout << "Enter value to search the binary tree: ";
	cin >> value;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	if (searchTree(value)) {
		cout << value << " was found in the binary tree.\n";
	}
	else {
		cout << value << " was NOT found in the binary tree.\n";
	}

	cout << "\n";

}

template <class T>
bool BinaryTreeTemplate<T>::searchTree(T value) {

	nodePtr* currentNode = root;

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

//template <class T>
//void BinaryTreeTemplate<T>::deleteNode(nodePtr*& currentNode, T value) {
//
//	nodePtr* temp = nullptr;
//
//	if (currentNode != nullptr) {
//
//		if (value < currentNode->value) {
//			deleteNode(currentNode->left, value);
//		}
//		else if (value > currentNode->value) {
//			deleteNode(currentNode->right, value);
//		}
//		else {
//			temp = 
//		}
//
//	}
//
//}

#endif