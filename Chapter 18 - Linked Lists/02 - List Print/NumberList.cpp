#include "NumberList.h"

NumberList::~NumberList() {

	ListNode* nodePtr;
	ListNode* nextNode;
	int num;

	nodePtr = head;

	while (nodePtr) {
		nextNode = nodePtr->next;
		num = nodePtr->value;
		delete nodePtr;
		cout << "Node with the value \"" << num << "\" was deleted.\n";
		cout << "\n";
		nodePtr = nextNode;
	}

	head = nullptr;

	cout << "Destructor activated. Linked list has been deleted.\n";
	cout << "\n";

}

void NumberList::print() {

	ListNode* nodePtr;

	cout << "List Values\n";
	cout << "-----------\n";

	if (!head) {
		cout << "### EMPTY LIST ###";
	}

	nodePtr = head;

	while (nodePtr) {
		cout << nodePtr->value << " ";
		nodePtr = nodePtr->next;
	}

	cout << "\n";
	cout << "-----------\n";
	cout << "\n";

}

void NumberList::appendNode(const int NUM) {

	ListNode* nodePtr;

	ListNode* newNode = new ListNode;
	newNode->value = NUM;
	newNode->next = nullptr;

	if (!head) {
		head = newNode;
	}

	else {

		nodePtr = head;

		while (nodePtr->next) {
			nodePtr = nodePtr->next;
		}

		nodePtr->next = newNode;	

	}	

	cout << "A new node was added with the value \"" << NUM << "\".\n";
	cout << "\n";
}

void NumberList::insertNode(const int NUM) {

	ListNode* nodePtr;
	ListNode* previousNode;
	ListNode* newNode;

	newNode = new ListNode;
	newNode->value = NUM;
	newNode->next = nullptr;

	if (!head) {
		head = newNode;
	}

	else {

		nodePtr = head;
		previousNode = nullptr;

		while (nodePtr && nodePtr->value < NUM) {
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		if (!previousNode) {
			head = newNode;
			newNode->next = nodePtr;
		}
		else {
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}

	}

}

void NumberList::deleteNode(const int NUM) {

	ListNode* nodePtr;
	ListNode* newNode;
	ListNode* previousNode = nullptr;

	if (head->value == NUM) {
		newNode = head->next;
		delete head;
		cout << "Node with the value \"" << NUM << "\" was deleted.\n";
		cout << "\n";
		head = newNode;
	}
	else {

		nodePtr = head;

		while (nodePtr->value != NUM) {

			previousNode = nodePtr;
			nodePtr = nodePtr->next;

		}

		newNode = nodePtr->next;
		delete nodePtr;
		cout << "Node with the value \"" << NUM << "\" was deleted.\n";
		cout << "\n";
		previousNode->next = newNode;

	}

}