#include<iostream>

using namespace std;

class NumberList {

private:
	struct ListNode {
		double value;
		ListNode* next;
	};

	ListNode* head;

public:

	NumberList() { head = nullptr; }
	~NumberList() {

		ListNode* nodePtr;
		ListNode* nextNode;

		nodePtr = head;

		while (nodePtr) {

			nextNode = nodePtr->next;
			delete nodePtr;
			nodePtr = nextNode;
			nextNode = nullptr;

		}

		head = nullptr;

		cout << "Linked list has been deleted.\n";
		cout << "\n";

	}

	void appendNode(const double NUM) {

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

	void displayList() {

		ListNode* nodePtr;
		int counter = 1;

		nodePtr = head;

		while (nodePtr) {
			cout << "Node #" << counter++ << "\n";
			cout << "Value: " << nodePtr->value << "\n";
			cout << "----------\n";
			nodePtr = nodePtr->next;
		}

		cout << "\n";

	}

	void deleteNode(const double NUM) {

		ListNode* nodePtr = nullptr;
		ListNode* previousNode = nullptr;

		if (!head) {
			return;
		}

		if (head->value == NUM) {
			nodePtr = head->next;
			delete head;
			head = nodePtr;
		}
		else {

			nodePtr = head;

			while (nodePtr) {

				if (nodePtr->value == NUM) {
					previousNode->next = nodePtr->next;
					delete nodePtr;
					nodePtr = previousNode->next;
				}
				else {
					previousNode = nodePtr;
					nodePtr = nodePtr->next;
				}

			}


		}		

	}

};

int main() {

	NumberList list;

	list.appendNode(1);
	list.appendNode(2);
	list.appendNode(3);
	list.appendNode(4);
	list.appendNode(5);
	list.appendNode(6);
	list.appendNode(7);

	cout << "OLD LIST\n";
	cout << "\n";

	list.displayList();

	list.deleteNode(5);
	list.deleteNode(6);
	list.deleteNode(1);
	list.deleteNode(7);

	cout << "NEW LIST\n";
	cout << "\n";

	list.displayList();

}