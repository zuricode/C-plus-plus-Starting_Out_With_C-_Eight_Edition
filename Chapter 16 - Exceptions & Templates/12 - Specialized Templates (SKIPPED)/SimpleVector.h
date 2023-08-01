// SimpleVector class template
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
using namespace std;

template <class T>
class SimpleVector
{
private:
   T *aptr;          // To point to the allocated array
   int arraySize;    // Number of elements in the array
   void memError();  // Handles memory allocation errors
   void subError();  // Handles subscripts out of range

public:
   // Default constructor
   SimpleVector()
      { aptr = 0; arraySize = 0;}
      
   // Constructor declaration
   SimpleVector(int);
   
   // Copy constructor declaration
   SimpleVector(const SimpleVector &);
   
   // Destructor declaration
   ~SimpleVector();
   
   // Accessor to return the array size
   int size() const
      { return arraySize; }

   // Accessor to return a specific element
   T getElementAt(int position);

   // Overloaded [] operator declaration
   T &operator[](const int &);
};

//***********************************************************
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

template <class T>
SimpleVector<T>::SimpleVector(int s)
{
   arraySize = s;
   // Allocate memory for the array.
   try
   {
      aptr = new T [s];
   }
   catch (bad_alloc)
   {
      memError();
   }

   // Initialize the array.
   for (int count = 0; count < arraySize; count++)
      *(aptr + count) = 0;
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
   // Copy the array size.
   arraySize = obj.arraySize;
   
   // Allocate memory for the array.
   aptr = new T [arraySize];
   if (aptr == 0)
      memError();
      
   // Copy the elements of obj's array.
   for(int count = 0; count < arraySize; count++)
      *(aptr + count) = *(obj.aptr + count);
}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <class T>
SimpleVector<T>::~SimpleVector()
{
   if (arraySize > 0)
      delete [] aptr;
}

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void SimpleVector<T>::memError()
{
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void SimpleVector<T>::subError()
{
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// cript in the array.                                  *
//*******************************************************

template <class T>
T SimpleVector<T>::getElementAt(int sub)
{
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
T &SimpleVector<T>::operator[](const int &sub)
{
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}

template<>
class SimpleVector<char*> {

protected:
    char* aptr;
    int arraySize;
    void memError();
    void subError();

public:
    SimpleVector() { arraySize = 0; aptr = nullptr; }   //Default constructor
    SimpleVector(const int);                            //Constructor with size argument
    SimpleVector(const SimpleVector&);                  //Copy constructor
    ~SimpleVector();                                    //Destructor
    int size() const { return arraySize; }               //Accessor to arraySize variable
    char getElementAt(const int) const;                 //Accessor to char at specific element
    char& operator[](const int&);                       //Overloaded [] operator for SimpleVector

};

SimpleVector<char*>::SimpleVector(const int SIZE) {
    try {
        aptr = new char[SIZE];
        arraySize = SIZE;
    }
    catch (bad_alloc) {
        cout << "ERROR: Cannot allocate memory.\n";
        cout << "Qutting the program...\n";
        exit(EXIT_FAILURE);
    }
}

SimpleVector<char*>::SimpleVector(const SimpleVector& OBJ) {
    arraySize = OBJ.size();
    aptr = new char[arraySize];

    for (int i = 0; i < arraySize; i++) {
        *(aptr + i) = *(OBJ.aptr + i);
    }

}

SimpleVector<char*>::~SimpleVector() {
    delete[] aptr;
    aptr = nullptr;
}

char SimpleVector<char*>::getElementAt(const int I) const {
    if (I < 0 || I > arraySize) {
        cout << "ERROR: " << I << " is not within range of the array size.\n";
        cout << "Qutting the program...\n";
        exit(EXIT_FAILURE);
    }
    return *(aptr + I);
}

char& SimpleVector<char*>::operator[] (const int& I) {
    if (I < 0 || I > arraySize) {
        cout << "ERROR: " << I << " is not within range of the array size.\n";
        cout << "Qutting the program...\n";
        exit(EXIT_FAILURE);
    }
    return *(aptr + I);
}
#endif 