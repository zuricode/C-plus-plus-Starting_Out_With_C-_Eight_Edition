//1. Unique Words
//
//Write a program that opens a specified text file then displays a list of all the unique words found in the file.
//
//Hint: Store each word as an element of a set.

#include<set>
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main() {

	ifstream text_file;
	string word;

	set<string> words;
	set<string>::iterator it;

	cout << "=================\n";
	cout << "01 - UNIQUE WORDS\n";
	cout << "=================\n";
	cout << "\n";

	text_file.open("C:\\Users\\Admin\\source\\repos\\Project2\\Project2\\C-plus-plus-Starting_Out_With_C-_Eight_Edition\\Chapter 17 - Introduction to the Standard Template Library\\01 - Unique Words\\words.txt", ios::in);

	if (!text_file.fail()) {

		while (text_file) {
			getline(text_file, word, '\n');
			words.insert(word);
		}

		cout << "LIST OF WORDS IMPORTED INTO THE SET\n";
		cout << "-----------------------------------\n";
		cout << "\n";

		for (it = words.begin(); it != words.end(); it++) {
			cout << *it << "\n";
		}

	}
	else {
		cout << "File name was invalid. Re-run the program and try again.\n";
	}		

	text_file.close();

	cout << "\n";
	cout << "Ending the program...\n";

}