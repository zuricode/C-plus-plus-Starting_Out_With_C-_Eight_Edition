#include <iostream>
#include <string>

using namespace std;

string enterNumber();
void sumOfSeries(string);
void findLowest(string);
void findHighest(string);

int main() {

	string series;

	series = enterNumber();

	sumOfSeries(series);
	findLowest(series);
	findHighest(series);

}

string enterNumber() {

	string series;

	cout << "Enter your number: ";
	getline(cin, series);

	return series;

}

void sumOfSeries(string series) {

	int sum = 0;
	string temp;

	for (int i = 0; i < series.length(); i++) {
		
		temp = series[i];
		sum += stoi(temp);

	}

	cout << "The sum of all numbers in the series is " << sum << "." << endl;

}

void findLowest(string series) {

	string temp_string;
	temp_string = series[0];
	int lowest = stoi(temp_string), temp_int;


	for (int i = 1; i < series.length(); i++) {

		temp_string= series[i];
		temp_int = stoi(temp_string);

		if (temp_int < lowest) {
			lowest = temp_int;
		}
	}

	cout << "The lowest number in the series is " << lowest << "." << endl;

}

void findHighest(string series) {

	string temp_string;
	temp_string = series[0];
	int highest = stoi(temp_string), temp_int;


	for (int i = 1; i < series.length(); i++) {

		temp_string = series[i];
		temp_int = stoi(temp_string);

		if (temp_int > highest) {
			highest = temp_int;
		}
	}

	cout << "The highest number in the series is " << highest << "." << endl;

}