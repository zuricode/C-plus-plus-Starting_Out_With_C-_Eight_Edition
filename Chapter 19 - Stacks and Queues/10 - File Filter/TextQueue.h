#ifndef TEXTQUEUE_H
#define TEXTQUEUE_H

#include<iostream>

using std::cout;

class TextQueue {

	struct queueNode {
		char letter {};
		queueNode* next = nullptr;
	};

private:
	queueNode* front;
	queueNode* rear;
	int number_of_nodes = 0;

public:
	TextQueue() { front = nullptr; rear = nullptr; }
	TextQueue(const TextQueue&);
	~TextQueue();

	void enqueue(const char);
	void dequeue(char&);
	bool isEmpty() const;

	void print();


};

#endif