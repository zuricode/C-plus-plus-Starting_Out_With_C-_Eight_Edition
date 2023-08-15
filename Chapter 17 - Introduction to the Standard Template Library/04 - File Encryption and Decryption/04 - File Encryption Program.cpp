//4. File Encrpytion and Decryption
//
//Write a program that uses a map to assign "codes" to each letter of the alphabet.For exmaple
//
//map<char, char> codes =
//{ {'A', '%'}, {'a', '9'}, {'B', '@'}, {'b', '#'}, etc };
//
//Using this example, the letter 'A' would be assigned the symbol %, the letter 'a' would
//be assigned the number 9, the letter 'B' would be assigned the symbol @, and so forth.
//The program should open a specified text file, read its contents, then use the map to write 
//an encrypted version of the file's contents to a second file. Each character in the second file
//should contain the code for the corresponding character in the first file. Write a second 
//program that opens an encrypted file and displays its decrypted contents on the screen.

#include<map>
#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

void createEncryptionMap(map<char, char>&);
void displayEncryptionMap(const map<char, char>&);

char encryptionFunction(const int);

void importText(vector<string>&);
void exportText(const vector<string>&);
void displayText(const vector<string>&, const string);
void encryptSourceText(const vector <string>&, const map<char, char>&, vector<string>&);

int main() {

	map<char, char> encryptionTable;
	vector<string> sourceText;
	vector<string> encryptedText;

	cout << "=============================\n";
	cout << "17-04 FILE ENCRYPTION PROGRAM\n";
	cout << "=============================\n";
	cout << "\n";

	createEncryptionMap(encryptionTable);

	displayEncryptionMap(encryptionTable);

	importText(sourceText);
	displayText(sourceText, "SOURCE TEXT");

	encryptSourceText(sourceText, encryptionTable, encryptedText);
	displayText(encryptedText, "ENCRYPTED TEXT");

	exportText(encryptedText);

	cout << "Closing the program...\n";
	cout << "\n";

}

char encryptionFunction(int a) {

	a += 34;
	a -= 11;

	return a;

}

void createEncryptionMap(map<char, char>& map) {

	for (int i = 0; i <= 255; i++) {
		map.insert(make_pair(i, encryptionFunction(i)));
	}
		
}

void displayEncryptionMap(const map<char, char>& MAP) {

	map<char, char>::const_iterator it;
	int spacer = 10;

	cout << "Encryption Table:\n";
	cout << "-----------------\n";
	cout << left << setw(spacer) << "KEY" << setw(spacer) << "VALUE\n";
	cout << "\n";

	for (it = MAP.begin(); it != MAP.end(); it++) {
		cout << setw(spacer) << it->first << setw(spacer) << it->second << "\n";
	}

	cout << "\n";

}

void importText(vector<string>& sourceText) {

	ifstream file;
	string file_location;
	string line;

	do {

		cout << "Enter the file location for the source text: ";
		getline(cin, file_location);

		file.open(file_location, ios::in);

		if (file.fail()) {
			cout << "Error: Could not open file. Invalid file location was provided.\n";
			cout << "\n";
		}
		else {
			file.clear();
		}

	} while (file.fail());

	while (getline(file, line)) {
		line += '\n';
		sourceText.push_back(line);
	}

	cout << "Source text has been successfully,\n";
	cout << "\n";	

}

void exportText(const vector<string>& ENCRYPTED_TEXT) {

	ofstream file;
	string file_location;
	vector<string>::const_iterator it;

	cout << "Enter the file location for your encrypted output file: ";
	getline(cin, file_location);
	cout << "\n";

	file.open(file_location, ios::out);

	if (file.fail()) {
		cout << "NOTE: \"" << file_location << "\" was not a pre-existing file.\n";
		cout << "Creating the file now...\n";
	}
	else {
		cout << "Output file was successfully opened.\n";
	}

	for (it = ENCRYPTED_TEXT.begin(); it != ENCRYPTED_TEXT.end(); it++) {
		file << *it;
	}

	cout << "\n";

	cout << "The encrypted text was exported successfully!.\n";
	cout << "\n";

	file.close();

}

void displayText(const vector<string>& V, const string DESCRIPTION) {

	cout << DESCRIPTION << ":\n";
	cout << "------------\n";
	cout << "\n";

	for (int i = 0; i < V.size(); i++) {
		cout << V[i];
	}

	cout << "\n";
	cout << "\n";

}

void encryptSourceText(const vector<string>& SOURCE, const map<char, char>& MAP, vector<string>& output) {

	vector<string>::const_iterator it;
	string line;

	cout << "Encrypting the source text...\n";
	cout << "\n";

	for (it = SOURCE.begin(); it != SOURCE.end(); it++) {

		line = *it;

		for (int i = 0; i < line.size(); i++) {
			line[i] = MAP.at(line[i]);
		}

		output.push_back(line);

	}

}