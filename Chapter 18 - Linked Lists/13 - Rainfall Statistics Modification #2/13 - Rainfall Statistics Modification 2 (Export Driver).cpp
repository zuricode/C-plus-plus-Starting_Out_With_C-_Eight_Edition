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

using std::ofstream;
using std::ios;

// Functions Declarations

double inputValidation(const double);

template <class T> double averageRainfall(const RainfallData<T>&, const int);
template <class T> int lowestRainfall(const RainfallData<T>&);
template <class T> int highestRainfall(const RainfallData<T>&);
void rainfallReport(const double, const double, const int, const int);

template <class T> void exportData(const RainfallData<T>&);

int main() {

	cout << "=================================================\n";
	cout << "18-13 RAINFALL STATISTICS MODIFICATION PROGRAM #2\n";
	cout << "=================================================\n";
	cout << "\n";

	RainfallData<double> data;
	int months;
	double rainfall_value;

	cout << "How many months of rainfall data would you like to collect? ";
	while (!(cin >> months) || months < 1 || months > 12) {
		cout << "ERROR: Number of months must be a value between 1 and 12. Re-enter your value: \n";
		cout << "\n";
		cin.ignore(1200, '\n');
		cin.clear();
		cout << "How many months of rainfall data would you like to collect? ";
	};

	cout << "\n";

	for (int i = 0; i < months; i++) {
		cout << "Enter rainfall for Month #" << i + 1 << " (in cubic mm): ";
		rainfall_value = inputValidation(0);
		data.appendNode(rainfall_value);
	}

	cout << "\n";

	exportData(data);

	double total_rainfall = data.getTotalValue();
	double average_rainfall = averageRainfall(data, months);
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
double averageRainfall(const RainfallData<T>& LIST, const int MONTHS) {

	double total = LIST.getTotalValue();

	return total / MONTHS;

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
void exportData(const RainfallData<T>& DATA) {

	ofstream file;
	string file_location;
	int counter = 1;

	cout << "Enter the file location to output the rainfall data: ";
	getline(cin, file_location);

	file.open(file_location, ios::out | ios::app);

	ListNode<T>* nodePtr;

	nodePtr = DATA.getHead();

	file << "Rainfall Statistics Export (mm)\n";
	file << "--------------------------\n";

	while (nodePtr != nullptr) {
		file << "Month #" << counter << ": " << nodePtr->value << "\n";
		counter++;
		nodePtr = nodePtr->next;
	}

	cout << "\n";
	cout << "Rainfall data was successfully exported to " << file_location << ".\n";

	file.close();

}
