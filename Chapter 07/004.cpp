#include <iostream>
#include <vector>

using namespace std;

// Variables

const int	ARRAY_SIZE{ 5 };
int			list[ARRAY_SIZE],
			size_size,
			number;

vector<int>	new_list;

// Function Declarations

int inputValidation(int, int);
int chooseN(int);
void createList(int[]);
void createNewList(vector<int> &, int[], int);
void showList(vector<int>);

int main() {

	number = chooseN(number);
	createList(list);	
	createNewList(new_list, list, number);
	showList(new_list);

	cout << endl;

}

// Functions Definitions

int inputValidation(int num, int limit) {
	while (!(cin >> num) || num < limit) {
		cout << "ERROR: Value must be greater than " << limit << ". Re-enter your value: ";
		cin.clear();
		cin.ignore(1200, '\n');
	}
	return num;
}

int chooseN(int number) {

	cout << "Please enter number n: ";
	number = inputValidation(number, 0);

	return number;

}

void createList(int list[]) {

	int value{};

	for (int i = 0; i < ARRAY_SIZE; i++) {
		cout << "Enter value #" << i + 1 << ": ";
		value = inputValidation(value, 0);
		list[i] = value;
	}

}

void createNewList(vector<int> & new_list, int list[], int number) {

	for (int i = 0; i < ARRAY_SIZE; i++) {
		if (list[i] > number) {
			new_list.push_back(list[i]);
		}
	}



}

void showList(vector<int> new_list) {

	cout << "\nNumbers that are greater than " << number << ": ";

	for (int i = 0; i < new_list.size(); i++) {
		cout << new_list[i] << " ";
	}

}

