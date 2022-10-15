#include <iostream>

using namespace std;

int inputValidation(int, int);
int linearSearch(int[], int, int, int&);
int binarySearch(int[], int, int, int&);
void displayArray(int[], int);
void lotteryResult(int, int, int);

int main() {

	const int		DRAW{10}, DIGITS{ 5 }, LOWEST{10000}, HIGHEST{99999};

	int				list[DRAW]{ 13579, 26791, 26792, 33445, 55555,
									62483, 77777, 79422, 85647, 93121 };

	int				lottery_number;
	int				element, count{0};

	cout << "Please enter your lottery ticket: ";
	lottery_number = inputValidation(LOWEST, HIGHEST);
	cout << endl;

	displayArray(list, DRAW);

	element = linearSearch(list, lottery_number, DRAW, count);
	lotteryResult(lottery_number, element, count);

	element = binarySearch(list, lottery_number, DRAW, count);
	lotteryResult(lottery_number, element, count);

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

int linearSearch(int array[], int numbers, int draw, int& count) {

	int element = -1;
	count = 0;

	for (int i = 0; i < draw; i++) {
		count++;
		if (array[i] == numbers) {
			element = i;
			return element;
		}
	}

	return element;

}

int binarySearch(int array[], int numbers, int draw, int& count) {

	int first = 0;
	int last = draw - 1;
	int middle;
	int element = -1;
	count = 0;

	while (element == -1 && first < last) {

		count++;

		middle = (first + last) / 2;

		if (numbers == array[middle]) {
			element = numbers;
		}
		else if (numbers < array[middle]) {
			last = middle - 1;
		}
		else if (numbers > array[middle]) {
			first = middle + 1;
		}

	}

	return element;


}

void lotteryResult(int numbers, int element, int count) {

	cout << "Loop count: " << count << endl;

	if (element != -1) {
		cout << numbers << " IS A WINNING NUMBER!" << endl << endl;
	}
	else {
		cout << numbers << " is not a winning number." << endl << endl;

	}

}