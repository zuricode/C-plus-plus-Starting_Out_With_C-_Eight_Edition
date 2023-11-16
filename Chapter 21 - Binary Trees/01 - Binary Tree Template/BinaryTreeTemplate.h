#ifndef BINARYTREETEMPLATE_H
#define BINARYTREETEMPLATE_H

template<class T>
class BinaryTreeTemplate {

	struct nodePtr {
		T value;
		BinaryTreeTemplate* right;
		BinaryTreeTemplate* left;
	};

private:
	nodePtr* root;

	void destroySubTree(nodePtr*);
	void insertNode(nodePtr*&, nodePtr*&);

public:

	BinaryTreeTemplate() { root = nullptr; }
	~BinaryTreeTemplate() { destroySubTree(root); }

	void insert(T);

	template<class T>
	void BinaryTreeTemplate<T>::destroySubTree(nodePtr* currentNode) {

		if (currentNode) {

			if (currentNode->left != nullptr) {
				destroySubTree(currentNode->left);
			}
			if (currentNode->right != nullptr) {
				destroySubTree(currentNode->right);
			}
			delete currentNode;

		}

	}

	template<class T>
	void BinaryTreeTemplate<T>::insert(T value) {

		nodePtr* newNode = new nodePtr;
		nodePtr->value = value;
		newNode->left = nullptr;
		newNode->right = nullptr;

		insertNode(root, newNode);

	}

	template<class T>
	void BinaryTreeTempalte<T>::insertNode(nodePtr *&currentNode, nodePtr *&newNode) {

		if (currentNode = nullptr) {
			currentNode = newNode;
		}
		else if (newNode->value < currentNode->value) {
			insertNode(currentNode->left, newNode);
		}
		else (newNode->value >= currentNode->value) {
			insertNode(currentNode->right, newNode);
		}

	}

};

#endif