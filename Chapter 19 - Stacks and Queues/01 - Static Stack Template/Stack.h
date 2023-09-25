#ifndef STACK_H
#define STACK_H

#include <iostream>

using std::cout;

template<class T>
class Stack {

private:
	T* staticArray;
	int arraySize;
	int top;

public:
	Stack(const int SIZE);
	Stack(const Stack&);
	~Stack();

	void push(const T);
	void pop(T&);
	bool isFull() const;
	bool isEmpty() const;


};

template<class T>
Stack<T>::Stack(const int SIZE) {
	arraySize = SIZE;
	staticArray = new T[arraySize];
	top = -1;
}

template<class T>
Stack<T>::Stack(const Stack& SOURCE) {

	arraySize = SOURCE.arraySize;

	staticArray = new T[arraySize];

	for (int i = 0; i < arraySize; i++) {
		arraySize[i] = SOURCE.arraySize[i];
	}
	
	top = SOURCE.top;

}

template<class T>
Stack<T>::~Stack() {

	if (arraySize > 0) {
		delete[] staticArray;
		arraySize = 0;
		top = -1;
	}

}

template<class T>
void Stack<T>::push(const T VALUE) {

	if (isFull()) {
		cout << "ERROR: " << VALUE << " could not be pushed becuase the array is full.\n";
	}
	else {

		top++;
		staticArray[top] = VALUE;
	}

}

template<class T>
void Stack<T>::pop(T& value) {

	if (isEmpty()) {
		cout << "ERROR: No value could be popped because the array is empty.\n";
	}
	else {

		value = staticArray[top];
		top--;

	}

}

template<class T>
bool Stack<T>::isFull() const {

	if (top == arraySize - 1) {
		return true;
	}
	else {
		return false;
	}

}

template<class T>
bool Stack<T>::isEmpty() const {

	if (top == -1) {
		return true;
	}
	else {
		return false;
	}

}



#endif

