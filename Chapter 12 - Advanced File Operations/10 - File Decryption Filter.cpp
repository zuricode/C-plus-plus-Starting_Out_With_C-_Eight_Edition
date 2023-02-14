//10. File Decryption Filter
//
//Write a program that decrypts the file produced by the program in Programming
//Challenge 9. The decryption program should read the contents of the coded file, restore
//the data to its original state, and write it to another file.

#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

void inputEncryptedText(ifstream&, vector<string> &);
void showEncryptedText(vector<string>);
void decryptText(vector<string>, vector<string> &);
void showDecryptedText(vector<string>);
void outputDecrpytedText(ofstream&, vector<string>);

int main() {

	ifstream input_file;
	ofstream output_file;

	vector<string> encrypted_text;
	vector<string> original;

	inputEncryptedText(input_file, encrypted_text);

	showEncryptedText(encrypted_text);

	decryptText(encrypted_text, original);

	showDecryptedText(original);

	outputDecrpytedText(output_file, original);

}

void inputEncryptedText(ifstream &input_file, vector<string> &input_basket) {

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

void showEncryptedText(vector<string> input_basket) {

	cout << "ENCRYPTED TEXT: " << endl;
	cout << endl;

	for (int i = 0; i < input_basket.size(); i++) {
		cout << input_basket[i] << endl;
	}

	cout << endl;

}

void decryptText(vector<string> encrypted_text, vector<string> &original) {

	for (int i = 0; i < encrypted_text.size(); i++) {

		for (int j = 0; j < encrypted_text[i].length(); j++) {
			encrypted_text[i][j] -= 10;
		}

		original.push_back(encrypted_text[i]);

	}

}

void showDecryptedText(vector<string> original) {

	cout << "DECRYPTED TEXT: " << endl;
	cout << endl;

	for (int i = 0; i < original.size(); i++) {

		cout << original[i] << endl;

	}

	cout << endl;

}

void outputDecrpytedText(ofstream &output_file, vector<string> original) {

	string location;

	cout << "Enter output location for the decrypted text: ";
	getline(cin, location);

	cout << endl;

	output_file.open(location, ios::out);

	for (int i = 0; i < original.size(); i++) {
		output_file << original[i] << endl;
	}

	cout << "Decrypted data was successfully exported to " << location << "." << endl;

	cout << endl;

}

