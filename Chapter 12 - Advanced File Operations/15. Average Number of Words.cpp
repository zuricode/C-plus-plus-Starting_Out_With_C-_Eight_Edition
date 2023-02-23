//15. Average Number of Words
//
//If you have downloaded this book’s source code from the companion Web site, you
//will find a file named text.txt in the Chapter 12 folder. (The companion Web site is
//at www.pearsonhighered.com / gaddis .) The text that is in the file is stored as one sentence
//per line.Write a program that reads the file’s contents and calculates the average
//number of words per sentence.

#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<vector>

using namespace std;

ifstream openFile(const string);
vector<string> importTextToMemory(ifstream&);
void displayVector(vector<string>);
double calcAverageWordsPerSentence(vector<string>);

int main() {

	const string TEXT_FILE_LOCATION = "C:\\Users\\test\\Documents\\GitHub\\C-plus-plus-Starting_Out_With_C-_Eight_Edition\\Chapter 12 - Advanced File Operations\\text.txt";

	ifstream file;
	vector<string> text;
	double average;

	file = openFile(TEXT_FILE_LOCATION);

	text = importTextToMemory(file);

	displayVector(text);

	average = calcAverageWordsPerSentence(text);

	cout << "The average number of words per sentence is " << average << "." << endl;
	cout << endl;

	cout << "Closing the file..." << endl;

	file.close();

	cout << "Quiting the program..." << endl;

}

ifstream openFile(const string FILE_LOCATION) {

	ifstream file;
	string file_text = "";
	string line;

	cout << "Opening file for source text..." << endl;

	file.open(FILE_LOCATION, ios::in);

	if (!file) {
		cout << "Error opening file. Check the file location and try again." << endl;
		cout << "Aborting the program";
		exit(EXIT_FAILURE);
	}
	else {
		cout << "File has been successfully opened." << endl;
	}
	
	cout << endl;

	return file;

}

vector<string> importTextToMemory(ifstream &file) {

	string line;
	vector<string> text;

	file.seekg(0L, ios::beg);

	cout << "Importing file contents to memory..." << endl;
	cout << endl;

	while (!file.eof()) {
		getline(file, line);
		text.push_back(line);
	}

	return text;

}

void displayVector(vector<string> text) {

	cout << left;

	for (int i = 0; i < text.size(); i++) {
		cout << "L" << setw(3) << i + 1 << text[i] << endl;
	}

	cout << endl;

}

double calcAverageWordsPerSentence(vector<string> text) {

	vector<int> word_counter;

	int count;
	int total = 0;
	double average;

	bool isWord;

	for (int sentence = 0; sentence < text.size(); sentence++) {

		count = 0;

		isWord = false;

		for (int character = 0; character < text[sentence].size(); character++) {

			if (isalnum(text[sentence][character]) && !isWord) {
				count++;
				isWord = true;
			}

			else if (isspace(text[sentence][character])) {
				isWord = false;
			}
			else if (text[sentence][character] == '.' || text[sentence][character] == '!' || text[sentence][character] == '?') {
				word_counter.push_back(count);
			}

		}
			
		cout << "Sentence #" << sentence + 1 << " has " << count << " words." << endl;

		total += count;

	}

	cout << endl;

	cout << "There are " << total << " words within " << text.size() << " sentences." << endl;
	cout << endl;

	average = total / static_cast<double>(text.size());

	return average;

}



