//8. SimpleVector Modification
//
//Modify the SimpleVector class template presented in this chapter to include the
//member functions push_back and pop_back. The push_back function should accept
//an argument and insert its value at the end of the array. The pop_back function
//should accept no argument and remove the last element from the array.Test the
//class with a driver program.

#include "SimpleVector.h"

template<class T>
void enterValues(SimpleVector<T>&);

template<class T>
void showValues(SimpleVector<T>&);

int main() {

	int size;

	cout << "======================================\n";
	cout << "08 - SIMPLEVECTOR MODIFICATION PROGRAM\n";
	cout << "======================================\n";
	cout << "\n";

	cout << "How many values would you like within the array: ";
	cin >> size;
	cin.ignore();

	SimpleVector<int> list(size);

	enterValues(list);

	showValues(list);

	list.pop_back();

	showValues(list);

	list.push_back(20000342);

	showValues(list);

	list.push_back(20000342);

	list.push_back(20000342);

	list.push_back(20000342);

	showValues(list);

	cout << "Ending the program...\n";

}

template<class T>
void enterValues(SimpleVector<T>& s) {

	cout << "Entering values into list...\n";
	cout << "\n";

	for (int i = 0; i < s.size(); i++) {

		cout << "Value #" << i + 1 << ": ";
		cin >> s[i];
		cin.ignore();

	}

	cout << "\n";

}

template<class T>
void showValues(SimpleVector<T>& s) {

	cout << "Showing all values in list...\n";
	cout << "\n";

	for (int i = 0; i < s.size(); i++) {
		cout << "Value #" << i + 1 << ": " << s.getElementAt(i) << "\n";
	}

	cout << "\n";

}