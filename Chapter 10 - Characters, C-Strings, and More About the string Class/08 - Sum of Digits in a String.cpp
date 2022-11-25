//8. Sum of Digits in a String
//Write a program that asks the user to enter a series of single digit numbers with nothing
//separating them.Read the input as a C - string or a string object.The program should
//display the sum of all the single - digit numbers in the string.For example, if the user
//enters 2514, the program should display 12, which is the sum of 2, 5, 1, and 4. The
//program should also display the highest and lowest digits in the string.

#include <iostream>
#include <string>

using namespace std;

string enterNumber();
void checkString(string);
void sumOfSeries(string);
void findLowest(string);
void findHighest(string);

int main() {

	string series;

	series = enterNumber();
	checkString(series);
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

void checkString(string series) {

	for (int i = 0; i < series.length(); i++) {
		if (!isdigit(series[i])) {
			cout << "A non-digit element was found in the string. Please re-run the program, entering ONLY digits in the string." << endl;
			exit(EXIT_FAILURE);
		}
	}

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

		temp_string = series[i];

		if (stoi(temp_string) < lowest) {
			lowest = stoi(temp_string);
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

		if (stoi(temp_string) > highest) {
			highest = stoi(temp_string);
		}

	}

	cout << "The highest number in the series is " << highest << "." << endl;

}