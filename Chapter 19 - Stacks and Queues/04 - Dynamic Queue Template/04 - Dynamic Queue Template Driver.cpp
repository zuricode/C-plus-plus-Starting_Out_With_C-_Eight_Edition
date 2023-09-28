//4. Dynammic Queue Template
//
//Write your own version of a class template that will create a dynamic queue of any data type.
//Demonstrate the class with a driver program.

#include "DynamicQueue.h"
#include<string>

using std::string;

int main() {

	cout << "===================================\n";
	cout << "19-04 DYNAMIC QUEUE TEMPLATE DRIVER\n";
	cout << "===================================\n";
	cout << "\n";

	int nodes;
	DynamicQueue<string> dq1;
	string value;

	cout << "How many nodes would you like in your dynamic queue? ";
	cin >> nodes;
	cin.ignore(1200, '\n');

	cout << "\n";

	for (int i = 0; i < nodes; i++) {

		cout << "Enqueue value #" << i + 1 << ": ";
		getline(cin, value);
		dq1.enqueue(value);

	}

	cout << "\n";

	dq1.displayQueue();

	dq1.dequeue(value);
	dq1.dequeue(value);
	dq1.dequeue(value);
	dq1.dequeue(value);

	cout << "\n";

	dq1.displayQueue();

	cout << "Ending the program...\n";

}