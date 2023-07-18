//11. Inheritance Modification
//
//Assuming you have completed Programming Challenges 9 and 10, modify the inheritance
//hierarchy of the SearchableVector class template so it is derived from the
//SortableVector class instead of the SimpleVector class.Implement a member function
//named sortAndSearch, both a sort and a binary search.

#include "SearchableVector.h"

template <class T>
void showValues(SearchableVector<T>&);

int main() {

	srand(time(NULL));

	int num_of_values;
	int int_search_value;
	double double_search_value;

	cout << "========================================\n";
	cout << "16-11 - INHERITANCE MODIFICATION PROGRAM\n";
	cout << "========================================\n";
	cout << "\n";

	cout << "Enter the number of values within every vector: ";
	cin >> num_of_values;
	cin.ignore();

	cout << "\n";

	cout << "Enter the value you would like to search for: ";
	cin >> int_search_value;
	cin.ignore();

	cout << "\n";

	SearchableVector<int> int_vector(num_of_values);
	SearchableVector<double> double_vector(num_of_values);
	SearchableVector<char> char_vector(num_of_values);

	for (int i = 0; i < num_of_values; i++) {
		int_vector[i] = rand() % 100 + 1;
		double_vector[i] = rand() % 100 / 1.235;
		char_vector[i] = rand() % 25 + 65;
	}

	cout << "Unsorted vector of integers...\n";
	showValues(int_vector);
	int_vector.sortAndSearch(int_search_value);

	cout << "Sorted vector of integers...\n";
	showValues(int_vector);

	cout << "\n";

	cout << "Enter the value you would like to search for: ";
	cin >> double_search_value;
	cin.ignore();

	cout << "\n";

	cout << "Unsorted vector of double...\n";
	showValues(double_vector);
	double_vector.sortAndSearch(double_search_value);

	cout << "Sorted vector of double...\n";
	showValues(double_vector);

	
}

template <class T>
void showValues(SearchableVector<T>& VECTOR) {

	for (int i = 0; i < VECTOR.size(); i++) {
		cout << VECTOR[i] << " ";
	}

	cout << "\n";

}
