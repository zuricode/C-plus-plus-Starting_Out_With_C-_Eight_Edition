//15. Character Analysis
// 
//If you have downloaded this book’s source code from the companion Web site, you
//will find a file named text.txt in the Chapter 10 folder. (The companion Web site is
//	at www.pearsonhighered.com / gaddis .) Write a program that reads the file’s contents
//	and determines the following :
// 
//• The number of uppercase letters in the file
//• The number of lowercase letters in the file
//• The number of digits in the file

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void importDataFromFile(string&);
void fileCharacterReport(string);

const string		FILE_LOCATION = "C:\\Users\\test\\Documents\\GitHub\\C-plus-plus-Starting_Out_With_C-_Eight_Edition\\Chapter 10 - Characters, C-Strings, and More About the string Class\\text.txt";
using namespace std;

int main() {

	string file_contents;

	importDataFromFile(file_contents);

	cout << "File contents: " << file_contents << endl;

	fileCharacterReport(file_contents);

}

void importDataFromFile(string& file_contents) {

	ifstream file_input;
	file_input.open(FILE_LOCATION);

	if (file_input) {
		getline(file_input, file_contents);
		file_input.close();
	}

}

void fileCharacterReport(string sentence) {

	int uppercase = 0, lowercase = 0, digits = 0;

	for (int i = 0; i < sentence.length(); i++) {

		if (isupper(sentence[i])) {
			uppercase++;
		}
		else if (islower(sentence[i])) {
			lowercase++;
		}
		else if (isdigit(sentence[i])) {
			digits++;
		}

	}

	cout << "File Report: " << endl;
	cout << endl;
	cout << "Uppercase characters: " << uppercase << endl;
	cout << "Lowercase characters: " << lowercase << endl;
	cout << "Digits: " << digits << endl;

	cout << endl;

}