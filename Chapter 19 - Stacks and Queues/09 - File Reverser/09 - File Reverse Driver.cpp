//9. File Reverser//
//Write a program that opens a text file and reads its contents into a stack of characters.
//The program should then pop the characters from the stack and save them in a second text file.
//The order of the chracters saved in the second file should be the reverse of their order in the
//first file.

#include "TextStack.h"
#include <fstream>
#include <string>

using std::ifstream;
using std::ofstream;
using std::string;
using std::cin;
using std::ios;

void importTextFromFile(TextStack&);
void exportStackToFile(TextStack&);

int main() {

	cout << "=========================\n";
	cout << "19-09 FILE REVERSE DRIVER\n";
	cout << "=========================\n";
	cout << "\n";

	TextStack stack;

	importTextFromFile(stack);
	exportStackToFile(stack);

	cout << "Ending the program...\n";

}

void importTextFromFile(TextStack& stack) {

	ifstream file;
	string str;
	char letter {};

	do {

		cout << "Enter the file location for the text of your source file: ";
		getline(cin, str);

		cout << "\n";

		file.open(str, ios::in);

		if (file.fail()) {
			cout << "ERROR: File could not be found. Please enter another file location.\n";
		}
		else {
			file.clear();
		}

	} while (file.fail());

	cout << "File was successfully opened.\n";

	while (getline(file, str)) {

		for (int i = 0; i < str.length(); i++) {
			stack.push(str[i]);
		}	
	
	}

	cout << "Text from file was successfully imported into the program.\n";
	cout << "\n";	

	file.close();

}

void exportStackToFile(TextStack& stack) {

	ofstream file;
	string str;
	char letter {};

	cout << "Enter the file location to export your TextStack: ";
	getline(cin, str);

	file.open(str, ios::out | ios::app);

	while (!stack.isEmpty()) {
		stack.pop(letter);
		file.put(letter);
	}

	cout << "\n";
	cout << "TextStack was successfully exported to \"" << str << "\".\n";
	cout << "\n";

	file.close();


}