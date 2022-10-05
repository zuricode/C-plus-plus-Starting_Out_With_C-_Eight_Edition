#include <iostream>
#include <vector>

const int	SIZE{ 3 }, GRID_SIZE{ 9 }, MAGIC_NUMBER{ 15 };
const int	GRID_NUMBERS[GRID_SIZE]{ 1,2,3,4,5,6,7,8,9 };

void		showSquare(int[][SIZE]);
bool		checkRows(int[][SIZE]);
bool		checkColumns(int[][SIZE]);
bool		checkDiagonals(int[][SIZE]);
bool		check1to9(int[][SIZE]);
void		checkSquare(int[][SIZE]);

using namespace std;

int main() {

	int		true_square[SIZE][SIZE]{ {4,9,2}, {3,5,7}, {8,1,6} }, 
			wrong_square[SIZE][SIZE]{ {8,1,6}, {3,5,7}, {4,9,2} };

	checkSquare(true_square);
	checkSquare(wrong_square);

}

void showSquare(int array[][SIZE]) {

	cout << "Image of the square: " << endl;
	cout << "---------------------" << endl << endl;

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {			
			cout << array[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
}

bool checkRows(int array[][SIZE]) {

	double total[SIZE];
	bool is_rows_magic;

	for (int i = 0; i < SIZE; i++) {
		total[i] = 0;
		for (int j = 0; j < SIZE; j++) {
			total[i] += array[i][j];
		}
		//cout << "Row #" << i << " has a total of: " << total[i] << endl;
	}

	for (int i = 0; i < SIZE; i++) {
		if (total[i] != MAGIC_NUMBER) {
			is_rows_magic = false;
			return is_rows_magic;
		}		
	}

	is_rows_magic = true;
	return is_rows_magic;

}

bool checkColumns(int array[][SIZE]) {

	double total[SIZE];
	bool is_column_magic;

	for (int i = 0; i < SIZE; i++) {
		total[i] = 0;
		for (int j = 0; j < SIZE; j++) {
			total[i] += array[j][i];
		}
	}

	for (int i = 0; i < SIZE; i++) {
		if (total[i] != MAGIC_NUMBER) {
			is_column_magic = false;
			return is_column_magic;
		}
	}

	is_column_magic = true;
	return is_column_magic;

}

bool checkDiagonals(int array[][SIZE]) {

	double total_one{0}, total_two{0};
	bool is_diagonals_magic;

	// Add total for diagonal #1

	for (int i = 0; i < SIZE; i++) {
		total_one += array[i][i];
	}

	// Add total for diagonal #2

	int diagonal_var = SIZE - 1;

	for (int i = 0; i < SIZE; i++) {
			total_two += array[diagonal_var][i];
			diagonal_var--;
	}

	if (total_one && total_two != MAGIC_NUMBER) {
		is_diagonals_magic = false;
		return is_diagonals_magic;
	}
	
	is_diagonals_magic = true;
	return is_diagonals_magic;

}

bool check1to9(int array[][SIZE]) {

	bool is_range_correct;
	vector<int> range_check;
	int range_counter;

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			range_counter = 0;
			range_check.push_back(array[i][j]);
			if (array[i][j] < 1 || array[i][j] > 9) {
				is_range_correct = false;
				return is_range_correct;
			} for (int k = 0; k < range_check.size(); k++) {
				if (array[i][j] == range_check[k]) {
					range_counter++;
				} if (range_counter > 1) {
					is_range_correct = false;
					return is_range_correct;
				}
			}
		}
	}

	is_range_correct = true;
	return is_range_correct;

}

void checkSquare(int array[][SIZE]) {

	bool	row_check,
			column_check,
			diagonal_check,
			range_check;

	showSquare(array);
	row_check = checkRows(array);
	column_check = checkColumns(array);
	diagonal_check = checkDiagonals(array);
	range_check = check1to9(array);

	cout << "Row check: " << row_check << endl;
	cout << "Column check: " << column_check << endl;
	cout << "Diagonal check: " << diagonal_check << endl;
	cout << "Range check: " << range_check << endl << endl;

	if (row_check && column_check && diagonal_check && range_check) {
		cout << "This IS a Lo Shu Magic Square!" << endl << endl;
	}
	else {
		cout << "This is NOT a Lo Shu Magic Square!" << endl << endl;
	}

}
