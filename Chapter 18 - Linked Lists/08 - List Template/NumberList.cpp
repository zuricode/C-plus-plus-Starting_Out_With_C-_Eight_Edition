#include "NumberList.h"

NumberList::NumberList(const NumberList& OLD) {
	
	ListNode* SourcePtr = nullptr;
	ListNode* nodePtr = nullptr;
	ListNode* newPtr = nullptr;

	SourcePtr = OLD.head;

	head = new ListNode;

	if (!SourcePtr) {
		cout << "A blank new list was created.\n";
		cout << "\n";
	}
	else if (!SourcePtr->next) {
		head->value = SourcePtr->value;
		cout << "A single list node with the value \"" << SourcePtr->value << "\" was created.\n";
		cout << "\n";
	}

	else {

		nodePtr = head;

		while (SourcePtr->next) {
			nodePtr->value = SourcePtr->value;
			newPtr = new ListNode;
			nodePtr->next = newPtr;
			nodePtr = newPtr;
			SourcePtr = SourcePtr->next;
		}

		nodePtr->value = SourcePtr->value;

	}	

}

NumberList::~NumberList() {

	ListNode* nodePtr;
	ListNode* nextNode;
	int num;

	nodePtr = head;

	while (nodePtr) {
		nextNode = nodePtr->next;
		num = nodePtr->value;
		delete nodePtr;
		nodePtr = nextNode;
	}

	head = nullptr;

}

void NumberList::print(const string DESCRIPTION) {

	ListNode* nodePtr;

	cout << DESCRIPTION << "\n";

	for (int i = 0; i < DESCRIPTION.size(); i++) {
		cout << "-";
	}

	cout << "\n";
	cout << "List Values: ";

	if (!head) {
		cout << "### EMPTY LIST ###";
	}

	nodePtr = head;

	while (nodePtr) {
		cout << nodePtr->value << " ";
		nodePtr = nodePtr->next;
	}

	cout << "\n";
	cout << "\n";

}

void NumberList::appendNode(const int NUM) {

	ListNode* nodePtr;

	ListNode* newNode = new ListNode;
	newNode->value = NUM;
	newNode->next = nullptr;

	if (!head) {
		head = newNode;
	}

	else {

		nodePtr = head;

		while (nodePtr->next) {
			nodePtr = nodePtr->next;
		}

		nodePtr->next = newNode;	

	}	

}

void NumberList::insertNode(const int NUM) {

	ListNode* nodePtr;
	ListNode* previousNode;
	ListNode* newNode;

	newNode = new ListNode;
	newNode->value = NUM;
	newNode->next = nullptr;

	if (!head) {
		head = newNode;
	}

	else {

		nodePtr = head;
		previousNode = nullptr;

		while (nodePtr && nodePtr->value < NUM) {
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		if (!previousNode) {
			head = newNode;
			newNode->next = nodePtr;
		}
		else {
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}

	}

}

void NumberList::deleteNode(const int NUM) {

	ListNode* nodePtr;
	ListNode* newNode;
	ListNode* previousNode = nullptr;

	if (head->value == NUM) {
		newNode = head->next;
		delete head;
		head = newNode;
	}
	else {

		nodePtr = head;

		while (nodePtr->value != NUM) {

			previousNode = nodePtr;
			nodePtr = nodePtr->next;

		}

		newNode = nodePtr->next;
		delete nodePtr;
		previousNode->next = newNode;

	}

}

void NumberList::reverse() {

	vector<int> numbers;
	ListNode* nodePtr = nullptr;

	nodePtr = head;

	if (!nodePtr) {
		cout << "There are no nodes in this list to reverse.\n";
	}
	else if (!nodePtr->next) {
		cout << "There is only one node in this list. The reverse function is unnecessary.\n";
	}
	else {

		while (nodePtr) {
			numbers.push_back(nodePtr->value);
			nodePtr = nodePtr->next;
		}

		nodePtr = head;

	}

	vector<int>::reverse_iterator rit;

	for (rit = numbers.rbegin(); rit != numbers.rend(); rit++) {
		nodePtr->value = *rit;
		nodePtr = nodePtr->next;
	}

}

int NumberList::search(const int NUM) {

	ListNode* nodePtr = nullptr;
	int counter = 0;

	nodePtr = head;

	if (!nodePtr) {
		cout << "There are no values in the list. Search function cannot run.\n";
	}
	else {

		while (nodePtr) {

			if (nodePtr->value == NUM) {
				cout << "\n";
				return counter;
			}

			nodePtr = nodePtr->next;
			counter++;

		}

		cout << "\n";
		return -1;
		
	}

}

void NumberList::insertValueAtPosition(const int POSITION, const int VALUE) {

	ListNode* nodePtr = nullptr;
	ListNode* previousNode = nullptr;
	int counter = 0;
	bool isInserted = false;

	ListNode* newNode = new ListNode;
	newNode->value = VALUE;
	newNode->next = nullptr;

	nodePtr = head;

	if (!nodePtr) {
		nodePtr = newNode;
		cout << "The new node was added at Position 0.\n";
	}
	else if (!nodePtr->next) {

		if (POSITION >= counter) {
			nodePtr->next = newNode;
		}
		else {
			head = newNode;
			head->next = nodePtr;
		}

	}

	else {

		while (nodePtr && !isInserted) {
			
			if (POSITION <= 0) {
				head = newNode;
				head->next = nodePtr;
				isInserted = true;
			}

			else if (POSITION == counter) {
				previousNode->next = newNode;
				newNode->next = nodePtr;
				isInserted = true;
			}

			else if (nodePtr->next == nullptr) {
				nodePtr->next = newNode;
				isInserted = true;
			}

			previousNode = nodePtr;
			nodePtr = nodePtr->next;
			counter++;

		}

	}

}

void NumberList::removeNodeAtPosition(const int POSITION) {

	ListNode* nodePtr;
	ListNode* previousNode = nullptr;

	int counter = 0;
	bool isRemoved = false;

	nodePtr = head;

	if (!nodePtr) {
		cout << "There are no values to remove because the list has no values stored.\n";
	}
	else if (nodePtr->next == nullptr && POSITION == 0) {
		delete nodePtr;
		head = nullptr;
		isRemoved = true;
	}

	else  {

		while(nodePtr && !isRemoved) {

			if (POSITION == counter) {

				if (nodePtr->next == nullptr) {
					previousNode->next = nullptr;
					delete nodePtr;
				}

				else if (POSITION == 0) {
					head = nodePtr->next;
					delete nodePtr;
				}

				else {
					previousNode->next = nodePtr->next;
					delete nodePtr;
					nodePtr = nullptr;
				} 

				isRemoved = true;

			}	

			if (!isRemoved) {
				previousNode = nodePtr;
				nodePtr = nodePtr->next;
				counter++;
			}

		}	if (!isRemoved) {
			cout << "Position #" << POSITION << " does not exist in this list.\n";
			cout << "No values were removed fomr the list.\n";
			cout << "\n";
		}

	}

}
