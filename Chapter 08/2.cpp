#include <iostream>

using namespace std;

int inputValidation(int, int);
void linearSearch(int[], int, int);
void displayArray(int[], int);

int main() {

	const int		DRAW{10}, DIGITS{ 5 }, LOWEST{10000}, HIGHEST{99999};

	int				list[DRAW]{ 13579, 26791, 26792, 33445, 55555,
									62483, 77777, 79422, 85647, 93121 };

	int				lottery_number;

	cout << "Please enter your lottery ticket: ";
	lottery_number = inputValidation(LOWEST, HIGHEST);
	cout << endl;

	displayArray(list, DRAW);
	linearSearch(list, lottery_number, DRAW);




}

int inputValidation(int LOWEST, int HIGHEST) {

	int num;

	while (!(cin >> num) || num < LOWEST || num > HIGHEST) {
		cout << "ERROR: Value must be a five-digit integer.";
		cin.clear();
		cin.ignore(1200, '\n');
	}

	return num;

}

void linearSearch(int array[], int numbers, int draw) {

	int element = -1;

	for (int i = 0; i < draw; i++) {
		if (array[i] == numbers) {
			element = i;
		}
	}

	if (element != -1) {
		cout << numbers << " IS A WINNING NUMBER!" << endl;
	}
	else {
		cout << numbers << " is not a winnig number" << endl;

	}

}

void displayArray(int array[], int size) {

	cout << "WINNING LOTTERY NUMBERS: " << endl;

	for (int i = 0; i < size; i++) {

		if (i == size - 1) {
			cout << array[i] << endl;
		}
		else {
			cout << array[i] << " ";
		}

	}

	cout << endl;

}