#include <iostream>

using namespace std;

const int			ROWS_AND_COLUMNS{ 3 };

// Function Declarations

void	initialiseGrid(char[][ROWS_AND_COLUMNS]);
void	showGrid(char[][ROWS_AND_COLUMNS]);
void	playerRowMove(int&);
void	playerColumnMove(int&);
int		moveInput(const int);
void	submitMove(char[][ROWS_AND_COLUMNS], int&, int&, const int);
void	checkHorizontals(bool&, char[][ROWS_AND_COLUMNS], const int);
void	checkVerticals(bool&, char[][ROWS_AND_COLUMNS], const int);
void	checkDiagonals(bool&, char[][ROWS_AND_COLUMNS], const int);
void	checkAllSpaces(char[][ROWS_AND_COLUMNS], bool&);
void	isWinner(bool& winner, char array[][ROWS_AND_COLUMNS], const int PLAYER);
void	result(bool, bool, bool);

int main() {

	//Variables

	bool		win_player1 = false,
				win_player2 = false,
				full_grid = false;

	const int	PLAYER_ONE{ 1 },
				PLAYER_TWO{ 2 };

	char		grid[ROWS_AND_COLUMNS][ROWS_AND_COLUMNS];

	int			player1_row,
				player1_column,
				player2_row,
				player2_column;

	// START OF PROGRAM	

	initialiseGrid(grid);

	do {

		if (!win_player1 && !win_player2 && !full_grid) {

			cout << "PLAYER ONE: " << endl;
			submitMove(grid, player1_row, player1_column, PLAYER_ONE);
			cout << endl;
			checkAllSpaces(grid, full_grid);
			isWinner(win_player1, grid, PLAYER_ONE);
			showGrid(grid);

			}
		
		if (!win_player1 && !win_player2 && !full_grid) {

			cout << "PLAYER TWO: " << endl;
			submitMove(grid, player2_row, player2_column, PLAYER_TWO);
			cout << endl;			
			checkAllSpaces(grid, full_grid);
			isWinner(win_player2, grid, PLAYER_TWO);
			showGrid(grid);

		}
		
	} while (!win_player1 && !win_player2 && !full_grid);

	result(win_player1, win_player2, full_grid);

}

//Function Definitions

void initialiseGrid(char array[][ROWS_AND_COLUMNS]) {

	for (int i = 0; i < ROWS_AND_COLUMNS; i++) {
		for (int j = 0; j < ROWS_AND_COLUMNS; j++) {
			array[i][j] = '*';
		}
	}

}

void showGrid(char array[][ROWS_AND_COLUMNS]) {

	cout << "-------------" << endl;

	for (int i = 0; i < ROWS_AND_COLUMNS; i++) {
		for (int j = 0; j < ROWS_AND_COLUMNS; j++) {
			if (j != ROWS_AND_COLUMNS - 1) {
				cout << "| " << array[i][j] << " ";
			}
			else {
				cout << "| " << array[i][j] << " |" << endl;
			}
		}

		cout << "-------------" << endl;

	}

	cout << endl;

}

int moveInput() {

	int num;

	while (!(cin >> num) || (num < 0 || num > ROWS_AND_COLUMNS)) {
		cout << "ERROR: Values must be between 0 and " << ROWS_AND_COLUMNS << ". Re-enter your value: ";
		cin.clear();
		cin.ignore(1200, '\n');
	}

	return num;

}

void playerRowMove(int& row) {

	cout << "Enter the row for your next move: ";

	row = moveInput();

}

void playerColumnMove(int& column) {

	cout << "Enter the column for your next move: ";

	column = moveInput();

}

void submitMove(char array[][ROWS_AND_COLUMNS], int& row, int& column, const int PLAYER) {

	bool clash = false;

	do {

		playerRowMove(row);
		playerColumnMove(column);	

		cout << endl;

		if (array[row][column] == '*') {
			if (PLAYER == 1) {
				array[row][column] = 'X';
			}
			if (PLAYER == 2) {
				array[row][column] = 'O';
			}
			clash = false;
		}
		else {
			cout << "ERROR: Square (" << row << "/" << column << ") is filled already. Choose another square." << endl << endl;
			clash = true;
		}

	} while (clash);
	

}

