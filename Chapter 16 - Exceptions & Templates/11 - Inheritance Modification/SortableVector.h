#ifndef SORTABLEVECTOR_H
#define SORTABLEVECTOR_H

#include "C:\\Users\\Admin\\source\\repos\\Project2\\Project2\\C-plus-plus-Starting_Out_With_C-_Eight_Edition\\SourceCode\\Chapter 16\\SimpleVector.h"

template <class T>
class SortableVector : public SimpleVector<T> {

public:
	SortableVector() : SimpleVector<T>() {}					// Empty Constructor
	SortableVector(int size) : SimpleVector<T>(size) {}		// Constructor - Dynamic Allocate Memory
	SortableVector(const SortableVector&);					// Copy Constructor
	void sort(); 

};

template <class T>
SortableVector<T>::SortableVector(const SortableVector& OBJ) : SimpleVector(OBJ.size()) {

	for (int i = 0; i < this->size(); i++) {
		this->operator[](i) = OBJ[i];
	}

}

template <class T>
void SortableVector<T>::sort() {

	int temp_min_index;
	T temp_value;
	T min_value;

	for (int start = 0; start < this->size(); start++) {
			
			min_value = this->operator[](start);
			temp_min_index = start;

			for (int i = start + 1; i < this->size(); i++) {

				if (this->operator[](i) < min_value) {
					min_value = this->operator[](i);
					temp_min_index = i;
				}

			}

			if (temp_min_index != start) {
				temp_value = this->operator[](start);
				this->operator[](start) = this->operator[](temp_min_index);
				this->operator[](temp_min_index) = temp_value;
			}

	}

}

#endif