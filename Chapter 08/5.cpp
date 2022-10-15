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
void displayArray(double[], string[], int);
void sortArray(double[], int[], int);
void swap_double(double&, double&);
void swap_int(int&, int&);


int main() {

	int	month_numbers[ARRAY_LENGTH]{ 1,2,3,4,5,6,7,8,9,10,11,12};
	string months[ARRAY_LENGTH] {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

	double	rainfall_array[ARRAY_LENGTH];

	collectRainfallInfo(rainfall_array, months);

	double total_rainfall = totalRainfall(rainfall_array);
	double average_rainfall = averageRainfall(rainfall_array);
	string lowest_rainfall = lowestRainfall(rainfall_array, months);
	string highest_rainfall = highestRainfall(rainfall_array, months);

	sortArray(rainfall_array, months, ARRAY_LENGTH);

	displayArray(rainfall_array, months, ARRAY_LENGTH);

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

	cout << endl;

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

void displayArray(double rainfall[], string months[], int size) {

	cout << "ANNUAL RAINFALL REPORT(in order of highet rainfall): " << endl << endl;

	for (int i = 0; i < size; i++) {
		cout << months[i] << " - " << rainfall[i] << endl;
	}

	cout << endl;

}

void sortArray(double rainfall[], string month[], int size) {

	int min_index;
	double min_value;

	for (int start = 0; start < size - 1; start++) {
		min_value = rainfall[start];
		min_index = start;
		for (int index = start + 1; index <= size; index++) {
			if (rainfall[index] < min_value) {
				min_value = rainfall[index];
				min_index = index;
			}
		}
		swap_double(rainfall[min_index], rainfall[start]);
		swap_int(month[min_index], month[start]);
	}

}

void swap_double(double& a, double& b) {

	double temp;
	temp = a;
	a = b;
	b = temp;

}

void swap_int(int& a, int& b) {

	int temp;
	temp = a;
	a = b;
	b = temp;

}