void checkHorizontals(bool& winner, char array[][ROWS_AND_COLUMNS], const int PLAYER) {

	string line;

	if (PLAYER == 1) {
		for (int i = 0; i < ROWS_AND_COLUMNS; i++) {
			line = "";
			for (int j = 0; j < ROWS_AND_COLUMNS; j++) {
				if (array[i][j] == 'X') {
					line += "X";
				}
			}
			if (line == "XXX") {
				winner = true;
			}
		}
	}

	else if (PLAYER == 2) {
		for (int i = 0; i < ROWS_AND_COLUMNS; i++) {
			line = "";
			for (int j = 0; j < ROWS_AND_COLUMNS; j++) {
				if (array[i][j] == 'O') {
					line += "O";
				}
			}
			if (line == "OOO") {
				winner = true;
			}
		}

	}
	
}

void checkVerticals(bool& winner, char array[][ROWS_AND_COLUMNS], const int PLAYER) {

	string line;

	if (PLAYER == 1) {
		for (int i = 0; i < ROWS_AND_COLUMNS; i++) {
			line = "";
			for (int j = 0; j < ROWS_AND_COLUMNS; j++) {
				if (array[j][i] == 'X') {
					line += "X";
				}
			}
			if (line == "XXX") {
				winner = true;
			}
		}
	}

	else if (PLAYER == 2) {
		for (int i = 0; i < ROWS_AND_COLUMNS; i++) {
			line = "";
			for (int j = 0; j < ROWS_AND_COLUMNS; j++) {
				if (array[j][i] == 'O') {
					line += "O";
				}
			}
			if (line == "OOO") {
				winner = true;
			}
		}

	}

}

void checkDiagonals(bool& winner, char array[][ROWS_AND_COLUMNS], const int PLAYER) {

	string line;

	if (PLAYER == 1) {
		line = "";
		for (int i = 0; i < ROWS_AND_COLUMNS; i++) {
			
				if (array[i][i] == 'X') {
					line += "X";
				}
		} if (line == "XXX") {
			winner = true;
		}

		int j = 2;
		line = "";

		for (int i = 0; i < ROWS_AND_COLUMNS; i++) {
			
			if (array[i][j] == 'X') {
				line += "X";
				j--;
			}
		} if (line == "XXX") {
			winner = true;
		}

	}

	if (PLAYER == 2) {
		line = "";
		for (int i = 0; i < ROWS_AND_COLUMNS; i++) {
			
			if (array[i][i] == 'O') {
				line += "O";
			}
		} if (line == "OOO") {
			winner = true;
		}

		int j = 2;
		line = "";

		for (int i = 0; i < ROWS_AND_COLUMNS; i++) {
			
			if (array[i][j] == 'O') {
				line += "O";
				j--;
			}
		} if (line == "OOO") {
			winner = true;
		}

	}

	
}

void isWinner(bool& winner, char array[][ROWS_AND_COLUMNS], const int PLAYER) {

	checkHorizontals(winner, array, PLAYER);
	checkVerticals(winner, array, PLAYER);
	checkDiagonals(winner, array, PLAYER);

}

void checkAllSpaces(char array[][ROWS_AND_COLUMNS], bool& full_grid) {

	int count{0};

	for (int i = 0; i < ROWS_AND_COLUMNS; i++) {
		for (int j = 0; j < ROWS_AND_COLUMNS; j++) {
			if (array[i][j] == '*') {
				count++;
			}
		}
	}

	if (count == 0) {
		full_grid = true;
	}
}

void result(bool win_player1, bool win_player2, bool full_grid) {

	if (win_player1) {
		cout << "Player 1 (\"X\") has won!" << endl << endl;
	}
	else if (win_player2) {
		cout << "Player 2 (\"X\") has won!" << endl << endl;
	} 
	else if (full_grid) {
		cout << "Tie. The grid is full." << endl << endl;
	}

}