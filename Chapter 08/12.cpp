#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

const int		NUMBER_OF_WEEKS{ 52 },
				NUMBER_OF_MONTHS{ 12 };

void importDataFromFile(string, vector<double>&, vector<int>&);
void displayVector(vector<double>, string);
void displayVector(vector<int>, string);
double calculateAverage(vector<double>);
void calculations(vector<double>, vector<int>, vector<double>&);
void outputDataToFile(vector<double>, vector<string>, string);


int main() {

	const string	FILE{ "C:\\Users\\test\\Documents\\GitHub\\C-plus-plus-Starting_Out_With_C-_Eight_Edition\\Chapter 08\\1994_Weekly_Gas_Averages.txt" };
	vector<string>	months{ "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	vector<double>	prices, averages;
	vector<int>		weeks;

	importDataFromFile(FILE, prices, weeks);

	calculations(prices, weeks, averages);

	outputDataToFile(averages, months, "C:\\Users\\test\\Documents\\GitHub\\C-plus-plus-Starting_Out_With_C-_Eight_Edition\\Chapter 08\\Gas_Exercise_Output.txt");

	cout << "Output file successfully exported." << endl << endl;

}

void importDataFromFile(string file_name, vector<double>& vector_double, vector<int>& vector_int) {

	ifstream file;
	file.open(file_name);

	if (file.fail()) {
		cout << "ERROR: File failed to open." << endl << endl;
		exit(EXIT_FAILURE);
	}

	else {

		double element;
		int value;

		for (int i = 0; i < NUMBER_OF_WEEKS; i++) {

			file >> value;
			vector_int.push_back(value);

			file >> element;
			vector_double.push_back(element);

		}

	}

	file.close();
	
}

void displayVector(vector<double> vector, string prompt) {

	cout << prompt << endl << endl;

	for (int i = 0; i < vector.size(); i++) {
		cout << vector[i] << endl;
	}

	cout << endl;


}

void displayVector(vector<int> vector, string prompt) {

	cout << prompt << endl << endl;

	for (int i = 0; i < vector.size(); i++) {
		cout << vector[i] << endl;
	}

	cout << endl;


}

double calculateAverage(vector<double> vector) {

	double total = 0;

	for (int i = 0; i < vector.size(); i++) {
		total += vector[i];
	}

	return total / vector.size();

}

void calculations(vector<double> prices, vector<int> weeks, vector<double>& averages) {

	vector<double> monthly_total;

	int j = 1;

	for (int i = 0; i <= NUMBER_OF_WEEKS; i++) {
		
		if (i == 52) {

			averages.push_back(calculateAverage(monthly_total));

		}

		else if (weeks[i] == j) {

			monthly_total.push_back(prices[i]);

		}		 

		else {

			averages.push_back(calculateAverage(monthly_total));
			monthly_total.clear();
			j++;
			monthly_total.push_back(prices[i]);

		}

		
	}

}

void outputDataToFile(vector<double> averages, vector<string> months, string file_name) {

	ofstream file;
	file.open(file_name);

	if (file.fail()) {
		cout << "ERROR: File failed to open." << endl << endl;
		exit(EXIT_FAILURE);
	}

	file << "Average gas prices per month: " << endl;
	file << "------------------------------" << endl;
	file << endl;

	for (int i = 0; i < NUMBER_OF_MONTHS; i++) {

		file << months[i] << ": " << averages[i] << endl;

	}

	file << endl;

	file.close();

}
