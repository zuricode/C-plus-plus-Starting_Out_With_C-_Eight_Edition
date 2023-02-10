//6. String Search
//
//Write a program that asks the user for a file name and a string to search for.The
//program should search the file for every occurrence of a specified string.When the
//string is found, the line that contains it should be displayed.After all the occurrences
//have been located, the program should report the number of times the string appeared
//in the file.

#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>

using namespace std;

void openFile(ifstream&);
void searchForString(ifstream&, string);

int main() {

	ifstream file;
	string search_str;

	openFile(file);

	cout << "Enter your string to find in the text file: ";
	getline(cin, search_str);

	cout << endl;

	searchForString(file, search_str);

	file.close();

}

void openFile(ifstream& file) {

	string location;
	string str;

	cout << "Enter the location of your file: ";
	getline(cin, location);

	cout << endl;

	file.open(location, ios::in);

	if (!file) {
		cout << "Error opening file. Re-run the program and try again." << endl;
		cout << "Aborting the program..." << endl;
		exit(EXIT_SUCCESS);
	}

	else {
		cout << "File was opened successfully." << endl;
	}

	cout << endl;

}

void searchForString(ifstream &file, string search_str) {

	int line_num = 1;
	int matches = 0;
	string str;

	cout << "MATCHES FOUND: " << endl;

	while (!file.eof()) {

		getline(file, str);

		if (str.find(search_str, 0) != -1) {
			cout << "Line " << left << setw(2) << line_num << ":\t" << str << endl;
			matches++;
		}

		line_num++;

	}

	cout << endl;

	cout << "\"" << search_str << "\" was found " << matches << " times in the file." << endl;

}
