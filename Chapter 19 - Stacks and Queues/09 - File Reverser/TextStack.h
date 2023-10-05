#ifndef TEXTSTACK_H
#define TEXTSTACK_H

#include <iostream>

using std::cout;

class TextStack {

	struct stackNode {
		char letter {;
		stackNode* next = nullptr;
	};

private:
	stackNode* top;
	int letters;
	
public:
	TextStack() { top = nullptr; letters = 0; }
	~TextStack();

	void push(const char);
	void pop(char&);

	bool isEmpty() const;

};

#endif