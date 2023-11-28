//7. Queue Converter
//
//Write a program that stores a series of numbers in a binary tree. Then have the program insert the 
//values into a queue in ascending order. Dequeue the values and display them on the screen to 
//confirm that they were stored in the proper order.

#include "BinaryTree.h"

void displayAndDequeue(Queue& queue);

using std::move;

int main() {

	cout << "============================\n";
	cout << "21-07 QUEUE CONVERTER DRIVER\n";
	cout << "============================\n";
	cout << "\n";

	BinaryTree tree;
	Queue queue;

	tree.insert(4);
	tree.insert(6);
	tree.insert(3);
	tree.insert(7);
	tree.insert(2);
	tree.insert(8);
	tree.insert(1);
	tree.insert(9);
	cout << "\n";

	tree.exportToQueue(queue);
	displayAndDequeue(queue);

	cout << "Ending the program...\n";

}

void displayAndDequeue(Queue& queue) {

	int value;

	cout << "QUEUE CONTENTS: ";

	if (queue.isEmpty()) {
		cout << "EMPTY";
	}

	else {

		while (!queue.isEmpty()) {
			queue.dequeue(value);
			cout << value << " | ";
		}

	}

	cout << "\n";
	cout << "\n";

}