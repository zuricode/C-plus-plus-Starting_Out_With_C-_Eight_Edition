//7. Word Index
//
//Write a program that reads the contents of a text file. The program should create a map in which 
//the key-value pairs are described as follows:
//
//	* Key - The keys are the individual words found in the file.
//	* Values - Each value is a set that contains the line numbers in the file where the word
//		(the key) is found.
//
//For example, suppose the word "robot" is found in lines 7, 18, 94, 138. The map would contain an element 
//in which the key was the string "robot", and the value was a set containing the numbers 7, 18, 94,
//and 138.
//
//Once the map is built, the program should create another text file, known as a word index, listing
//the contents of the map. The word index file should contain an alphabetic listing of the words 
//that are stored as keys in the map, along with the line numbers where the words appears in the
//original file. Figure 17-9 shows an example of an original text file (Kennedy.txt) and its index
//file (index.txt).
//
//Hint: See Chapter 10 for a discussion of string tokenizing.

#include<iostream>
#include<string>
#include<fstream>
#include<map>
#include<set>
#include<vector>
#include<iomanip>

using namespace std;

void importDataFromFile(multimap<string, int>&);
void showData(const multimap<string, int>&);
void createWordIndexMap(const multimap<string, int>&, map<string, set<int>>&);
void showWordIndexMap(const map<string, set<int>>&);

int main() {

	multimap<string, int>imported_data;
	map<string, set<int>> index_map;

	cout << "========================\n";
	cout << "17-07 WORD INDEX PROGRAM\n";
	cout << "========================\n";
	cout << "\n";

	importDataFromFile(imported_data);

	showData(imported_data);

	createWordIndexMap(imported_data, index_map);

	showWordIndexMap(index_map);

}

void importDataFromFile(multimap<string, int>& map) {

	ifstream file;
	string file_location;
	string line;
	string word = "";
	int line_counter = 1;

	do {

		cout << "Enter the file location of the source text file: ";
		getline(cin, file_location);
		cout << "\n";

		file.open(file_location, ios::in);

		if (file.fail()) {
			cout << "ERROR: An invalid file location was entered. Choose a different file location.\n";
			cout << "\n";
		}
		else {
			cout << "Source text file was successfully opened.\n";
			cout << "\n";
			file.clear();
		}

	} while (file.fail());

	cout << "Importing data in the program...\n";
	cout << "\n";
	
	while (getline(file, line)) {

		line += '\n';

		for (int i = 0; i < line.size(); i++) {

			if (isspace(line[i]) || ispunct(line[i])) {
				if (word != "") {
					map.insert(make_pair(word, line_counter));
					word = "";
				}				
			}
			else {
				word += tolower(line[i]);
			}

		}

		line_counter++;

	}

	cout << "The data has been successfully imported into the program.\n";
	cout << "\n";
	
	file.close();

}

void showData(const multimap<string, int>& MAP) {

	multimap<string, int>::const_iterator map_cit;

	cout << "SOURCE DATA\n";
	cout << "-----------\n";
	cout << "\n";
	cout << left;

	for (map_cit = MAP.begin(); map_cit != MAP.end(); map_cit++) {

		cout << setw(20) << map_cit->first << map_cit->second << "\n";

	}

	cout << "\n";
	cout << "-----------------------------------------------------------------------------------------------\n";
	cout << "\n";

}

void createWordIndexMap(const multimap<string, int>& SOURCE, map<string, set<int>>& map) {

	string word;
	set<int> page_numbers;

	multimap<string, int>::const_iterator source_cit;

	cout << "Creating index map...\n";
	cout << "\n";

	source_cit = SOURCE.begin();
	word = source_cit->first;
	page_numbers.insert(source_cit->second);

	source_cit++;

	for (; source_cit != SOURCE.end(); source_cit++) {

		if (word == source_cit->first) {
			page_numbers.insert(source_cit->second);
		}
		else {
			map.insert(make_pair(word, page_numbers));
			word = source_cit->first;
			page_numbers.clear();
			page_numbers.insert(source_cit->second);
		}

	}

}

void showWordIndexMap(const map<string, set<int>>& MAP) {

	map<string, set<int>>::const_iterator cit;
	set<int>::iterator it;

	cout << "INDEX MAP\n";
	cout << "---------\n";
	cout << "\n";

	cout << left;

	cout << setw(20) << "WORD" << "PAGE NUMBERS" << "\n";
	cout << setfill('-') << setw(40) << "";
	cout << "\n" << setfill(' ');

	for (cit = MAP.begin(); cit != MAP.end(); cit++) {
		cout << setw(20) << cit->first;
		
		for (it = cit->second.begin(); it != cit->second.end(); it++) {
			cout << *it << " ";
		}

		cout  << "\n";

	}

}