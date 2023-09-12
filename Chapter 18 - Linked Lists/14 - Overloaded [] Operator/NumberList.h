#ifndef NUMBERLIST_H
#define NUMBERLIST_H

#include<iostream>

using std::cout;
using std::cin;

class NumberList {

private:

	struct ListNode {
		int value;
		ListNode* next;
	};

	ListNode* head;

public:

	NumberList() { head = nullptr; }
	~NumberList();

	class invalidSubscript {

	private:
		int subscript;

	public:
		invalidSubscript(const int VALUE) { subscript = VALUE; }
		int getSubscript() const { return subscript; }

	};

	void displayList();
	void appendNode(const int);
	void insertNode(const int);
	void deleteNode(const int);

	int& operator[](const int);

};

#endif