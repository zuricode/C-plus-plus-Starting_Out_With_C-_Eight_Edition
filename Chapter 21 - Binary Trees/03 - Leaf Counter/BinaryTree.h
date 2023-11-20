#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>

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

	void removeSubTree(TreeNode*);
	void insertNode(TreeNode*&, TreeNode*);
	void countLeafNodes(TreeNode*, int&);
	void displayInOrder(TreeNode*);
	void displayPreOrder(TreeNode*);
	void displayPostOrder(TreeNode*);
	bool searchTree(const T) const;
	void deleteNode(TreeNode*&, T);
	void makeDeletion(TreeNode*&);

public:

	BinaryTree() { root = nullptr; }
	~BinaryTree() { removeSubTree(root); }

	void insert(T);
	void search(T);
	void remove(T);
	int getLeafNodes();

	void displayInOrder() {
		cout << "BinaryTree InOrder: ";
		displayInOrder(root);
		cout << "\n";
	}
	void displayPreOrder() {
		cout << "BinaryTree PreOrder: ";
		displayPreOrder(root);
		cout << "\n";
	}
	void displayPostOrder() {
		cout << "BinaryTree PostOrder: ";
		displayPostOrder(root);
		cout << "\n";
	}

};

template <class T>
void BinaryTree<T>::removeSubTree(TreeNode* node) {

	if (node != nullptr) {

		if (node->left != nullptr) {
			removeSubTree(node->left);
		}
		if (node->right != nullptr) {
			removeSubTree(node->right);
		}

		delete node;

	}

}

template <class T>
void BinaryTree<T>::insert(T value) {

	TreeNode* newNode = new TreeNode;
	newNode->value = value;
	newNode->left = nullptr;
	newNode->right = nullptr;

	insertNode(root, newNode);

	cout << "NEW NODE: \"" << value << "\"\n";

}

template <class T>
void BinaryTree<T>::remove(T value) {

	deleteNode(root, value);

}

template <class T>
void BinaryTree<T>::deleteNode(TreeNode*& currentNode, T value) {

	if (currentNode != nullptr) {

		if (value < currentNode->value) {
			deleteNode(currentNode->left, value);
		}
		else if (value > currentNode->value) {
			deleteNode(currentNode->right, value);
		}
		else if (value == currentNode->value) {
			makeDeletion(currentNode);
		}		

	} else {
		cout << "DELETE FUNCTION: Node with the value \"" << value << "\" could not be found in the BinaryTree. ";
		cout << "Deletion failed.\n";
	}
	
}

template <class T>
void BinaryTree<T>::makeDeletion(TreeNode*& node) {

	T value = node->value;

	TreeNode* temp = nullptr;

	if (node == nullptr) {
		cout << "ERROR: Empty cannot be deleted.\n";
		cout << "\n";
	}
	else if (node->right == nullptr) {
		temp = node;
		node = node->left;
		delete temp;
	}
	else if (node->left == nullptr) {
		temp = node;
		node = node->right;
		delete temp;
	}
	else {

		temp = node->right;

		while (temp->left != nullptr) {
			temp = temp->left;
		}

		temp->left = node->left;
		temp = node;
		node = node->right;
		delete temp;	

	}

	cout << "DELETE FUNCTION: Node with the value \"" << value << "\" was deleted from the BinaryTree.\n";

}

template <class T>
int BinaryTree<T>::getLeafNodes() {
	
	int counter = 0;

	countLeafNodes(root, counter);

	return counter;

}

template <class T>
void BinaryTree<T>::countLeafNodes(TreeNode* currentNode, int& counter) {

	if (currentNode != nullptr) {

		countLeafNodes(currentNode->left, counter);

		if (currentNode->left == nullptr && currentNode->right == nullptr) {
			counter++;
		}

		countLeafNodes(currentNode->right, counter);

	}

}

template <class T>
void BinaryTree<T>::insertNode(TreeNode*& currentNode, TreeNode* newNode) {

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
void BinaryTree<T>::search(T value) {

	if (searchTree(value)) {
		cout << "TREE SEARCH: Value \"" << value << "\" WAS found in the BinaryTree.\n";
		cout << "\n";
	}
	else {
		cout << "TREE SEARCH: Value \"" << value << "\" WAS NOT found in the BinaryTree.\n";
		cout << "\n";
	}

}

template <class T>
bool BinaryTree<T>::searchTree(const T value) const {

	TreeNode* currentNode = root;

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
void BinaryTree<T>::displayInOrder(TreeNode* currentNode) {

	if (currentNode != nullptr) {
		displayInOrder(currentNode->left);
		cout << currentNode->value << " | ";
		displayInOrder(currentNode->right);
	}

}

template <class T>
void BinaryTree<T>::displayPreOrder(TreeNode* currentNode) {

	if (currentNode != nullptr) {
		cout << currentNode->value << " | ";
		displayPreOrder(currentNode->left);
		displayPreOrder(currentNode->right);
	}

}

template <class T>
void BinaryTree<T>::displayPostOrder(TreeNode* currentNode) {

	if (currentNode != nullptr) {
		displayPostOrder(currentNode->left);
		displayPostOrder(currentNode->right);
		cout << currentNode->value << " | ";
	}

}

#endif