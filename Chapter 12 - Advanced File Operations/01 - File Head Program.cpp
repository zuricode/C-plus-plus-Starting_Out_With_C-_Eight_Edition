//1. File Head Program
//
//Write a program that asks the user for the name of a file.The program should display
//the first 10 lines of the file on the screen(the “head” of the file).If the file has fewer
//than 10 lines, the entire file should be displayed, with a message indicating the entire
//file has been displayed.
//
//NOTE: Using an editor, you should create a simple text file that can be used to test
//this program.

#include<iostream>
#include<fstream>
#include<string>

using namespace std;


int main() {

	ifstream file;
	string file_location;
	string line;
	int line_counter = 0;

	cout << "What is the file location of your text file: ";
	getline(cin, file_location);

	cout << endl;

	file.open(file_location, ios::in);

	if (!file) {
		cout << "Error opening the file \"" << file_location << "\"." << endl;
		exit(EXIT_FAILURE);
	}
	else {

		while (getline(file, line) && line_counter <= 10) {
			cout << line << endl;
			line_counter++;
		}

		cout << endl;

		if (file.eof() || line_counter <= 10) {
			cout << "The entire file was printed." << endl;
		}
		else {
			cout << "Only the first 10 lines of the text file were printed." << endl;
		}

	}

	file.close();

	cout << endl;

	cout << "Quitting the program..." << endl;

}

