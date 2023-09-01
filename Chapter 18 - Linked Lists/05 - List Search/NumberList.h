#ifndef NUMBERLIST_H
#define NUMBERLIST_H

#include<iostream>
#include<string>
#include<vector>

using std::cout;
using std::cin;
using std::string;
using std::vector;

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

	void print(const string);
	void appendNode(const int);
	void insertNode(const int);
	void deleteNode(const int);

	void reverse();
	int search(const int);

};

#endif