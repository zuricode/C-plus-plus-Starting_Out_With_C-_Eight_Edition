// Implementation file for the MathStack class
#include "MathStack.h"

//***********************************************
// Member function add. add pops                *
// the first two values off the stack and       *
// adds them. The sum is pushed onto the stack. *
//***********************************************

void MathStack::add()
{
   int num, sum;

   // Pop the first two values off the stack.
   pop(sum);
   pop(num);

   // Add the two values, store in sum.
   sum += num;

   // Push sum back onto the stack.
   push(sum);
}

//***********************************************
// Member function sub. sub pops the            *
// first two values off the stack. The          *
// second value is subtracted from the          *
// first value. The difference is pushed        *
// onto the stack.                              *
//***********************************************

void MathStack::sub()
{
   int num, diff;

   // Pop the first two values off the stack.
   pop(diff);
   pop(num);

   // Subtract num from diff.
   diff -= num;

   // Push diff back onto the stack.
   push(diff);
}

void MathStack::mult() {

	int num, num1;

	//Pop the first two values off the stack.	
	pop(num1);
	pop(num);

	cout << "Removing " << num << " and " << num1 << " from the stack...\n";
	cout << "Multiplying " << num << " and " << num1 << " to push " << num * num1 << " to the stack...\n";

	//Multiply num by num1
	num *= num1;

	//Push num onto the stack
	push(num);

	cout << num << " was pushed to the stack!\n";
	cout << "\n";

}

void MathStack::div() {

	int num, num1;

	//Pop the first two values off the stack.	
	pop(num1);
	pop(num);

	cout << "Removing " << num << " and " << num1 << " from the stack...\n";
	cout << "Dividing " << num << " by " << num1 << " to push " << num / num1 << " to the stack...\n";


	//Divide num by num1
	num /= num1;

	//Push num onto the stack
	push(num);

	cout << num << " was pushed to the stack!\n";
	cout << "\n";

}

void MathStack::addAll() {

	int value;
	int sum = 0;

	// Pop all values from the stack and add them to sum.
	while (!isEmpty()) {
		pop(value);
		cout << value << " was removed from the stack - ";
		sum += value;
		cout << "Total - " << sum << "\n";
	}

	//Push sum onto the stack
	push(sum);

	cout << sum << " was pushed to the stack!\n";
	cout << "\n";


}

void MathStack::multAll() {

	int value;
	int multTotal = 1;

	//Pop all values from the stack and multiply them together, storing the total in multTotal
	while (!isEmpty()) {
		pop(value);
		cout << value << " was removed from the stack - ";
		multTotal *= value;
		cout << "Total - " << multTotal << "\n";

	}

	//Push multTotal onto the stack
	push(multTotal);

	cout << multTotal << " was pushed to the stack!\n";
	cout << "\n";

}