//6. Word Frequency
//
//Write a program that reads the contents of a text file. The program should create a map in which 
//the keys are the individual words found in the file and the values are the number of times each word appears.
//For example, if the word "the" appears 128 times, the map would contain an element with "the" as the key 
//and 128 as the value. The program should either display the frequency of each word or create a second file
//containing a list of each word and its frequency.
//
//Hint: See Chapter 10 for a discussion of string tokenizing.

#include<iostream>
#include<iomanip>
#include<map>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

void importTextFromFile(vector<string>&);
void createTextMap(vector<string>, map<string, int>&);
string toUpperCase(string);
void displayMap(const map<string, int>&, const string);

void outputMapToFile(const map<string, int>&);

int main() {

	vector<string> text_data;
	map<string, int> word_frequency_map;

	cout << "============================\n";
	cout << "17-06 WORD FREQUENCY PROGRAM\n";
	cout << "============================\n";
	cout << "\n";

	importTextFromFile(text_data);
	createTextMap(text_data, word_frequency_map);

	displayMap(word_frequency_map, "WORD FREQUENCY MAP");
	
	outputMapToFile(word_frequency_map);

	cout << "Ending the program...\n";
	cout << "\n";

}

string toUpperCase(string text) {

	for (int i = 0; i < text.size(); i++) {
		text[i] = toupper(text[i]);
	}

	return text;

}

void importTextFromFile(vector<string>& vector) {

	ifstream file;
	string file_location;
	string word;

	do {

		cout << "Enter the location of the source text file: ";
		getline(cin, file_location);

		file.open(file_location, ios::in);

		if (file.fail()) {
			cout << "ERROR: File location seems to be invalid. Please try again.\n";
			cout << "\n";
		}
		else {
			cout << "Source file was successfully opened.\n";
			file.clear();
		}

		cout << "\n";

	} while (file.fail());

	while (file >> word) {
		vector.push_back(word);
	}
	
	file.close();
	cout << "Source file has been closed.\n";
	cout << "\n";

}

void createTextMap(vector<string>text, map<string, int>& map) {

	int counter;
	vector<string>::iterator it;
	vector<string>::iterator it_2;

	for (it = text.begin(); it != text.end();) {

		counter = 1;

		for (it_2 = it + 1; it_2 != text.end();) {

			if (toUpperCase(*it_2) == toUpperCase(*it)) {
				counter++;
				it_2 = text.erase(it_2);
			}
			else {
				it_2++;
			}

		}

		map.insert(make_pair(*it, counter));
		it = text.erase(it);

	}

}

void displayMap(const map<string, int>& MAP, const string DESCRIPTION) {

	map<string, int>::const_iterator it;
	int spacer = 20;

	cout << DESCRIPTION << "\n";
	cout << "-----------------------\n";
	cout << "\n";

	cout << "Unique Words: " << MAP.size() << "\n";
	cout << "\n";

	cout << left << setw(spacer) << "KEY" << setw(spacer) << "VALUE" << "\n";
	cout << setfill('-') << setw(spacer * 2) << "";
	cout << setfill(' ') << "\n";
	
	for (it = MAP.begin(); it != MAP.end(); it++) {
		cout << setw(spacer) << it->first << it->second << "\n";
	}

	cout << setfill('-') << setw(spacer * 2) << "";
	cout << setfill(' ') << "\n";

	cout << "\n";

}

void outputMapToFile(const map<string, int>& MAP) {

	map<string, int>::const_iterator it;
	ofstream file;
	string file_location;
	int spacer = 20;

	cout << "Outputting map to a .txt file...\n";
	cout << "\n";

	cout << "Enter a file location to output your map: ";
	getline(cin, file_location);
	
	file.open(file_location, ios::app);

	cout << "Output file has been opened.\n";
	cout << "\n";

	file << "WORD FREQUENCY MAP\n";
	file << "Unique Words: " << MAP.size() << "\n";
	file << "\n";
	file << left << setw(spacer) << "KEY" << setw(spacer) << "VALUE" << "\n";
	file << setfill('-') << setw(spacer * 2) << "";
	file << setfill(' ') << "\n";

	for (it = MAP.begin(); it != MAP.end(); it++) {
		file << setw(spacer) << it->first << it->second << "\n";
	}

	file << setfill('-') << setw(spacer * 2) << "";
	file << setfill(' ') << "\n";

	file.close();

	cout << "The Word Frequency Map has successfully been exported.\n";
	cout << "Output file has been saved and closed.\n";
	cout << "\n";

}