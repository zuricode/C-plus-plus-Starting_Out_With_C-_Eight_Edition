//9. File Encryption Filter
//
//File encryption is the science of writing the contents of a file in a secret code.Your
//encryption program should work like a filter, reading the contents of one file, modifying
//the data into a code, and then writing the coded contents out to a second file.The
//second file will be a version of the first file, but written in a secret code.
//
//Although there are complex encryption techniques, you should come up with a
//simple one of your own.For example, you could read the first file one character at
//a time, and add 10 to the ASCII code of each character before it is written to the
//second file.

#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

void inputSourceData(ifstream&, vector<string> &);
void showSourceText(vector<string>);
void encryptText(vector<string>, vector<char> &);
void deEncryptAndShowText(vector<char>);

void showEncryptedText(vector<char>);

void outputEncrpytedText(ofstream&, vector<char>);


int main() {

	ifstream input_file;
	ofstream coded_file;

	vector<string> input_basket;
	vector<char> coded_text;

	inputSourceData(input_file, input_basket);

	showSourceText(input_basket);

	encryptText(input_basket, coded_text);

	showEncryptedText(coded_text);

	outputEncrpytedText(coded_file, coded_text);

	deEncryptAndShowText(coded_text);

}

void inputSourceData(ifstream &input_file, vector<string> &input_basket) {

	string location;
	string str;

	cout << "Enter the location of your source file: ";
	getline(cin, location);

	cout << endl;

	input_file.open(location, ios::in);

	if (!input_file) {
		cout << "Error opening file. Re-run the program and try another file location." << endl;
		cout << "Aborting the program..." << endl;
		exit(EXIT_FAILURE);
	}
	else {
		cout << location << " was successfully opened." << endl;
	}

	while (!input_file.eof()) {
		getline(input_file, str);
		input_basket.push_back(str);
	}

	input_file.close();

	cout << endl;

}

void showSourceText(vector<string> input_basket) {

	cout << "SOURCE TEXT: " << endl;
	cout << endl;

	for (int i = 0; i < input_basket.size(); i++) {
		cout << input_basket[i] << endl;
	}

	cout << endl;

}

void encryptText(vector<string> original, vector<char> &coded_text) {

	char letter;

	for (int i = 0; i < original.size(); i++) {

		for (int j = 0; j < original[i].length(); j++) {
			letter = static_cast<char>(original[i][j] + 10);
			coded_text.push_back(letter);
		}

	}

}

void deEncryptAndShowText(vector<char> coded_text) {

	cout << "DE-ENCRYPTED TEXT: " << endl;
	cout << endl;

	char letter;

	for (int i = 0; i < coded_text.size(); i++) {
		letter = static_cast<char>(coded_text[i] - 10);
		cout << letter;
	}

	cout << endl;

	cout << endl;

}

void showEncryptedText(vector<char> coded_text) {

	cout << "ENCRYPTED TEXT: " << endl;
	cout << endl;

	for (int i = 0; i < coded_text.size(); i++) {

		cout << coded_text[i];

	}

	cout << endl;

	cout << endl;

}

void outputEncrpytedText(ofstream &output_file, vector<char> coded_text) {

	string location;

	cout << "Enter output location for the encrypted text: ";
	getline(cin, location);

	cout << endl;

	output_file.open(location, ios::out);

	for (int i = 0; i < coded_text.size(); i++) {
		output_file << coded_text[i];
	}

	cout << "Encrypted data was successfully exported to " << location << "." << endl;

	cout << endl;

}

