#include "Queue.h"

Queue::Queue() {
	front = nullptr;
	rear = nullptr;
	items = 0;
}

Queue::~Queue() {
	clear();
}

Queue::Queue(const Queue& SOURCE) {

	Node* currentNode = nullptr;
	Node* sourceNode = SOURCE.front;

	front = new Node[SOURCE.items];
	currentNode = front;


	while (sourceNode->next != nullptr) {
		currentNode->value = sourceNode->value;
		currentNode = currentNode->next;
		sourceNode = sourceNode->next;
	}

	rear = currentNode;
	items = SOURCE.items;

}

Queue& Queue::operator=(const Queue& SOURCE) {

	Node* currentNode = nullptr;
	Node* sourceNode = SOURCE.front;

	this->front = new Node[SOURCE.items];
	currentNode = this->front;

	while (sourceNode->next != nullptr) {
		currentNode->value = sourceNode->value;
		currentNode = currentNode->next;
		sourceNode = sourceNode->next;
	}

	this->rear = currentNode;

	return *this;

}

Queue::Queue(Queue&& source) {

	front = source.front;
	rear = source.rear;
	items = source.items;
	source.items = 0;

	delete source.front;
	delete source.rear;
	source.front = nullptr;
	source.rear = nullptr;	

}

Queue& Queue::operator=(Queue&& source) {

	this->front = source.front;
	this->rear = source.rear;
	this->items = source.items;
	source.items = 0;

	delete source.front;
	delete source.rear;
	source.front = nullptr;
	source.rear = nullptr;

	return *this;

}

void Queue::enqueue(const int VALUE) {

	Node* currentNode = front;

	Node* newNode = new Node;
	newNode->value = VALUE;
	newNode->next = nullptr;

	if (currentNode == nullptr) {
		front = newNode;
		rear = newNode;
	}
	else {

		rear->next = newNode;
		rear = newNode;

	}

	items++;

}

void Queue::dequeue(int& value) {

	Node* temp = nullptr;

	if (front == nullptr) {
		cout << "ERROR: Dequeue function failed. Queue is empty.\n";
		cout << "\n";
	}
	else {

		value = front->value;
		items--;
		temp = front;
		front = front->next;
		delete temp;

	}

}

void Queue::clear() {

	Node* temp = nullptr;

	while (front != nullptr) {
		temp = front;
		front = front->next;
		delete temp;
	}

	rear = nullptr;
	items = 0;

}

bool Queue::isEmpty() const {

	if (front == nullptr) {
		return true;
	}
	else {
		return false;
	}

}