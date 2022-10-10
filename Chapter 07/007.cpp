#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void lowest(vector<int>);
void highest(vector<int>);
void sumOfNumbers(vector<int>);
void average(vector<int>);

int main() {

	vector<int> numbers;

	string fileName;

	cout << "Please enter the name of your chosen file: ";

	getline(cin, fileName);

	ifstream inputFile;
	inputFile.open(fileName);

	if (inputFile) {
		cout << "Valid file." << endl;
		cout << endl;
		int file_number;
		while (inputFile >> file_number) {
			numbers.push_back(file_number);
		}
		inputFile.close();
	}
	else {
		cout << "Invalid file." << endl;
		exit(EXIT_SUCCESS);
	}

	cout << "List of numbers from file: " << endl;
	cout << endl;

	for (int i = 0; i < numbers.size(); i++) {
		cout << numbers[i] << endl;
	}

	cout << endl;
	
	lowest(numbers);
	highest(numbers);
	sumOfNumbers(numbers);
	average(numbers);

}

void lowest(vector<int> array) {

	int lowest = array[0];

	for (int i = 1; i < array.size(); i++) {
		if (array[i] < lowest) {
			lowest = array[i];
		}
	}

	cout << "Lowest number of the array: " << lowest << endl << endl;

}

void highest(vector<int> array) {

	int highest = array[0];

	for (int i = 1; i < array.size(); i++) {
		if (array[i] > highest) {
			highest = array[i];
		}
	}

	cout << "Highest number of the array: " << highest << endl << endl;

}

vector sumOfNumbers(vector<int> array) {

	int sum_of_numbers{ 0 };

	for (int i = 0; i < array.size(); i++) {
		sum_of_numbers = sum_of_numbers + array[i];
	}

	cout << "The sum of all numbers in the array is: " << sum_of_numbers << endl << endl;

}

vector average(vector<int> array) {

	int sum_of_numbers{ 0 };

	for (int i = 0; i < array.size(); i++) {
		sum_of_numbers = sum_of_numbers + array[i];
	}

	double average = sum_of_numbers / double(array.size());

	cout << "The average of the numebrs in the array is: " << average << endl << endl;

}