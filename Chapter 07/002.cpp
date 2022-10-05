#include <iostream>
#include <string>

using namespace std;

// Variables

const int ARRAY_LENGTH{ 12 };

// Functions Declarations

double inputValidation(double, double);
void collectRainfallInfo(double [], string[]);
double totalRainfall(double[]);
double averageRainfall(double[]);
string lowestRainfall(double[], string[]);
string highestRainfall(double[], string[]);
void rainfallReport(double, double, string, string);

int main() {

	string months[] {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

	double	rainfall_array[ARRAY_LENGTH];

	collectRainfallInfo(rainfall_array, months);

	double total_rainfall = totalRainfall(rainfall_array);
	double average_rainfall = averageRainfall(rainfall_array);
	string lowest_rainfall = lowestRainfall(rainfall_array, months);
	string highest_rainfall = highestRainfall(rainfall_array, months);

	rainfallReport(total_rainfall, average_rainfall, lowest_rainfall, highest_rainfall);

	cout << endl;

}

// Function Definitions

double inputValidation(double num, double limit) {

	while (!(cin >> num) || num < limit) {
		cout << "ERROR: Value must be a double greater than " << limit << ". Please re - enter your value : ";
		cin.clear();
		cin.ignore(1200, '\n');
	}

	return num;

}

void collectRainfallInfo(double list[], string months[]) {

	double num{};

	for (int i = 0; i < ARRAY_LENGTH; i++) {

		cout << "Enter rainfall for " << months[i] << " (in cubic mm): ";
		num = inputValidation(num, 0);
		list[i] = num;

	}

}

double totalRainfall(double list[]) {

	double total{0};

	for (int i = 0; i < ARRAY_LENGTH; i++) {
		total += list[i];
	}

	return total;

}

double averageRainfall(double list[]) {

	double total{ 0 };

	for (int i = 0; i < ARRAY_LENGTH; i++) {
		total += list[i];
	}

	return total / ARRAY_LENGTH;

}

string lowestRainfall(double list[], string months[]) {
	
	double min;
	int month;

	for (int i = 0; i < ARRAY_LENGTH; i++) {

		if (i == 0) {
			min = list[i];
			month = i;
		}
		
		else if ((i > 0) && (list[i] < min)) {
			min = list[i];
			month = i;
		}

	}

	return months[month];

}

string highestRainfall(double list[], string months[]) {

	double max;
	int month;

	for (int i = 0; i < ARRAY_LENGTH; i++) {

		if (i == 0) {
			max = list[i];
			month = i;
		}

		else if ((i > 0) && (list[i] > max)) {
			max = list[i];
			month = i;
		}

	}

	return months[month];

}

void rainfallReport(double total, double average, string min, string max) {

	cout << "\nTotal rainfall: " << total << " cubic mm.";
	cout << "\nAverage rainfall: " << average << " cubic mm.";
	cout << "\nLowest rainfall month: " << min;
	cout << "\nHighest rainfall month: " << max;

}
