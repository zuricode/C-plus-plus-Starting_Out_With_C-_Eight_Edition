#ifndef NUMBERLIST_H
#define NUMBERLIST_H

#include<iostream>

using std::cout;
using std::cin;

class NumberList {

private:

	struct ListNode {
		int value = 0;
		ListNode* next = nullptr;
	};

	ListNode* head;

public:

	NumberList() { head = nullptr; }
	NumberList(const NumberList&);
	~NumberList();

	void print();
	void appendNode(const int);
	void insertNode(const int);
	void deleteNode(const int);

};

#endif