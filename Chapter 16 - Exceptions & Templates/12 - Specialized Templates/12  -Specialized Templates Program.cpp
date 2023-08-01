//12. Specialized Templates
//
//In this chapter, the section Specialized Templates within Section 16.4 describes
//how to design templates that are specialized for one particular data type.The
//section introduces a method for specializing a version of the SimpleVector class
//template so it will work with strings.Complete the specialization for both the
//SimpleVector and SearchableVector templates.Demonstrate them with a simple
//driver program.

#include "SearchableVector.h"
#include <string>

using std::string;

int main() {

	srand(time(NULL));

	int num_of_elements;

	cout << "=====================================\n";
	cout << "16 - 12 SPECIALIZED TEMPLATES PROGRAM\n";
	cout << "=====================================\n";
	cout << "\n";

	cout << "How many elements will be in each vector: ";
	cin >> num_of_elements;
	cout << "\n";

	cout << "Creating a searchable vector of doubles...\n";
	SearchableVector<double> double_vector(num_of_elements);

	for (int i = 0; i < num_of_elements; i++) {
		double_vector[i] = rand() % 100 / 1.034;
	}
	
	cout << "\n";

	for (int i = 0; i < num_of_elements; i++) {
		cout << "Element #" << i + 1 << ": " << double_vector[i] << "\n";
	}

	cout << "\n";

	cout << "Creating a searchable vector of c-strings...\n";
	SearchableVector<char*> c_string_vector(num_of_elements);

	for (int i = 0; i < num_of_elements; i++) {

		int string_length = rand() % 10 + 1;
		string temp_string = "";

		for (int j = 0; j < string_length; j++) {
			temp_string += (rand() % 25 + 65);
		}

		//c_string_vector[i] = temp_string.c_str();
 
	}

	cout << "\n";

	for (int i = 0; i < num_of_elements; i++) {
		cout << "Element #" << i + 1 << ": " << c_string_vector[i] << "\n";
	}	

	cout << "\n";

}