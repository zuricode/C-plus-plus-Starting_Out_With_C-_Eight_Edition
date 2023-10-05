#include "TextQueue.h"

TextQueue::TextQueue(const TextQueue& SOURCE) {

	queueNode* sourceNode = SOURCE.front;

	if (SOURCE.isEmpty()) {
		cout << "NOTE: Copy constructor has created a new empty TextQueue object.\n";
		cout << "The source TextQueue object was empty.\n";
	}

	else {

		front = new queueNode;
		rear = front;

		while (sourceNode != nullptr) {

			if (number_of_nodes == 0) {
				front->letter = sourceNode->letter;
				front->next = nullptr;
			}

			else {
				rear->next = new queueNode;
				rear = rear->next;
				rear->letter = sourceNode->letter;
				rear->next = nullptr;
			}

			
			sourceNode = sourceNode->next;

		}

	}

	number_of_nodes = SOURCE.number_of_nodes;

}

TextQueue::~TextQueue() {

	queueNode* temp = nullptr;

	while (front != nullptr) {
		temp = front->next;
		delete front;
		front = temp;
	}

}

void TextQueue::enqueue(const char LETTER) {

	queueNode* newNode = new queueNode;
	newNode->letter = LETTER;
	newNode->next = nullptr;

	if (isEmpty()) {
		front = newNode;
		rear = front;
	}
	else {
		rear->next = newNode;
		rear = newNode;
	}

	number_of_nodes++;

}

void TextQueue::dequeue(char& letter) {

	queueNode* temp = nullptr;

	if (isEmpty()) {
		cout << "ERROR: Dequeue function failed because this TextQueue object is empty.\n";
		cout << "\n";
	}
	else {

		letter = front->letter;
		temp = front->next;
		delete front;
		front = temp;
		number_of_nodes--;
	}

}


bool TextQueue::isEmpty() const {

	if (front == nullptr) {
		return true;
	}
	else {
		return false;
	}

}

void TextQueue::print() {

	queueNode* currentNode = front;

	if (isEmpty()) {
		cout << "ERROR: TextQueue is empty. There is nothing to print.\n";
		cout << "\n";
	}
	else {

		cout << "TEXTSTACK DISPLAY\n";
		cout << "-----------------\n";

		while (currentNode != nullptr) {
			cout << currentNode->letter;
			currentNode = currentNode->next;
		}

		cout << "-----------------\n";
		cout << "\n";

	}

}