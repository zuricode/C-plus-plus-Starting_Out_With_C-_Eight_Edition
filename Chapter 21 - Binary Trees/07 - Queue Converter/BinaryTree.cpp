#include "BinaryTree.h"


BinaryTree::BinaryTree() {
	cout << "Default constructor activated.\n\n";
	root = nullptr;
}

BinaryTree::~BinaryTree() {
	cout << "Destructor activated...\n\n";
	removeSubTree(root);
}

BinaryTree::BinaryTree(const BinaryTree& SOURCE) {

	cout << "Copy constructor activated...\n\n";

	if (SOURCE.root != nullptr) {
		root = new TreeNode;
		copySubTree(SOURCE.root, root);
	}
	else {
		root = nullptr;
	}
	
}

BinaryTree& BinaryTree::operator=(const BinaryTree& SOURCE) {

	cout << "Copy assignment operator...\n\n";

	if (SOURCE.root != nullptr) {
		this->root = new TreeNode;
		copySubTree(SOURCE.root, this->root);
	}
	else {
		this->root = nullptr;
	}

	return *this;	

}

BinaryTree::BinaryTree(BinaryTree&& source) {

	cout << "Move constructor activated...\n\n";

	root = source.root;
	source.root = nullptr;

}

BinaryTree& BinaryTree::operator=(BinaryTree&& source) {

	cout << "Move assignment operator activated...\n\n";

	if (source.root != nullptr) {
		this->root = source.root;
		source.root = nullptr;
	}
	else {
		this->root = nullptr;
	}
	
	return *this;

}

void BinaryTree::removeSubTree(TreeNode* currentNode) {

	if (currentNode != nullptr) {
		removeSubTree(currentNode->left);
		removeSubTree(currentNode->right);
	}
	else {
		delete currentNode;
	}

}

void BinaryTree::copySubTree(const TreeNode* sourceNode, TreeNode*& currentNode) {

	if (sourceNode != nullptr) {

		TreeNode* newNode = new TreeNode;
		newNode->value = sourceNode->value;
		newNode->left = nullptr;
		newNode->right = nullptr;

		currentNode = newNode;

		copySubTree(sourceNode->left, currentNode->left);
		copySubTree(sourceNode->right, currentNode->right);

	}

}

void BinaryTree::insert(const int VALUE) {

	TreeNode* newNode = new TreeNode;
	newNode->value = VALUE;
	newNode->left = nullptr;
	newNode->right = nullptr;

	insertNode(root, newNode);

}

void BinaryTree::insertNode(TreeNode*& currentNode, TreeNode*& newNode) {

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

void BinaryTree::search(const int VALUE) {

	bool result;

	result = searchNodes(root, VALUE);

	if (result) {
		cout << "NODE FOUND: A node was found with the value of " << VALUE << ".\n";
	}
	else {
		cout << "There is no node in the BinaryTree with a value of " << VALUE << ".\n";
	}

	cout << "\n";

}

bool BinaryTree::searchNodes(TreeNode* currentNode, const int VALUE) {

	while (currentNode != nullptr) {

		if (VALUE < currentNode->value) {
			currentNode = currentNode->left;
		}
		else if (VALUE > currentNode->value) {
			currentNode = currentNode->right;
		}
		else {
			return true;
		}

	}

	return false;

}

void BinaryTree::displayInOrder() {

	cout << "BinaryTree displayInOrder: ";

	if (root != nullptr) {
		displayInOrder(root);
	}
	else {
		cout << "Empty BinaryTree!";
	}
	cout << "\n";
	cout << "\n";

}

void BinaryTree::displayInOrder(const TreeNode* CURRENTNODE) {
	
	if (CURRENTNODE != nullptr) {

		displayInOrder(CURRENTNODE->left);
		cout << CURRENTNODE->value << " | ";
		displayInOrder(CURRENTNODE->right);

	}

}

void BinaryTree::displayPreOrder() {

	cout << "BinaryTree displayPreOrder: ";

	if (root != nullptr) {
		displayPreOrder(root);
	}
	else {
		cout << "Empty BinaryTree!";
	}
	cout << "\n";
	cout << "\n";
}

void BinaryTree::displayPreOrder(const TreeNode* CURRENTNODE) {

	if (CURRENTNODE != nullptr) {

		cout << CURRENTNODE->value << " | ";
		displayPreOrder(CURRENTNODE->left);
		displayPreOrder(CURRENTNODE->right);

	}

}

void BinaryTree::displayPostOrder() {
	
	cout << "BinaryTree displayPostOrder: ";

	if (root != nullptr) {
		displayPostOrder(root);
	}
	else {
		cout << "Empty BinaryTree!";
	}
	cout << "\n";
	cout << "\n";

}

void BinaryTree::displayPostOrder(const TreeNode* CURRENTNODE) {

	if (CURRENTNODE != nullptr) {

		displayPostOrder(CURRENTNODE->left);
		displayPostOrder(CURRENTNODE->right);
		cout << CURRENTNODE->value << " | ";

	}

}