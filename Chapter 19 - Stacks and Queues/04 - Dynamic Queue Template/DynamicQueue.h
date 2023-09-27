#ifndef DYNAMICQUEUE_H
#define DYNAMICQUEUE_H

#include <iostream>

using std::cout;

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

};

template<class T>
DynamicQueue<T>::DynamicQueue() {

	front = nullptr;
	rear = nullptr;
	number_of_nodes = 0;

}

template<class T>
DynamicQueue<T>::DynamicQueue(const DynamicQueue& SOURCE) {

	*stackNode sourceNode = SOURCE.front;

	if (sourceNode.front == nullptr) {
		cout << "Copy constructor failed. Source queue is empty.\n";
		cout << "\n";
	}

	else {

		front = new stackNode;
		front->next = nullptr;

		while(sourceNode->next != nullptr) {

			if (number_of_nodes == 0) {
				front->value = sourceNode->value;
				sourceNode = sourceNode->next;
				number_of_nodes++;
			}

			else {
				rear = new stackNode;
				rear->value = sourceNode->value;
				rear->next = new stackNode;
				rear = rear->next;
				sourceNode = sourceNode->next;
				number_of_nodes++;
			}

		}

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