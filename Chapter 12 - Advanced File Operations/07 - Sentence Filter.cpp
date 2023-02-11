//7. Sentence Filter
//#
//Write a program that asks the user for two file names.The first file will be opened for
//inputand the second file will be opened for output. (It will be assumed that the first file
//contains sentences that end with a period.) The program will read the contents of the first
//file and change all the letters to lowercase except the first letter of each sentence, which
//should be made uppercase.The revised contents should be stored in the second file.

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

void getFirstFile(ifstream &);
void getSecondFile(ofstream &);
void changeTextFormat(ifstream&, ofstream&);

int main() {

	ifstream input_file;
	ofstream output_file;

	getFirstFile(input_file);
	getSecondFile(output_file);

	changeTextFormat(input_file, output_file);

	input_file.close();
	output_file.close();

}

void getFirstFile(ifstream& input) {

	string location;

	cout << "Enter the location of your input file: ";
	getline(cin, location);

	cout << endl;

	input.open(location, ios::in);

	if (!input) {
		cout << "Error opening file. Re-run the program and try again." << endl;
		cout << "Aborting the program..." << endl;
		exit(EXIT_FAILURE);
	}

	else {
		cout << "Input file was successfully opened." << endl;
	}

	cout << endl;

}

void getSecondFile(ofstream& output) {

	string location;

	cout << "Enter the location of your output file: ";
	getline(cin, location);

	cout << endl;

	output.open(location, ios::out);

	cout << "Output file was successfully opened." << endl;

	cout << endl;

}

void changeTextFormat(ifstream &input, ofstream &output) {

	string str;
	bool period = false;

	while (!input.eof()) {

		getline(input, str);

		for (int i = 0; i < str.size(); i++) {

			if (i == 0 && islower(str[i])) {
				str[i] = toupper(str[i]);
			}

			else if (str[i] == '.') {
				period = true;
			}

			else if (isupper(str[i]) && !period) {
				str[i] = tolower(str[i]);
			}

			else if (islower(str[i]) && period) {
				str[i] = toupper(str[i]);
				period = false;
			}

			else if (isupper(str[i]) && period) {
				period = false;
			}

		}

		output << str << endl;

	}

	cout << "The text from the input file was successfully processed into the output file." << endl;

	cout << endl;

}
