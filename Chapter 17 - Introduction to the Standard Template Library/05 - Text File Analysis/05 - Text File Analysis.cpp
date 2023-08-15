//5. Text File Analysis
//
//Write a program that reads the contents of two text files and compares then in the following ways:
//
//	* It should display a list of all the unique words contained in both files.
//	* It should display a list of the words that appears in both files.
//	* It should display a list of the words that appears in the first file, but not the second.
//	* It should display a list of the words that appears in the second file, but not the first.
//	* It should display a list of the words that appears in either the first or second file, but not in both.
//
//Hint: Use set operations to perform these analyses. Also, see Chapter 10 for a discussion of string tokenizing.
//

#include<iostream>
#include<string>
#include<set>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

void importTextFromFiles(set<string>&, set<string>&);
void displaySetData(const set<string>&, const string);

void displaySetUnion(const set<string>&, const set<string>&);
void displaySetIntersection(const set<string>&, const set<string>&);
void displayFirstSetSD(const set<string>&, const set<string>&);
void displaySecondSetSD(const set<string>&, const set<string>&);
void displaySSD(const set<string>&, const set<string>&);

int main() {

	cout << "--------------------------------\n";
	cout << "17-05 TEXT FILE ANALYSIS PROGRAM\n";
	cout << "--------------------------------\n";
	cout << "\n";

	set<string> tf1;
	set<string> tf2;

	importTextFromFiles(tf1, tf2);

	displaySetData(tf1, "Text File #1");
	displaySetData(tf2, "Text File #2");

	displaySetUnion(tf1, tf2);
	displaySetIntersection(tf1, tf2);
	displayFirstSetSD(tf1, tf2);
	displaySecondSetSD(tf1, tf2);
	displaySSD(tf1, tf2);

	cout << "Ending the program...\n";
	cout << "\n";

}

void importTextFromFiles(set<string>& set1, set<string>& set2) {

	ifstream file1;
	ifstream file2;
	string fileLocation1;
	string fileLocation2;
	string currentWord;

	do {

		cout << "Enter the location of your first text file: ";
		//fileLocation1 = "C:\\Users\\Admin\\source\\repos\\Project2\\Project2\\C - plus - plus - Starting_Out_With_C - _Eight_Edition\\Chapter 17 - Introduction to the Standard Template Library\\04 - File Encryption and Decryption\\input.txt";
		getline(cin, fileLocation1);

		file1.open(fileLocation1, ios::in);

		if (file1.fail()) {
			cout << "ERROR: The file location provided seems to be invalid. Please try again.\n";
			cout << "\n";
		}
		else {
			cout << "File 1 was successfully opened.\n";
			cout << "\n";
			file1.clear();
		}

	} while (file1.fail());

	while (file1 >> currentWord) {
		set1.insert(currentWord);
	}
	
	cout << "The text data was successfully imported from File #1.\n";
	cout << "\n";

	do {

		cout << "Enter the location of your second text file: ";
		//fileLocation2 = "C:\\Users\\Admin\\Downloads\\_FirmwareInfo_Samfw.com.txt";
		getline(cin, fileLocation2);

		file2.open(fileLocation2, ios::in);

		if (file2.fail()) {
			cout << "ERROR: The file location provided seems to be invalid. Please try again.\n";
			cout << "\n";
		}
		else {
			cout << "File 2 was successfully opened.\n";
			cout << "\n";
			file2.clear();
		}

	} while (file2.fail());

	while (file2 >> currentWord) {
		set2.insert(currentWord);
	}

	cout << "The text data was successfully imported from File #2.\n";
	cout << "\n";

	file1.close();
	file2.close();

}

void displaySetData(const set<string>& SET, const string DESCRIPTION) {

	set<string>::const_iterator cit;

	cout << DESCRIPTION << " values\n";
	cout << "----------------------\n";
	cout << "Number of unique words in the set: " << SET.size() << "\n";
	cout << "\n";

	for (cit = SET.begin(); cit != SET.end(); cit++) {
		cout << *cit << " | ";
	}

	cout << "\n";
	cout << "\n";
	cout << "\n";

}

void displaySetUnion(const set<string>& SET1, const set<string>& SET2) {

	vector<string> result(SET1.size() + SET2.size());
	vector<string>::iterator it;

	it = set_union(SET1.begin(), SET1.end(), SET2.begin(), SET2.end(), result.begin());

	result.resize(it - result.begin());

	cout << "Number of unique words from both files: " << result.size() << "\n";
	cout << "\n";

	cout << "Words that appear in both files: ";

	for (it = result.begin(); it != result.end(); it++) {
		cout << *it << " | ";
	}

	cout << "\n";
	cout << "\n";
	cout << "\n";

}

void displaySetIntersection(const set<string>& SET1, const set<string>& SET2) {

	vector<string> result(SET1.size() + SET2.size());
	vector<string>::iterator it;

	it = set_intersection(SET1.begin(), SET1.end(), SET2.begin(), SET2.end(), result.begin());

	result.resize(it - result.begin());

	cout << "Number of words found in BOTH sets: " << result.size() << "\n";
	cout << "\n";

	cout << "Words that were found in both sets...\n";
	cout << "----------------------------------------\n";

	for (it = result.begin(); it != result.end(); it++) {
		cout << *it << " | ";
	}

	cout << "\n";
	cout << "\n";
	cout << "\n";

}

void displayFirstSetSD(const set<string>& SET1, const set<string>& SET2) {

	vector<string> result(SET1.size() + SET2.size());
	vector<string>::iterator it;

	it = set_difference(SET1.begin(), SET1.end(), SET2.begin(), SET2.end(), result.begin());

	result.resize(it - result.begin());

	cout << "Number of unique words only found in SET 1: " << result.size() << "\n";
	cout << "\n";

	cout << "List of unique words only found in SET 1...\n";
	cout << "-------------------------------------------\n";

	for (it = result.begin(); it != result.end(); it++) {
		cout << *it << " | ";
	}

	cout << "\n";
	cout << "\n";
	cout << "\n";

}

void displaySecondSetSD(const set<string>& SET1, const set<string>& SET2) {

	vector<string> result(SET1.size() + SET2.size());
	vector<string>::iterator it;

	it = set_difference(SET2.begin(), SET2.end(), SET1.begin(), SET1.end(), result.begin());

	result.resize(it - result.begin());

	cout << "Number of unique words only found in SET 2: " << result.size() << "\n";
	cout << "\n";

	cout << "List of unique words only found in SET 2...\n";
	cout << "-------------------------------------------\n";

	for (it = result.begin(); it != result.end(); it++) {
		cout << *it << " | ";
	}

	cout << "\n";
	cout << "\n";
	cout << "\n";

}

void displaySSD(const set<string>& SET1, const set<string>& SET2) {

	vector<string> result(SET1.size() + SET2.size());
	vector<string>::iterator it;

	it = set_symmetric_difference(SET1.begin(), SET1.end(), SET2.begin(), SET2.end(), result.begin());

	result.resize(it - result.begin());

	cout << "Number of words that can be found in each set, but not both: " << result.size() << "\n";
	cout << "\n";

	cout << "List of words that can be found in each set, but not both...\n";
	cout << "------------------------------------------------------------\n";
	
	for (it = result.begin(); it != result.end(); it++) {
		cout << *it << " | ";
	}

	cout << "\n";
	cout << "\n";
	cout << "\n";

}