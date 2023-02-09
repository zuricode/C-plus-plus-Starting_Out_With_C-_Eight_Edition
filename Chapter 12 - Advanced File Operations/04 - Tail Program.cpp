//4. Tail Program
//
//Write a program that asks the user for the name of a file.The program should display
//the last 10 lines of the file on the screen(the “tail” of the file).If the file has fewer than
//10 lines, the entire file should be displayed, with a message indicating the entire file
//has been displayed.

#include<fstream>
#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

int main() {

	const int MAX_LINES = 10;

	ifstream file;
	string file_location;
	string str;
	long total_bytes;
	long current_pos = 0;
	long offset = -1;
	int counter = 0;
	char ch;


	cout << "Enter the location of your text file: ";
	getline(cin, file_location);

	cout << endl;

	file.open(file_location, ios::in);

	if (!file) {
		cout << "An error occured whilst opening the file. Aborting the program..." << endl;
		return 0;
	} 
	
	else {

		cout << "Scanning the last 10 lines of the file..." << endl;

		file.seekg(0L, ios::end);
		current_pos = static_cast<long>(file.tellg());
		total_bytes = current_pos;

		while (counter < MAX_LINES && current_pos > 0) {

			file.seekg(offset, ios::end);
			current_pos = static_cast<long>(file.tellg());
			file.get(ch);

			if (ch == '\n') {
				counter++;
				offset--;
			}

			offset--;

		}

		if (current_pos == 0) {
			cout << "There are 10 or less lines of text within this file." << endl;
			cout << "The entire file will be displayed..." << endl;
			cout << endl;
		}

		else {
			cout << "The last 10 lines of the text file are as follows..." << endl;
			cout << endl;
		}

		file.clear();

		while (!file.eof()) {
			getline(file, str);
			cout << str << endl;

		}

	}

}