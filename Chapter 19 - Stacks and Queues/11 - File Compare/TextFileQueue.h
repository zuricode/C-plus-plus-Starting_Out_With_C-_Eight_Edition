#ifndef TEXTFILEQUEUE_H
#define TEXTFILEQUEUE_H

#include <iostream>
#include <string>

using std::string;
using std::cout;

class TextFileQueue {

	struct queueNode {
		char letter;
		queueNode* next;
	};

private:
	queueNode* front;
	queueNode* rear;
	int characters;

public:
	TextFileQueue() { front = nullptr; rear = nullptr; characters = 0; }
	TextFileQueue(const TextFileQueue&);
	~TextFileQueue();

	void enqueue(const char);
	void dequeue(char&);
	int getTotalChars() const { return characters; }
	void print(const string);

	bool isEmpty() const;


};

#endif