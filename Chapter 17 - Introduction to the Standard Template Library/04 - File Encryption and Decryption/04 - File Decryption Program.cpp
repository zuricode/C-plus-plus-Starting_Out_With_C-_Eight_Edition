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
#include<iomanip>
#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

char decryptionFunction(int);
void importEncryptedText(vector<string>&);
void showEncryptedText(const vector<string>&);
void showDecryptedText(const vector<string>&);

int main() {

	vector<string> encrypted_text;

	cout << "=============================\n";
	cout << "17-04 FILE DECRYPTION PROGRAM\n";
	cout << "=============================\n";
	cout << "\n";

	importEncryptedText(encrypted_text);

	showEncryptedText(encrypted_text);
	showDecryptedText(encrypted_text);

	cout << "Ending the program...\n";
	cout << "\n";

}

char decryptionFunction(int a) {

	a += 11;
	a -= 34;

	return a;

}

void importEncryptedText(vector<string>& text) {

	ifstream file;
	string file_location;
	vector<string>::iterator it;
	string line;

	do {

		cout << "Enter the file location of your encrypted source file: ";
		getline(cin, file_location);
		cout << "\n";

		file.open(file_location, ios::in);

		if (file.fail()) {
			cout << "ERROR: No file can be found at the aofrementioned file location. Please try again...\n";
		}
		else {
			cout << "The encryted source file was opened successfully.\n";
			file.clear();
		}

		cout << "\n";

	} while(file.fail());

	while (getline(file, line)) {
		text.push_back(line);
	}

	cout << "The encrypted text was imported successfully.\n";
	cout << "\n";

}

void showEncryptedText(const vector<string>& TEXT) {

	vector<string>::const_iterator it;

	cout << "ENCRYPTED TEXT:\n";
	cout << "---------------\n";
	cout << "\n";

	for (it = TEXT.begin(); it != TEXT.end(); it++) {
		cout << *it;
	}

	cout << "\n";
	cout << "\n";

}

void showDecryptedText(const vector<string>& TEXT) {

	vector<string>::const_iterator it;
	string line;

	cout << "DECRYPTED TEXT:\n";
	cout << "---------------\n";
	cout << "\n";

	for (it = TEXT.begin(); it != TEXT.end(); it++) {
		
		line = *it;

		for (int i = 0; i < line.size(); i++) {
			line[i] = decryptionFunction(line[i]);
		}

		cout << line;

	}

	cout << "\n";

}