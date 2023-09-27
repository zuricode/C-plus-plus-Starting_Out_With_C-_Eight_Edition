//3. Static Queue Template
//
//Write your own version of a class template that will create a static queue of any data type.
//Demonstrate the class with adriver program.

#include "StaticQueue.h"
#include<string>

using std::string;

template<class T>
void push(StaticQueue<T>&, const T);

template<class T>
void pop(StaticQueue<T>&, T&);

int main() {

	const int SIZE = 5;

	cout << "====================================\n";
	cout << "19-03 STATIC QUEUE TEMPLATE DRIVER\n";
	cout << "====================================\n";
	cout << "\n";

	StaticQueue<int> i_queue(SIZE);
	int value;

	push(i_queue, 6);
	i_queue.displayQueue();

	push(i_queue, 3);
	i_queue.displayQueue();

	push(i_queue, 8);
	i_queue.displayQueue();

	pop(i_queue, value);
	i_queue.displayQueue();

	push(i_queue, 5);
	i_queue.displayQueue();
	
	push(i_queue, 0);
	i_queue.displayQueue();

	push(i_queue, 2);
	i_queue.displayQueue();

	push(i_queue, 9);
	i_queue.displayQueue();

	pop(i_queue, value);
	i_queue.displayQueue();

	pop(i_queue, value);
	i_queue.displayQueue();

	pop(i_queue, value);
	i_queue.displayQueue();

	pop(i_queue, value);
	i_queue.displayQueue();


	cout << "Ending the program...\n";

}

template<class T>
void push(StaticQueue<T>& s, const T VALUE) {

	cout << "Pushing \"" << VALUE << "\" to the queue...\n";
	cout << "\n";

	s.push_rear(VALUE);		

}

template<class T>
void pop(StaticQueue<T>& s, T& value) {

	cout << "Popping value from the queue..\n";

	s.pop_front(value);
	
	cout << "\"" << value << "\" was popped from the queue.\n";
	cout << "\n";
	
}