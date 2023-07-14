//9. SearchableVector Modification
//
//Modify the SearchableVector class template presented in this chapter so that it performs
//a binary search instead of a linear search.Test the template in a driver program.

#include "SearchableVector.h"

template <class T>
void showValues(SearchableVector<T>&);

int main() {

	srand(time(NULL));

	const int MIN_RANGE = 1;
	const int MAX_RANGE = 50;

	int num_of_values;
	int int_value;
	char char_value;

	cout << "=============================================\n";
	cout << "16-09 - SEARCHABLEVECTOR MODIFICATION PROGRAM\n";
	cout << "=============================================\n";
	cout << "\n";

	cout << "How many values will exist in each vector array? ";
	cin >> num_of_values;
	cin.ignore();

	cout << "\n";

	SearchableVector<int> int_list(num_of_values);
	SearchableVector<char> char_list(num_of_values);
	SearchableVector<double> double_list(num_of_values);

	for (int i = 0; i < num_of_values; i++) {
		int_list[i] = i + 1;
		char_list[i] = i + 65;
		double_list[i] = i + 1.4353;
	}

	cout << "Enter the int value you would like to search for: ";
	cin >> int_value;
	cin.ignore();
	

	cout << "\n";

	cout << "Performing a binary search for the value \"" << int_value << "\".\n";
	cout << "\n";

	showValues(int_list);

	try {
		cout << "VALUE FOUND! " << int_value << " was found at subscript[" << int_list.findItem(int_value) << "] of the vector.\n";
		cout << "\n";
	}
	catch (SearchableVector<int>::AbsentValue<int> x) {
		cout << "\"" << x.getAbsentValue() << "\" does not exist within the vector.\n";
		cout << "\n";
	}

	cout << "==============================================================\n";
	cout << "\n";

	cout << "Enter the char value you would like to search for: ";
	cin >> char_value;
	cin.ignore();

	cout << "\n";

	cout << "Performing a binary search for the value \"" << char_value << "\".\n";
	cout << "\n";

	showValues(char_list);

	try {
		cout << "VALUE FOUND! " << char_value << " was found at subscript[" << char_list.findItem(char_value) << "] of the vector.\n";
		cout << "\n";
	}
	catch (SearchableVector<char>::AbsentValue<char> x) {
		cout << "\"" << x.getAbsentValue() << "\" does not exist within the vector.\n";
		cout << "\n";
	}

	cout << "Ending the program...\n";

}

template <class T>
void showValues(SearchableVector<T>& v) {

	cout << "Showing values in the list...\n";
	cout << "\n";

	for (int i = 0; i < v.size(); i++) {
		cout << "Value #" << i + 1 << ": " << v.getElementAt(i) << "\n";
	}

	cout << "\n";

}