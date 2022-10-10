#include<iostream>
#include<vector>

using namespace std;

const int		ROWS{ 7 }, COLUMNS{ 9}, LOWEST{1}, HIGHEST{9};


void generateArrayData(int[][COLUMNS], const int, const int);

void showArray(int[][COLUMNS]);

int getTotal(int[][COLUMNS]);
double getAverage(int[][COLUMNS]);
int getRowTotal(int[][COLUMNS], int);
int getColumnTotal(int[][COLUMNS], int);
int getHighestInRow(int[][COLUMNS], int);
int getLowestInRow(int[][COLUMNS], int);

int inputRow();
int inputColumn();

int main() {

	srand(time(NULL));

	//Variables

	int			test_data_array[ROWS][COLUMNS], total, input_row, input_column, row_total,
				column_total, highest_in_row, lowest_in_row;

	double		average;
	
	generateArrayData(test_data_array, LOWEST, HIGHEST);
	showArray(test_data_array);

	total = getTotal(test_data_array);
	cout << "Total of all numbers in the array: " << total << endl;

	average = getAverage(test_data_array);
	cout << "Mean average of all numbers in the array: " << average << endl << endl;

	cout << "The next function will find sum of all numbers in a specified row." << endl;
	cout << "Enter the number of your chosen row: ";
	input_row = inputRow();
	row_total = getRowTotal(test_data_array, input_row);
	cout << "Total of all numbers in row " << input_row << " of the array: " << row_total << endl << endl;

	cout << "The next function will find sum of all numbers in a specified column." << endl;
	cout << "Enter the number of your chosen column: ";
	input_column = inputColumn();
	column_total = getColumnTotal(test_data_array, input_column);
	cout << "Total of all numbers in column " << input_column << " of the array: " << column_total << endl << endl;

	cout << "The next function will find the highest number in a specified row." << endl;
	cout << "Enter the number of your chosen row: ";
	input_row = inputRow();
	highest_in_row = getHighestInRow(test_data_array, input_row);
	cout << "Highest of numbers in row " << input_row << ": " << highest_in_row << endl << endl;

	cout << "The next function will find the lowest number in a specified row." << endl;
	cout << "Enter the number of your chosen row: ";
	input_row = inputRow();
	lowest_in_row = getLowestInRow(test_data_array, input_row);
	cout << "Lowest of numbers in row " << input_row << ": " << lowest_in_row << endl << endl;

}

int inputRow() {

	int num;



	while (!(cin >> num) || (num < 0 || num > ROWS - 1)) {
		cout << "ERROR: Value must be an integer greater than 0 and lower than " << ROWS - 1 << ". Re-enter your value: ";
		cin.clear();
		cin.ignore(1200, '\n');
	}

	return num;

}

int inputColumn() {

	int num;

	while (!(cin >> num) || (num < 0 || num > COLUMNS - 1)) {
		cout << "ERROR: Value must be an integer greater than 0 and lower than " << COLUMNS - 1 << ". Re-enter your value: ";
		cin.clear();
		cin.ignore(1200, '\n');
	}

	return num;

}

void generateArrayData(int array[ROWS][COLUMNS], const int LOWEST, const int HIGHEST) {

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			array[i][j] = rand() % HIGHEST + LOWEST;
		}
	}

}

void showArray(int array[][COLUMNS]) {

	string section = "";

	for (int i = 0; i < COLUMNS; i++) {
		section += "----";
	}

	section += "-";

			cout << section << endl;

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			if (j != COLUMNS - 1) {
				cout << "| " << array[i][j] << " ";
			}
			else {
				cout << "| " << array[i][j] << " |" << endl;
			}
		}
			cout << section << endl;
	}

	cout << endl << endl;

}

int getTotal(int array[][COLUMNS]) {

	int total{ 0 };

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			total += array[i][j];
		}
	}

	return total;

}

double getAverage(int array[][COLUMNS]) {

	double average, total{ 0 };

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			total += array[i][j];
		}
	}

	average = total / static_cast<double>(ROWS * COLUMNS);

	return average;

}

int getRowTotal(int array[][COLUMNS], int row) {

	int total{ 0 };
		
		for (int j = 0; j < COLUMNS; j++) {
			total += array[row][j];
		}

	return total;

}

int getColumnTotal(int array[][COLUMNS], int column) {

	int total{ 0 };

	for (int j = 0; j < ROWS; j++) {
		total += array[j][column];
	}

	return total;

}

int getHighestInRow(int array[][COLUMNS], int row) {

	int highest;
	highest = array[row][0];

	for (int j = 1; j < COLUMNS; j++) {
		if (array[row][j] > highest) {
			highest = array[row][j];
		}
	}

	return highest;

}

int getLowestInRow(int array[][COLUMNS], int row) {

	int lowest;
	lowest = array[row][0];

	for (int j = 1; j < COLUMNS; j++) {
		if (array[row][j] < lowest) {
			lowest = array[row][j];
		}
	}

	return lowest;

}


