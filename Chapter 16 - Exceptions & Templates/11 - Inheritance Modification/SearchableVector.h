#ifndef SEARCHABLEVECTOR_H
#define SEARCHABLEVECTOR_H
#include "SortableVector.h"

template <class T>
class SearchableVector : public SortableVector<T>
{
public:
   // Default constructor
   SearchableVector() : SortableVector<T>()
      {}
   
   // Constructor
   SearchableVector(int size) : SortableVector<T>(size)
      { }
   
   // Copy constructor
   SearchableVector(const SearchableVector &);

   // Accessor to find an item
   int findItem(const T);

   // Function that sort and search for a particular value within a vector
   void sortAndSearch(const T);

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
                     SortableVector<T>(obj)
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

        count = (range / 2) + (beginning);

        currentValue = this->getElementAt(count);

        if (item == currentValue) {
            itemFound = true;
        }
        else if (range == 0) {
            throw AbsentValue<T>(item);
        }
        else if (item > currentValue) {
            beginning = (range / 2) + beginning;
            if (range == 1) {
                beginning++;
            }
        }
        else if (item < currentValue) {
            end = (range / 2) +  beginning;
            if (range == 1) {
                beginning++;
            }
        }        

    }

    return count;

}

template <class T>
void SearchableVector<T>::sortAndSearch(const T value) {

    this->sort();

    cout << "\n";

    try {
        cout << "\"" << value << "\"" << " was found at element [" << this->findItem(value) << "] of the vector.\n";
        cout << "\n";
    }
    catch (SearchableVector::AbsentValue<T> aV) {
        cout << "\"" <<  aV.getAbsentValue() << "\"" << " could not be found at any element of this vector.\n";
        cout << "\n";
    }

}

#endif