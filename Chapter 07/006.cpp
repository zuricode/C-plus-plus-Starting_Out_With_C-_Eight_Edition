#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Constant variables

const int		COLUMNS{ 3 },
				ROWS{30};

const string	MONTHS_WORDS[COLUMNS]{ "June", "July", "August" },
				rainOrShine{ "C:\\Users\\Admin\\source\\repos\\Project2\\Project2\\Chapter 07\\RainOrShine.txt" },
				WEATHER_TYPES_WORDS[COLUMNS]{ "Rainy", "Cloudy", "Sunny" };

const char		WEATHER_TYPES[COLUMNS]{ 'R', 'C', 'S' };


// Function Declarations

void getInfoFromFile(char[][COLUMNS], string);
void threeMonthReport(char[][COLUMNS]);
void individualMonthReport(char[][COLUMNS]);

int main() {

	// Local variables
					
	char		weather_conditions[ROWS][COLUMNS];

	// Program

	getInfoFromFile(weather_conditions, rainOrShine);

	individualMonthReport(weather_conditions);

	threeMonthReport(weather_conditions);

	

	}

// Function Definitions

void getInfoFromFile(char array[][COLUMNS], string fileName) {

	ifstream inputFile;
	inputFile.open(fileName);

	for (int i = 0; i < COLUMNS; i++) {
		for (int j = 0; j < ROWS; j++) {
			inputFile >> array[i][j];
		}
	}

	inputFile.close();

}

void threeMonthReport(char array[][COLUMNS]) {

	int count_1{ 0 }, count_2{ 0 }, count_3{ 0 };

	for (int i = 0; i < COLUMNS; i++) {
		for (int j = 0; j < ROWS; j++) {
			if (array[i][j] == 'R') {
				count_1++;
			}
			else if (array[i][j] == 'C') {
				count_2++;
			}
			else if (array[i][j] == 'S') {
				count_3++;
			}
		}
	}

	cout << "Total Three Month Report: " << endl;
	cout << "--------------------------------------" << endl;
	cout << endl;
	cout << "Total number of rainy days: " << count_1 << endl;
	cout << "Total number of cloudy days: " << count_2 << endl;
	cout << "Total number of sunny days: " << count_3 << endl;

	cout << endl << endl;

}

void individualMonthReport(char array[][COLUMNS]) {

	int june_rainy{ 0 }, june_cloudy{ 0 }, june_sunny{ 0 },
		july_rainy{ 0 }, july_cloudy{ 0 }, july_sunny{ 0 },
		august_rainy{ 0 }, august_cloudy{ 0 }, august_sunny{ 0 };

	string highest_rain;

	for (int i = 0; i < COLUMNS; i++) {
		for (int j = 0; j < ROWS; j++) {

			if (i == 0 && array[i][j] == 'R') {
				june_rainy++;
			}
			else if (i == 0 && array[i][j] == 'C') {
				june_cloudy++;
			}
			else if (i == 0 && array[i][j] == 'S') {
				june_sunny++;
			}
			else if (i == 1 && array[i][j] == 'R') {
				july_rainy++;
			}
			else if (i == 1 && array[i][j] == 'C') {
				july_cloudy++;
			}
			else if (i == 1 && array[i][j] == 'S') {
				july_sunny++;
			}
			else if (i == 2 && array[i][j] == 'R') {
				august_rainy++;
			}
			else if (i == 2 && array[i][j] == 'C') {
				august_cloudy++;
			}
			else if (i == 2 && array[i][j] == 'S') {
				august_sunny++;
			}
		}
	}

	if (june_rainy > july_rainy && june_rainy > august_rainy) {
		highest_rain = MONTHS_WORDS[0];
	}
	else if (july_rainy > june_rainy && july_rainy > august_rainy) {
		highest_rain = MONTHS_WORDS[1];
	}
	else {
		highest_rain = MONTHS_WORDS[2];
	}
	

	cout << "Individual Monthly Report: " << endl;
	cout << "--------------------------------------" << endl;
	cout << endl;
	cout << "June ---> " << "Rain: " << june_rainy << " Cloudy: " << june_cloudy << " Sunny: " << june_sunny << endl;
	cout << "July ---> " << "Rain: " << july_rainy << " Cloudy: " << july_cloudy << " Sunny: " << july_sunny << endl;
	cout << "August ---> " << "Rain: " << august_rainy << " Cloudy: " << august_cloudy << " Sunny: " << august_sunny << endl;

	cout << endl;

	cout << "The month of most rainfall was " << highest_rain << "." << endl;

	cout << endl << endl;

}
