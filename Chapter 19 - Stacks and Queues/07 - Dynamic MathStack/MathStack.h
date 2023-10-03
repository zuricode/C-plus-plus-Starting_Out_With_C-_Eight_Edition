// Specification file for the MathStack class
#ifndef MATHSTACK_H
#define MATHSTACK_H
#include "IntStack.h"
#include<iostream>

using std::cout;

class MathStack : public IntStack
{
public:
   // Constructor
   MathStack(int s) : IntStack(s) {}

   // MathStack operations
   void add();
   void sub();
   void mult();
   void div();
   void addAll();
   void multAll();
};
#endif