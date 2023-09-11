//07-02. Rainfall Statistics
// 
//Write a program that lets the user enter the total rainfall for each of 12 months into
//an array of double s.The program should calculate and display the total rainfall for
//the year, the average monthly rainfall, and the months with the highest and lowest
//amounts.
// 
//Input Validation : Do not accept negative numbers for monthly rainfall figures.

//18-09. Rainfall Statistics Modification
//
//Modify Programming Challenge 2 in Chapter 7 (Rainfall Statistics) to let the user decide how many
//months of data will be entered. Use a linked list instead of an array to hold the monthly data
//
//18-13 Rainfall Statistics Modification #2
//
//Modify the program you wrote for Programming Challenge 9 so it saves the data in the linked list to a file. Write a
//second program that reads the data from the file into a linked list and displays it on the screen.

#include "RainfallData.h"
#include <fstream>

using std::ifstream;
using std::ios;

// Functions Declarations

double inputValidation(const double);

template <class T> double averageRainfall(const RainfallData<T>&);
template <class T> int lowestRainfall(const RainfallData<T>&);
template <class T> int highestRainfall(const RainfallData<T>&);
void rainfallReport(const double, const double, const int, const int);

template <class T> void importData(RainfallData<T>&);

int main() {

	cout << "=================================================================\n";
	cout << "18-13 RAINFALL STATISTICS MODIFICATION PROGRAM #2 (IMPORT DRIVER)\n";
	cout << "=================================================================\n";
	cout << "\n";

	RainfallData<double> data;

	importData(data);

	double total_rainfall = data.getTotalValue();
	double average_rainfall = averageRainfall(data);
	int lowest_rainfall = lowestRainfall(data);
	int highest_rainfall = highestRainfall(data);

	rainfallReport(total_rainfall, average_rainfall, lowest_rainfall, highest_rainfall);

}

// Function Definitions

double inputValidation(const double LIMIT) {

	double num;

	while (!(cin >> num) || num < LIMIT) {
		cout << "ERROR: Value must be a double greater than " << LIMIT << ". Please re - enter your value : ";
		cin.clear();
		cin.ignore(1200, '\n');
	}

	cin.ignore(1200, '\n');
	cin.clear();

	return num;

}

template <class T>
double averageRainfall(const RainfallData<T>& LIST) {

	double total = LIST.getTotalValue();

	return total / LIST.getNumberOfMonths();

}

template <class T>
int lowestRainfall(const RainfallData<T>& LIST) {

	int counter = 1;
	ListNode<T>* nodePtr = LIST.getHead();

	double lowest_rainfall = nodePtr->value;
	int lowest_month = counter;

	nodePtr = nodePtr->next;
	counter++;

	while (nodePtr) {

		if (nodePtr->value < lowest_rainfall) {
			lowest_rainfall = nodePtr->value;
			lowest_month = counter;
		}

		nodePtr = nodePtr->next;
		counter++;

	}

	return lowest_month;

}

template <class T>
int highestRainfall(const RainfallData<T>& LIST) {

	int counter = 1;
	ListNode<T>* nodePtr = LIST.getHead();

	double highest_rainfall = nodePtr->value;
	int highest_month = counter;

	nodePtr = nodePtr->next;
	counter++;

	while (nodePtr) {

		if (nodePtr->value > highest_rainfall) {
			highest_rainfall = nodePtr->value;
			highest_month = counter;
		}

		nodePtr = nodePtr->next;
		counter++;

	}

	return highest_month;

}

void rainfallReport(const double total, const double average, const int min, const int max) {

	cout << "\nTotal rainfall: " << total << " cubic mm.";
	cout << "\nAverage rainfall: " << average << " cubic mm.";
	cout << "\nLowest rainfall: Month #" << min;
	cout << "\nHighest rainfall: Month #" << max;
	cout << "\n";

}

template <class T>
void importData(RainfallData<T>& data) {

	string file_location;
	ifstream file;

	cout << "Enter the file location of the Rainfall source file: ";
	getline(cin, file_location);

	file.open(file_location, ios::in);

	while (file.fail()) {

		cout << "ERROR: File could not be found at the specified location.\n";
		cout << "\n";

		file.clear();

		cout << "Enter the file location of the Rainfall source file: ";
		getline(cin, file_location);

		file.open(file_location, ios::in);

	}
	
	cout << "\n";

	cout << "File was successfully opened, not yet imported.\n";

	string current_line;
	int space_counter = 0;

	while (getline(file, current_line)) {

		if (current_line[6] == '#') {

			for (int i = 0; i < current_line.length(); i++) {

				if (space_counter == 2) {
					current_line = current_line.substr(i, current_line.length() - i);
					data.appendNode(stod(current_line));
					space_counter = 0;
					break;
				}

				else if (current_line[i] == ' ') {
					space_counter++;
				}

			}

		}		

	}

	cout << "Rainfall data was successfully imported into the program.\n";

	file.close();

}