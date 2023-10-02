#ifndef DYNAMICQUEUE_H
#define DYNAMICQUEUE_H

#include <iostream>

using std::cout;
using std::cin;

template<class T>
class DynamicQueue {

private:

	struct stackNode {
		T value;
		stackNode* next;
	};

	stackNode* front;
	stackNode* rear;
	int number_of_nodes;

public:

	DynamicQueue(); 
	DynamicQueue(const DynamicQueue&);
	~DynamicQueue();

	void enqueue(const T);
	void dequeue(T&);
	bool isEmpty() const;

	void displayQueue();

};

template<class T>
DynamicQueue<T>::DynamicQueue() {

	front = nullptr;
	rear = nullptr;
	number_of_nodes = 0;

}

template<class T>
DynamicQueue<T>::DynamicQueue(const DynamicQueue& SOURCE) {

	stackNode* sourceNode = SOURCE.front;
	stackNode* temp = nullptr;

	if (sourceNode == nullptr) {
		cout << "Copy constructor failed. Source queue is empty.\n";
		cout << "\n";
	}

	else {

		front = new stackNode;
		front->next = nullptr;

		while(sourceNode != nullptr) {

			if (number_of_nodes == 0) {
				front->value = sourceNode->value;
				front->next = nullptr;
				temp = front;
				sourceNode = sourceNode->next;
			}

			else {
				temp->next = new stackNode;
				temp = temp->next;
				temp->value = sourceNode->value;
				temp->next = nullptr;
				sourceNode = sourceNode->next;
			}


			number_of_nodes++;

		}

		rear = temp;

	}

}

template<class T>
DynamicQueue<T>::~DynamicQueue() {

	stackNode* tempNode = nullptr;

	while (front != nullptr) {
		tempNode = front;
		front = front->next;
		delete tempNode;
	}

	rear = nullptr;

}

template<class T>
void DynamicQueue<T>::enqueue(const T VALUE) {

	stackNode* newNode = new stackNode;
	newNode->value = VALUE;
	newNode->next = nullptr;

	if (isEmpty()) {
		front = newNode;
		rear = newNode;
	}
	else {
		rear->next = newNode;
		rear = newNode;
	}

	number_of_nodes++;

}

template<class T>
void DynamicQueue<T>::dequeue(T& value) {

	stackNode* temp = nullptr;

	if (isEmpty()) {
		cout << "ERROR: Dequeing failed. Queue is already empty.\n";
		cout << "\n";
	}
	else {

		value = front->value;

		temp = front;
		front = front->next;
		delete temp;

		cout << value << " was dequeued from the queue.\n";

		number_of_nodes--;

	}

}



template<class T>
bool DynamicQueue<T>::isEmpty() const {

	if (front == nullptr || rear == nullptr) {
		return true;
	}
	else {
		return false;
	}

}

template<class T>
void DynamicQueue<T>::displayQueue() {

	if (isEmpty()) {
		cout << "ERROR: Queue is empty. There is nothing to display.\n";
		cout << "\n";
	}
	else {

		stackNode* currentNode = front;

		cout << "-------------\n";
		cout << "QUEUE DISPLAY:\t";

		for (int i = 0; i < number_of_nodes; i++) {

			if (i != (number_of_nodes - 1)) {
				cout << currentNode->value << " >>> ";
			}
			else {
				cout << currentNode->value << "\n";
			}

			currentNode = currentNode->next;
		}

		cout << "-------------\n";
		cout << "\n";

	}

}

#endif