#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void importData(string, vector<string>&);
void vectorToArray(vector<string>, string[]);
void selectionSort(string[], int);
void swap_string(string&, string&);
void displayArray(string[], int);
void displayVector(vector<string>);

int main() {

	const int		NUM_NAMES{ 20 };
	vector<string>	temp_list;
	string			names[NUM_NAMES];
	const string	FILE{ "C:\\Users\\test\\Documents\\GitHub\\C-plus-plus-Starting_Out_With_C-_Eight_Edition\\Chapter 08\\names.txt" };

	importData(FILE, temp_list);

	vectorToArray(temp_list, names);

	cout << "Array of names BEFORE sort function: " << endl << endl;

	displayArray(names, NUM_NAMES);

	selectionSort(names, NUM_NAMES);

	cout << "Array of names AFTER sort function: " << endl << endl;

	displayArray(names, NUM_NAMES);

}

void displayArray(string array[], int size) {

	for (int i = 0; i < size; i++) {
		cout << array[i] << endl;
	}

	cout << endl;

}

void displayVector(vector<string> vector) {

	cout << "List of names: " << endl << endl;

	for (int i = 0; i < vector.size(); i++) {

		cout << vector[i] << endl;

	}

}

void importData(string file_name, vector<string>& vector) {

	int i = 0;

	string str;
	ifstream input;
	input.open(file_name);

	if (input.fail()) {
		cout << "ERROR: File failed to open." << endl << endl;
		exit(EXIT_SUCCESS);
	}

	while (getline(input, str))	{

		vector.push_back(str);

	}

	input.close();

}

void vectorToArray(vector<string> vector, string array[]) {

	for (int i = 0; i < vector.size(); i++) {
		array[i] = vector[i];
	} 

}

void selectionSort(string array[], int size) {

	string min_value;
	int min_index;

	for (int start = 0; start < size - 1; start++) {

		min_value = array[start];
		min_index = start;

		for (int index = start + 1; index < size; index++) {

			if (array[index] < min_value) {
				min_value = array[index];
				min_index = index;
			}

		}

		swap_string(array[min_index], array[start]);

	}


}

void swap_string(string& a, string& b) {

	string temp;
	temp = a;
	a = b;
	b = temp;

}

