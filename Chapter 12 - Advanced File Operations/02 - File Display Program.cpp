//2. File Display Program
//
//Write a program that asks the user for the name of a file.The program should display the
//contents of the file on the screen.If the file’s contents won’t fit on a single screen, the program
//should display 24 lines of output at a time, and then pause.Each time the program
//pauses, it should wait for the user to strike a key before the next 24 lines are displayed.
//
//NOTE: Using an editor, you should create a simple text file that can be used to test
//this program.

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

int main() {

	ifstream file;
	string file_location;
	string str;
	char next_24;

	cout << "Enter the location of your file: ";
	getline(cin, file_location);

	cout << endl;

	file.open(file_location, ios::in);

	if (!file) {
		cout << "ERROR: \"" << file_location << "\" could not be opened." << endl;
		exit(EXIT_FAILURE);
	}

	for (int count = 1; !file.eof(); count++) {

		getline(file, str);
		cout << setw(2) << left << count << " " << str << endl;

		if (count % 24 == 0) {
			cout << endl;
			cout << "If you would like to print another 24 lines of text, press the ENTER key: ";
			cin.get();
			cout << endl;
		}

	}

	cout << endl;

	cout << "The end of the document has been reached." << endl;
	cout << "Quitting the program...." << endl;

}