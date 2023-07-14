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

   template <class T>
   class AbsentValue {

   private:
       T absentValue;

   public:
       AbsentValue(T aV) { absentValue = aV; }
       T getAbsentValue() { return absentValue; }

   };

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
    bool itemFound = false;
    int end = this->size();
    int beginning = 0;
    int range;
    int count = -1;
    T currentValue;

    while (!itemFound) {

        range = end - beginning;

        count = (range / 2) + beginning;

        currentValue = this->getElementAt(count);

        if (item == currentValue) {
            itemFound = true;
        }
        else if (count == this->size() - 1 || count == 0) {
            throw AbsentValue<T>(item);
        }
        else if (item > currentValue) {
            beginning = (range / 2) + beginning;
        }
        else if (item < currentValue) {
            end = (range / 2) +  beginning;
        }

    }

    return count;

}

#endif