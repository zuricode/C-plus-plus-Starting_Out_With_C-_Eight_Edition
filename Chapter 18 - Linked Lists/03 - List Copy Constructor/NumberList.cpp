#include "NumberList.h"

NumberList::NumberList(const NumberList& OLD) {
	
	ListNode* SourcePtr = nullptr;
	ListNode* nodePtr = nullptr;
	ListNode* newPtr = nullptr;

	SourcePtr = OLD.head;

	head = new ListNode;

	if (!SourcePtr) {
		cout << "A blank new list was created.\n";
		cout << "\n";
	}
	else if (!SourcePtr->next) {
		head->value = SourcePtr->value;
		cout << "A single list node with the value \"" << SourcePtr->value << "\" was created.\n";
		cout << "\n";
	}

	else {

		nodePtr = head;

		while (SourcePtr->next) {
			nodePtr->value = SourcePtr->value;
			newPtr = new ListNode;
			nodePtr->next = newPtr;
			nodePtr = newPtr;
			SourcePtr = SourcePtr->next;
		}

		nodePtr->value = SourcePtr->value;

	}	

}

NumberList::~NumberList() {

	ListNode* nodePtr;
	ListNode* nextNode;
	int num;

	nodePtr = head;

	while (nodePtr) {
		nextNode = nodePtr->next;
		num = nodePtr->value;
		delete nodePtr;
		nodePtr = nextNode;
	}

	head = nullptr;

}

void NumberList::print() {

	ListNode* nodePtr;

	cout << "List Values: ";

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
		previousNode->next = newNode;

	}

}