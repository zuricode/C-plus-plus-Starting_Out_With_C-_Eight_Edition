#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::setw;
using std::left;

template <class T>
class ListNode {

public:
	T value;
	ListNode* next;

	ListNode(const T VALUE) { value = VALUE; next = nullptr; }

};

template <class T>
class LinkedList {

private:
	ListNode<T>* head;

public:
	LinkedList() { head = nullptr; }
	~LinkedList();

	void appendNode(const T);
	void displayList(const int) const;

};

template <class T>
LinkedList<T>::~LinkedList() {

	ListNode<T>* nodePtr;
	ListNode<T>* nextNode;

	nodePtr = head;

	while (nodePtr) {
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}

}

template <class T>
void LinkedList<T>::appendNode(const T NEW_VALUE) {

	ListNode<T>* newNode = new ListNode<T>(NEW_VALUE);

	if (!head) {
		head = newNode;
	}

	else {

		ListNode<T>* nodePtr = head;

		while (nodePtr->next) {
			nodePtr = nodePtr->next;
		}

		nodePtr->next = newNode;

	}	

}

template <class T>
void LinkedList<T>::displayList(const int SPACER) const {

	ListNode<T>* nodePtr = head;

	if (!nodePtr) {
		cout << "### EMPTY LIST ### - There are no values to display in this LinkedList.\n";
	}

	else {

		while (nodePtr) {
			cout << left << setw(SPACER) << nodePtr->value << "| ";
			nodePtr = nodePtr->next;
		}

	}

	cout << "\n";

}

#endif

