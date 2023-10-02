#ifndef DYNSTRSTACK_H
#define DYNSTRSTACK_H

#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::string;

class DynStrStack {

	struct stackNode {
		string value = "";
		stackNode* next = nullptr;
	};

private:
	stackNode* top = nullptr;
	int nodes = 0;

public:
	DynStrStack() {}
	DynStrStack(const DynStrStack&);
	~DynStrStack();

	bool isEmpty() const;
	void push();
	void pop();

	void print();

};

#endif