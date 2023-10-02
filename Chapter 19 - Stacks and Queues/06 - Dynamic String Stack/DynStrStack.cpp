#include "DynStrStack.h"

DynStrStack::DynStrStack(const DynStrStack& SOURCE) {

	stackNode* newNode = top;
	stackNode* sourceNode = SOURCE.top;

	while (sourceNode->next != nullptr) {
		newNode = new stackNode;
		newNode->value = sourceNode->value;
		newNode = newNode->next;
		sourceNode = sourceNode->next;
	}

	newNode->next = nullptr;
	nodes = SOURCE.nodes;

}

DynStrStack::~DynStrStack() {

	stackNode* temp = nullptr;

	while (top != nullptr) {
		temp = top->next;
		delete top;
		top = temp;
	}

	cout << "Stack destructor deactived.\n";

}

bool DynStrStack::isEmpty() const {

	if (top == nullptr) {
		return true;
	}
	else {
		return false;
	}

}

void DynStrStack::push() {

	string str = "";

	cout << "Enter your chosen string: ";
	getline(cin, str);

	cout << "\n";

	stackNode* newNode = new stackNode;
	newNode->value = str;
	newNode->next = nullptr;

	if (isEmpty()) {
		top = newNode;
	}
	else {

		newNode->next = top;
		top = newNode;

	}

	nodes++;

	cout << "\"" << str << "\" was pushed to the stack.\n";
	cout << "Strings in stack: " << nodes << "\n";
	cout << "\n";

}

void DynStrStack::pop() {

	stackNode* temp;
	string str;

	if (isEmpty()) {
		cout << "ERROR: String could not be popped becuase the stack is empty.\n";
	}
	else {

		str = top->value;
		temp = top->next;
		delete top;
		top = temp;
		nodes--;

		cout << "\"" << str << "\" was popped from the stack.\n";
	}

	cout << "Strings in stack: " << nodes << "\n";
	cout << "\n";

}

void DynStrStack::print() {

	stackNode* currentNode = top ;

	cout << "------------\n";
	cout << "STRING STACK\n";
	cout << "------------\n";
	cout << "\n";

	if (isEmpty()) {
		cout << "STACK IS EMPTY!\n";
	}
	else {

		while (currentNode != nullptr) {
			cout << currentNode->value;
			currentNode = currentNode->next;
			cout << "\n";
		}

		cout << "\n";
		cout << "Total number of strings: " << nodes << "\n";
		cout << "\n";

	}

}