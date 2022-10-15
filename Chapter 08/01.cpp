#include <iostream>

using namespace std;

void linearSearch(int[], int, int);
int inputValidation();

int main() {

	const int	SIZE{ 18 };
	int			list[SIZE]{ 5658845, 4520125, 7895122, 8777541, 8451277, 1302850,
							8080152, 4562555, 5552012, 5050552, 7825877, 1250255,
							1005231, 6545231, 3852085, 7576651, 7881200, 4581002 };

	int			charge_account_number;

	cout << "Please enter your charge account number: ";
	charge_account_number = inputValidation();

	cout << endl;

	linearSearch(list, SIZE, charge_account_number);







 
}

int inputValidation() {

	int num;

	while (!(cin >> num)) {
		cout << "ERROR: Value must be an integer. Re-enter your value: ";
		cin.clear();
		cin.ignore(1200, '\n');
	}

	return num;

}

void linearSearch(int array[], int size, int search_value) {

	int element = -1;

	for (int i = 0; i < size; i++) {

		if (array[i] == search_value) {
			element = i;
		}

	}

	if (element != -1) {
		cout << search_value << " IS a valid charge acount number." << endl;
	}
	else {
		cout << search_value << " is NOT a valid charge acount number." << endl;
	}

}