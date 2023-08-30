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

	~NumberList();

	void displayList();
	void appendNode(const int);
	void insertNode(const int);
	void deleteNode(const int);

};

#endif