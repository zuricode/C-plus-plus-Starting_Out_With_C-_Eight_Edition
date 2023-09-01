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

void NumberList::print(const string DESCRIPTION) {

	ListNode* nodePtr;

	cout << DESCRIPTION << "\n";

	for (int i = 0; i < DESCRIPTION.size(); i++) {
		cout << "-";
	}

	cout << "\n";
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

void NumberList::reverse() {

	vector<int> numbers;
	ListNode* nodePtr = nullptr;

	nodePtr = head;

	if (!nodePtr) {
		cout << "There are no nodes in this list to reverse.\n";
	}
	else if (!nodePtr->next) {
		cout << "There is only one node in this list. The reverse function is unnecessary.\n";
	}
	else {

		while (nodePtr) {
			numbers.push_back(nodePtr->value);
			nodePtr = nodePtr->next;
		}

		nodePtr = head;

	}

	vector<int>::reverse_iterator rit;

	for (rit = numbers.rbegin(); rit != numbers.rend(); rit++) {
		nodePtr->value = *rit;
		nodePtr = nodePtr->next;
	}

}

int NumberList::search(const int NUM) {

	ListNode* nodePtr = nullptr;
	int counter = 0;

	nodePtr = head;

	if (!nodePtr) {
		cout << "There are no values in the list. Search function cannot run.\n";
	}
	else {

		while (nodePtr) {

			if (nodePtr->value == NUM) {
				cout << "\n";
				return counter;
			}

			nodePtr = nodePtr->next;
			counter++;

		}

		cout << "\n";
		return -1;
		
	}

}