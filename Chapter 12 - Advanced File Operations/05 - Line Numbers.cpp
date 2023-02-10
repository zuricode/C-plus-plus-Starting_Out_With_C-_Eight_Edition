//5. Line Numbers
// 
//(This assignment could be done as a modification of the program in Programming
//	Challenge 2.) Write a program that asks the user for the name of a file.The program
//	should display the contents of the file on the screen.Each line of screen output should
//	be preceded with a line number, followed by a colon.The line numbering should start
//	at 1. Here is an example :
//1 : George Rolland
//2 : 127 Academy Street
//3 : Brasstown, NC 28706
// 
//If the file’s contents won’t fit on a single screen, the program should display 24 lines of
//output at a time, and then pause.Each time the program pauses, it should wait for the
//user to strike a key before the next 24 lines are displayed.

#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#
using namespace std;

void openFile(ifstream &);
void showFileData(ifstream &, const int);

int main() {

	const int LINE_LIMIT = 24;

	ifstream file;

	openFile(file);
	showFileData(file, LINE_LIMIT);

}

void openFile(ifstream &file){

	string location;
	string str;

	cout << "Enter the location of your text file: ";
	getline(cin, location);

	cout << endl;

	file.open(location, ios::in);

	if (!file) {
		cout << "Error opening file. Re-run the program and try again." << endl;
		cout << "Aborting the program..." << endl;
		exit(EXIT_SUCCESS);
	}

	else {
		cout << location << " was successfully opened." << endl;
	}

	cout << endl;

}

void showFileData(ifstream &file, const int LINE_LIMIT) {

	string str;
	int line_num = 1;

	cout << right;

	while(!file.eof()) {

		getline(file, str);
		cout << setw(2) << line_num << ":" << str << endl;

		if (line_num % LINE_LIMIT != 0) {			
			line_num++;
		}
		

		else {

			cout << endl;

			cout << "Press ENTER to continue reading the file...";
			cin.get();
			line_num++;
			cout << endl;

		}		

	}

	cout << endl;

	cout << "The end of the file has been reached." << endl;
	cout << "Exiting the program..." << endl;

}
