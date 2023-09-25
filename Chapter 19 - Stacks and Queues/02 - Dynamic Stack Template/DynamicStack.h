#ifndef DYNAMICSTACK_H
#define DYNAMICSTACK_H

#include<iostream>

using std::cout;

template <class T>
class DynamicStack {

private:

	struct StackNode {
		T value;
		StackNode* next;
	};

	StackNode* top;
	int number_of_nodes;

public:

	DynamicStack();
	DynamicStack(const DynamicStack&);
	~DynamicStack();

	void push(const T);
	void pop(T&);
	bool isEmpty() const;

};

template<class T>
DynamicStack<T>::DynamicStack() {
	top = nullptr;
	number_of_nodes = 0;
}

template<class T>
DynamicStack<T>::DynamicStack(const DynamicStack& STACK) {

	StackNode* sourceNode;
	StackNode* destNode;

	if (STACK.isEmpty()) {
		cout << "ERROR: Source stack is empty. Copy constructor has failed.\n";
	} 
	
	top = new StackNode;

	sourceNode = STACK.top;
	destNode = top;

	while(sourceNode->next != nullptr) {
		destNode->value = sourceNode->value;
		destNode->next = new StackNode;
		sourceNode = sourceNode->next;
		destNode = destNode->next;
	}

	destNode->value = sourceNode->value;
	destNode->next = nullptr;

	number_of_nodes = STACK.number_of_nodes;

}

template<class T>
DynamicStack<T>::~DynamicStack() {

	StackNode* currentNode;
	StackNode* tempNode;

	if (isEmpty()) {
	}
	else {

		currentNode = top;

		while (currentNode->next != nullptr) {
			tempNode = currentNode;
			currentNode = currentNode->next;
			delete tempNode;
		}

		currentNode = nullptr;

	}

}

template<class T>
void DynamicStack<T>::push(const T VALUE) {

	StackNode* newNode = new StackNode;
	newNode->value = VALUE;
	newNode->next = nullptr;

	if (isEmpty()) {
		top = newNode;
		number_of_nodes++;

	} else {

		newNode->next = top;
		top = newNode;
		number_of_nodes++;

	}

}

template<class T>
void DynamicStack<T>::pop(T& value) {

	StackNode* tempNode;

	if (isEmpty()) {
		cout << "ERROR: pop function failed. Stack is empty.\n";
	}
	else {

		value = top->value;
		tempNode = top->next;
		delete top;
		number_of_nodes--;
		top = tempNode;

		cout << value << " has been popped from the stack.\n";


	}

}

template<class T>
bool DynamicStack<T>::isEmpty() const {

	if (top == nullptr) {
		return true;
	}
	else {
		return false;
	}

}

#endif