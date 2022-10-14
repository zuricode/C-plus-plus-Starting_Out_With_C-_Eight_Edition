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
void displayReport(double[], string[], int);
void displayArray(double[], int);
void displayArray(int[], int);
void sortArray(double[], string[], int);
void swap_double(double&, double&);
void swap_int(int&, int&);
void swap_string(string&, string&);


int main() {


	int month_numbers[ARRAY_LENGTH]{ 0,1,2,3,4,5,6,7,8,9,10,11 };
	string months[ARRAY_LENGTH] {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

	double	rainfall_array[ARRAY_LENGTH];

	collectRainfallInfo(rainfall_array, months);

	double total_rainfall = totalRainfall(rainfall_array);
	double average_rainfall = averageRainfall(rainfall_array);
	string lowest_rainfall = lowestRainfall(rainfall_array, months);
	string highest_rainfall = highestRainfall(rainfall_array, months);

	sortArray(rainfall_array, months, ARRAY_LENGTH);

	cout << "ANNUAL RAINFALL REPORT(in order of highest rainfall): " << endl << endl;

	displayReport(rainfall_array, months, ARRAY_LENGTH);

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

void displayReport(double rainfall[], string months[], int size) {

	for (int i = 0; i < size; i++) {
		cout << months[i] << " - " << rainfall[i] << "mm" << endl;
	}

	cout << endl;

}

void sortArray(double rainfall[], string month[], int size) {

	int max_index;
	double max_value;

	for (int start = 0; start < size - 1; start++) {
		max_value = rainfall[start];
		max_index = start;
		for (int index = start + 1; index < size; index++) {
			if (rainfall[index] > max_value) {
				max_value = rainfall[index];
				max_index = index;
			}
		}
		swap(rainfall[max_index], rainfall[start]);
		swap(month[max_index], month[start]);
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

void displayArray(double array[], int size) {

	for (int i = 0; i < size; i++) {

		if (i != size - 1) {
			cout << i + 1 << " - " << array[i] << ", ";
		}
		else {
			cout << i + 1 << " - " << array[i] << endl;
		}

	}

	cout << endl;


}

void displayArray(int array[], int size) {

	for (int i = 0; i < size; i++) {

		if (i != size - 1) {
			cout << i + 1 << " - " << array[i] << ", ";
		}
		else {
			cout << i + 1 << " - " << array[i] << endl;
		}

	}

	cout << endl;

}

void swap_string(string& a, string& b) {

	string temp;
	temp = a;
	a = b;
	b = temp;

}
