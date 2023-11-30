#ifndef EMPLOYEETRE_H
#define EMPLOYEETRE_H

#include "EmployeeInfo.h"

template <class T>
class EmployeeTree {

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
	void displayInOrder(const TreeNode*);
	void displayPreOrder(const TreeNode*);
	void displayPostOrder(const TreeNode*);
	bool search(TreeNode*, const int);
	void removeNode(TreeNode*&, const int);
	void removeNodeDeletion(TreeNode*&);

public:

	EmployeeTree() {
		root = nullptr;
	}

	~EmployeeTree() {
		if (root != nullptr) {
			removeSubTree(root);
		}
	}

	EmployeeTree(const EmployeeTree&);							// Copy constructor
	EmployeeTree& operator=(const EmployeeTree&);				// Copy assignment constructor
	EmployeeTree(EmployeeTree&&);								// Move constructor
	EmployeeTree& operator=(EmployeeTree&&);					// Move assignemnt constructor

	void insert(const T&);
	void search();
	void remove(const int);

	void displayInOrder() {

		cout << "EmployeeTree InOrder: \n";

		if (root != nullptr) {
			cout << "\n";
			displayInOrder(root);
			cout << "\n";
		}
		else {
			cout << "EMPTY EMPLOYEETREE!\n";
			cout << "\n";
		}
		
	}

	void displayPreOrder() {

		cout << "EmployeeTree PreOrder: \n";

		if (root != nullptr) {
			cout << "\n";
			displayPreOrder(root);
			cout << "\n";
		}
		else {
			cout << "EMPTY EMPLOYEETREE!\n";
			cout << "\n";
		}

	}

	void displayPostOrder() {
		
		cout << "EmployeeTree PostOrder: \n";

		if (root != nullptr) {
			cout << "\n";
			displayPostOrder(root);
			cout << "\n";
		}
		else {
			cout << "EMPTY EMPLOYEETREE!\n";
			cout << "\n";
		}

	}

};

template <class T> // Copy constructor
EmployeeTree<T>::EmployeeTree(const EmployeeTree& SOURCE) {

	delete root;
	copySubTree(SOURCE.root, root);

}

template <class T> // Copy assignment operator
EmployeeTree<T>& EmployeeTree<T>::operator=(const EmployeeTree& SOURCE) {

	copySubTree(SOURCE.root, this->root);

	return *this;

}

template <class T> // Move constructor
EmployeeTree<T>::EmployeeTree(EmployeeTree&& source) {

	root = source.root;
	source.root = nullptr;

}

template <class T> // Move assignment operator
EmployeeTree<T>& EmployeeTree<T>::operator=(EmployeeTree&& source) {

	this->root = source.root;
	source.root = nullptr;

	return *this;

}


template <class T>
void EmployeeTree<T>::copySubTree(TreeNode* source, TreeNode*& dest) {

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
void EmployeeTree<T>::removeSubTree(TreeNode*& currentNode) {

	if (currentNode != nullptr) {

		removeSubTree(currentNode->left);
		removeSubTree(currentNode->right);
		delete currentNode;
		currentNode = nullptr;

	}

}

template <class T>
void EmployeeTree<T>::insert(const T& ITEM) {

	TreeNode* newNode = new TreeNode;
	newNode->item = ITEM;
	newNode->left = nullptr;
	newNode->right = nullptr;

	insert(root, newNode);

}

template <class T>
void EmployeeTree<T>::insert(TreeNode*& currentNode, TreeNode*& newNode) {

	if (currentNode == nullptr) {
		currentNode = newNode;
	}
	else {

		if (newNode->item == currentNode->item) {
			cout << "ERROR: An entry with the ID \"" << currentNode->item.getId() << "\" already exist in the EmployeeTree.\n";
			cout << "\n";
			delete newNode;
			newNode = nullptr;
		}
		else if (newNode->item < currentNode->item) {
			insert(currentNode->left, newNode);
		}
		else {
			insert(currentNode->right, newNode);
		}

	}

}

template <class T>
void EmployeeTree<T>::search() {

	int id;

	cout << "Enter the ID to search: ";
	cin >> id;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	if (search(root, id)) {
		cout << "ID " << id << " was found in the EmployeeTree.\n";
	}
	else {
		cout << "ID " << id << " was NOT found in the EmployeeTree.\n";
	}

	cout << "\n";

}

template <class T>
bool EmployeeTree<T>::search(TreeNode* currentNode, const int ID) {

	while (currentNode != nullptr) {

		if (ID == currentNode->item.getId()) {
			return true;
		}
		else if (ID < currentNode->item.getId()) {
			currentNode = currentNode->left;
		}
		else {
			currentNode = currentNode->right;
		}

	}

	return false;

}

template<class T>
void EmployeeTree<T>::remove(const int ID) {

	if (root != nullptr) {
		removeNode(root, ID);
	}
	else {
		cout << "ERROR: There are no nodes to delete. EmployeTree is empty.\n";
		cout << "\n";
	}

}

template <class T>
void EmployeeTree<T>::removeNode(TreeNode*& currentNode, const int ID) {

	if (currentNode != nullptr) {

		if (ID < currentNode->item.getId()) {
			removeNode(currentNode->left, ID);
		}
		else if (ID > currentNode->item.getId()) {
			removeNode(currentNode->right, ID);
		}
		else {
			removeNodeDeletion(currentNode);
		}

	}

}

template <class T>
void EmployeeTree<T>::removeNodeDeletion(TreeNode*& node) {

	TreeNode* temp = nullptr;

	if (node == nullptr) {
		cout << "ERROR: Node is empty.\n";
		cout << "\n";
	}
	else if (node->left == nullptr && node->right == nullptr) {
		removeSubTree(node);
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

		while (temp != nullptr) {
			temp = temp->left;
		}

		node->left = temp;
		temp = node;
		node = node->right;
		delete temp;

	}

}

template <class T>
void EmployeeTree<T>::displayInOrder(const TreeNode* currentNode) {

	if (currentNode != nullptr) {

		displayInOrder(currentNode->left);
		cout << currentNode->item << "\n";
		displayInOrder(currentNode->right);

	}

}

template <class T>
void EmployeeTree<T>::displayPreOrder(const TreeNode* CURRENTNODE) {

	if (CURRENTNODE != nullptr) {

		cout << CURRENTNODE->item << "\n";
		displayPreOrder(CURRENTNODE->left);
		displayPreOrder(CURRENTNODE->right);

	}

}

template <class T>
void EmployeeTree<T>::displayPostOrder(const TreeNode* CURRENTNODE) {

	if (CURRENTNODE != nullptr) {

		displayPostOrder(CURRENTNODE->left);
		displayPostOrder(CURRENTNODE->right);
		cout << CURRENTNODE->item << "\n";

	}

}

#endif