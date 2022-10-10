#include <iostream>
#include <vector>

const int		AMOUNT_OF_NUMBERS{ 5 },
				LOWEST_NUMBER{ 0 },
				HIGHEST_NUMBER{ 9 };

using namespace std;

// Function Declarations

void printArray(int[], const int);
void printVector(vector<int>);
int inputValidation(const int, const int);
void generateRandomNumbers(int[AMOUNT_OF_NUMBERS]);
void inputUserNumbers(int[AMOUNT_OF_NUMBERS]);
void compareNumbers(int[AMOUNT_OF_NUMBERS], int[AMOUNT_OF_NUMBERS], vector<int>&, int);
void showMatch(vector<int>, int);

int main() {

	srand(time(NULL));

	// Variables

	int			draw[AMOUNT_OF_NUMBERS],
				user[AMOUNT_OF_NUMBERS],
				counter{0};

	vector<int>	matching_numbers;

	generateRandomNumbers(draw);
	inputUserNumbers(user);
	compareNumbers(draw, user, matching_numbers, counter);

	cout << "LOTTERY DRAW: "; 
	printArray(draw, AMOUNT_OF_NUMBERS);

	showMatch(matching_numbers, counter);

}

// Function Definitions

void printArray(int array[], const int num) {

	for (int i = 0; i < num; i++) {
		if (i == num - 1) {
			cout << array[i] << endl;
		} else
		cout << array[i] << ", ";
	}

}

void printVector(vector<int> vector) {

	for (int i = 0; i < vector.size(); i++) {
		if (i == vector.size() - 1) {
			cout << vector[i] << endl;
		}
		else {
			cout << vector[i] << ", ";
		}
	}

	cout << endl;

}

int inputValidation(const int LOWEST, const int HIGHEST) {

	int num;

	while (!(cin >> num) || (num < LOWEST || num > HIGHEST)) {
		cout << "ERROR: Value must be an integer greater than " << LOWEST << " and lesser than " << HIGHEST << ". Re-enter your value: ";
		cin.clear();
		cin.ignore(1200, '\n');
	}

	return num;

}

void generateRandomNumbers(int array[AMOUNT_OF_NUMBERS]) {

	for (int i = 0; i < AMOUNT_OF_NUMBERS; i++) {
		array[i] = rand() % HIGHEST_NUMBER;
	}

}

void inputUserNumbers(int array[AMOUNT_OF_NUMBERS]) {

	cout << "ENTRY OF NUMBERS: " << endl;
	cout << "-----------------------" << endl;
	cout << endl;
	cout << "Please enter your " << AMOUNT_OF_NUMBERS << " chosen numbers..." << endl;
	cout << endl;

	for (int i = 0; i < AMOUNT_OF_NUMBERS; i++) {
		cout << "#" << i + 1 << ": ";
		array[i] = inputValidation(LOWEST_NUMBER, HIGHEST_NUMBER);
	}

	cout << endl;

}

void compareNumbers(int draw[AMOUNT_OF_NUMBERS], int user[AMOUNT_OF_NUMBERS], vector<int>& winners, int count) {

	count = 0;

	for (int i = 0; i < AMOUNT_OF_NUMBERS; i++) {
		if (user[i] == draw[i]) {
			winners.push_back(draw[i]);
			count++;
		}
	}

}

void showMatch(vector<int> vector, int count) {

	cout << "Total matching numbers: " << count << "\tList of numbers: ";
		if (count > 0) {
			printVector(vector);
			cout << endl;

		} 
		if (count == AMOUNT_OF_NUMBERS) {
			cout << "**********************************************" << endl;
			cout << "**********************************************" << endl << endl;
			cout << "CONGRATULATIONS! YOU ARE A GRAND PRIZE WINNER!" << endl << endl;
			cout << "**********************************************" << endl;
			cout << "**********************************************" << endl << endl;
		
		}
		if (count == 0) {
			cout << "None" << endl;
		}

}