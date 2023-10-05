//10. File Filter
//
//Write a program that opens a text file and reads its contents into a queue of characters. The program should
//then dequeue each character, convert it to uppercase, and store it in a second file.

#include "TextQueue.h"
#include <fstream>
#include <string>

using std::cin;
using std::ios;
using std::ifstream;
using std::ofstream;
using std::string;

void importTextFromFile(TextQueue&);
void exportTextToFile(TextQueue&);

int main() {

	cout << "========================\n";
	cout << "19-10 FILE FILTER DRIVER\n";
	cout << "========================\n";
	cout << "\n";

	TextQueue text;

	importTextFromFile(text);

	text.print();

	exportTextToFile(text);

	cout << "Ending the program...\n";

}

void importTextFromFile(TextQueue& q) {

	ifstream file;
	string str;

	do {

		cout << "Enter file location of your source text: ";
		getline(cin, str);

		cout << "\n";

		file.open(str, ios::in);

		if (file.fail()) {
			cout << "ERROR: An invalid file location was entered. Enter another file location.\n";
			cout << "\n";
		}
		else {
			file.clear();
			cout << "Source file was successfully opened.\n";
		}

	} while (file.fail());

	cout << "Importing text to TextQueue object...\n";

	while (getline(file, str)) {

		str += '\n';

		for (int i = 0; i < str.length(); i++) {
			q.enqueue(str[i]);
		}

	}

	cout << "Congratulations! Text was successfully extracted from the source file into your TextQueue object\n";
	cout << "\n";	

	file.close();

}

void exportTextToFile(TextQueue& Q) {

	ofstream file;
	string location;
	char letter;

	cout << "Enter the file location for your text to capitalised and exported to: ";
	getline(cin, location);

	cout << "\n";

	file.open(location, ios::out | ios::app);

	if (file.fail()) {
		cout << "NOTE: File already exists. The exported text will be added to the end of the file.\n";
		cout << "\n";
	}

	while (!Q.isEmpty()) {
		Q.dequeue(letter);
		file.put(toupper(letter));
	}

	cout << "Congratulations! Your text was successfully exported as an uppercase format to \"" << location << "\".\n";
	cout << "\n";

	file.close();


}