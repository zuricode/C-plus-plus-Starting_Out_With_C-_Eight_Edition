#ifndef SEARCHABLEVECTOR_H
#define SEARCHABLEVECTOR_H
#include "SimpleVector.h"

template <class T>
class SearchableVector : public SimpleVector<T>
{
public:
   // Default constructor
   SearchableVector() : SimpleVector<T>()
      {}
   
   // Constructor
   SearchableVector(int size) : SimpleVector<T>(size)
      { }
   
   // Copy constructor
   SearchableVector(const SearchableVector &);

   // Accessor to find an item
   int findItem(const T);
};

//*******************************************************
// Copy constructor                                     *
//*******************************************************

template <class T>
SearchableVector<T>::SearchableVector(const SearchableVector &obj) :
                     SimpleVector<T>(obj.size())
{
   for(int count = 0; count < this->size(); count++)
      this->operator[](count) = obj[count];
}

//*******************************************************
// findItem function                                    *
// This function searches for item. If item is found    *
// the subscript is returned. Otherwise -1 is returned. *
//*******************************************************

template <class T>
int SearchableVector<T>::findItem(const T item)
{
   for (int count = 0; count <= this->size(); count++)
   {
      if (this->getElementAt(count) == item)
         return count;
   }
   return -1;
}

template<>
class SearchableVector<char*> : public SimpleVector<char*> {

public:
    SearchableVector() : SimpleVector<char*>() {}                       //Default Constructor
    SearchableVector(const int SIZE) : SimpleVector<char*>(SIZE) {}     //Constructor with array size argument
    SearchableVector(const SearchableVector&);                          //Copy constructor

    int findItem(const char*);

};

SearchableVector<char*>::SearchableVector(const SearchableVector& OBJ) {

    arraySize = OBJ.size();

    aptr = new char[OBJ.size()];

    for (int i = 0; i < arraySize; i++) {
        *(aptr + i) = *(OBJ.aptr + i);
    }

}

int SearchableVector<char*>::findItem(const char* STRING) {

    int string_index;
    bool isMatch;

    for (int array_index = 0; array_index < arraySize; array_index++) {

        string_index = 0;
        isMatch = true;

        while (STRING[string_index] != '\0' && isMatch) {

            if (STRING[string_index] == this->getElementAt(string_index)) {
                string_index++;
            }
            else {
                isMatch = false;
                return -1;
            }
        }

        if (isMatch) {
            cout << "Match was found!\n";
            return array_index;
        }

    }

}

#endif