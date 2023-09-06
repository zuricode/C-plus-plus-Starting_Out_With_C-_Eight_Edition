#ifndef RAINFALLDATA_H
#define RAINFALLDATA_H

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;

template <class T>
class ListNode {

public:
	T value;
	ListNode<T>* next;

	ListNode(T nodeValue) {
		value = nodeValue;
		next = nullptr;
	}

};

template <class T>
class RainfallData {

private:
	ListNode<T>* head;

public:
	RainfallData();
	~RainfallData();

	ListNode<T>* getHead() const;

	void insertNode(const T);
	void appendNode(const T);
	T getTotalValue() const;

};

template <class T>
RainfallData<T>::RainfallData() {
	head = nullptr;
}

template<class T>
RainfallData<T>::~RainfallData() {

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
ListNode<T>* RainfallData<T>::getHead() const {

	return head;

}

template <class T>
void RainfallData<T>::insertNode(const T VALUE) {

	ListNode<T> *nodePtr;
	ListNode<T> *previousNode;
	ListNode<T> *newNode = new ListNode<T>(VALUE);

	nodePtr = head;

	if (!nodePtr) {
		nodePtr = newNode;
	}

	else {

		bool isInserted = false;
		previousNode = nodePtr;

		while (nodePtr && !isInserted) {

			if (VALUE <= nodePtr->value) {
				newNode->next = nodePtr;
				previousNode = newNode;
				isInserted = true;
			}
			else {
				nodePtr->next = newNode;
				isInserted = true;

			}

			if (!isInserted) {
				previousNode = nodePtr;
				nodePtr = nodePtr->next;
			}	

		}

	}

}

template <class T>
void RainfallData<T>::appendNode(const T VALUE) {

	ListNode<T>* nodePtr;
	ListNode<T>* newNode = new ListNode<T>(VALUE);

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

template <class T>
T RainfallData<T>::getTotalValue() const {

	T total = NULL;

	ListNode<T>* nodePtr;

	nodePtr = head;

	while (nodePtr) {
		total = total + nodePtr->value;
		nodePtr = nodePtr->next;
	}

	return total;

}

#endif

