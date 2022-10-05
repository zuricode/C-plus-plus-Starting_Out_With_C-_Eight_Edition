#include <iostream>

const int	SIZE{ 3 },
			GRID_SIZE{ 9 },
			GRID_NUMBERS[GRID_SIZE]{ 1,2,3,4,5,6,7,8,9 },
			MAGIC_NUMBER{15};

void	checkSquare(int[][SIZE]),
		showSquare(int[][SIZE]);

using namespace std;


int main() {

	int sqaure[SIZE][SIZE]{ 4,9,2,3,5,7,8,1,6 };

	showSquare(square);
	checkSquare(square);

}

void showSquare(int array[][SIZE]) {

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cout << "Image of the square: " << endl;
			cout << "---------------------" << endl << endl;
			cout << array[i][j] << "  ";
		}
		cout << endl;
	}

}

void checkSquare(int array[][SIZE]) {

	bool is_magic_square = true;

	if ((array[1][1] + array[1][2] + array[1][3]) ||
		(array[2][1] + array[2][2] + array[2][3]) ||
		(array[3][1] + array[3][2] + array[3][3]) ||
		(array[1][1] + array[2][1] + array[3][1]) ||
		(array[1][2] + array[2][2] + array[3][2]) ||
		(array[1][3] + array[2][3] + array[3][3]) || != MAGIC_NUMBER) {
		is_magic_square = false;
	}
	else {
		is_magic_square = true;
	}

	if (is_magic_square) {
		cout << "Congratulations! This square is a Lo Shu Magic Square." << endl << endl;
	}
	else {
		cout << "Sorry...this is just another ordinary square." << endl << endl;
	}

}