#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

using std::cout;

class Queue {

private:

	struct Node {
		int value;
		Node* next;
	};

	Node* front;
	Node* rear;
	int items;

public:

	Queue();							// Default constructor
	~Queue();							// Destructor
	Queue(const Queue&);				// Copy constructor
	Queue& operator=(const Queue&);		// Copy assignment operator
	Queue(Queue&&);						// Move constructor
	Queue& operator=(Queue&&);			// Move assignment operator

	void enqueue(const int);
	void dequeue(int&);
	void clear();
	bool isEmpty() const;

};

#endif