#ifndef STATICQUEUE_H
#define STATICQUEUE_H

#include<iostream>

using std::cout;

template<class T>
class StaticQueue {

private:
	T* queueArray;
	int arraySize;
	int front;
	int rear;
	int number_of_elements;

public:
	StaticQueue(const int);
	StaticQueue(const StaticQueue&);
	~StaticQueue();
	
	void push_rear(const T);
	void pop_front(T&);
	bool isEmpty() const;
	bool isFull() const;

	void displayQueue();

};

template<class T>
StaticQueue<T>::StaticQueue(const int SIZE) {

	arraySize = SIZE;
	queueArray = new T[arraySize];
	front = -1;
	rear = -1;
	number_of_elements = 0;

}

template<class T>
StaticQueue<T>::StaticQueue(const StaticQueue& SOURCE) {

	front = SOURCE.front;
	rear = SOURCE.rear;
	arraySize = SOURCE.arraySize;
	number_of_elements = SOURCE.number_of_elements;
	int counter = 0;
	int current_position = front;

	queueArray = new T[arraySize];


	if (front != -1 && rear != -1) {

		while (counter <= number_of_elements) {

			queueArray[current_position] = SOURCE.queueArray[current_position];
			current_position++;

			if (current_position == number_of_elements) {
				current_position = 0;
			}

			counter++;

		}

	}

}

template<class T>
StaticQueue<T>::~StaticQueue() {

	arraySize = 0;
	number_of_elements = 0;
	front = -1;
	rear = -1;
	delete[] queueArray;

}

template<class T>
bool StaticQueue<T>::isEmpty() const {

	if (number_of_elements == 0) {
		return true;
	}
	else {
		return false;
	}

}

template<class T>
bool StaticQueue<T>::isFull() const {

	if (number_of_elements == arraySize) {
		return true;
	}
	else {
		return false;
	}

}

template<class T>
void StaticQueue<T>::push_rear(const T VALUE) {

	if (isFull()) {
		cout << "ERROR: Push failed. Queue is currently full.\n";
		cout << "\n";
	}
	else {

		rear = (rear + 1) % arraySize;
		queueArray[rear] = VALUE;
		number_of_elements++;

		if (number_of_elements == 1) {
			front = rear;
		}

	}

}

template<class T>
void StaticQueue<T>::pop_front(T& value) {

	if (isEmpty()) {
		cout << "ERROR: Pop failed. Queue is currently empty.\n";
		cout << "\n";
	}
	else {

		value = queueArray[front];
		front = (front + 1) % arraySize;
		number_of_elements--;

		if (number_of_elements == 1) {
			rear = front;
		}

	}

}

template<class T>
void StaticQueue<T>::displayQueue() {

	int current_position;

	for (int i = 0; i < arraySize; i++) {
		if (front == i) {
			cout << "  F ";
		}
		else {
			cout << "    ";
		}
	}

	cout << " ";
	cout << "\n";

	for (int i = 0; i < arraySize; i++) {
		cout << "----";
	}

	cout << "-\n";

	if (front <= rear) {
		current_position = front;
	}
	else {
		current_position = rear;
	}

	for (int i = 0; i < arraySize; i++) {

		if (front <= rear) {

			if (current_position == i && current_position <= rear) {
				cout << "| " << queueArray[i] << " ";
			}
			else {
				cout << "|   ";
			}

			current_position++;

		} else {

			if (current_position == i && (current_position <= rear || current_position >= front)) {
				cout << "| " << queueArray[i] << " ";

				if (current_position == arraySize) {
					current_position = 0;
				}

			}
			else {
				cout << "|   ";
			}

			current_position++;

		}

		
	}

	cout << "|\n";

	for (int i = 0; i < arraySize; i++) {
		cout << "----";
	}

	cout << "-\n";

	for (int i = 0; i < arraySize; i++) {
		if (rear == i) {
			cout << "  R ";
		}
		else {
			cout << "    ";
		}
	}

	cout << "\n";
	cout << "\n";

}

#endif