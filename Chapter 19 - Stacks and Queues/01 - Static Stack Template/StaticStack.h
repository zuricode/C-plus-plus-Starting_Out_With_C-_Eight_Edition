#ifndef STATICSTACK_H
#define STATICSTACK_H

#include <iostream>

using std::cout;

template<class T>
class StaticStack {

private:
	T* staticArray;
	int arraySize;
	int top;

public:
	StaticStack(const int SIZE);
	StaticStack(const StaticStack&);
	~StaticStack();

	void push(const T);
	void pop(T&);
	bool isFull() const;
	bool isEmpty() const;


};

template<class T>
StaticStack<T>::StaticStack(const int SIZE) {
	arraySize = SIZE;
	staticArray = new T[arraySize];
	top = -1;
}

template<class T>
StaticStack<T>::StaticStack(const StaticStack& SOURCE) {

	arraySize = SOURCE.arraySize;

	staticArray = new T[arraySize];

	for (int i = 0; i < arraySize; i++) {
		staticArray[i] = SOURCE.staticArray[i];
	}
	
	top = SOURCE.top;

}

template<class T>
StaticStack<T>::~StaticStack() {

	if (arraySize > 0) {
		delete[] staticArray;
		arraySize = 0;
		top = -1;
	}

}

template<class T>
void StaticStack<T>::push(const T VALUE) {

	if (isFull()) {
		cout << "ERROR: " << VALUE << " could not be pushed becuase the array is full.\n";
	}
	else {

		top++;
		staticArray[top] = VALUE;
	}

}

template<class T>
void StaticStack<T>::pop(T& value) {

	if (isEmpty()) {
		cout << "ERROR: No value could be popped because the array is empty.\n";
	}
	else {

		value = staticArray[top];
		top--;

	}

}

template<class T>
bool StaticStack<T>::isFull() const {

	if (top == arraySize - 1) {
		return true;
	}
	else {
		return false;
	}

}

template<class T>
bool StaticStack<T>::isEmpty() const {

	if (top == -1) {
		return true;
	}
	else {
		return false;
	}

}



#endif

