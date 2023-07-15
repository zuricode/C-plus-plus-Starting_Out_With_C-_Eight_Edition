//10. SortableVector Class Template
//
//Write a class template named SortableVector.The class should be derived from the
//SimpleVector class presented in this chapter.It should have a member function that
//sorts the array elements in ascending order. (Use the sorting algorithm of your choice.)
//Test the template in a driver program.

#include "SortableVector.h"
#include<iostream>
#include<iomanip>

using std::cout;
using std::cin;
using std::fixed;
using std::setprecision;

template <class T>
void showValues(SortableVector<T>&);

int main() {

	srand(time(NULL));

	int num_of_values;

	cout << "=============================================\n";
	cout << "16-10 - SORTABLEVECTOR CLASS TEMPLATE PROGRAM\n";
	cout << "=============================================\n";
	cout << "\n";

	cout << fixed << setprecision(2);

	cout << "Enter the number of values per vector: ";
	cin >> num_of_values;
	cin.ignore();

	cout << "\n";

	SortableVector<int> int_vector(num_of_values);
	SortableVector<double> double_vector(num_of_values);
	SortableVector<char> char_vector(num_of_values);

	cout << "Generating random values for the vectors...\n";
	cout << "\n";

	for (int i = 0; i < num_of_values; i++) {
		int_vector[i] = rand() % 100 + 1;
		double_vector[i] = rand() % 100 / 1.1f8 + 1;
		char_vector[i] = rand() % 25 + 65;
	}

	cout << "Unsorted integer vector order...." << "\n";
	showValues(int_vector);
	cout << "\n";
	
	cout << "Sorted integer vector order...." << "\n";
	int_vector.sort();
	showValues(int_vector);
	cout << "\n";

	cout << "Unsorted double vector order...." << "\n";
	showValues(double_vector);
	cout << "\n";

	cout << "Sorted double vector order...." << "\n";
	double_vector.sort();
	showValues(double_vector);
	cout << "\n";

	cout << "Unsorted char vector order...." << "\n";
	showValues(char_vector);
	cout << "\n";

	cout << "Sorted char vector order...." << "\n";
	char_vector.sort();
	showValues(char_vector);

}

template <class T>
void showValues(SortableVector<T>& vector) {

	for (int i = 0; i < vector.size(); i++) {
		//cout << "Value #" << i + 1 << " : " << vector[i] << "\n";
		cout << vector[i] << " ";
	}

	cout << "\n";

}