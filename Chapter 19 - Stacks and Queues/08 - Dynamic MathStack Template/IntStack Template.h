// Specification file for the IntStack class
#ifndef INTSTACK_TEMPLATE_H
#define INTSTACK_TEMPLATE_H

#include <iostream>

using std::cout;

template <class T>
class IntStack
{
private:
   T *stackArray;  // Pointer to the stack array
   int stackSize;    // The stack size
   int top;          // Indicates the top of the stack

public:
   // Constructor
   IntStack(int);

   // Copy constructor
   IntStack(const IntStack &);

   // Destructor
   ~IntStack();
   
   // Stack operations
   void push(T);
   void pop(T&);
   bool isFull() const;
   bool isEmpty() const;

};


//***********************************************
// Constructor                                  *
// This constructor creates an empty stack. The *
// size parameter is the size of the stack.     *
//***********************************************

template<class T>
IntStack<T>::IntStack(int size)
{
    stackArray = new T[size];
    stackSize = size;
    top = -1;
}

//***********************************************
// Copy constructor                             *
//***********************************************

template<class T>
IntStack<T>::IntStack(const IntStack& obj)
{
    // Create the stack array.
    if (obj.stackSize > 0)
        stackArray = new T[obj.stackSize];
    else
        stackArray = nullptr;

    // Copy the stackSize attribute.
    stackSize = obj.stackSize;

    // Copy the stack contents.
    for (int count = 0; count < stackSize; count++)
        stackArray[count] = obj.stackArray[count];

    // Set the top of the stack.
    top = obj.top;
}

//***********************************************
// Destructor                                   *
//***********************************************

template<class T>
IntStack<T>::~IntStack()
{
    delete[] stackArray;
}

//*************************************************
// Member function push pushes the argument onto  *
// the stack.                                     *
//*************************************************

template<class T>
void IntStack<T>::push(T value)
{
    if (isFull())
    {
        cout << "The stack is full.\n";
    }
    else
    {
        top++;
        stackArray[top] = value;
    }
}

//****************************************************
// Member function pop pops the value at the top     *
// of the stack off, and copies it into the variable *
// passed as an argument.                            *
//****************************************************

template<class T>
void IntStack<T>::pop(T& value)
{
    if (isEmpty())
    {
        cout << "The stack is empty.\n";
    }
    else
    {
        value = stackArray[top];
        top--;
    }
}

//***************************************************
// Member function isFull returns true if the stack *
// is full, or false otherwise.                     *
//***************************************************

template<class T>
bool IntStack<T>::isFull() const
{
    bool status;

    if (top == stackSize - 1)
        status = true;
    else
        status = false;

    return status;
}

//****************************************************
// Member funciton isEmpty returns true if the stack *
// is empty, or false otherwise.                     *
//****************************************************

template<class T>
bool IntStack<T>::isEmpty() const
{
    bool status;

    if (top == -1)
        status = true;
    else
        status = false;

    return status;
}

#endif 