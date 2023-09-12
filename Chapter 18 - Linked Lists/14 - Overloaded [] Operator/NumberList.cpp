#include "NumberList.h"
#include <string>

using std::string;

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

void NumberList::displayList() {

	ListNode* nodePtr;
	string line = "";

	nodePtr = head;

	cout << "NumberList Values\n";

	while (nodePtr) {

		if (nodePtr->value >= 10) {
			line += "-";
		} 

		line += "--";
		nodePtr = nodePtr->next;
	}

	nodePtr = head;

	cout << line << "\n";

	while (nodePtr) {
		cout << nodePtr->value << " ";
		nodePtr = nodePtr->next;
	}

	cout << "\n";
	cout << line << "\n";
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

int& NumberList::operator[](const int ELEMENT) {

	ListNode* nodePtr;
	int counter = 0;
	bool isFound = false;
	nodePtr = head;

	while (nodePtr != nullptr && counter != ELEMENT) {
		nodePtr = nodePtr->next;
		counter++;
	}

	if (counter == ELEMENT && nodePtr != nullptr) {
		return nodePtr->value;
	}
	else {
		throw invalidSubscript(ELEMENT);
	}

}