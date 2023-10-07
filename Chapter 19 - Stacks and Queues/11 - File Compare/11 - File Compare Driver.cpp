//11. File Compare
//
//Write a program that opens two text files and reads their contents into two separate queues.
//The program should then determine whether the files are identical by comparing the characters 
//in the queues. When two nonidentical characters are encountered, the program should display 
//a message indicating that the files are not the same. If both queues contain the same set of 
//characters, a message should be displayed indicating that the files are identical.

#include "TextFileQueue.h"
#include <fstream>

using std::cin;
using std::ifstream;
using std::ofstream;
using std::ios;

void importTextFromFile(TextFileQueue&, const string);
bool equalQueues(TextFileQueue&, TextFileQueue&);

int main() {

	cout << "=========================\n";
	cout << "19-11 FILE COMPARE DRIVER\n";
	cout << "=========================\n";
	cout << "\n";

	TextFileQueue q1;
	TextFileQueue q2;

	importTextFromFile(q1, "FILE #1:");
	q1.print("TextFileQueue #1");

	importTextFromFile(q2, "FILE #2:");
	q2.print("TextFileQueue #2");

	bool same_text_data = equalQueues(q1, q2);

	if (same_text_data) {
		cout << "Both TextFileQueue objects contain the same text data.\n";
	}
	else {
		cout << "The TextFileQueue objects contain different text data.\n";
	}

	cout << "\n";

	cout << "Ending the program...\n";

}

void importTextFromFile(TextFileQueue& q, const string LABEL) {

	ifstream file;
	string str;
	
	do {

		cout << LABEL << ": Enter the file location for your source text file: ";
		getline(cin, str);

		cout << "\n";

		file.clear();

		file.open(str, ios::in);

		if (file.fail()) {
			cout << "ERROR: An invalid file location was provided.\n";
			cout << "\n";
		}

	} while (file.fail());

	cout << "Source text file was successfully opened.\n";
	cout << "Importing text data...\n";

	while (getline(file, str)) {

		str += "\n";

		for (int i = 0; i < str.length(); i++) {
			q.enqueue(str[i]);
		}

	}

	file.close();

	cout << "Source text was successfully imported into a TextFileQueue object.\n";
	cout << "\n";

}

bool equalQueues(TextFileQueue& Q1, TextFileQueue& Q2) {

	if (Q1.getTotalChars() != Q2.getTotalChars()) {
		return false;
	}

	else {

		char letter1, letter2;

		while (Q1.getTotalChars()) {

			Q1.dequeue(letter1);
			Q2.dequeue(letter2);

			if (letter1 != letter2) {
				return false;
			}

		}

		return true;

	}

}