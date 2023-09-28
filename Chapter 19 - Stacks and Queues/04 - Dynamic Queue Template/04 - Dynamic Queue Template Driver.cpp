//4. Dynammic Queue Template
//
//Write your own version of a class template that will create a dynamic queue of any data type.
//Demonstrate the class with a driver program.

#include "DynamicQueue.h"

int main() {

	cout << "===================================\n";
	cout << "19-04 DYNAMIC QUEUE TEMPLATE DRIVER\n";
	cout << "===================================\n";
	cout << "\n";

	DynamicQueue<int> dq1;
	int value;

	dq1.enqueue(4);
	dq1.enqueue(2);
	dq1.enqueue(6);
	dq1.enqueue(34563);
	dq1.enqueue(29);
	dq1.enqueue(-6);
	dq1.enqueue(763);
	dq1.enqueue(-234452);

	DynamicQueue<int> dq2(dq1);

	dq1.dequeue(value);
	cout << value << " was dequeued.\n";

	dq1.dequeue(value);
	cout << value << " was dequeued.\n";

	dq1.dequeue(value);
	cout << value << " was dequeued.\n";

	dq1.dequeue(value);
	cout << value << " was dequeued.\n";

	dq1.dequeue(value);

}