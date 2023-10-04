#include "TextStack.h"

TextStack::~TextStack() {

	stackNode* temp = nullptr;

	while (top != nullptr) {
		temp = top->next;
		delete top;
		top = temp;
	}

	cout << "TextStack destructor was activated.\n";
	cout << "\n";

}

bool TextStack::isEmpty() const {

	if (top == nullptr) {
		return true;
	}
	else {
		return false;
	}

}

void TextStack::push(const char LETTER) {

	stackNode* newNode = new stackNode;
	newNode->letter = LETTER;
	newNode->next = nullptr;

	if (isEmpty()) {
		top = newNode;
	}
	else {

		top->next = newNode;
		top = newNode;

	}

	letters++;

}

void TextStack::pop(char& letter) {

	stackNode* temp = nullptr;

	if (isEmpty()) {
		cout << "ERROR: pop function failed. There are no nodes in the stack to pop!.\n";
		cout << "\n";
	}
	else {

		letter = top->letter;
		temp = top->next;
		delete top;
		top = temp;

	}

}