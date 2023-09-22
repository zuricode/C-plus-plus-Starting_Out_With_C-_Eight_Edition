#include<iostream>
#include<string>

using std::string;
using std::cout;

class intQueue {

private:
	int* queueArray;
	int queueSize;
	int front;
	int rear;
	int numOfElements;

public:

	intQueue(const int SIZE);
	~intQueue();
	void push_back(const int);
	void pop_front(int&);
	bool isFull();
	bool isEmpty();
	void displayQueue(const int);
};

intQueue::intQueue(const int SIZE) {
	queueSize = SIZE;
	queueArray = new int[queueSize];
	front = -1;
	rear = -1;
	numOfElements = 0;
}

intQueue::~intQueue() {
	delete[] queueArray;
	cout << "Queue destructor activated.\n";
	cout << "\n";
}

bool intQueue::isFull() {

	if (numOfElements == queueSize) {
		return true;
	}
	else {
		return false;
	}

}

bool intQueue::isEmpty() {

	if (numOfElements == 0) {
		return true;
	}
	else {
		return false;
	}

}

void intQueue::push_back(const int NUM) {

	if (isFull()) {

		cout << "This queue is already full. \"" << NUM << "\" could not be pushed into the queue.\n";
		cout << "\n";

	}
	else {

		queueArray[rear] = NUM;

		cout << "\"" << NUM << "\" was enqueued.\n";
		cout << "\n";


		if (rear == queueSize - 1) {
			rear = 0;
		}
		else {
			rear++;
		}

		numOfElements++;

	}

}

void intQueue::pop_front(int& num) {

	if (isEmpty()) {
		cout << "This is queue already empty. No values can be popped out of the queue.\n";
		cout << "\n";
	}
	else {

		num = queueArray[front];
		queueArray[front] = NULL;
		

		front = (front + 1) % queueSize {
			front = 0;
		}
		else {
			front++;
		}

		numOfElements--;

	}

}

void intQueue::displayQueue(const int SIZE) {

	cout << "QUEUE DISPLAY\n";
	cout << "=============\n";
	cout << "\n";

	string element = "----";

	for (int i = 0; i < SIZE; i++) {
		cout << element;
	}

	cout << "-\n";

	for (int i = 0; i < SIZE; i++) {
		cout << "| " << queueArray[i] << " ";
	}

	cout << "|\n";

	for (int i = 0; i < SIZE; i++) {
		cout << element;
	}

	cout << "-\n";
	cout << "\n";
	
}

int main() {

	cout << "CH19 ALGORITHM WORKBENCH\n";
	cout << "------------------------\n";
	cout << "WRAP-AROUND INDEXING (STATIC QUEUES)\n";
	cout << "\n";

	const int SIZE = 9;
	intQueue numberQueue(SIZE);
	int value;

	for (int i = 4; i < SIZE; i++) {
		numberQueue.push_back(i);
	}

	cout << "\n";

	numberQueue.displayQueue(SIZE);

	numberQueue.push_back(2);

	numberQueue.pop_front(value);
	cout << "\"" << value << "\" was dequeued.\n\n";
	
	numberQueue.displayQueue(SIZE);
	
	numberQueue.pop_front(value);
	cout << "\"" << value << "\" was dequeued.\n\n";
	
	numberQueue.displayQueue(SIZE);
	
	numberQueue.pop_front(value);
	cout << "\"" << value << "\" was dequeued.\n\n";
	
	numberQueue.displayQueue(SIZE);

	numberQueue.pop_front(value);
	cout << "\"" << value << "\" was dequeued.\n\n";
	
	numberQueue.displayQueue(SIZE);

	for (int i = 4; i < SIZE; i++) {
		numberQueue.push_back(i);
	}

	numberQueue.displayQueue(SIZE);

	for (int i = 4; i < SIZE; i++) {
		numberQueue.push_back(i);
	}

	numberQueue.displayQueue(SIZE);

	numberQueue.display

}