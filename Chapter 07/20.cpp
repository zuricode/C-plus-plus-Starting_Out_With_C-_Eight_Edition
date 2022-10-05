#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<vector>

using namespace std;

const int			ROWS{ 15 }, COLUMNS{ 30 };
const char			AVAILABLE{ '#' }, SOLD{ '*' };
const string		ROW_PRICING = "C:\\Users\\Admin\\source\\repos\\Project2\\Project2\\Chapter 07\\TheatreRowPrices.txt";

int  inputRow(), inputSeatNumber(), inputMenu();
char inputYesOrNo();

void initTheatre(char[][COLUMNS]);
void displayTheatre(char[][COLUMNS], vector<double>);

void getAndStorePricesFromFile(vector<double>&);

void showMenu(char [][COLUMNS], vector<double>&, int&, int&, bool&, int& sales_count, double& total_sales);
void salesReport(char[][COLUMNS], vector<double>&, int&, double&);
void buySeat(char [][COLUMNS], vector<double>, int &, int &, int&, double&);
void checkEmptySeat(char[][COLUMNS], int, int);

int main() {

	int				row, seat_number, sales_count{0};
	double			total_sales{0.00};
	bool			quit_program = false;

	char			theatre[ROWS][COLUMNS];
	vector<double>	row_pricing;

	initTheatre(theatre);
	getAndStorePricesFromFile(row_pricing);

	do {

		showMenu(theatre, row_pricing, row, seat_number, quit_program, sales_count, total_sales);

	} while (!quit_program);

}

int inputRow() {

	int num;

	while (!(cin >> num) || (num < 1 || num > ROWS)) {
		cout << "ERROR: Value must be an integer between 1 and " << ROWS << ". Re-enter your row: ";
		cin.clear();
		cin.ignore(1200, '\n');
	}

	return num;

}

int inputSeatNumber() {

	int num;

	while (!(cin >> num) || (num < 1 || num > COLUMNS)) {
		cout << "ERROR: Value must be an integer between 1 and " << COLUMNS << ". Re-enter your row: ";
		cin.clear();
		cin.ignore(1200, '\n');
	}

	return num;

}

int inputMenu() {

	int num;

	while (!(cin >> num) || (num < 1 || num > 4)) {
		cout << "ERROR: Value must be an integer between 1 and 4. Re-enter your menu selection: ";
		cin.clear();
		cin.ignore(1200, '\n');
	}

	return num;

}

char inputYesOrNo() {

	char yesorno;

	while (!(cin >> yesorno) || (yesorno != 'Y' && yesorno != 'y' && yesorno != 'N' && yesorno != 'n')) {
		cout << "ERROR: Value must be a character, either \"Y\", \"y\", \"N\" or \"n\". Re-enter your answer: ";
		cin.clear();
		cin.ignore(1200, '\n');
	}

	return yesorno;

}

void initTheatre(char array[][COLUMNS]) {

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			array[i][j] = AVAILABLE;
		}
	}

}

void displayTheatre(char array[][COLUMNS], vector<double> row_pricing) {

	cout << endl;
	cout << "Row\t\t\t" << setw(COLUMNS/2) << "Seats" << endl << endl;
	
	cout << "\t\t\t";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 9) {
				cout << 0;
			}
			else {
				cout << j + 1;
			}
		}
	}

	cout << endl;

	for (int i = 0; i < ROWS; i++) {
		cout << "Row " << i + 1 << " ($" << fixed << setprecision(2) << row_pricing[i] << setprecision(0) << ")\t\t";
		for (int j = 0; j < COLUMNS; j++) {
			cout << array[i][j];
		}
		cout << endl;
	}

	cout << endl << endl;

}

void getAndStorePricesFromFile(vector<double>& row_pricing) {

	ifstream inputFile;
	inputFile.open(ROW_PRICING);

	if (inputFile.fail()) {
		cout << "File failed to open";
		exit(EXIT_SUCCESS);
	}
	
		double price;

		while (inputFile >> price) {
			row_pricing.push_back(price);
		}

		inputFile.close();	

}

void buySeat(char array[][COLUMNS], vector<double> row_pricing, int& row, int& seat_number, int& sales_count, double& total_sales) {

	char menu_answer;

	do {

		cout << "Row: ";
		row = inputRow();

		cout << "Seat number: ";
		seat_number = inputSeatNumber();
		
		array[row - 1][seat_number - 1] = SOLD;
		sales_count++;
		total_sales += row_pricing[row];
		
		cout << endl << endl;

		cout << "Would you like to be another ticket (Y/N): ";
		menu_answer = inputYesOrNo();

	} while (menu_answer == 'Y' || menu_answer == 'y');	

}

void checkEmptySeat(char array[][COLUMNS], int row, int seat_number) {

	if()

}

void salesReport(char array[][COLUMNS], vector<double>& row_pricing, int& sales_count, double& total_sales) {

	cout << "SALES REPORT" << endl;
	cout << "------------------" << endl;
	cout << endl;
	cout << "Seats sold: ";

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			if (array[i][j] == SOLD) {
					cout << "(" << i+1 << "/" << j+1 << "), ";
			}
		}
		
	}

	cout << endl;

	cout << "Total number of seats sold: " << sales_count << endl;
	cout << "Total sales: $" << total_sales << endl;

	cout << endl;

}

void showMenu(char array[][COLUMNS], vector<double>& row_pricing, int& row, int& seat_number, bool& quit_program, int& sales_count, double& total_sales) {

	int menu_selection;

	cout << "   MENU  " << endl;
	cout << "---------" << endl;
	cout << endl;
	cout << "1. Purchases tickets" << endl;
	cout << "2. Sales report" << endl;
	cout << "3. View theatre seating" << endl;
	cout << "4. Quit" << endl;
	cout << endl;
	cout << "Selection: ";

	menu_selection = inputMenu();

	cout << endl;

	switch (menu_selection) {

		case 1:
			buySeat(array, row_pricing, row, seat_number, sales_count, total_sales);
			break;
		case 2:
			salesReport(array, row_pricing, sales_count, total_sales);
			break;
		case 3:
			displayTheatre(array, row_pricing);
			break;
		case 4:
			quit_program = true;
			cout << "Exiting the program..." << endl;
			break;
		default:
			cout << "Invalid option" << endl;
			break;

	}

}
