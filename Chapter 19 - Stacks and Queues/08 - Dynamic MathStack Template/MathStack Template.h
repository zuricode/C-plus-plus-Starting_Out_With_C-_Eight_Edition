// Specification file for the MathStack class
#ifndef MATHSTACK_TEMPLATE_H
#define MATHSTACK_TEMPLATE_H

#include "IntStack Template.h"
#include<iostream>

using std::cout;

template<class T>
class MathStack : public IntStack<T> {

public:
   // Constructor
   MathStack(int s) : IntStack<T>(s) {}

   // MathStack operations
   void add();
   void sub();
   void mult();
   void div();
   void addAll();
   void multAll();

};
#endif

//***********************************************
// Member function add. add pops                *
// the first two values off the stack and       *
// adds them. The sum is pushed onto the stack. *
//***********************************************

template<class T>
void MathStack<T>::add()
{
	T num, sum;

	// Pop the first two values off the stack.
	this.pop(sum);
	this.pop(num);

	// Add the two values, store in sum.
	sum += num;

	// Push sum back onto the stack.
	this.push(sum);
}

//***********************************************
// Member function sub. sub pops the            *
// first two values off the stack. The          *
// second value is subtracted from the          *
// first value. The difference is pushed        *
// onto the stack.                              *
//***********************************************

template<class T>
void MathStack<T>::sub()
{
	T num, diff;

	// Pop the first two values off the stack.
	this->pop(diff);
	this->pop(num);

	// Subtract num from diff.
	diff -= num;

	// Push diff back onto the stack.
	this->push(diff);
}

template<class T>
void MathStack<T>::mult() {

	T num, num1;

	//Pop the first two values off the stack.	
	this->pop(num1);
	this->pop(num);

	cout << "Removing " << num << " and " << num1 << " from the stack...\n";
	cout << "Multiplying " << num << " and " << num1 << " to push " << num * num1 << " to the stack...\n";

	//Multiply num by num1
	num *= num1;

	//Push num onto the stack
	this->push(num);

	cout << num << " was pushed to the stack!\n";
	cout << "\n";

}

template<class T>
void MathStack<T>::div() {

	T num, num1;

	//Pop the first two values off the stack.	
	this->pop(num1);
	this->pop(num);

	cout << "Removing " << num << " and " << num1 << " from the stack...\n";
	cout << "Dividing " << num << " by " << num1 << " to push " << num / num1 << " to the stack...\n";

	//Divide num by num1
	num /= num1;

	//Push num onto the stack
	this->push(num);

	cout << num << " was pushed to the stack!\n";
	cout << "\n";

}

template<class T>
void MathStack<T>::addAll() {

	T value;
	T sum = 0;

	// Pop all values from the stack and add them to sum.
	while (!this->isEmpty()) {
		this->pop(value);
		cout << value << " was removed from the stack - ";
		sum += value;
		cout << "Total - " << sum << "\n";
	}

	//Push sum onto the stack
	this->push(sum);

	cout << sum << " was pushed to the stack!\n";
	cout << "\n";


}

template<class T>
void MathStack<T>::multAll() {

	T value;
	T multTotal = 1;

	//Pop all values from the stack and multiply them together, storing the total in multTotal
	while (!this->isEmpty()) {
		this->pop(value);
		cout << value << " was removed from the stack - ";
		multTotal *= value;
		cout << "Total - " << multTotal << "\n";

	}

	//Push multTotal onto the stack
	this->push(multTotal);

	cout << multTotal << " was pushed to the stack!\n";
	cout << "\n";

}